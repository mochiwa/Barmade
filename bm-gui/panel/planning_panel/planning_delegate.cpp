#include "planning_delegate.h"

PlanningDelegate::PlanningDelegate(QObject *parent):
    QStyledItemDelegate (parent)
{

}

void PlanningDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Planning p;
    QString value;
    QTextOption textOption;
    p.fromVariant(index.model()->data(index,PlanningModel::Roles::VariantRole));

    painter->save();

    switch (index.column())
    {
        case 0:
            textOption.setAlignment(Qt::AlignLeft| Qt::AlignVCenter);
            painter->drawText(option.rect,p.getBegin().toString("dddd dd/M/yyyy"),textOption);
            break;
        case 1:
            textOption.setAlignment(Qt::AlignCenter| Qt::AlignVCenter);
            if(p.getIsDayOff())
                value="True";
            else
                value="False";

            painter->drawText(option.rect,value,textOption);

            break;
        case 2:
            textOption.setAlignment(Qt::AlignCenter| Qt::AlignVCenter);
            painter->drawText(option.rect,p.getBegin().toString("HH:mm"),textOption);
            break;
        case 3:
            textOption.setAlignment(Qt::AlignCenter| Qt::AlignVCenter);
            painter->drawText(option.rect,p.getEnd().toString("HH:mm"),textOption);
            break;
        default:
            QStyledItemDelegate::paint(painter,option,index);
            break;
    }
    painter->restore();
}

QWidget *PlanningDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    int column=index.column();
    QDateTimeEdit *edit=nullptr;
    QComboBox *box =nullptr;
    QLineEdit *lineEdit=nullptr;

    Planning p;
    p.fromVariant(index.model()->data(index,PlanningModel::Roles::VariantRole));
    if(column==0)
    {
        return nullptr;
    }
    else if(column==1)
    {
        box=new QComboBox(parent);
        box->addItem("True");
        box->addItem("False");
        return box;
    }
    else if(column==2 || column==3)
    {
        edit=new QDateTimeEdit(parent);
        edit->setDisplayFormat("HH:mm");
        return edit;
    }
    else if(column==4)
    {
        lineEdit=new QLineEdit(parent);
        lineEdit->setText(p.getComment());
        return lineEdit;
    }
    else
        return QStyledItemDelegate::createEditor(parent,option,index);
}

void PlanningDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    Planning p;
    QDateTimeEdit *dateEdit=nullptr;
    QComboBox *box=nullptr;
    QLineEdit *lineEdit=nullptr;
    int column=index.column();

    p.fromVariant(index.model()->data(index,PlanningModel::Roles::VariantRole));
    if(column==1)
    {
        box=static_cast<QComboBox *>(editor);
        if(p.getIsDayOff())
            box->setCurrentIndex(0);//true
        else
            box->setCurrentIndex(1);//false
    }
    else if(column==2 || column==3)
    {
        dateEdit=static_cast<QDateTimeEdit*>(editor);
        if(column==2)
            dateEdit->setDateTime(p.getBegin());
        else
            dateEdit->setDateTime(p.getEnd());
    }
    else if(column==4)
    {
        lineEdit=static_cast<QLineEdit*>(editor);
        lineEdit->setText(p.getComment());
    }
    else
        QStyledItemDelegate::setEditorData(editor,index);
}

void PlanningDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    Planning p;
    QDateTimeEdit *dateEdit=nullptr;
    QComboBox *box=nullptr;
    QDateTime selectedDate;
    int column=index.column();

    p.fromVariant(index.model()->data(index,PlanningModel::Roles::VariantRole));
    if(column==1)
    {
        box=static_cast<QComboBox*>(editor);
        if(box->currentIndex()==0)
            p.setIsDayOff(true);
        else
            p.setIsDayOff(false);
        model->setData(index,p.toVariant(),PlanningModel::Roles::VariantRole);
    }
    else if (column==2 || column==3)
    {
        dateEdit=static_cast<QDateTimeEdit*>(editor);
        if(column==2)
        {
            if(dateEdit->dateTime()<p.getEnd())
                p.setBegin(selectedDate);
        }
        else
        {
            if(dateEdit->dateTime()>p.getBegin())
                p.setEnd(selectedDate);
        }
        model->setData(index,p.toVariant(),PlanningModel::Roles::VariantRole);
    }
    QStyledItemDelegate::setModelData(editor,model,index);
}

void PlanningDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(index);
    editor->setGeometry(option.rect);
}


