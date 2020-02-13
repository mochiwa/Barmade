#include "information_panel.h"
#include "ui_information_panel.h"

InformationPanel::InformationPanel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InformationPanel)
{
    ui->setupUi(this);
    connect(ui->button_logout,SIGNAL(clicked()),this,SIGNAL(logout()));
    initTimer();
    initStyleSheet();
}

InformationPanel::~InformationPanel()
{
    delete ui;
}

void InformationPanel::setEmployee(const Employee &e)
{
    ui->label_name->setText("Name: "+e.getName());
    ui->label_forename->setText("Forename: "+e.getForename());
}

void InformationPanel::initTimer()
{
    QTimer *timer=new QTimer(this);
    timer->setInterval(1000);
    connect(timer,SIGNAL(timeout()),this,SLOT(showTime()));
    timer->start();
}

void InformationPanel::initStyleSheet()
{
    QFile f(":/css/information_panel.css");
    f.open(QFile::ReadOnly);
    this->setStyleSheet(QLatin1String(f.readAll()));
    f.close();
}

void InformationPanel::showTime()
{
    ui->label_date->setText(QDateTime::currentDateTime().toString("dddd dd MMMM yyyy h:mm:ss"));
}
