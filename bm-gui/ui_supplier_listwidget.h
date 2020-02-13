/********************************************************************************
** Form generated from reading UI file 'supplier_listwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUPPLIER_LISTWIDGET_H
#define UI_SUPPLIER_LISTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SupplierListWidget
{
public:
    QVBoxLayout *verticalLayout;
    QVBoxLayout *layout_button;
    QPushButton *button_append;
    QPushButton *button_edit;
    QPushButton *button_delete;
    QListView *listView;

    void setupUi(QWidget *SupplierListWidget)
    {
        if (SupplierListWidget->objectName().isEmpty())
            SupplierListWidget->setObjectName(QString::fromUtf8("SupplierListWidget"));
        SupplierListWidget->resize(256, 459);
        SupplierListWidget->setMaximumSize(QSize(500, 16777215));
        SupplierListWidget->setStyleSheet(QString::fromUtf8("QWidget#EmployeeListWidget\n"
"{\n"
"border-width: 2px;\n"
"    border-style: solid;\n"
"    border-color: black;\n"
"}"));
        verticalLayout = new QVBoxLayout(SupplierListWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(9, -1, -1, 6);
        layout_button = new QVBoxLayout();
        layout_button->setObjectName(QString::fromUtf8("layout_button"));
        button_append = new QPushButton(SupplierListWidget);
        button_append->setObjectName(QString::fromUtf8("button_append"));

        layout_button->addWidget(button_append);

        button_edit = new QPushButton(SupplierListWidget);
        button_edit->setObjectName(QString::fromUtf8("button_edit"));

        layout_button->addWidget(button_edit);

        button_delete = new QPushButton(SupplierListWidget);
        button_delete->setObjectName(QString::fromUtf8("button_delete"));

        layout_button->addWidget(button_delete);


        verticalLayout->addLayout(layout_button);

        listView = new QListView(SupplierListWidget);
        listView->setObjectName(QString::fromUtf8("listView"));

        verticalLayout->addWidget(listView);


        retranslateUi(SupplierListWidget);

        QMetaObject::connectSlotsByName(SupplierListWidget);
    } // setupUi

    void retranslateUi(QWidget *SupplierListWidget)
    {
        SupplierListWidget->setWindowTitle(QApplication::translate("SupplierListWidget", "Form", nullptr));
        button_append->setText(QApplication::translate("SupplierListWidget", "Append", nullptr));
        button_edit->setText(QApplication::translate("SupplierListWidget", "Edit", nullptr));
        button_delete->setText(QApplication::translate("SupplierListWidget", "Delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SupplierListWidget: public Ui_SupplierListWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUPPLIER_LISTWIDGET_H
