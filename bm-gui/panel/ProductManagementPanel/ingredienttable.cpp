#include "ingredienttable.h"

IngredientTable::IngredientTable(QWidget *parent):
    AbstractTableWidget(parent)
{
    initColumns();
    setItemDelegate(new TableWidgetSpinBoxDelegate(Column::Quantity,this));
}

IngredientTable::~IngredientTable(){}

void IngredientTable::appendIngredient(const QVariant &variant, int qty)
{
    appendToPanel(variant);
    item(rowCount-1,Column::Quantity)->setText(QString::number(qty));
}
QVariant IngredientTable::build()
{
    QVariantList variant;
    Product p;
    QTableWidgetItem *itemQuantity=nullptr;

    for(int i=0;i<rowCount;++i)
    {
        Ingredient ingredient;
        itemQuantity=item(i,Column::Quantity);
        p.fromVariant(objects.value(i));

        ingredient.setIngredient(p.getId());
        ingredient.setQuantity(itemQuantity->text().toFloat());
        variant.push_back(ingredient.toVariant());
    }
    return variant;
}

void IngredientTable::updateLine(int row)
{
    Q_UNUSED(row);
}

void IngredientTable::remove()
{   
    on_remove(currentRow());
}

void IngredientTable::initColumns()
{
    setColumnCount(columnCount);
    QTableWidgetItem *name=new QTableWidgetItem("Products");
    setItemEditable(name,false);
    QTableWidgetItem *quantity=new QTableWidgetItem("Quantity(cl)");
    setItemEditable(quantity,true);
    setHorizontalHeaderItem(Column::Name,name);
    setHorizontalHeaderItem(Column::Quantity,quantity);
}

void IngredientTable::createRow(int row)
{
    Product p;
    p.fromVariant(objects.value(row));
    QTableWidgetItem *name=new QTableWidgetItem(p.getName());
    setItemEditable(name,false);
    QTableWidgetItem *quantity=new QTableWidgetItem("1");

    setItemEditable(quantity,true);
    setItem(row,Column::Name,name);
    setItem(row,Column::Quantity,quantity);
}


void IngredientTable::incrementQuantity(int row)
{
    Q_UNUSED(row);
}
