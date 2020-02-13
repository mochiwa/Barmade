/********************************************************************************
** Form generated from reading UI file 'productform_widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRODUCTFORM_WIDGET_H
#define UI_PRODUCTFORM_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProductFormWidget
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *layout_form;
    QLabel *label_name;
    QLineEdit *line_name;
    QLabel *label_price;
    QDoubleSpinBox *spin_price;
    QLabel *label_capacity;
    QLabel *label_alarm;
    QSpinBox *spin_alarm;
    QLabel *label_stock;
    QSpinBox *spin_stock;
    QFrame *frame;
    QHBoxLayout *layout_table;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_2;
    QFrame *frame_table_button;
    QHBoxLayout *horizontalLayout;
    QPushButton *button_remove;
    QPushButton *button_append;
    QSpacerItem *verticalSpacer_2;
    QFrame *frame_table;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *ProductFormWidget)
    {
        if (ProductFormWidget->objectName().isEmpty())
            ProductFormWidget->setObjectName(QString::fromUtf8("ProductFormWidget"));
        ProductFormWidget->resize(844, 318);
        verticalLayout = new QVBoxLayout(ProductFormWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        layout_form = new QFormLayout();
        layout_form->setObjectName(QString::fromUtf8("layout_form"));
        label_name = new QLabel(ProductFormWidget);
        label_name->setObjectName(QString::fromUtf8("label_name"));

        layout_form->setWidget(1, QFormLayout::LabelRole, label_name);

        line_name = new QLineEdit(ProductFormWidget);
        line_name->setObjectName(QString::fromUtf8("line_name"));
        line_name->setFrame(false);
        line_name->setReadOnly(true);

        layout_form->setWidget(1, QFormLayout::FieldRole, line_name);

        label_price = new QLabel(ProductFormWidget);
        label_price->setObjectName(QString::fromUtf8("label_price"));

        layout_form->setWidget(2, QFormLayout::LabelRole, label_price);

        spin_price = new QDoubleSpinBox(ProductFormWidget);
        spin_price->setObjectName(QString::fromUtf8("spin_price"));
        spin_price->setReadOnly(true);
        spin_price->setMaximum(500.000000000000000);

        layout_form->setWidget(2, QFormLayout::FieldRole, spin_price);

        label_capacity = new QLabel(ProductFormWidget);
        label_capacity->setObjectName(QString::fromUtf8("label_capacity"));

        layout_form->setWidget(3, QFormLayout::LabelRole, label_capacity);

        label_alarm = new QLabel(ProductFormWidget);
        label_alarm->setObjectName(QString::fromUtf8("label_alarm"));

        layout_form->setWidget(4, QFormLayout::LabelRole, label_alarm);

        spin_alarm = new QSpinBox(ProductFormWidget);
        spin_alarm->setObjectName(QString::fromUtf8("spin_alarm"));
        spin_alarm->setWrapping(false);
        spin_alarm->setFrame(true);
        spin_alarm->setReadOnly(true);
        spin_alarm->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        spin_alarm->setAccelerated(true);
        spin_alarm->setProperty("showGroupSeparator", QVariant(false));
        spin_alarm->setMaximum(50000);

        layout_form->setWidget(4, QFormLayout::FieldRole, spin_alarm);

        label_stock = new QLabel(ProductFormWidget);
        label_stock->setObjectName(QString::fromUtf8("label_stock"));

        layout_form->setWidget(5, QFormLayout::LabelRole, label_stock);

        spin_stock = new QSpinBox(ProductFormWidget);
        spin_stock->setObjectName(QString::fromUtf8("spin_stock"));
        spin_stock->setReadOnly(true);
        spin_stock->setMaximum(999999);

        layout_form->setWidget(5, QFormLayout::FieldRole, spin_stock);


        verticalLayout->addLayout(layout_form);

        frame = new QFrame(ProductFormWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Raised);
        layout_table = new QHBoxLayout(frame);
        layout_table->setSpacing(0);
        layout_table->setObjectName(QString::fromUtf8("layout_table"));
        layout_table->setContentsMargins(0, -1, 0, -1);
        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::NoFrame);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, -1);
        frame_table_button = new QFrame(frame_2);
        frame_table_button->setObjectName(QString::fromUtf8("frame_table_button"));
        frame_table_button->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    border:none;\n"
"    font: 18pt 'Open Sans';\n"
"    color:rgb(252, 255, 247);\n"
"    background-color: rgb(33, 160, 160);\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"    background-color: rgba(33, 160, 160,200);\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"    background-color: rgb(4, 95, 92);\n"
"}"));
        frame_table_button->setFrameShape(QFrame::NoFrame);
        frame_table_button->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame_table_button);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        button_remove = new QPushButton(frame_table_button);
        button_remove->setObjectName(QString::fromUtf8("button_remove"));

        horizontalLayout->addWidget(button_remove);

        button_append = new QPushButton(frame_table_button);
        button_append->setObjectName(QString::fromUtf8("button_append"));
        button_append->setStyleSheet(QString::fromUtf8("border-left:1px solid white;"));

        horizontalLayout->addWidget(button_append);


        verticalLayout_2->addWidget(frame_table_button);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);


        layout_table->addWidget(frame_2);

        frame_table = new QFrame(frame);
        frame_table->setObjectName(QString::fromUtf8("frame_table"));
        frame_table->setFrameShape(QFrame::NoFrame);
        frame_table->setFrameShadow(QFrame::Raised);

        layout_table->addWidget(frame_table);


        verticalLayout->addWidget(frame);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(ProductFormWidget);

        QMetaObject::connectSlotsByName(ProductFormWidget);
    } // setupUi

    void retranslateUi(QWidget *ProductFormWidget)
    {
        ProductFormWidget->setWindowTitle(QApplication::translate("ProductFormWidget", "Form", nullptr));
        label_name->setText(QApplication::translate("ProductFormWidget", "Name :", nullptr));
        line_name->setPlaceholderText(QApplication::translate("ProductFormWidget", "Product Name", nullptr));
        label_price->setText(QApplication::translate("ProductFormWidget", "Price :", nullptr));
        spin_price->setSuffix(QApplication::translate("ProductFormWidget", " $", nullptr));
        label_capacity->setText(QApplication::translate("ProductFormWidget", "Capacity :", nullptr));
        label_alarm->setText(QApplication::translate("ProductFormWidget", "Alarm :", nullptr));
        spin_alarm->setSpecialValueText(QString());
        spin_alarm->setSuffix(QString());
        spin_alarm->setPrefix(QString());
        label_stock->setText(QApplication::translate("ProductFormWidget", "Stock :", nullptr));
        spin_stock->setSuffix(QApplication::translate("ProductFormWidget", " unity", nullptr));
        spin_stock->setPrefix(QString());
        button_remove->setText(QApplication::translate("ProductFormWidget", "-", nullptr));
        button_append->setText(QApplication::translate("ProductFormWidget", "+", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProductFormWidget: public Ui_ProductFormWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRODUCTFORM_WIDGET_H
