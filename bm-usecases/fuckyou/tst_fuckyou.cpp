#include <QtTest>
#include <QCoreApplication>
#include <QDebug>

#include "business/productbusiness.h"
#include "models/builder/productbuilder.h"
#include "models/builder/invoicebuilder.h"
#include "sql/database_manager.h"

class fuckyou : public QObject
{
    Q_OBJECT

public:
    fuckyou();
    ~fuckyou();

private slots:

};

fuckyou::fuckyou()
{

}

fuckyou::~fuckyou()
{

}

// Product p=DatabaseManager::getInstance().productDao->getById(47);

QTEST_MAIN(fuckyou)

#include "tst_fuckyou.moc"
