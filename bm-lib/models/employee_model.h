#ifndef EMPLOYEE_MODEL_H
#define EMPLOYEE_MODEL_H


#include "abstractlistmodel.h"
#include "entities/employee.h"
#include "builder/employeebuilder.h"


class  EmployeeModel: public AbstractListModel
{
    Q_OBJECT
public:
    EmployeeModel(QObject *parent=nullptr);

    // QAbstractItemModel interface
public:
    QVariant data(const QModelIndex &index, int role) const override;
    bool setData(const QModelIndex& index, const QVariant& value, int role) override;

    Employee getEmployeeById(int id);
    // AbstractListModel interface
protected:
    virtual void initEntities() override;
    virtual void makeEntity(const QModelIndex &index, const QVariant &variant) override;
};
#endif // EMPLOYEE_MODEL_H
