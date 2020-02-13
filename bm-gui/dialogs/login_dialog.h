#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QGraphicsBlurEffect>
#include "business/login_business.h"

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();

    QString getInput() const;

    Employee getEmployee() const;
public slots:
    void button_login();
    void on_error();
    void on_loginSucess(const Employee&);

private:
    void init();
    void initStyleSheet();
    void initLogo();
    void showErrorMessage(bool value);
private:
    Ui::LoginDialog *ui;
    Employee employee;
    LoginBusiness loginBusiness;
};

#endif // LOGINDIALOG_H
