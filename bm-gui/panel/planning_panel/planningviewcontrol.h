#ifndef PLANNINGVIEWCONTROL_H
#define PLANNINGVIEWCONTROL_H
#include "components/tableviewcontrol.h"
#include "models/planning_model.h"
#include "dialogs/dayselector_dialog.h"
#include "planning_delegate.h"

namespace Ui {
class PlanningViewControl;
}

class PlanningViewControl : public TableViewControl
{
    Q_OBJECT

public:
    explicit PlanningViewControl(QWidget *parent = nullptr);

public slots:
    void on_load(int id)override;
    void on_loadAll()override;
    void on_create()override;
    void on_calendarPopup(const QModelIndex &index);

protected:
    void init() override;
private:
    Ui::PlanningViewControl *planningUi;
};



#endif // PLANNINGVIEWCONTROL_H
