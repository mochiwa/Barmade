/********************************************************************************
** Form generated from reading UI file 'login_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_DIALOG_H
#define UI_LOGIN_DIALOG_H

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
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *layout_text;
    QLabel *label_title;
    QLabel *label_error;
    QHBoxLayout *horizontalLayout;
    QFormLayout *formLayout;
    QLineEdit *lineEdit_id;
    QLabel *label_id;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *button_login;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName(QString::fromUtf8("LoginDialog"));
        LoginDialog->setWindowModality(Qt::ApplicationModal);
        LoginDialog->resize(387, 250);
        LoginDialog->setMinimumSize(QSize(387, 250));
        LoginDialog->setMaximumSize(QSize(387, 250));
        LoginDialog->setStyleSheet(QString::fromUtf8(""));
        LoginDialog->setModal(true);
        horizontalLayout_3 = new QHBoxLayout(LoginDialog);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        layout_text = new QVBoxLayout();
        layout_text->setSpacing(2);
        layout_text->setObjectName(QString::fromUtf8("layout_text"));
        label_title = new QLabel(LoginDialog);
        label_title->setObjectName(QString::fromUtf8("label_title"));
        label_title->setScaledContents(false);
        label_title->setAlignment(Qt::AlignCenter);
        label_title->setMargin(0);
        label_title->setIndent(0);

        layout_text->addWidget(label_title);

        label_error = new QLabel(LoginDialog);
        label_error->setObjectName(QString::fromUtf8("label_error"));
        label_error->setAlignment(Qt::AlignCenter);
        label_error->setMargin(0);

        layout_text->addWidget(label_error);


        verticalLayout_2->addLayout(layout_text);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(20, -1, 20, -1);
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setHorizontalSpacing(0);
        formLayout->setContentsMargins(20, -1, 20, 10);
        lineEdit_id = new QLineEdit(LoginDialog);
        lineEdit_id->setObjectName(QString::fromUtf8("lineEdit_id"));
        lineEdit_id->setMinimumSize(QSize(200, 32));
        QFont font;
        font.setFamily(QString::fromUtf8("Caladea"));
        font.setPointSize(16);
        font.setBold(false);
        font.setWeight(50);
        lineEdit_id->setFont(font);
        lineEdit_id->setFocusPolicy(Qt::StrongFocus);
        lineEdit_id->setAutoFillBackground(false);
        lineEdit_id->setStyleSheet(QString::fromUtf8(""));
        lineEdit_id->setMaxLength(50);
        lineEdit_id->setFrame(false);
        lineEdit_id->setEchoMode(QLineEdit::Normal);
        lineEdit_id->setCursorPosition(0);
        lineEdit_id->setAlignment(Qt::AlignCenter);
        lineEdit_id->setReadOnly(false);
        lineEdit_id->setCursorMoveStyle(Qt::LogicalMoveStyle);
        lineEdit_id->setClearButtonEnabled(false);

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_id);

        label_id = new QLabel(LoginDialog);
        label_id->setObjectName(QString::fromUtf8("label_id"));
        label_id->setStyleSheet(QString::fromUtf8(""));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_id);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(2, QFormLayout::FieldRole, verticalSpacer_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(0, QFormLayout::FieldRole, verticalSpacer);


        horizontalLayout->addLayout(formLayout);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        button_login = new QPushButton(LoginDialog);
        button_login->setObjectName(QString::fromUtf8("button_login"));
        button_login->setAutoFillBackground(false);
        button_login->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_2->addWidget(button_login);


        verticalLayout_2->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(LoginDialog);

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QApplication::translate("LoginDialog", "Login", nullptr));
        label_title->setText(QString());
        label_error->setText(QApplication::translate("LoginDialog", "Bad login !", nullptr));
        lineEdit_id->setPlaceholderText(QApplication::translate("LoginDialog", "****************", nullptr));
        label_id->setText(QApplication::translate("LoginDialog", "ID :", nullptr));
        button_login->setText(QApplication::translate("LoginDialog", "Log in", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_DIALOG_H
