/********************************************************************************
** Form generated from reading UI file 'stockmanagement_panel.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STOCKMANAGEMENT_PANEL_H
#define UI_STOCKMANAGEMENT_PANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StockManagementPanel
{
public:
    QVBoxLayout *verticalLayout_2;
    QFrame *frame_table;
    QVBoxLayout *layout_table;
    QFrame *frame_information;
    QFormLayout *formLayout;
    QLabel *label_total;
    QDoubleSpinBox *spinBox_total;
    QLabel *label_supplier;
    QComboBox *comboBox_supplier;
    QFrame *frame_button;
    QHBoxLayout *horizontalLayout;
    QPushButton *button_cancel;
    QPushButton *button_validate;

    void setupUi(QWidget *StockManagementPanel)
    {
        if (StockManagementPanel->objectName().isEmpty())
            StockManagementPanel->setObjectName(QString::fromUtf8("StockManagementPanel"));
        StockManagementPanel->resize(785, 477);
        verticalLayout_2 = new QVBoxLayout(StockManagementPanel);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        frame_table = new QFrame(StockManagementPanel);
        frame_table->setObjectName(QString::fromUtf8("frame_table"));
        frame_table->setFrameShape(QFrame::NoFrame);
        frame_table->setFrameShadow(QFrame::Raised);
        layout_table = new QVBoxLayout(frame_table);
        layout_table->setObjectName(QString::fromUtf8("layout_table"));

        verticalLayout_2->addWidget(frame_table);

        frame_information = new QFrame(StockManagementPanel);
        frame_information->setObjectName(QString::fromUtf8("frame_information"));
        frame_information->setFrameShape(QFrame::StyledPanel);
        frame_information->setFrameShadow(QFrame::Raised);
        formLayout = new QFormLayout(frame_information);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_total = new QLabel(frame_information);
        label_total->setObjectName(QString::fromUtf8("label_total"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_total);

        spinBox_total = new QDoubleSpinBox(frame_information);
        spinBox_total->setObjectName(QString::fromUtf8("spinBox_total"));
        spinBox_total->setReadOnly(true);
        spinBox_total->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        spinBox_total->setMaximum(99999999.000000000000000);

        formLayout->setWidget(1, QFormLayout::FieldRole, spinBox_total);

        label_supplier = new QLabel(frame_information);
        label_supplier->setObjectName(QString::fromUtf8("label_supplier"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_supplier);

        comboBox_supplier = new QComboBox(frame_information);
        comboBox_supplier->setObjectName(QString::fromUtf8("comboBox_supplier"));

        formLayout->setWidget(0, QFormLayout::FieldRole, comboBox_supplier);


        verticalLayout_2->addWidget(frame_information);

        frame_button = new QFrame(StockManagementPanel);
        frame_button->setObjectName(QString::fromUtf8("frame_button"));
        frame_button->setFrameShape(QFrame::StyledPanel);
        frame_button->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame_button);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        button_cancel = new QPushButton(frame_button);
        button_cancel->setObjectName(QString::fromUtf8("button_cancel"));

        horizontalLayout->addWidget(button_cancel);

        button_validate = new QPushButton(frame_button);
        button_validate->setObjectName(QString::fromUtf8("button_validate"));
        button_validate->setEnabled(false);

        horizontalLayout->addWidget(button_validate);


        verticalLayout_2->addWidget(frame_button);


        retranslateUi(StockManagementPanel);

        QMetaObject::connectSlotsByName(StockManagementPanel);
    } // setupUi

    void retranslateUi(QWidget *StockManagementPanel)
    {
        StockManagementPanel->setWindowTitle(QApplication::translate("StockManagementPanel", "Form", nullptr));
        label_total->setText(QApplication::translate("StockManagementPanel", "Total :", nullptr));
        spinBox_total->setSuffix(QApplication::translate("StockManagementPanel", " $", nullptr));
        label_supplier->setText(QApplication::translate("StockManagementPanel", "Supplier", nullptr));
        button_cancel->setText(QApplication::translate("StockManagementPanel", "Cancel", nullptr));
        button_validate->setText(QApplication::translate("StockManagementPanel", "Validate", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StockManagementPanel: public Ui_StockManagementPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STOCKMANAGEMENT_PANEL_H
