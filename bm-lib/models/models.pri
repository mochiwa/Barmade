SOURCES += \
        models/employee_model.cpp \
    $$PWD/planning_model.cpp \
    $$PWD/supplier_model.cpp \
    $$PWD/abstractlistmodel.cpp \
    $$PWD/abstracttablemodel.cpp \
    $$PWD/product_model.cpp \
    $$PWD/invoice_model.cpp

HEADERS += \
        models/employee_model.h \ 
    $$PWD/planning_model.h \
    $$PWD/supplier_model.h \
    $$PWD/abstractlistmodel.h \
    $$PWD/abstracttablemodel.h \
    $$PWD/product_model.h \
    $$PWD/invoice_model.h


include(builder/builder.pri)
