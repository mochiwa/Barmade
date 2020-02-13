#ifndef EMPLOYEE_INPUTCHECKER_H
#define EMPLOYEE_INPUTCHECKER_H
#include <QString>
#include <QDate>

class  EmployeeInputChecker
{
public:
    EmployeeInputChecker();

    bool isLineInputValid(const QString& input);
    bool isBirthdayValid(const QDate& input);
    bool isPhoneValid(const QString& input);
};

#endif // EMPLOYEE_INPUTCHECKER_H
