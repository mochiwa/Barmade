#ifndef EMPLOYEE_PANEL_H
#define EMPLOYEE_PANEL_H

#include "bm-lib_global.h"
#include <QWidget>
#include <QVBoxLayout>

#include "models/employee_model.h"
#include "models/planning_model.h"
#include "models/invoice_model.h"

#include "components/listviewcontrol.h"
#include "panel/planning_panel/planningviewcontrol.h"
#include "employee_widget.h"
#include "panel/invoice_panel/invoice_panel.h"


namespace Ui {
class employeePanel;
}

class BMLIBSHARED_EXPORT EmployeePanel : public QWidget
{
    Q_OBJECT

public:
    explicit EmployeePanel(QWidget *parent = nullptr);
    ~EmployeePanel();

    void setEmployeeModel(EmployeeModel *model);
    void setEmployeeSelectionModel(QItemSelectionModel* selected);

    void setPlanningModel(PlanningModel *model);
    void setPlanningSelectionModel(QItemSelectionModel* selected);

    void activeManagementPanel(bool value);

    void setInvoiceModel(InvoiceModel *value);
    void setInvoiceSelected(QItemSelectionModel *value);


private:
    void init();
    void initLayout();
    void initEmployeeList();
    void initEmployeeWidget();
    void initInvoicePanel();
    void initPlanningList();


private:
    Ui::employeePanel *ui;
    InvoicePanel *invoicePanel;

    EmployeeModel *employeModel;
    QItemSelectionModel *employeeSelected;

    PlanningModel *planningModel;
    QItemSelectionModel*planningSelected;

    InvoiceModel *invoiceModel;



    ListViewControl *listControlEmployee;
    EmployeeWidget *employeeWidget;
    PlanningViewControl *planningViewControl;

};

#endif // EMPLOYEE_PANEL_H
