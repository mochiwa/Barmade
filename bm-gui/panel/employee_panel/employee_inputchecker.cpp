#include "employee_inputchecker.h"

EmployeeInputChecker::EmployeeInputChecker()
{

}

bool EmployeeInputChecker::isLineInputValid(const QString& input)
{
    if(input.trimmed().isEmpty())
        return false;
    return true;
}
bool EmployeeInputChecker::isBirthdayValid(const QDate& input)
{
    if(input>QDate::currentDate())
        return false;
    return true;
}

bool EmployeeInputChecker::isPhoneValid(const QString& input)
{
    if(input.trimmed().length()==13)
        return true;
    return false;
}
