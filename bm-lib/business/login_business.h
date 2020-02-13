#ifndef LOGIN_BUSINESS_H
#define LOGIN_BUSINESS_H

#include "bm-lib_global.h"
#include <QObject>
#include "models/builder/employeebuilder.h"

class BMLIBSHARED_EXPORT LoginBusiness : public QObject
{
    Q_OBJECT
public:
    LoginBusiness(QObject *parent=nullptr);
    virtual ~LoginBusiness();
    void process(const QString& input);

signals:
    void login_found(const Employee&);
    void login_notFound();
};
#endif // LOGIN_BUSINESS_H
