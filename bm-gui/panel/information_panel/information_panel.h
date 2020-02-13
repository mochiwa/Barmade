#ifndef INFORMATION_PANEL_H
#define INFORMATION_PANEL_H

#include <QWidget>
#include <QTimer>

#include <entities/employee.h>

namespace Ui {
class InformationPanel;
}

class InformationPanel : public QWidget
{
    Q_OBJECT

public:
    explicit InformationPanel(QWidget *parent = nullptr);
    ~InformationPanel();

    void setEmployee(const Employee& e);
    void initTimer();
    void initStyleSheet();
private slots:
    void showTime();
signals:
    void logout();

private:
    Ui::InformationPanel *ui;
};

#endif // INFORMATION_PANEL_H
