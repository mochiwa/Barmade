/********************************************************************************
** Form generated from reading UI file 'dayselector.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DAYSELECTOR_H
#define UI_DAYSELECTOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QDialog>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DaySelector
{
public:
    QVBoxLayout *verticalLayout;
    QCalendarWidget *calendarWidget;

    void setupUi(QDialog *DaySelector)
    {
        if (DaySelector->objectName().isEmpty())
            DaySelector->setObjectName(QString::fromUtf8("DaySelector"));
        DaySelector->setWindowModality(Qt::ApplicationModal);
        DaySelector->resize(400, 300);
        verticalLayout = new QVBoxLayout(DaySelector);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        calendarWidget = new QCalendarWidget(DaySelector);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));

        verticalLayout->addWidget(calendarWidget);


        retranslateUi(DaySelector);

        QMetaObject::connectSlotsByName(DaySelector);
    } // setupUi

    void retranslateUi(QDialog *DaySelector)
    {
        DaySelector->setWindowTitle(QApplication::translate("DaySelector", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DaySelector: public Ui_DaySelector {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DAYSELECTOR_H
