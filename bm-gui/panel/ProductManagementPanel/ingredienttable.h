#ifndef INGREDIENTTABLE_H
#define INGREDIENTTABLE_H
#include "components/abstracttablewidget.h"
#include "components/tablewidgetspinbox_delegate.h"
#include "entities/product.h"
#include "valueObjects/ingredient.h"
#include <vector>

class IngredientTable : public AbstractTableWidget
{
    Q_OBJECT
public:
    enum Column {Name,Quantity};
    const int columnCount=2;

    IngredientTable(QWidget *parent =nullptr);
    ~IngredientTable();

    void appendIngredient(const QVariant& varient,int qty);

public:
    virtual QVariant build();

public slots:
    virtual void updateLine(int row);
    virtual void remove();

protected:
    virtual void initColumns();
    virtual void createRow(int row);
    virtual void incrementQuantity(int row);

};


#endif // INGREDIENTTABLE_H
