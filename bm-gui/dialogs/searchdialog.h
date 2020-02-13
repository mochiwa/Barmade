#ifndef SEARCHDIALOG_H
#define SEARCHDIALOG_H

#include <QDialog>
#include <QItemSelectionModel>
#include <QSortFilterProxyModel>
#include "models/abstractlistmodel.h"
namespace Ui {
class SearchDialog;
}

class SearchDialog : public QDialog
{
    Q_OBJECT

public:
    SearchDialog(AbstractListModel *model,QWidget *parent = nullptr);
    ~SearchDialog();

    void setModel(QAbstractItemModel *value);
    QItemSelectionModel *getSelectionModel();
    QVariant getVariant();

private:
    void initProxyModel(QAbstractItemModel *model);
    void setCurrentSelectionToFirst();
    void enableValidateButton();

public slots:
    void on_valid();
    void on_cancel();
    void on_search(const QString&);
    //void on_buttonEnabled();
private:
    Ui::SearchDialog *ui;

    QSortFilterProxyModel *proxyModel;
};

#endif // SEARCHDIALOG_H
