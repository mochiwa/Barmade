#include "productstockorder.h"

ProductStockOrder::ProductStockOrder(QWidget *parent):
    AbstractTableWidget (parent)
{
    initColumns();
    TableWidgetSpinBoxDelegate *delegate=new TableWidgetSpinBoxDelegate(Column::ToOrder,this);
    setItemDelegate(delegate);
    connect(delegate,&TableWidgetSpinBoxDelegate::cellUpdate,this,&AbstractTableWidget::updateLine);
}
ProductStockOrder::~ProductStockOrder()
{
}

QVariant ProductStockOrder::build()
{
    Invoice invoice;
    std::vector<CompositionOrder> compositions;
    Product p;
    QTableWidgetItem *itemToOrder=nullptr;
    for(int row=0;row<rowCount;++row)
    {
        itemToOrder=item(row,Column::ToOrder);
        p.fromVariant(objects.value(row));
        if(itemToOrder->text().toInt()>0 && p.getIngredients().empty())
        {
            CompositionOrder composition;

            composition.setIdProduct(p.getId());
            composition.setQuantity(itemToOrder->text().toInt());
            compositions.push_back(composition);
        }
    }
    invoice.setCompositions(compositions);
    invoice.setPrice(getTotalPriceNoTVA());
    return invoice.toVariant();
}

void ProductStockOrder::fillTable()
{
    QModelIndex index;
    for(int i=0;i<productModel->rowCount();++i)
    {
        index=productModel->index(i,0);
        Product p(productModel->data(index,AbstractListModel::VariantRole));
        if(p.getIngredients().empty())
            appendToPanel(p.toVariant());
    }
}

void ProductStockOrder::updateLine(int row)
{
    QTableWidgetItem *total=item(row,Column::Total);
    total->setText(QString::number(getTotalPriceForRow(row)));
    emit dataChange();
}

void ProductStockOrder::initColumns()
{
    QTableWidgetItem *name=new QTableWidgetItem("Products");
    QTableWidgetItem *stock=new QTableWidgetItem("Stock");
    QTableWidgetItem *toOrder=new QTableWidgetItem("toOrder");
    QTableWidgetItem *price=new QTableWidgetItem("Price $");
    QTableWidgetItem *total=new QTableWidgetItem("Total $");
    setColumnCount(columnCount);
    setItemEditable(name,false);
    setItemEditable(stock,false);
    setItemEditable(toOrder,true);
    setItemEditable(price,false);
    setItemEditable(total,false);

    setHorizontalHeaderItem(Column::Name,name);
    setHorizontalHeaderItem(Column::Stock,stock);
    setHorizontalHeaderItem(Column::ToOrder,toOrder);
    setHorizontalHeaderItem(Column::Price,price);
    setHorizontalHeaderItem(Column::Total,total);
}
void ProductStockOrder::createRow(int row)
{
    Product p;
    p.fromVariant(objects.value(row));
    QTableWidgetItem *name=new QTableWidgetItem(p.getName());
    QTableWidgetItem *stock=new QTableWidgetItem(QString::number(p.getStock()));
    QTableWidgetItem *toOrder=new QTableWidgetItem("0");
    QTableWidgetItem *price=new QTableWidgetItem(QString::number(p.getPrice()));
    QTableWidgetItem *total=new QTableWidgetItem("0");

    setItem(row,Column::Name,name);
    setItem(row,Column::Stock,stock);
    setItem(row,Column::ToOrder,toOrder);
    setItem(row,Column::Price,price);
    setItem(row,Column::Total,total);

    setItemEditable(name,false);
    setItemEditable(stock,false);
    setItemEditable(price,false);
    setItemEditable(total,false);
}

void ProductStockOrder::incrementQuantity(int row)
{
    Q_UNUSED(row);
}

float ProductStockOrder::getTotalPriceForRow(int row)
{
    float priceUnity=0;
    int quantity=0;
    QTableWidgetItem *toOrder=item(row,Column::ToOrder);
    QTableWidgetItem *price=item(row,Column::Price);
    priceUnity=price->text().toFloat();
    quantity=toOrder->text().toInt();
    return priceUnity*quantity;
}

float ProductStockOrder::getTotalPriceNoTVA()
{
    float total=0;
    for(int row=0;row<rowCount;++row)
        total+=getTotalPriceForRow(row);
    return total-(total*0.25f);
}

void ProductStockOrder::setProductModel(ProductModel *value)
{
    productModel = value;
    connect(productModel,&QAbstractItemModel::dataChanged,[this](){
        removeAllRow();
        fillTable();
    });
    fillTable();
}

float ProductStockOrder::sumTotalPrice()
{
    float sumTotal=0;
    QTableWidgetItem *total=nullptr;
    for(int row=0;row<rowCount;++row)
    {
        total=item(row,Column::Total);
        sumTotal+=total->text().toFloat();
    }
    return sumTotal;
}

void ProductStockOrder::resetTable()
{
    QTableWidgetItem *total=nullptr;
    QTableWidgetItem *toOrder=nullptr;
    for(int row=0;row<rowCount;++row)
    {
        total=item(row,Column::Total);
        toOrder=item(row,Column::ToOrder);
        total->setText("0");
        toOrder->setText("0");
    }
}
