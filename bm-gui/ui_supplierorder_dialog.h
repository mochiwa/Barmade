/********************************************************************************
** Form generated from reading UI file 'supplierorder_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUPPLIERORDER_DIALOG_H
#define UI_SUPPLIERORDER_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SupplierOrderDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame_information;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_title;
    QFrame *frame;
    QFormLayout *formLayout_2;
    QLabel *label_product;
    QLabel *label_stock;
    QLabel *label_alarm;
    QLabel *label_productValue;
    QLabel *label_stockValue;
    QLabel *label_alarmValue;
    QFrame *frame_form;
    QFormLayout *formLayout;
    QLabel *label_supplier;
    QLabel *label_quantity;
    QComboBox *comboBox;
    QSpinBox *spinBox;
    QPushButton *button_validate;

    void setupUi(QDialog *SupplierOrderDialog)
    {
        if (SupplierOrderDialog->objectName().isEmpty())
            SupplierOrderDialog->setObjectName(QString::fromUtf8("SupplierOrderDialog"));
        SupplierOrderDialog->resize(614, 409);
        verticalLayout = new QVBoxLayout(SupplierOrderDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frame_information = new QFrame(SupplierOrderDialog);
        frame_information->setObjectName(QString::fromUtf8("frame_information"));
        frame_information->setFrameShape(QFrame::StyledPanel);
        frame_information->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame_information);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_title = new QLabel(frame_information);
        label_title->setObjectName(QString::fromUtf8("label_title"));
        label_title->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_title);

        frame = new QFrame(frame_information);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        formLayout_2 = new QFormLayout(frame);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        label_product = new QLabel(frame);
        label_product->setObjectName(QString::fromUtf8("label_product"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_product);

        label_stock = new QLabel(frame);
        label_stock->setObjectName(QString::fromUtf8("label_stock"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_stock);

        label_alarm = new QLabel(frame);
        label_alarm->setObjectName(QString::fromUtf8("label_alarm"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_alarm);

        label_productValue = new QLabel(frame);
        label_productValue->setObjectName(QString::fromUtf8("label_productValue"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, label_productValue);

        label_stockValue = new QLabel(frame);
        label_stockValue->setObjectName(QString::fromUtf8("label_stockValue"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, label_stockValue);

        label_alarmValue = new QLabel(frame);
        label_alarmValue->setObjectName(QString::fromUtf8("label_alarmValue"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, label_alarmValue);


        verticalLayout_2->addWidget(frame);


        verticalLayout->addWidget(frame_information);

        frame_form = new QFrame(SupplierOrderDialog);
        frame_form->setObjectName(QString::fromUtf8("frame_form"));
        frame_form->setFrameShape(QFrame::StyledPanel);
        frame_form->setFrameShadow(QFrame::Raised);
        formLayout = new QFormLayout(frame_form);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_supplier = new QLabel(frame_form);
        label_supplier->setObjectName(QString::fromUtf8("label_supplier"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_supplier);

        label_quantity = new QLabel(frame_form);
        label_quantity->setObjectName(QString::fromUtf8("label_quantity"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_quantity);

        comboBox = new QComboBox(frame_form);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        formLayout->setWidget(0, QFormLayout::FieldRole, comboBox);

        spinBox = new QSpinBox(frame_form);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));

        formLayout->setWidget(1, QFormLayout::FieldRole, spinBox);


        verticalLayout->addWidget(frame_form);

        button_validate = new QPushButton(SupplierOrderDialog);
        button_validate->setObjectName(QString::fromUtf8("button_validate"));

        verticalLayout->addWidget(button_validate);


        retranslateUi(SupplierOrderDialog);

        QMetaObject::connectSlotsByName(SupplierOrderDialog);
    } // setupUi

    void retranslateUi(QDialog *SupplierOrderDialog)
    {
        SupplierOrderDialog->setWindowTitle(QApplication::translate("SupplierOrderDialog", "Dialog", nullptr));
        label_title->setText(QApplication::translate("SupplierOrderDialog", "Order  to supplier", nullptr));
        label_product->setText(QApplication::translate("SupplierOrderDialog", "Product :", nullptr));
        label_stock->setText(QApplication::translate("SupplierOrderDialog", "stock :", nullptr));
        label_alarm->setText(QApplication::translate("SupplierOrderDialog", "Alarm :", nullptr));
        label_productValue->setText(QString());
        label_stockValue->setText(QString());
        label_alarmValue->setText(QString());
        label_supplier->setText(QApplication::translate("SupplierOrderDialog", "Supplier :", nullptr));
        label_quantity->setText(QApplication::translate("SupplierOrderDialog", "Quantity :", nullptr));
        button_validate->setText(QApplication::translate("SupplierOrderDialog", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SupplierOrderDialog: public Ui_SupplierOrderDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUPPLIERORDER_DIALOG_H
