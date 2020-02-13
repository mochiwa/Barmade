#include "dayselector_dialog.h"
#include "ui_dayselector.h"

DaySelector::DaySelector(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DaySelector)
{
    ui->setupUi(this);
    connect(ui->calendarWidget,&QCalendarWidget::clicked,this,&DaySelector::on_cliked);
}

DaySelector::~DaySelector()
{
    delete ui;
}

 QDate const DaySelector::getDate() const
{
    return date;
}

void DaySelector::on_cliked(const QDate &date)
{
    this->date=date;
    done( QDialog::Accepted);
}
