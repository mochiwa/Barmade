#include "sql/database_manager.h"
using namespace postgres;

DatabaseManager::~DatabaseManager()
{
    if(db->isOpen())
        db->close();
    delete db;

    delete cityDao;
    delete streetDao;
    delete entityDao;
    delete typeEmployeeDao;
    delete employeeDao;
    delete planningDao;
    delete supplierDao;
    delete productDao;
    delete ingredientDao;
    delete orderDao;
    delete compositionOrderDao;
}
//------------- PROTECTED -------------//
DatabaseManager::DatabaseManager():
    db(new QSqlDatabase(QSqlDatabase::addDatabase("QPSQL")))
{
    cityDao=new CityDao(*db);
    streetDao=new StreetDao(*db);
    entityDao=new EntityDao(*db);
    typeEmployeeDao=new TypeEmployeDao(*db);
    employeeDao=new EmployeeDao(*db);
    planningDao=new PlanningDao(*db);
    supplierDao=new SupplierDao(*db);
    productDao=new ProductDao(*db);
    ingredientDao = new IngredientDao(*db);
    orderDao=new InvoiceDao(*db);
    compositionOrderDao=new CompositionOrderDao(*db);
    //db=new QSqlDatabase(QSqlDatabase::addDatabase(type));
    db->setDatabaseName("barmade");
    db->setHostName("172.17.0.1");
    db->setPort(5432);
    db->setUserName("postgres");
    db->setPassword("root");
    db->open();
}

DatabaseManager& DatabaseManager::operator=(DatabaseManager const& src)
{
    db=src.db;
    return *this;
}

//------------- PUBLIC -------------//

DatabaseManager& DatabaseManager::getInstance()
{
    static DatabaseManager database;
    return database;
}

QSqlDatabase& DatabaseManager::getdb()
{
    return *DatabaseManager::getInstance().getDatabase();
}

//-------- Getter & Setter ---------//


QSqlDatabase *DatabaseManager::getDatabase() const
{
    return db;
}
