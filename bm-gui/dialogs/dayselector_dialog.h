#ifndef DAYSELECTOR_H
#define DAYSELECTOR_H

#include <QDialog>
#include <QDate>

namespace Ui {
class DaySelector;
}

class DaySelector : public QDialog
{
    Q_OBJECT

public:
    explicit DaySelector(QWidget *parent = nullptr);
    ~DaySelector();

    QDate const getDate()const;
public slots:
    void on_cliked(const QDate & date);

private:
    Ui::DaySelector *ui;

    QDate date;
};

#endif // DAYSELECTOR_H
