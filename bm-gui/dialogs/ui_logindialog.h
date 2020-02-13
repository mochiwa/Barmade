/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_error;
    QHBoxLayout *horizontalLayout;
    QFormLayout *formLayout;
    QLineEdit *lineEdit_id;
    QLabel *label_id;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *button_login;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName(QString::fromUtf8("LoginDialog"));
        LoginDialog->setWindowModality(Qt::ApplicationModal);
        LoginDialog->resize(387, 208);
        LoginDialog->setMaximumSize(QSize(387, 208));
        LoginDialog->setModal(true);
        horizontalLayout_3 = new QHBoxLayout(LoginDialog);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(64, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        label_error = new QLabel(LoginDialog);
        label_error->setObjectName(QString::fromUtf8("label_error"));
        label_error->setAlignment(Qt::AlignCenter);
        label_error->setMargin(0);

        verticalLayout_2->addWidget(label_error);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setHorizontalSpacing(0);
        lineEdit_id = new QLineEdit(LoginDialog);
        lineEdit_id->setObjectName(QString::fromUtf8("lineEdit_id"));
        lineEdit_id->setMinimumSize(QSize(200, 20));
        QFont font;
        font.setFamily(QString::fromUtf8("Caladea"));
        font.setPointSize(16);
        font.setBold(false);
        font.setWeight(50);
        lineEdit_id->setFont(font);
        lineEdit_id->setStyleSheet(QString::fromUtf8("border: 1px solid black;\n"
"border-left:none;\n"
"background-color: rgb(238, 238, 236);\n"
""));
        lineEdit_id->setMaxLength(50);
        lineEdit_id->setFrame(true);
        lineEdit_id->setEchoMode(QLineEdit::Normal);
        lineEdit_id->setAlignment(Qt::AlignCenter);
        lineEdit_id->setReadOnly(false);
        lineEdit_id->setCursorMoveStyle(Qt::VisualMoveStyle);
        lineEdit_id->setClearButtonEnabled(false);

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_id);

        label_id = new QLabel(LoginDialog);
        label_id->setObjectName(QString::fromUtf8("label_id"));
        label_id->setStyleSheet(QString::fromUtf8("border: 1px solid black;\n"
"border-right: none;\n"
"background-color: rgb(238, 238, 236);"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_id);


        horizontalLayout->addLayout(formLayout);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        button_login = new QPushButton(LoginDialog);
        button_login->setObjectName(QString::fromUtf8("button_login"));
        button_login->setAutoFillBackground(false);
        button_login->setStyleSheet(QString::fromUtf8("background-color: #1E91D6;\n"
"padding: 10px;"));

        horizontalLayout_2->addWidget(button_login);


        verticalLayout_2->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout_3->addLayout(verticalLayout_2);

        horizontalSpacer_2 = new QSpacerItem(53, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        retranslateUi(LoginDialog);

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QApplication::translate("LoginDialog", "Login", nullptr));
        label_error->setText(QApplication::translate("LoginDialog", "Id no found !", nullptr));
        lineEdit_id->setPlaceholderText(QString());
        label_id->setText(QApplication::translate("LoginDialog", "ID :", nullptr));
        button_login->setText(QApplication::translate("LoginDialog", "Login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
