#ifndef EMPLOYEE_WIDGET_H
#define EMPLOYEE_WIDGET_H

#include "components/entitywidget.h"


namespace Ui {
class EmployeeWidget;
}

class BMLIBSHARED_EXPORT EmployeeWidget : public EntityWidget
{
    Q_OBJECT

public:
    explicit EmployeeWidget(QWidget *parent = nullptr);
    ~EmployeeWidget();


protected:
    virtual void initLineEditable();
    virtual void fillWidget();
    virtual void fillEntity(QVariant &variant);

private:
    void setReadableOnly(bool value);
    void initPicture();

private:
    Ui::EmployeeWidget *employeeUi;
};


#endif // EMPLOYEE_WIDGET_H
