#include "abstracttablewidget.h"
#include <QHeaderView>
AbstractTableWidget::AbstractTableWidget(QWidget *parent):
    QTableWidget (parent)
{
    initStyleSheet();
    verticalHeader()->setVisible(false);
    rowCount=0;
    horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    connect(this,SIGNAL(rowUpdate(int)),this,SLOT(updateLine(int)));
}

AbstractTableWidget::~AbstractTableWidget()
{
}


//------------- SLOTS -------------//
void AbstractTableWidget::on_remove(int row)
{
    objects.remove(row);
    removeRow(row);
    setRowCount(--rowCount);
    updateKey(row);
    emit dataChange();
}

//------------- PROTECTED -------------//
void AbstractTableWidget::setItemEditable(QTableWidgetItem *item, bool value)
{
    if(!value)
        item->setFlags(Qt::ItemIsEditable);
}

void AbstractTableWidget::appendToPanel(const QVariant &variant)
{
    setRowCount(++rowCount);
    objects.insert(rowCount-1,variant);
    createRow(rowCount-1);
    emit rowUpdate(rowCount-1);
}

void AbstractTableWidget::updateKey(int begin)
{
    QMap<int,QVariant> tmp;
    int row;
    QMap<int,QVariant>::iterator it;
    for(it=objects.begin(); it != objects.end();++it)
    {
        row = it.key();
        if(row>begin)
            row--;
        tmp.insert(row,it.value());
    }
    objects.swap(tmp);
}
void AbstractTableWidget::setRowCount(int value)
{
    rowCount = value;
    QTableWidget::setRowCount(rowCount);
}

void AbstractTableWidget::removeAllRow()
{
    setRowCount(0);
}

void AbstractTableWidget::initStyleSheet()
{
    QFile f(":/css/table_view.css");
    f.open(QFile::ReadOnly);
    this->setStyleSheet(QLatin1String(f.readAll()));
    f.close();
}

//------------- PUBLIC -------------//
#include <QDebug>
void AbstractTableWidget::AppendObject(const QVariant &variant)
{
    int row=objects.key(variant);
    if(objects.value(row)!=variant)
        appendToPanel(variant);
    else
        incrementQuantity(row);
}
void AbstractTableWidget::clear()
{
    objects.clear();
    this->clearContents();
    setRowCount(0);
    emit dataChange();
}

//-------- Getter & Setter ---------//
int AbstractTableWidget::getRowCount() const
{
    return rowCount;
}



