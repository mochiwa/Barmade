/********************************************************************************
** Form generated from reading UI file 'tableviewcontrol.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABLEVIEWCONTROL_H
#define UI_TABLEVIEWCONTROL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TableViewControl
{
public:
    QHBoxLayout *horizontalLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_3;
    QTableView *tableView;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout;
    QFrame *frame_button;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *button_remove;
    QPushButton *button_append;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *TableViewControl)
    {
        if (TableViewControl->objectName().isEmpty())
            TableViewControl->setObjectName(QString::fromUtf8("TableViewControl"));
        TableViewControl->resize(815, 124);
        horizontalLayout = new QHBoxLayout(TableViewControl);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        frame = new QFrame(TableViewControl);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, -1);
        tableView = new QTableView(frame);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setSelectionMode(QAbstractItemView::SingleSelection);
        tableView->setShowGrid(true);
        tableView->setGridStyle(Qt::SolidLine);
        tableView->setSortingEnabled(false);
        tableView->setWordWrap(true);
        tableView->setCornerButtonEnabled(false);
        tableView->horizontalHeader()->setCascadingSectionResizes(false);
        tableView->horizontalHeader()->setMinimumSectionSize(50);
        tableView->horizontalHeader()->setStretchLastSection(true);
        tableView->verticalHeader()->setVisible(false);

        horizontalLayout_3->addWidget(tableView);

        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setStyleSheet(QString::fromUtf8(""));
        frame_2->setFrameShape(QFrame::NoFrame);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, -1);
        frame_button = new QFrame(frame_2);
        frame_button->setObjectName(QString::fromUtf8("frame_button"));
        frame_button->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout_2 = new QHBoxLayout(frame_button);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        button_remove = new QPushButton(frame_button);
        button_remove->setObjectName(QString::fromUtf8("button_remove"));

        horizontalLayout_2->addWidget(button_remove);

        button_append = new QPushButton(frame_button);
        button_append->setObjectName(QString::fromUtf8("button_append"));
        QFont font;
        font.setFamily(QString::fromUtf8("Open Sans"));
        font.setPointSize(10);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        button_append->setFont(font);
        button_append->setStyleSheet(QString::fromUtf8("border-left:1px solid #ecf0f1;"));
        button_append->setFlat(false);

        horizontalLayout_2->addWidget(button_append);


        verticalLayout->addWidget(frame_button);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_3->addWidget(frame_2);


        horizontalLayout->addWidget(frame);


        retranslateUi(TableViewControl);

        QMetaObject::connectSlotsByName(TableViewControl);
    } // setupUi

    void retranslateUi(QWidget *TableViewControl)
    {
        TableViewControl->setWindowTitle(QApplication::translate("TableViewControl", "Form", nullptr));
        button_remove->setText(QApplication::translate("TableViewControl", "-", nullptr));
        button_append->setText(QApplication::translate("TableViewControl", "+", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TableViewControl: public Ui_TableViewControl {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLEVIEWCONTROL_H
