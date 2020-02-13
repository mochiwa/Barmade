#include "tablewidgetspinbox_delegate.h"

TableWidgetSpinBoxDelegate::TableWidgetSpinBoxDelegate(int column,QObject *parent):
    QStyledItemDelegate(parent)
{
    this->column=column;
}



QWidget *TableWidgetSpinBoxDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if(index.column()!=column)
        return QStyledItemDelegate::createEditor(parent,option,index);
    QSpinBox *box=new QSpinBox(parent);
    box->setFrame(false);
    box->setMinimum(0);
    box->setMaximum(1000);
    return box;
}

void TableWidgetSpinBoxDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    if(index.column()!=column)
        return QStyledItemDelegate::setEditorData(editor,index);
    int value=index.model()->data(index,Qt::EditRole).toInt();
    QSpinBox *box = qobject_cast<QSpinBox *>(editor);
    box->setValue(value);
}

void TableWidgetSpinBoxDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    if(index.column()!=column)
        return QStyledItemDelegate::setModelData(editor,model,index);
    QSpinBox *box = qobject_cast<QSpinBox *>(editor);
    box->interpretText();
    int value=box->value();

    model->setData(index,value,Qt::EditRole);
    emit cellUpdate(index.row());
}
