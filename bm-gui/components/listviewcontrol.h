#ifndef LISTCONTROL_H
#define LISTCONTROL_H

#include "bm-lib_global.h"
#include <QWidget>
#include <QMessageBox>
#include <QItemSelectionModel>
#include "models/abstractlistmodel.h"

namespace Ui {
class ListViewControl;
}

class BMLIBSHARED_EXPORT ListViewControl : public QWidget
{
    Q_OBJECT

public:
    explicit ListViewControl(QWidget *parent = nullptr);
    ~ListViewControl();

    void setModel(AbstractListModel *model);
    void setSelectionModel(QItemSelectionModel *selection);
    /**
     * @brief enable or disable buttons
     * @param value
     * @note it is used whit a not manager
     */
    void setEditable(const bool value);
    void selectFirstElement();
    void initStyleSheet();
protected:
    void init();
    /**
     * @brief show confirmationbox
     * @note it's used before deleting an entity
     */
    bool confirmSuppresionBox();
private slots:
    void on_create();
    void on_delete();
signals:
    void on_edit();

private:
    Ui::ListViewControl *ui;
    AbstractListModel *model;
    QItemSelectionModel *selection;
};

#endif // LISTCONTROL_H
