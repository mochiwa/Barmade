#ifndef SUPPLIER_WIDGET_H
#define SUPPLIER_WIDGET_H

#include <QRegularExpressionValidator>
#include "components/entitywidget.h"
#include "employee_panel/employee_inputchecker.h"

namespace Ui {
class SupplierWidget;
}

class  SupplierWidget : public EntityWidget
{
    Q_OBJECT
public:
    explicit SupplierWidget(QWidget *parent = nullptr);
    ~SupplierWidget();

protected:
    virtual void initLineEditable();
    virtual void fillWidget();
    virtual void fillEntity(QVariant &variant);

private:
    void initLineEdits();
private:
    Ui::SupplierWidget *supplierUi;
};






#endif // SUPPLIER_WIDGET_H
