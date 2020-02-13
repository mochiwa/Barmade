#ifndef PLANNINGCASE_WIDGET_H
#define PLANNINGCASE_WIDGET_H

#include <QWidget>

namespace Ui {
class PlanningCaseWidget;
}

class PlanningCaseWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PlanningCaseWidget(QWidget *parent = nullptr);
    ~PlanningCaseWidget();

    virtual QSize sizeHint() const;

    QDateTime begin();
    QDateTime end();
    QString comment();

    void setBegin(const QDateTime& begin);
    void setEnd(const QDateTime& end);
    void setcomment(const QString &comment);


private:
    Ui::PlanningCaseWidget *ui;


    // QWidget interface
public:

};




#endif // PLANNINGCASE_WIDGET_H
