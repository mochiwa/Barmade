#-------------------------------------------------
#
# Project created by QtCreator 2019-04-11T14:48:19
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = bm-gui
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        mainwindow.h

FORMS += \
        mainwindow.ui


include($$PWD/panel/panel.pri)
include($$PWD/components/components.pri)
include($$PWD/dialogs/dialogs.pri)
INCLUDEPATH += $$PWD/panel/
#########################################
#           ADD library
#########################################
LIBS += -L$$OUT_PWD/../bm-lib -lbm-lib
INCLUDEPATH += $$PWD/../bm-lib/
DEPENDPATH += $$PWD/../bm-lib/

RESOURCES += \
    ressources.qrc

DISTFILES += \
    css/list_control.css \
    css/entity_widget.css \
    css/information_panel.css \
    css/employee_form.css \
    css/list_invoice.css