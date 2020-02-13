QT += testlib sql
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_planningbusiness.cpp
#########################################
#           ADD library
#########################################
LIBS += -L$$OUT_PWD/../../bm-lib -lbm-lib
INCLUDEPATH += $$PWD/../../bm-lib/
DEPENDPATH += $$PWD/../../bm-lib/
