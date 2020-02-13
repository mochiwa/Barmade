#ifndef ENTITYWIDGET_H
#define ENTITYWIDGET_H

#include "bm-lib_global.h"
#include <QWidget>
#include <QItemSelectionModel>
#include <QLineEdit>
#include <QStyle>
#include "models/abstractlistmodel.h"

namespace Ui {
class EntityWidget;
}

class BMLIBSHARED_EXPORT EntityWidget : public QWidget
{
    Q_OBJECT
public:
    explicit EntityWidget(QWidget *parent = nullptr);
    virtual ~EntityWidget();

    void setModel(AbstractListModel *model);
    virtual void setSelectionModel(QItemSelectionModel *selection);
public slots:
    void on_load();
    void on_save();
    void on_edit();
    void on_cancel();

protected slots:
    /**
     * @brief Check if all input field are valid before enable valid button
     */
    virtual void check_lineEdit_fields();

signals:
    void entity_presentation();
    void entity_editingFinsih();

protected:
    virtual void init();
    virtual void updatStyleSheet();

    enum class Property{on_edit};
    void setProperty(Property property,bool value);
    bool isPropertyActived(Property property);
    /**
     * @brief Append All line can be edited in QList
     */
    virtual void initLineEditable()=0;
    /**
     * @brief fill widget with the model selected
     */
    virtual void fillWidget()=0;
    /**
     * @brief fill the entity from the widget input
     */
    virtual void fillEntity(QVariant& variant)=0;
    virtual void setReadableOnly(bool value);
    virtual void showValidationButtons(bool value);

protected:
    Ui::EntityWidget *ui;
    QString cssFilename;
    QList<QLineEdit*> lineEdits;

    AbstractListModel *model;
    QItemSelectionModel *selection;

};

#endif // ENTITYWIDGET_H
