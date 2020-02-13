/********************************************************************************
** Form generated from reading UI file 'invoice_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INVOICE_DIALOG_H
#define UI_INVOICE_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_InvoiceDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame_widget;
    QVBoxLayout *layout_wdget;
    QFrame *frame_button;
    QHBoxLayout *horizontalLayout;
    QPushButton *button_exit;

    void setupUi(QDialog *InvoiceDialog)
    {
        if (InvoiceDialog->objectName().isEmpty())
            InvoiceDialog->setObjectName(QString::fromUtf8("InvoiceDialog"));
        InvoiceDialog->resize(400, 300);
        verticalLayout = new QVBoxLayout(InvoiceDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frame_widget = new QFrame(InvoiceDialog);
        frame_widget->setObjectName(QString::fromUtf8("frame_widget"));
        frame_widget->setFrameShape(QFrame::StyledPanel);
        frame_widget->setFrameShadow(QFrame::Raised);
        layout_wdget = new QVBoxLayout(frame_widget);
        layout_wdget->setObjectName(QString::fromUtf8("layout_wdget"));

        verticalLayout->addWidget(frame_widget);

        frame_button = new QFrame(InvoiceDialog);
        frame_button->setObjectName(QString::fromUtf8("frame_button"));
        frame_button->setFrameShape(QFrame::StyledPanel);
        frame_button->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame_button);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        button_exit = new QPushButton(frame_button);
        button_exit->setObjectName(QString::fromUtf8("button_exit"));

        horizontalLayout->addWidget(button_exit);


        verticalLayout->addWidget(frame_button);


        retranslateUi(InvoiceDialog);

        QMetaObject::connectSlotsByName(InvoiceDialog);
    } // setupUi

    void retranslateUi(QDialog *InvoiceDialog)
    {
        InvoiceDialog->setWindowTitle(QApplication::translate("InvoiceDialog", "Dialog", nullptr));
        button_exit->setText(QApplication::translate("InvoiceDialog", "exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InvoiceDialog: public Ui_InvoiceDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INVOICE_DIALOG_H
