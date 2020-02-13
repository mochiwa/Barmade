/********************************************************************************
** Form generated from reading UI file 'supplier_panel.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUPPLIER_PANEL_H
#define UI_SUPPLIER_PANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SupplierPanel
{
public:
    QHBoxLayout *horizontalLayout;
    QFrame *frame_list;
    QVBoxLayout *layout_list;
    QFrame *frame_widget;
    QVBoxLayout *layout_widget;
    QFrame *frame_InvoiceEmployee;
    QVBoxLayout *layout_invoice;

    void setupUi(QWidget *SupplierPanel)
    {
        if (SupplierPanel->objectName().isEmpty())
            SupplierPanel->setObjectName(QString::fromUtf8("SupplierPanel"));
        SupplierPanel->resize(595, 345);
        horizontalLayout = new QHBoxLayout(SupplierPanel);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        frame_list = new QFrame(SupplierPanel);
        frame_list->setObjectName(QString::fromUtf8("frame_list"));
        frame_list->setMinimumSize(QSize(200, 0));
        frame_list->setMaximumSize(QSize(400, 16777215));
        frame_list->setStyleSheet(QString::fromUtf8(""));
        frame_list->setFrameShape(QFrame::NoFrame);
        frame_list->setFrameShadow(QFrame::Raised);
        layout_list = new QVBoxLayout(frame_list);
        layout_list->setSpacing(0);
        layout_list->setObjectName(QString::fromUtf8("layout_list"));
        layout_list->setContentsMargins(0, 0, 0, 0);

        horizontalLayout->addWidget(frame_list);

        frame_widget = new QFrame(SupplierPanel);
        frame_widget->setObjectName(QString::fromUtf8("frame_widget"));
        frame_widget->setFrameShape(QFrame::NoFrame);
        frame_widget->setFrameShadow(QFrame::Raised);
        layout_widget = new QVBoxLayout(frame_widget);
        layout_widget->setObjectName(QString::fromUtf8("layout_widget"));

        horizontalLayout->addWidget(frame_widget);

        frame_InvoiceEmployee = new QFrame(SupplierPanel);
        frame_InvoiceEmployee->setObjectName(QString::fromUtf8("frame_InvoiceEmployee"));
        frame_InvoiceEmployee->setMinimumSize(QSize(100, 0));
        frame_InvoiceEmployee->setMaximumSize(QSize(300, 16777215));
        frame_InvoiceEmployee->setFrameShape(QFrame::NoFrame);
        frame_InvoiceEmployee->setFrameShadow(QFrame::Raised);
        frame_InvoiceEmployee->setLineWidth(19);
        layout_invoice = new QVBoxLayout(frame_InvoiceEmployee);
        layout_invoice->setObjectName(QString::fromUtf8("layout_invoice"));

        horizontalLayout->addWidget(frame_InvoiceEmployee);


        retranslateUi(SupplierPanel);

        QMetaObject::connectSlotsByName(SupplierPanel);
    } // setupUi

    void retranslateUi(QWidget *SupplierPanel)
    {
        SupplierPanel->setWindowTitle(QApplication::translate("SupplierPanel", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SupplierPanel: public Ui_SupplierPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUPPLIER_PANEL_H
