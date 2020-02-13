CONFIG += object_parallel_to_source
SOURCES += \
    sql/database_manager.cpp \
    $$PWD/dao/entity_abstractdao.cpp \
    $$PWD/dao/abstractdao.cpp \
    $$PWD/dao/city_abstractdao.cpp \
    $$PWD/dao/street_abstractdao.cpp \
    $$PWD/dao/employee_abstractdao.cpp \
    $$PWD/dao/typeemployee_abstractdao.cpp \
    $$PWD/dao/planning_abstractdao.cpp \
    $$PWD/dao/supplier_abstractdao.cpp \
    $$PWD/dao/postgres/city_dao.cpp \
    $$PWD/dao/postgres/employee_dao.cpp \
    $$PWD/dao/postgres/street_dao.cpp \
    $$PWD/dao/sqlite/city_dao.cpp \
    $$PWD/dao/postgres/typeemploye_dao.cpp \
    $$PWD/dao/postgres/entity_dao.cpp \
    $$PWD/dao/postgres/planning_dao.cpp \
    $$PWD/dao/postgres/supplier_dao.cpp \
    $$PWD/dao/product_abstractdo.cpp \
    $$PWD/dao/postgres/product_dao.cpp \
    $$PWD/dao/compositionorder_abstractdao.cpp \
    $$PWD/dao/postgres/compositionorder_dao.cpp \
    $$PWD/dao/invoice_abstractdao.cpp \
    $$PWD/dao/postgres/invoice_dao.cpp \
    $$PWD/dao/ingredient_abstractdao.cpp \
    $$PWD/dao/postgres/ingredient_dao.cpp

HEADERS += \
    sql/database_manager.h \
    $$PWD/dao/entity_abstractdao.h \
    $$PWD/dao/abstractdao.h \
    $$PWD/dao/city_abstractdao.h \
    $$PWD/dao/street_abstractdao.h \
    $$PWD/dao/employee_abstractdao.h \
    $$PWD/dao/typeemployee_abstractdao.h \
    $$PWD/dao/planning_abstractdao.h \
    $$PWD/dao/supplier_abstractdao.h \
    $$PWD/dao/postgres/city_dao.h \
    $$PWD/dao/postgres/employee_dao.h \
    $$PWD/dao/postgres/street_dao.h \
    $$PWD/dao/sqlite/city_dao.h \
    $$PWD/dao/postgres/typeemploye_dao.h \
    $$PWD/dao/postgres/entity_dao.h \
    $$PWD/dao/postgres/planning_dao.h \
    $$PWD/dao/postgres/supplier_dao.h \
    $$PWD/dao/product_abstractdo.h \
    $$PWD/dao/postgres/product_dao.h \
    $$PWD/dao/compositionorder_abstractdao.h \
    $$PWD/dao/postgres/compositionorder_dao.h \
    $$PWD/dao/invoice_abstractdao.h \
    $$PWD/dao/postgres/invoice_dao.h \
    $$PWD/dao/ingredient_abstractdao.h \
    $$PWD/dao/postgres/ingredient_dao.h

