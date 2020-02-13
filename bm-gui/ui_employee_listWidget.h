/********************************************************************************
** Form generated from reading UI file 'employee_listWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMPLOYEE_LISTWIDGET_H
#define UI_EMPLOYEE_LISTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EmployeeListWidget
{
public:
    QVBoxLayout *verticalLayout;
    QVBoxLayout *layout_button;
    QPushButton *button_append;
    QPushButton *button_edit;
    QPushButton *button_delete;
    QListView *listView;

    void setupUi(QWidget *EmployeeListWidget)
    {
        if (EmployeeListWidget->objectName().isEmpty())
            EmployeeListWidget->setObjectName(QString::fromUtf8("EmployeeListWidget"));
        EmployeeListWidget->resize(256, 459);
        EmployeeListWidget->setMaximumSize(QSize(500, 16777215));
        EmployeeListWidget->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(EmployeeListWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(9, -1, -1, 6);
        layout_button = new QVBoxLayout();
        layout_button->setObjectName(QString::fromUtf8("layout_button"));
        button_append = new QPushButton(EmployeeListWidget);
        button_append->setObjectName(QString::fromUtf8("button_append"));

        layout_button->addWidget(button_append);

        button_edit = new QPushButton(EmployeeListWidget);
        button_edit->setObjectName(QString::fromUtf8("button_edit"));

        layout_button->addWidget(button_edit);

        button_delete = new QPushButton(EmployeeListWidget);
        button_delete->setObjectName(QString::fromUtf8("button_delete"));

        layout_button->addWidget(button_delete);


        verticalLayout->addLayout(layout_button);

        listView = new QListView(EmployeeListWidget);
        listView->setObjectName(QString::fromUtf8("listView"));

        verticalLayout->addWidget(listView);


        retranslateUi(EmployeeListWidget);

        QMetaObject::connectSlotsByName(EmployeeListWidget);
    } // setupUi

    void retranslateUi(QWidget *EmployeeListWidget)
    {
        EmployeeListWidget->setWindowTitle(QApplication::translate("EmployeeListWidget", "Form", nullptr));
        button_append->setText(QApplication::translate("EmployeeListWidget", "Append", nullptr));
        button_edit->setText(QApplication::translate("EmployeeListWidget", "Edit", nullptr));
        button_delete->setText(QApplication::translate("EmployeeListWidget", "Delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EmployeeListWidget: public Ui_EmployeeListWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPLOYEE_LISTWIDGET_H
