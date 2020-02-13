#ifndef TABLEWIDGETSPINBOX_DELEGATE_H
#define TABLEWIDGETSPINBOX_DELEGATE_H
#include "bm-lib_global.h"

#include <QStyledItemDelegate>
#include <QSpinBox>
class BMLIBSHARED_EXPORT TableWidgetSpinBoxDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    TableWidgetSpinBoxDelegate(QObject *parent=nullptr);
    TableWidgetSpinBoxDelegate(int column,QObject *parent=nullptr);
    virtual ~TableWidgetSpinBoxDelegate(){}

    virtual void setEditorData(QWidget *editor, const QModelIndex &index) const;
    virtual void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
    virtual QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;

signals:
    void cellUpdate(int row)const;
private:
    int column;
};

#endif // TABLEWIDGETSPINBOX_DELEGATE_H
