/********************************************************************************
** Form generated from reading UI file 'planningviewcontrol.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLANNINGVIEWCONTROL_H
#define UI_PLANNINGVIEWCONTROL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PlanningViewControl
{
public:

    void setupUi(QWidget *PlanningViewControl)
    {
        if (PlanningViewControl->objectName().isEmpty())
            PlanningViewControl->setObjectName(QString::fromUtf8("PlanningViewControl"));
        PlanningViewControl->resize(400, 300);
        PlanningViewControl->setStyleSheet(QString::fromUtf8(""));

        retranslateUi(PlanningViewControl);

        QMetaObject::connectSlotsByName(PlanningViewControl);
    } // setupUi

    void retranslateUi(QWidget *PlanningViewControl)
    {
        PlanningViewControl->setWindowTitle(QApplication::translate("PlanningViewControl", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PlanningViewControl: public Ui_PlanningViewControl {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLANNINGVIEWCONTROL_H
