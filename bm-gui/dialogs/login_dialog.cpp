#include "login_dialog.h"
#include "ui_login_dialog.h"
LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    init();
    connect(ui->button_login,SIGNAL(clicked()),this,SLOT(button_login()));
    connect(ui->lineEdit_id,&QLineEdit::cursorPositionChanged,[this](){showErrorMessage(false);});

    connect(&loginBusiness,SIGNAL(login_notFound()),this,SLOT(on_error()));
    connect(&loginBusiness,SIGNAL(login_found(const Employee&)),this,SLOT(on_loginSucess(const Employee&)));
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

//------------- SLOTS -------------//
void LoginDialog::button_login()
{
    loginBusiness.process(ui->lineEdit_id->text());
}

void LoginDialog::on_error()
{
    ui->lineEdit_id->setText("");
    ui->lineEdit_id->setFocus();
    showErrorMessage(true);
}

void LoginDialog::on_loginSucess(const Employee &e)
{
    employee=e;
    done(QDialog::Accepted);
}

//------------- PRIVATE -------------//
void LoginDialog::init()
{
    setWindowTitle(" ");
    initStyleSheet();
    initLogo();
    showErrorMessage(false);
}
void LoginDialog::initStyleSheet()
{
    QFile f(":/css/login_dialog.css");
    f.open(QFile::ReadOnly);
    this->setStyleSheet(QLatin1String(f.readAll()));
    f.close();
}
void LoginDialog::initLogo()
{
    QPixmap img(":/images/logo_flat.png");
    ui->label_title->setPixmap(img.scaled(100,150,Qt::KeepAspectRatio));
}

void LoginDialog::showErrorMessage(const bool value)
{
    ui->label_error->setVisible(value);
}

Employee LoginDialog::getEmployee() const
{
    return employee;
}


//------------- PUBLIC -------------//

//-------- Getter & Setter ---------//


