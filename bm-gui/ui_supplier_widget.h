/********************************************************************************
** Form generated from reading UI file 'supplier_widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUPPLIER_WIDGET_H
#define UI_SUPPLIER_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SupplierWidget
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QFrame *frame;
    QFormLayout *formLayout;
    QLabel *label_code;
    QLabel *label_name;
    QLineEdit *line_name;
    QLabel *label_forename;
    QLineEdit *line_forename;
    QLabel *label_address;
    QWidget *widget_address;
    QGridLayout *layout_address;
    QLineEdit *line_number;
    QLineEdit *line_cp;
    QLabel *label_cp;
    QLabel *label_street;
    QLineEdit *line_city;
    QLabel *label_number;
    QLabel *label_city;
    QLineEdit *line_street;
    QLabel *label_phone;
    QLineEdit *line_phone;
    QLabel *label_fax;
    QLineEdit *line_fax;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *SupplierWidget)
    {
        if (SupplierWidget->objectName().isEmpty())
            SupplierWidget->setObjectName(QString::fromUtf8("SupplierWidget"));
        SupplierWidget->resize(676, 594);
        SupplierWidget->setStyleSheet(QString::fromUtf8("background-color:white;"));
        verticalLayout = new QVBoxLayout(SupplierWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(-1, 2, -1, 2);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        frame = new QFrame(SupplierWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        formLayout = new QFormLayout(frame);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_code = new QLabel(frame);
        label_code->setObjectName(QString::fromUtf8("label_code"));
        QFont font;
        font.setPointSize(20);
        label_code->setFont(font);
        label_code->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);
        label_code->setTextInteractionFlags(Qt::NoTextInteraction);

        formLayout->setWidget(0, QFormLayout::FieldRole, label_code);

        label_name = new QLabel(frame);
        label_name->setObjectName(QString::fromUtf8("label_name"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_name);

        line_name = new QLineEdit(frame);
        line_name->setObjectName(QString::fromUtf8("line_name"));
        line_name->setMaxLength(50);
        line_name->setFrame(false);
        line_name->setCursorPosition(0);
        line_name->setReadOnly(true);
        line_name->setClearButtonEnabled(false);

        formLayout->setWidget(1, QFormLayout::FieldRole, line_name);

        label_forename = new QLabel(frame);
        label_forename->setObjectName(QString::fromUtf8("label_forename"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_forename);

        line_forename = new QLineEdit(frame);
        line_forename->setObjectName(QString::fromUtf8("line_forename"));
        line_forename->setMaxLength(50);
        line_forename->setFrame(false);
        line_forename->setReadOnly(true);

        formLayout->setWidget(2, QFormLayout::FieldRole, line_forename);

        label_address = new QLabel(frame);
        label_address->setObjectName(QString::fromUtf8("label_address"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_address);

        widget_address = new QWidget(frame);
        widget_address->setObjectName(QString::fromUtf8("widget_address"));
        layout_address = new QGridLayout(widget_address);
        layout_address->setSpacing(10);
        layout_address->setObjectName(QString::fromUtf8("layout_address"));
        layout_address->setContentsMargins(5, 5, 20, 4);
        line_number = new QLineEdit(widget_address);
        line_number->setObjectName(QString::fromUtf8("line_number"));
        line_number->setMaxLength(50);
        line_number->setFrame(false);
        line_number->setReadOnly(true);

        layout_address->addWidget(line_number, 0, 3, 1, 1);

        line_cp = new QLineEdit(widget_address);
        line_cp->setObjectName(QString::fromUtf8("line_cp"));
        line_cp->setMaxLength(50);
        line_cp->setFrame(false);
        line_cp->setReadOnly(true);

        layout_address->addWidget(line_cp, 1, 3, 1, 1);

        label_cp = new QLabel(widget_address);
        label_cp->setObjectName(QString::fromUtf8("label_cp"));

        layout_address->addWidget(label_cp, 1, 2, 1, 1);

        label_street = new QLabel(widget_address);
        label_street->setObjectName(QString::fromUtf8("label_street"));

        layout_address->addWidget(label_street, 0, 0, 1, 1);

        line_city = new QLineEdit(widget_address);
        line_city->setObjectName(QString::fromUtf8("line_city"));
        line_city->setMaxLength(50);
        line_city->setFrame(false);
        line_city->setReadOnly(true);

        layout_address->addWidget(line_city, 1, 1, 1, 1);

        label_number = new QLabel(widget_address);
        label_number->setObjectName(QString::fromUtf8("label_number"));

        layout_address->addWidget(label_number, 0, 2, 1, 1);

        label_city = new QLabel(widget_address);
        label_city->setObjectName(QString::fromUtf8("label_city"));

        layout_address->addWidget(label_city, 1, 0, 1, 1);

        line_street = new QLineEdit(widget_address);
        line_street->setObjectName(QString::fromUtf8("line_street"));
        line_street->setMaxLength(50);
        line_street->setFrame(false);
        line_street->setReadOnly(true);

        layout_address->addWidget(line_street, 0, 1, 1, 1);


        formLayout->setWidget(3, QFormLayout::FieldRole, widget_address);

        label_phone = new QLabel(frame);
        label_phone->setObjectName(QString::fromUtf8("label_phone"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_phone);

        line_phone = new QLineEdit(frame);
        line_phone->setObjectName(QString::fromUtf8("line_phone"));
        line_phone->setMaxLength(13);
        line_phone->setFrame(false);
        line_phone->setReadOnly(true);

        formLayout->setWidget(4, QFormLayout::FieldRole, line_phone);

        label_fax = new QLabel(frame);
        label_fax->setObjectName(QString::fromUtf8("label_fax"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_fax);

        line_fax = new QLineEdit(frame);
        line_fax->setObjectName(QString::fromUtf8("line_fax"));
        line_fax->setFrame(false);
        line_fax->setReadOnly(true);

        formLayout->setWidget(5, QFormLayout::FieldRole, line_fax);


        verticalLayout->addWidget(frame);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

#ifndef QT_NO_SHORTCUT
        label_code->setBuddy(widget_address);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(line_name, line_forename);
        QWidget::setTabOrder(line_forename, line_street);
        QWidget::setTabOrder(line_street, line_number);
        QWidget::setTabOrder(line_number, line_city);
        QWidget::setTabOrder(line_city, line_cp);
        QWidget::setTabOrder(line_cp, line_phone);
        QWidget::setTabOrder(line_phone, line_fax);

        retranslateUi(SupplierWidget);

        QMetaObject::connectSlotsByName(SupplierWidget);
    } // setupUi

    void retranslateUi(QWidget *SupplierWidget)
    {
        SupplierWidget->setWindowTitle(QApplication::translate("SupplierWidget", "Form", nullptr));
        label_code->setText(QApplication::translate("SupplierWidget", "#0000", nullptr));
        label_name->setText(QApplication::translate("SupplierWidget", "Name:", nullptr));
        line_name->setInputMask(QString());
        line_name->setPlaceholderText(QApplication::translate("SupplierWidget", "Company name", nullptr));
        label_forename->setText(QApplication::translate("SupplierWidget", "Forename: ", nullptr));
        line_forename->setPlaceholderText(QApplication::translate("SupplierWidget", "Contact Name", nullptr));
        label_address->setText(QApplication::translate("SupplierWidget", "Address :", nullptr));
        line_number->setPlaceholderText(QApplication::translate("SupplierWidget", "Home number", nullptr));
        line_cp->setPlaceholderText(QApplication::translate("SupplierWidget", "City postal code", nullptr));
        label_cp->setText(QApplication::translate("SupplierWidget", "cp:", nullptr));
        label_street->setText(QApplication::translate("SupplierWidget", "Street:", nullptr));
        line_city->setPlaceholderText(QApplication::translate("SupplierWidget", "Your city", nullptr));
        label_number->setText(QApplication::translate("SupplierWidget", "N\302\260;", nullptr));
        label_city->setText(QApplication::translate("SupplierWidget", "City:", nullptr));
        line_street->setPlaceholderText(QApplication::translate("SupplierWidget", "Your street", nullptr));
        label_phone->setText(QApplication::translate("SupplierWidget", "phone:", nullptr));
        line_phone->setInputMask(QApplication::translate("SupplierWidget", "9999.99.99.99", nullptr));
        line_phone->setPlaceholderText(QApplication::translate("SupplierWidget", "Your phone number", nullptr));
        label_fax->setText(QApplication::translate("SupplierWidget", "Fax:", nullptr));
        line_fax->setInputMask(QApplication::translate("SupplierWidget", "+99-999-9999999", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SupplierWidget: public Ui_SupplierWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUPPLIER_WIDGET_H
