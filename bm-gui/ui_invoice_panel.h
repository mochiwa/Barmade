/********************************************************************************
** Form generated from reading UI file 'invoice_panel.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INVOICE_PANEL_H
#define UI_INVOICE_PANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InvoicePanel
{
public:
    QVBoxLayout *verticalLayout_2;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QFrame *frame_title;
    QVBoxLayout *layout_header;
    QLabel *label_title;
    QListView *listView;
    QFrame *frame_total;
    QFormLayout *layout_total;
    QLabel *label_total;
    QDoubleSpinBox *spinBox_total;
    QFrame *frame_search;
    QFormLayout *formLayout_2;
    QLabel *label;
    QLabel *label_2;
    QDateEdit *date_begin;
    QDateEdit *date_end;

    void setupUi(QWidget *InvoicePanel)
    {
        if (InvoicePanel->objectName().isEmpty())
            InvoicePanel->setObjectName(QString::fromUtf8("InvoicePanel"));
        InvoicePanel->resize(363, 655);
        InvoicePanel->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_2 = new QVBoxLayout(InvoicePanel);
        verticalLayout_2->setSpacing(2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(2, 2, 2, -1);
        frame = new QFrame(InvoicePanel);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setStyleSheet(QString::fromUtf8(""));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        frame_title = new QFrame(frame);
        frame_title->setObjectName(QString::fromUtf8("frame_title"));
        layout_header = new QVBoxLayout(frame_title);
        layout_header->setSpacing(2);
        layout_header->setObjectName(QString::fromUtf8("layout_header"));
        layout_header->setContentsMargins(0, -1, 0, 10);
        label_title = new QLabel(frame_title);
        label_title->setObjectName(QString::fromUtf8("label_title"));
        QFont font;
        font.setPointSize(30);
        font.setBold(true);
        font.setWeight(75);
        label_title->setFont(font);
        label_title->setAlignment(Qt::AlignCenter);

        layout_header->addWidget(label_title);


        verticalLayout->addWidget(frame_title);

        listView = new QListView(frame);
        listView->setObjectName(QString::fromUtf8("listView"));

        verticalLayout->addWidget(listView);

        frame_total = new QFrame(frame);
        frame_total->setObjectName(QString::fromUtf8("frame_total"));
        layout_total = new QFormLayout(frame_total);
        layout_total->setObjectName(QString::fromUtf8("layout_total"));
        layout_total->setHorizontalSpacing(5);
        layout_total->setVerticalSpacing(0);
        layout_total->setContentsMargins(5, 5, -1, 20);
        label_total = new QLabel(frame_total);
        label_total->setObjectName(QString::fromUtf8("label_total"));

        layout_total->setWidget(0, QFormLayout::LabelRole, label_total);

        spinBox_total = new QDoubleSpinBox(frame_total);
        spinBox_total->setObjectName(QString::fromUtf8("spinBox_total"));
        spinBox_total->setReadOnly(true);
        spinBox_total->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_total->setMaximum(99999999.000000000000000);

        layout_total->setWidget(0, QFormLayout::FieldRole, spinBox_total);


        verticalLayout->addWidget(frame_total);

        frame_search = new QFrame(frame);
        frame_search->setObjectName(QString::fromUtf8("frame_search"));
        formLayout_2 = new QFormLayout(frame_search);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setHorizontalSpacing(0);
        formLayout_2->setVerticalSpacing(20);
        formLayout_2->setContentsMargins(0, 15, 0, 0);
        label = new QLabel(frame_search);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label);

        label_2 = new QLabel(frame_search);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_2);

        date_begin = new QDateEdit(frame_search);
        date_begin->setObjectName(QString::fromUtf8("date_begin"));
        date_begin->setCalendarPopup(true);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, date_begin);

        date_end = new QDateEdit(frame_search);
        date_end->setObjectName(QString::fromUtf8("date_end"));
        date_end->setDateTime(QDateTime(QDate(2000, 1, 1), QTime(0, 0, 0)));
        date_end->setCalendarPopup(true);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, date_end);


        verticalLayout->addWidget(frame_search);


        verticalLayout_2->addWidget(frame);


        retranslateUi(InvoicePanel);

        QMetaObject::connectSlotsByName(InvoicePanel);
    } // setupUi

    void retranslateUi(QWidget *InvoicePanel)
    {
        InvoicePanel->setWindowTitle(QApplication::translate("InvoicePanel", "Form", nullptr));
        label_title->setText(QApplication::translate("InvoicePanel", "Invoice", nullptr));
        label_total->setText(QApplication::translate("InvoicePanel", "Total :", nullptr));
        spinBox_total->setSuffix(QApplication::translate("InvoicePanel", " $", nullptr));
#ifndef QT_NO_WHATSTHIS
        frame_search->setWhatsThis(QApplication::translate("InvoicePanel", "<html><head/><body><p>frame_search</p></body></html>", nullptr));
#endif // QT_NO_WHATSTHIS
        label->setText(QApplication::translate("InvoicePanel", "Begin:", nullptr));
        label_2->setText(QApplication::translate("InvoicePanel", "End :  ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InvoicePanel: public Ui_InvoicePanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INVOICE_PANEL_H
