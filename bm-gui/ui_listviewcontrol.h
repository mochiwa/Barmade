/********************************************************************************
** Form generated from reading UI file 'listviewcontrol.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LISTVIEWCONTROL_H
#define UI_LISTVIEWCONTROL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ListViewControl
{
public:
    QVBoxLayout *verticalLayout_2;
    QListView *listView;
    QFrame *frame_button;
    QHBoxLayout *horizontalLayout;
    QPushButton *button_delete;
    QPushButton *button_edit;
    QPushButton *button_create;

    void setupUi(QWidget *ListViewControl)
    {
        if (ListViewControl->objectName().isEmpty())
            ListViewControl->setObjectName(QString::fromUtf8("ListViewControl"));
        ListViewControl->resize(380, 562);
        ListViewControl->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_2 = new QVBoxLayout(ListViewControl);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 2, 0, 2);
        listView = new QListView(ListViewControl);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setFrameShape(QFrame::HLine);
        listView->setFrameShadow(QFrame::Plain);
        listView->setLineWidth(3);

        verticalLayout_2->addWidget(listView);

        frame_button = new QFrame(ListViewControl);
        frame_button->setObjectName(QString::fromUtf8("frame_button"));
        frame_button->setStyleSheet(QString::fromUtf8(""));
        frame_button->setFrameShadow(QFrame::Sunken);
        frame_button->setLineWidth(0);
        horizontalLayout = new QHBoxLayout(frame_button);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        button_delete = new QPushButton(frame_button);
        button_delete->setObjectName(QString::fromUtf8("button_delete"));
        button_delete->setStyleSheet(QString::fromUtf8("margin-right:0px;\n"
"\n"
"border-top-right-radius:0px;\n"
"border-top-left-radius:0px;\n"
"border-bottom-right-radius:0px;\n"
""));

        horizontalLayout->addWidget(button_delete);

        button_edit = new QPushButton(frame_button);
        button_edit->setObjectName(QString::fromUtf8("button_edit"));
        button_edit->setStyleSheet(QString::fromUtf8("margin-left:0px;\n"
"\n"
"border-radius:0px;\n"
"border-left:1px solid white;"));

        horizontalLayout->addWidget(button_edit);

        button_create = new QPushButton(frame_button);
        button_create->setObjectName(QString::fromUtf8("button_create"));
        button_create->setStyleSheet(QString::fromUtf8("margin-left:0px;\n"
"\n"
"border-top-left-radius:0px;\n"
"border-top-right-radius:0px;\n"
"border-bottom-left-radius:0px;\n"
"border-left : 1px solid white;"));

        horizontalLayout->addWidget(button_create);


        verticalLayout_2->addWidget(frame_button);


        retranslateUi(ListViewControl);

        QMetaObject::connectSlotsByName(ListViewControl);
    } // setupUi

    void retranslateUi(QWidget *ListViewControl)
    {
        ListViewControl->setWindowTitle(QApplication::translate("ListViewControl", "Form", nullptr));
        button_delete->setText(QApplication::translate("ListViewControl", "-", nullptr));
        button_edit->setText(QApplication::translate("ListViewControl", "Edit", nullptr));
        button_create->setText(QApplication::translate("ListViewControl", "+", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ListViewControl: public Ui_ListViewControl {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTVIEWCONTROL_H
