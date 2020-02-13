#ifndef DATABASE_MANAGER_H
#define DATABASE_MANAGER_H

#include "../bm-lib_global.h"
#include <QSqlDatabase>
#include <QString>

#include "dao/postgres/city_dao.h"
#include "dao/postgres/street_dao.h"
#include "dao/postgres/entity_dao.h"
#include "dao/postgres/typeemploye_dao.h"
#include "dao/postgres/employee_dao.h"
#include "dao/postgres/planning_dao.h"
#include "dao/postgres/supplier_dao.h"
#include "dao/postgres/product_dao.h"
#include "dao/postgres/ingredient_dao.h"
#include "dao/postgres/invoice_dao.h"
#include "dao/postgres/compositionorder_dao.h"

class BMLIBSHARED_EXPORT DatabaseManager
{
public:
    ~DatabaseManager();
    /**
     * @brief getInstance
     * @return an instance of DatabaseManager
     */
    static DatabaseManager& getInstance();

    /**
     * @brief getdb
     * @return an instance of the database
     */
    static QSqlDatabase& getdb();
    QSqlDatabase *getDatabase() const;

    const CityAbstractDao *cityDao;
    const StreetAbstractDao *streetDao;
    const EntityAbstractDao *entityDao;
    const TypeEmployeeAbstractDao *typeEmployeeDao;
    const EmployeeAbstractDao * employeeDao;
    const PlanningAbstractDao *planningDao;
    const SupplierAbstractDao *supplierDao;
    const ProductAbstractDo *productDao;
    const IngredientAbstractDao *ingredientDao;
    const InvoiceAbstractDao * orderDao;
    const CompositionOrderAbstractDao *compositionOrderDao;
protected:
    DatabaseManager();
    DatabaseManager& operator=(DatabaseManager const& src);
private:
    QSqlDatabase *db;
};

#endif // DATABASE_MANAGER_H

