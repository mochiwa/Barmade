#include "lineeditcalculable.h"

LineEditCalculable::LineEditCalculable(QWidget *parent):
    QLineEdit (parent)
{
    setValidator(new QRegularExpressionValidator(QRegularExpression("^[0-9*]{1,50}$"),this));
    connect(this,SIGNAL(returnPressed()),this,SLOT(on_returnPressed()));
}

QString LineEditCalculable::text() const
{
    if(hasOperant())
        return QString::number(getCacul());
    return QLineEdit::text();
}

void LineEditCalculable::on_returnPressed()
{
    this->setText(text());
}


//------------- SLOTS -------------//

//------------- PRIVATE -------------//
bool LineEditCalculable::hasOperant() const
{
    QString input=QLineEdit::text();
    for(auto c:input)
        if(c=='*')
            return true;
    return false;
}


//------------- PUBLIC -------------//

double LineEditCalculable::getCacul() const
{
    double value=1;
    QString text;

    for(auto c:QLineEdit::text())
    {
        if(c=='*')
        {
            value*=text.toDouble();
            text="";
        }
        else
            text+=c;
    }
    value*=text.toDouble();
    return value;
}

//-------- Getter & Setter ---------//

