#ifndef PLANNING_DELEGATE_H
#define PLANNING_DELEGATE_H

#include <QStyledItemDelegate>
#include <QPainter>
#include <QDateTimeEdit>
#include <QLabel>
#include <QComboBox>
#include <QLineEdit>

#include "models/planning_model.h"

class PlanningDelegate:public QStyledItemDelegate
{
    Q_OBJECT
public:
    PlanningDelegate(QObject *parent=nullptr);

public:
    virtual void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    virtual QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    virtual void setEditorData(QWidget *editor, const QModelIndex &index) const;
    virtual void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
    virtual void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;
};







#endif // PLANNING_DELEGATE_H
