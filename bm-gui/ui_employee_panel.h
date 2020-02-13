/********************************************************************************
** Form generated from reading UI file 'employee_panel.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMPLOYEE_PANEL_H
#define UI_EMPLOYEE_PANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_employeePanel
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QFrame *frame_listEmployee;
    QVBoxLayout *layout_listemployee;
    QFrame *frame_Invoice;
    QVBoxLayout *layout_widgetEmployee;
    QFrame *frame_widgetEmployee;
    QVBoxLayout *layout_listOrder;

    void setupUi(QWidget *employeePanel)
    {
        if (employeePanel->objectName().isEmpty())
            employeePanel->setObjectName(QString::fromUtf8("employeePanel"));
        employeePanel->resize(880, 609);
        employeePanel->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_2 = new QVBoxLayout(employeePanel);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, 0, -1, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 10, -1, 10);
        frame_listEmployee = new QFrame(employeePanel);
        frame_listEmployee->setObjectName(QString::fromUtf8("frame_listEmployee"));
        frame_listEmployee->setMinimumSize(QSize(200, 0));
        frame_listEmployee->setMaximumSize(QSize(400, 16777215));
        frame_listEmployee->setStyleSheet(QString::fromUtf8(""));
        frame_listEmployee->setFrameShape(QFrame::NoFrame);
        frame_listEmployee->setFrameShadow(QFrame::Plain);
        layout_listemployee = new QVBoxLayout(frame_listEmployee);
        layout_listemployee->setSpacing(2);
        layout_listemployee->setObjectName(QString::fromUtf8("layout_listemployee"));
        layout_listemployee->setContentsMargins(0, 0, 0, 0);

        horizontalLayout->addWidget(frame_listEmployee);

        frame_Invoice = new QFrame(employeePanel);
        frame_Invoice->setObjectName(QString::fromUtf8("frame_Invoice"));
        frame_Invoice->setStyleSheet(QString::fromUtf8(""));
        frame_Invoice->setFrameShape(QFrame::NoFrame);
        frame_Invoice->setFrameShadow(QFrame::Raised);
        layout_widgetEmployee = new QVBoxLayout(frame_Invoice);
        layout_widgetEmployee->setObjectName(QString::fromUtf8("layout_widgetEmployee"));

        horizontalLayout->addWidget(frame_Invoice);

        frame_widgetEmployee = new QFrame(employeePanel);
        frame_widgetEmployee->setObjectName(QString::fromUtf8("frame_widgetEmployee"));
        frame_widgetEmployee->setMinimumSize(QSize(100, 0));
        frame_widgetEmployee->setMaximumSize(QSize(300, 16777215));
        frame_widgetEmployee->setFrameShape(QFrame::StyledPanel);
        frame_widgetEmployee->setFrameShadow(QFrame::Raised);
        layout_listOrder = new QVBoxLayout(frame_widgetEmployee);
        layout_listOrder->setObjectName(QString::fromUtf8("layout_listOrder"));
        layout_listOrder->setContentsMargins(0, 0, 0, 0);

        horizontalLayout->addWidget(frame_widgetEmployee);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(employeePanel);

        QMetaObject::connectSlotsByName(employeePanel);
    } // setupUi

    void retranslateUi(QWidget *employeePanel)
    {
        employeePanel->setWindowTitle(QApplication::translate("employeePanel", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class employeePanel: public Ui_employeePanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPLOYEE_PANEL_H
