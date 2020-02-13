#ifndef ABSTRACTTABLEWIDGET_H
#define ABSTRACTTABLEWIDGET_H

#include "bm-lib_global.h"
#include <QTableWidget>
#include <QLineEdit>
#include <QMap>
#include <iterator>
#include <QFile>

class BMLIBSHARED_EXPORT AbstractTableWidget : public QTableWidget
{
    Q_OBJECT
public:
    AbstractTableWidget(QWidget *parent =nullptr);
    virtual ~AbstractTableWidget();

    virtual QVariant build()=0;
    virtual void AppendObject(const QVariant&);
    virtual void clear();
    virtual void setItemEditable(QTableWidgetItem *item,bool value);

    int getRowCount() const;
public slots:
    virtual void updateLine(int row)=0;
    void on_remove(int);


signals:
    void rowUpdate(int row);
    void dataChange();

protected:
    virtual void initColumns()=0;
    virtual void createRow(int row)=0;
    virtual void incrementQuantity(int row)=0;

    void appendToPanel(const QVariant&);
    void updateKey(int begin);
    void setRowCount(int value);
    void removeAllRow();
    void initStyleSheet();
protected:
    int rowCount;
    QMap<int,QVariant> objects;
};

#endif // ABSTRACTTABLEWIDGET_H
