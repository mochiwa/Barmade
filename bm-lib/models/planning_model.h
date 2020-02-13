#ifndef PLANNING_MODEL_H
#define PLANNING_MODEL_H


#include "abstracttablemodel.h"
#include "entities/planning.h"

class  PlanningModel: public AbstractTableModel
{
    Q_OBJECT
public:
    PlanningModel(QObject *parent=nullptr);

    void setEmployeeId(int value);


    virtual QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    virtual QVariant data(const QModelIndex &index, int role=Qt::DisplayRole) const override;
    virtual bool setData(const QModelIndex& index, const QVariant& value, int role) override;

protected:
    virtual void initEntities() override;
    virtual void makeEntity(const QModelIndex &index, const QVariant &variant) override;

    void loadPlanningForEmployee(int idEmployee);

private:
    int employeeId;
};



#endif // PLANNING_MODEL_H
