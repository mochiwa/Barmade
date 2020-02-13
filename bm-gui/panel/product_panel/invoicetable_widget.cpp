#include "invoicetable_widget.h"

InvoiceTable::InvoiceTable(QWidget *parent):
    AbstractTableWidget(parent)
{
    initColumns();
    connect(this,SIGNAL(cellChanged(int,int)),this,SLOT(on_updateData(int,int)));
    TableWidgetSpinBoxDelegate *delegate=new TableWidgetSpinBoxDelegate(Column::Quantity,this);
    setItemDelegate(delegate);
    connect(delegate,&TableWidgetSpinBoxDelegate::cellUpdate,this,&AbstractTableWidget::updateLine);
}

InvoiceTable::~InvoiceTable(){}

//------------- SLOTS -------------//
void InvoiceTable::updateLine(int row)
{
    if(item(row,0)==nullptr)
        return;
    float totalPrice;
    int qty;
    float priceUnite;
    QTableWidgetItem *quantity=item(row,Column::Quantity);
    QTableWidgetItem *price=item(row,Column::Price);
    QTableWidgetItem *total=item(row,Column::Total);
    qty=quantity->text().toInt();
    priceUnite=price->text().toFloat();
    totalPrice=priceUnite*qty;

    total->setText(QString::number(static_cast<double>(totalPrice)));
    emit dataChange();
}

void InvoiceTable::on_updateData(int row, int column)
{
    if(column!=Column::Quantity)
        return;
    if(getQuantity(row)<=0)
        on_remove(row);
}
//------------- PRIVATE -------------//
void InvoiceTable::initColumns()
{
    setColumnCount(columnCount);
    QTableWidgetItem *name=new QTableWidgetItem("Name");
    QTableWidgetItem *quantity=new QTableWidgetItem("Quantity");
    QTableWidgetItem *price=new QTableWidgetItem("Price");
    QTableWidgetItem *total=new QTableWidgetItem("Total");

    setHorizontalHeaderItem(Column::Name,name);
    setHorizontalHeaderItem(Column::Quantity,quantity);
    setHorizontalHeaderItem(Column::Price,price);
    setHorizontalHeaderItem(Column::Total,total);
}
void InvoiceTable::createRow(int row)
{
    Product p;
    p.fromVariant(objects.value(row));

    QTableWidgetItem *name=new QTableWidgetItem(p.getName());
    setItemEditable(name,false);
    QTableWidgetItem *quantity=new QTableWidgetItem("1");
    setItemEditable(quantity,true);
    QTableWidgetItem *price=new QTableWidgetItem(QString::number(p.getPrice().getValue()));
    setItemEditable(price,false);
    QTableWidgetItem *total=new QTableWidgetItem(QString::number(p.getPrice().getValue()));
    setItemEditable(total,false);

    setItem(row,Column::Name,name);
    setItem(row,Column::Quantity,quantity);
    setItem(row,Column::Price,price);
    setItem(row,Column::Total,total);
}
void InvoiceTable::incrementQuantity(int row)
{
    QTableWidgetItem *itemQuantity=item(row,Column::Quantity);
    itemQuantity->setText(QString::number(getQuantity(row)+1));
    emit updateLine(row);
}

int InvoiceTable::getQuantity(int row)
{
    return item(row,Column::Quantity)->text().toInt();
}
//------------- PUBLIC -------------//

//-------- Getter & Setter ---------//
QVariant InvoiceTable::build()
{
    Invoice order;
    std::vector<CompositionOrder> compositions;
    Product p;

    for(int i=0;i<rowCount;++i)
    {
        CompositionOrder c;
        p.fromVariant(objects.value(i));
        c.setQuantity(getQuantity(i));
        c.setIdProduct(p.getId());
        compositions.push_back(c);
    }
    order.setCompositions(compositions);
    order.setPrice(sumTotalPrice());
    return order.toVariant();
}

float InvoiceTable::sumTotalPrice()
{
    float totalPrice=0;
    for(int i=0;i<getRowCount();++i)
        totalPrice+=item(i,Column::Total)->text().toFloat();
    return totalPrice;
}
