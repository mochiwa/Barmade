/********************************************************************************
** Form generated from reading UI file 'information_panel.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFORMATION_PANEL_H
#define UI_INFORMATION_PANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InformationPanel
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *layout_info;
    QLabel *label_name;
    QLabel *label_forename;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *layout_logout;
    QLabel *label_date;
    QPushButton *button_logout;

    void setupUi(QWidget *InformationPanel)
    {
        if (InformationPanel->objectName().isEmpty())
            InformationPanel->setObjectName(QString::fromUtf8("InformationPanel"));
        InformationPanel->resize(400, 300);
        InformationPanel->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(InformationPanel);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(InformationPanel);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setStyleSheet(QString::fromUtf8(""));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame);
        horizontalLayout_2->setSpacing(10);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(10, 0, 10, 0);
        layout_info = new QVBoxLayout();
        layout_info->setObjectName(QString::fromUtf8("layout_info"));
        label_name = new QLabel(frame);
        label_name->setObjectName(QString::fromUtf8("label_name"));

        layout_info->addWidget(label_name);

        label_forename = new QLabel(frame);
        label_forename->setObjectName(QString::fromUtf8("label_forename"));

        layout_info->addWidget(label_forename);


        horizontalLayout_2->addLayout(layout_info);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        layout_logout = new QVBoxLayout();
        layout_logout->setSpacing(30);
        layout_logout->setObjectName(QString::fromUtf8("layout_logout"));
        label_date = new QLabel(frame);
        label_date->setObjectName(QString::fromUtf8("label_date"));

        layout_logout->addWidget(label_date);

        button_logout = new QPushButton(frame);
        button_logout->setObjectName(QString::fromUtf8("button_logout"));
        button_logout->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    padding: 10px;\n"
"    border:none;\n"
"    font: 16pt 'Open Sans';\n"
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
"}\n"
""));

        layout_logout->addWidget(button_logout);


        horizontalLayout_2->addLayout(layout_logout);


        verticalLayout->addWidget(frame);


        retranslateUi(InformationPanel);

        QMetaObject::connectSlotsByName(InformationPanel);
    } // setupUi

    void retranslateUi(QWidget *InformationPanel)
    {
        InformationPanel->setWindowTitle(QApplication::translate("InformationPanel", "Form", nullptr));
        label_name->setText(QApplication::translate("InformationPanel", "Name: ", nullptr));
        label_forename->setText(QApplication::translate("InformationPanel", "Forename: ", nullptr));
        label_date->setText(QApplication::translate("InformationPanel", "Date", nullptr));
        button_logout->setText(QApplication::translate("InformationPanel", "Logout", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InformationPanel: public Ui_InformationPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFORMATION_PANEL_H
