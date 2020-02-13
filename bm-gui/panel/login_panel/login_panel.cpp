#include "login_panel.h"
#include "ui_login_panel.h"

LoginPanel::LoginPanel(Employee* user,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginPanel)
{
    ui->setupUi(this);
    this->user=user;
    connect(ui->button_login,SIGNAL(clicked()),this,SLOT(on_button_login_clicked()));
    connect(&auth,SIGNAL(error_detected()),this,SLOT(error_detected()));
    connect(&auth,SIGNAL(user_connected(Employee)),this,SLOT(user_connected(Employee)));
}

LoginPanel::~LoginPanel()
{
    delete ui;
}


//------------- SLOTS -------------//

void LoginPanel::on_button_login_clicked()
{
    auth.login(ui->lineEdit_id->text());
}

void LoginPanel::user_connected(Employee user)
{
    *this->user=user;
    emit user_connected();
}

void LoginPanel::error_detected()
{
    ui->label_id->setStyleSheet("color: red");
}

//------------- PRIVATE -------------//

//------------- PUBLIC -------------//

//-------- Getter & Setter ---------//

