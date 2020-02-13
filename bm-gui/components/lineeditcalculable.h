#ifndef LINEEDITCALCULABLE_H
#define LINEEDITCALCULABLE_H

#include <QLineEdit>
#include <QRegularExpressionValidator>
#include <QLabel>
#include <QLayout>
class LineEditCalculable: public QLineEdit
{
    Q_OBJECT
public:
    LineEditCalculable(QWidget *parent=nullptr);
    QString text() const;

private slots:
    void on_returnPressed();
private:
    double getCacul() const;
    bool hasOperant() const;

    void removeSuffix(QString& str);

private:
    QLabel *suffix;
};

#endif // LINEEDITCALCULABLE_H
