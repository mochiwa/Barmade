#ifndef PRODUCTFORM_WIDGET_H
#define PRODUCTFORM_WIDGET_H

#include "components/entitywidget.h"
#include "dialogs/searchdialog.h"
#include "ingredienttable.h"
#include "business/productbusiness.h"
#include "components/lineeditcalculable.h"

namespace Ui {
class ProductFormWidget;
}

class ProductFormWidget : public EntityWidget
{
    Q_OBJECT

public:
    explicit ProductFormWidget(QWidget *parent = nullptr);
    ~ProductFormWidget();

    void setSelectionModel(QItemSelectionModel *selection);
private:
    void initIngredientTable();
    void initCalculableLine();

public slots:
    void on_createComposition();
    void on_removeComposition();
    void on_updateStock();

protected:
    virtual void initLineEditable();
    virtual void fillWidget();
    virtual void fillEntity(QVariant &variant);
    virtual void setReadableOnly(bool value);

private:
    Ui::ProductFormWidget *productForm;
    IngredientTable *ingredientTable;
    LineEditCalculable *lineCalculable;
};



#endif // PRODUCTFORM_WIDGET_H
