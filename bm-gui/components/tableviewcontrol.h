#ifndef TABLEVIEWCONTROL_H
#define TABLEVIEWCONTROL_H

#include "bm-lib_global.h"
#include <QWidget>
#include <QMessageBox>
#include <QItemSelectionModel>
#include "models/abstracttablemodel.h"

namespace Ui {
class TableViewControl;
}

class BMLIBSHARED_EXPORT TableViewControl : public QWidget
{
    Q_OBJECT
public:
    explicit TableViewControl(QWidget *parent = nullptr);
    virtual ~TableViewControl();

    void setModel(AbstractTableModel *model);
    void setSelection(QItemSelectionModel *selection);

    void setEditable(const bool value);


public slots:
    virtual void on_load(int id)=0;
    virtual void on_loadAll()=0;
    virtual void on_create();
    void on_remove();

protected:
    bool confirmSuppresionBox();
    virtual void init();
    void initStyleSheet();

protected:
    Ui::TableViewControl *ui;

    AbstractTableModel *model;
    QItemSelectionModel *selection;
};

#endif // TABLEVIEWCONTROL_H
