#ifndef LOGIN_PANEL_H
#define LOGIN_PANEL_H

#include <QWidget>
#include "business/authenticator.h"
#include "entities/employee.h"

namespace Ui {
class LoginPanel;
}

class LoginPanel : public QWidget
{
    Q_OBJECT
public:
    explicit LoginPanel(Employee* user,QWidget *parent = nullptr);
    ~LoginPanel();

public slots:
    void on_button_login_clicked(); // launch th auth
    void user_connected(Employee user); // assigne user
    void error_detected(); //change the color

signals:
    void user_connected();

private:
    Ui::LoginPanel *ui;

    Authenticator auth;
    Employee *user;


};

#endif // LOGIN_PANEL_H
