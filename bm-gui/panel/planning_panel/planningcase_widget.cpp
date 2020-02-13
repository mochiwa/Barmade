#include "planningcase_widget.h"
#include "ui_planningcase_widget.h"

PlanningCaseWidget::PlanningCaseWidget(QWidget *parent):
    QWidget (parent),
    ui(new Ui::PlanningCaseWidget)
{
    ui->setupUi(this);
}

PlanningCaseWidget::~PlanningCaseWidget()
{

}

QSize PlanningCaseWidget::sizeHint() const
{
    return QSize(ui->frame->width()+20,ui->frame->height());
}

QDateTime PlanningCaseWidget::begin()
{

    return ui->timeEdit_begin->dateTime();
}

QDateTime PlanningCaseWidget::end()
{
    return ui->timeEdit_begin->dateTime();
}

QString PlanningCaseWidget::comment()
{
    return ui->textEdit_comment->toPlainText();
}

void PlanningCaseWidget::setBegin(const QDateTime& begin)
{
    ui->timeEdit_begin->setDateTime(begin);
}
void PlanningCaseWidget::setEnd(const QDateTime& end)
{
    ui->timeEdit_end->setDateTime(end);
}
void PlanningCaseWidget::setcomment(const QString &comment)
{
    ui->textEdit_comment->setPlainText(comment);
}
