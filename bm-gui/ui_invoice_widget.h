/********************************************************************************
** Form generated from reading UI file 'invoice_widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INVOICE_WIDGET_H
#define UI_INVOICE_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InvoiceWidget
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame_info;
    QFormLayout *formLayout;
    QLabel *label_date;
    QLabel *label_employee;
    QLabel *label_date_value;
    QLabel *label_employee_value;
    QFrame *frame_table;
    QVBoxLayout *layout_table;
    QFrame *frame_total;
    QFormLayout *formLayout_2;
    QLabel *label_total;
    QDoubleSpinBox *spinbox_total;

    void setupUi(QWidget *InvoiceWidget)
    {
        if (InvoiceWidget->objectName().isEmpty())
            InvoiceWidget->setObjectName(QString::fromUtf8("InvoiceWidget"));
        InvoiceWidget->resize(435, 442);
        verticalLayout = new QVBoxLayout(InvoiceWidget);
        verticalLayout->setSpacing(2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        frame_info = new QFrame(InvoiceWidget);
        frame_info->setObjectName(QString::fromUtf8("frame_info"));
        frame_info->setFrameShape(QFrame::StyledPanel);
        frame_info->setFrameShadow(QFrame::Raised);
        formLayout = new QFormLayout(frame_info);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_date = new QLabel(frame_info);
        label_date->setObjectName(QString::fromUtf8("label_date"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_date);

        label_employee = new QLabel(frame_info);
        label_employee->setObjectName(QString::fromUtf8("label_employee"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_employee);

        label_date_value = new QLabel(frame_info);
        label_date_value->setObjectName(QString::fromUtf8("label_date_value"));

        formLayout->setWidget(0, QFormLayout::FieldRole, label_date_value);

        label_employee_value = new QLabel(frame_info);
        label_employee_value->setObjectName(QString::fromUtf8("label_employee_value"));

        formLayout->setWidget(1, QFormLayout::FieldRole, label_employee_value);


        verticalLayout->addWidget(frame_info);

        frame_table = new QFrame(InvoiceWidget);
        frame_table->setObjectName(QString::fromUtf8("frame_table"));
        frame_table->setFrameShape(QFrame::NoFrame);
        frame_table->setFrameShadow(QFrame::Plain);
        frame_table->setLineWidth(0);
        layout_table = new QVBoxLayout(frame_table);
        layout_table->setObjectName(QString::fromUtf8("layout_table"));

        verticalLayout->addWidget(frame_table);

        frame_total = new QFrame(InvoiceWidget);
        frame_total->setObjectName(QString::fromUtf8("frame_total"));
        frame_total->setFrameShape(QFrame::StyledPanel);
        frame_total->setFrameShadow(QFrame::Raised);
        formLayout_2 = new QFormLayout(frame_total);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        label_total = new QLabel(frame_total);
        label_total->setObjectName(QString::fromUtf8("label_total"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_total);

        spinbox_total = new QDoubleSpinBox(frame_total);
        spinbox_total->setObjectName(QString::fromUtf8("spinbox_total"));
        spinbox_total->setStyleSheet(QString::fromUtf8("background-color: none;"));
        spinbox_total->setFrame(false);
        spinbox_total->setReadOnly(true);
        spinbox_total->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinbox_total->setProperty("showGroupSeparator", QVariant(false));
        spinbox_total->setMaximum(99999.990000000005239);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, spinbox_total);


        verticalLayout->addWidget(frame_total);


        retranslateUi(InvoiceWidget);

        QMetaObject::connectSlotsByName(InvoiceWidget);
    } // setupUi

    void retranslateUi(QWidget *InvoiceWidget)
    {
        InvoiceWidget->setWindowTitle(QApplication::translate("InvoiceWidget", "Form", nullptr));
        label_date->setText(QApplication::translate("InvoiceWidget", "Date: ", nullptr));
        label_employee->setText(QApplication::translate("InvoiceWidget", "Employee:", nullptr));
        label_date_value->setText(QString());
        label_employee_value->setText(QString());
        label_total->setText(QApplication::translate("InvoiceWidget", "Total :", nullptr));
        spinbox_total->setPrefix(QString());
        spinbox_total->setSuffix(QApplication::translate("InvoiceWidget", "$", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InvoiceWidget: public Ui_InvoiceWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INVOICE_WIDGET_H
