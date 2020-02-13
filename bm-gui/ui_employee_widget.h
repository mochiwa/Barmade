/********************************************************************************
** Form generated from reading UI file 'employee_widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMPLOYEE_WIDGET_H
#define UI_EMPLOYEE_WIDGET_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EmployeeWidget
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QFrame *frame;
    QFormLayout *formLayout;
    QLabel *label_picture;
    QLabel *label_code;
    QLabel *label_name;
    QLineEdit *line_name;
    QLabel *label_forename;
    QLineEdit *line_forename;
    QLabel *label_birthday;
    QDateEdit *line_birthday;
    QLabel *label_address;
    QWidget *widget_address;
    QGridLayout *layout_address;
    QLineEdit *line_number;
    QLabel *label_number;
    QLabel *label_cp;
    QLineEdit *line_city;
    QLineEdit *line_cp;
    QLineEdit *line_street;
    QLabel *label_street;
    QLabel *label_city;
    QLabel *label_phone;
    QLineEdit *line_phone;
    QDoubleSpinBox *line_salary;
    QLabel *label_salary;
    QLabel *label_rank;
    QComboBox *comboBox_rank;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *EmployeeWidget)
    {
        if (EmployeeWidget->objectName().isEmpty())
            EmployeeWidget->setObjectName(QString::fromUtf8("EmployeeWidget"));
        EmployeeWidget->resize(821, 543);
        EmployeeWidget->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(EmployeeWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(-1, 2, -1, 2);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        frame = new QFrame(EmployeeWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        formLayout = new QFormLayout(frame);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_picture = new QLabel(frame);
        label_picture->setObjectName(QString::fromUtf8("label_picture"));
        label_picture->setMaximumSize(QSize(200, 200));
        label_picture->setPixmap(QPixmap(QString::fromUtf8(":/images/undefinedUser_icon.png")));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_picture);

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

        formLayout->setWidget(3, QFormLayout::LabelRole, label_name);

        line_name = new QLineEdit(frame);
        line_name->setObjectName(QString::fromUtf8("line_name"));
        line_name->setMaxLength(50);
        line_name->setFrame(false);
        line_name->setCursorPosition(0);
        line_name->setReadOnly(false);
        line_name->setClearButtonEnabled(false);

        formLayout->setWidget(3, QFormLayout::FieldRole, line_name);

        label_forename = new QLabel(frame);
        label_forename->setObjectName(QString::fromUtf8("label_forename"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_forename);

        line_forename = new QLineEdit(frame);
        line_forename->setObjectName(QString::fromUtf8("line_forename"));
        line_forename->setMaxLength(50);
        line_forename->setFrame(false);
        line_forename->setReadOnly(true);

        formLayout->setWidget(4, QFormLayout::FieldRole, line_forename);

        label_birthday = new QLabel(frame);
        label_birthday->setObjectName(QString::fromUtf8("label_birthday"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_birthday);

        line_birthday = new QDateEdit(frame);
        line_birthday->setObjectName(QString::fromUtf8("line_birthday"));
        line_birthday->setWrapping(false);
        line_birthday->setFrame(false);
        line_birthday->setReadOnly(false);
        line_birthday->setButtonSymbols(QAbstractSpinBox::NoButtons);
        line_birthday->setKeyboardTracking(false);
        line_birthday->setCurrentSection(QDateTimeEdit::DaySection);
        line_birthday->setCalendarPopup(true);
        line_birthday->setTimeSpec(Qt::LocalTime);
        line_birthday->setDate(QDate(2000, 1, 1));

        formLayout->setWidget(5, QFormLayout::FieldRole, line_birthday);

        label_address = new QLabel(frame);
        label_address->setObjectName(QString::fromUtf8("label_address"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_address);

        widget_address = new QWidget(frame);
        widget_address->setObjectName(QString::fromUtf8("widget_address"));
        layout_address = new QGridLayout(widget_address);
        layout_address->setSpacing(10);
        layout_address->setObjectName(QString::fromUtf8("layout_address"));
        layout_address->setContentsMargins(5, 10, 20, 10);
        line_number = new QLineEdit(widget_address);
        line_number->setObjectName(QString::fromUtf8("line_number"));
        line_number->setMaxLength(50);
        line_number->setFrame(false);
        line_number->setReadOnly(true);

        layout_address->addWidget(line_number, 0, 3, 1, 1);

        label_number = new QLabel(widget_address);
        label_number->setObjectName(QString::fromUtf8("label_number"));

        layout_address->addWidget(label_number, 0, 2, 1, 1);

        label_cp = new QLabel(widget_address);
        label_cp->setObjectName(QString::fromUtf8("label_cp"));

        layout_address->addWidget(label_cp, 1, 2, 1, 1);

        line_city = new QLineEdit(widget_address);
        line_city->setObjectName(QString::fromUtf8("line_city"));
        line_city->setMaxLength(50);
        line_city->setFrame(false);
        line_city->setReadOnly(true);

        layout_address->addWidget(line_city, 1, 1, 1, 1);

        line_cp = new QLineEdit(widget_address);
        line_cp->setObjectName(QString::fromUtf8("line_cp"));
        line_cp->setMaxLength(50);
        line_cp->setFrame(false);
        line_cp->setReadOnly(true);

        layout_address->addWidget(line_cp, 1, 3, 1, 1);

        line_street = new QLineEdit(widget_address);
        line_street->setObjectName(QString::fromUtf8("line_street"));
        line_street->setMaxLength(50);
        line_street->setFrame(false);
        line_street->setReadOnly(true);

        layout_address->addWidget(line_street, 0, 1, 1, 1);

        label_street = new QLabel(widget_address);
        label_street->setObjectName(QString::fromUtf8("label_street"));

        layout_address->addWidget(label_street, 0, 0, 1, 1);

        label_city = new QLabel(widget_address);
        label_city->setObjectName(QString::fromUtf8("label_city"));

        layout_address->addWidget(label_city, 1, 0, 1, 1);


        formLayout->setWidget(6, QFormLayout::FieldRole, widget_address);

        label_phone = new QLabel(frame);
        label_phone->setObjectName(QString::fromUtf8("label_phone"));

        formLayout->setWidget(7, QFormLayout::LabelRole, label_phone);

        line_phone = new QLineEdit(frame);
        line_phone->setObjectName(QString::fromUtf8("line_phone"));
        line_phone->setMaxLength(13);
        line_phone->setFrame(false);
        line_phone->setReadOnly(false);

        formLayout->setWidget(7, QFormLayout::FieldRole, line_phone);

        line_salary = new QDoubleSpinBox(frame);
        line_salary->setObjectName(QString::fromUtf8("line_salary"));
        line_salary->setFrame(false);
        line_salary->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        line_salary->setProperty("showGroupSeparator", QVariant(false));
        line_salary->setMaximum(1000000.989999999990687);

        formLayout->setWidget(8, QFormLayout::FieldRole, line_salary);

        label_salary = new QLabel(frame);
        label_salary->setObjectName(QString::fromUtf8("label_salary"));

        formLayout->setWidget(8, QFormLayout::LabelRole, label_salary);

        label_rank = new QLabel(frame);
        label_rank->setObjectName(QString::fromUtf8("label_rank"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_rank);

        comboBox_rank = new QComboBox(frame);
        comboBox_rank->addItem(QString());
        comboBox_rank->addItem(QString());
        comboBox_rank->addItem(QString());
        comboBox_rank->setObjectName(QString::fromUtf8("comboBox_rank"));
        comboBox_rank->setEditable(false);
        comboBox_rank->setInsertPolicy(QComboBox::NoInsert);
        comboBox_rank->setFrame(false);

        formLayout->setWidget(2, QFormLayout::FieldRole, comboBox_rank);


        verticalLayout->addWidget(frame);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

#ifndef QT_NO_SHORTCUT
        label_code->setBuddy(widget_address);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(comboBox_rank, line_name);
        QWidget::setTabOrder(line_name, line_forename);
        QWidget::setTabOrder(line_forename, line_birthday);
        QWidget::setTabOrder(line_birthday, line_street);
        QWidget::setTabOrder(line_street, line_number);
        QWidget::setTabOrder(line_number, line_city);
        QWidget::setTabOrder(line_city, line_cp);
        QWidget::setTabOrder(line_cp, line_phone);
        QWidget::setTabOrder(line_phone, line_salary);

        retranslateUi(EmployeeWidget);

        QMetaObject::connectSlotsByName(EmployeeWidget);
    } // setupUi

    void retranslateUi(QWidget *EmployeeWidget)
    {
        EmployeeWidget->setWindowTitle(QApplication::translate("EmployeeWidget", "Form", nullptr));
        label_picture->setText(QString());
        label_code->setText(QApplication::translate("EmployeeWidget", "#0000", nullptr));
        label_name->setText(QApplication::translate("EmployeeWidget", "Name:", nullptr));
        line_name->setInputMask(QString());
        line_name->setPlaceholderText(QApplication::translate("EmployeeWidget", "Your name", nullptr));
        label_forename->setText(QApplication::translate("EmployeeWidget", "Forename: ", nullptr));
        line_forename->setPlaceholderText(QApplication::translate("EmployeeWidget", "Your forname", nullptr));
        label_birthday->setText(QApplication::translate("EmployeeWidget", "Birthday:", nullptr));
        line_birthday->setDisplayFormat(QApplication::translate("EmployeeWidget", "dd/MM/yyyy", nullptr));
        label_address->setText(QApplication::translate("EmployeeWidget", "Address :", nullptr));
        line_number->setPlaceholderText(QApplication::translate("EmployeeWidget", "Home number", nullptr));
        label_number->setText(QApplication::translate("EmployeeWidget", "N\302\260;", nullptr));
        label_cp->setText(QApplication::translate("EmployeeWidget", "cp:", nullptr));
        line_city->setPlaceholderText(QApplication::translate("EmployeeWidget", "Your city", nullptr));
        line_cp->setPlaceholderText(QApplication::translate("EmployeeWidget", "City postal code", nullptr));
        line_street->setPlaceholderText(QApplication::translate("EmployeeWidget", "Your street", nullptr));
        label_street->setText(QApplication::translate("EmployeeWidget", "Street:", nullptr));
        label_city->setText(QApplication::translate("EmployeeWidget", "City:", nullptr));
        label_phone->setText(QApplication::translate("EmployeeWidget", "phone:", nullptr));
        line_phone->setInputMask(QApplication::translate("EmployeeWidget", "9999.99.99.99", nullptr));
        line_phone->setPlaceholderText(QApplication::translate("EmployeeWidget", "Your phone number", nullptr));
        line_salary->setSuffix(QApplication::translate("EmployeeWidget", "$", nullptr));
        label_salary->setText(QApplication::translate("EmployeeWidget", "Salary:", nullptr));
        label_rank->setText(QApplication::translate("EmployeeWidget", "Rank :", nullptr));
        comboBox_rank->setItemText(0, QApplication::translate("EmployeeWidget", "WAITER", nullptr));
        comboBox_rank->setItemText(1, QApplication::translate("EmployeeWidget", "BARMAN", nullptr));
        comboBox_rank->setItemText(2, QApplication::translate("EmployeeWidget", "MANAGER", nullptr));

    } // retranslateUi

};

namespace Ui {
    class EmployeeWidget: public Ui_EmployeeWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPLOYEE_WIDGET_H
