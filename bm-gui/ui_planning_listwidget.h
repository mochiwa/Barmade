/********************************************************************************
** Form generated from reading UI file 'planning_listwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLANNING_LISTWIDGET_H
#define UI_PLANNING_LISTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_planningListWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QTableView *tableView;
    QFrame *frame_button;
    QVBoxLayout *layout_button;
    QPushButton *button_append;
    QPushButton *button_remove;

    void setupUi(QWidget *planningListWidget)
    {
        if (planningListWidget->objectName().isEmpty())
            planningListWidget->setObjectName(QString::fromUtf8("planningListWidget"));
        planningListWidget->resize(845, 98);
        planningListWidget->setMaximumSize(QSize(16777215, 500));
        horizontalLayout = new QHBoxLayout(planningListWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tableView = new QTableView(planningListWidget);
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

        horizontalLayout->addWidget(tableView);

        frame_button = new QFrame(planningListWidget);
        frame_button->setObjectName(QString::fromUtf8("frame_button"));
        layout_button = new QVBoxLayout(frame_button);
        layout_button->setObjectName(QString::fromUtf8("layout_button"));
        button_append = new QPushButton(frame_button);
        button_append->setObjectName(QString::fromUtf8("button_append"));

        layout_button->addWidget(button_append);

        button_remove = new QPushButton(frame_button);
        button_remove->setObjectName(QString::fromUtf8("button_remove"));

        layout_button->addWidget(button_remove);


        horizontalLayout->addWidget(frame_button);


        retranslateUi(planningListWidget);

        QMetaObject::connectSlotsByName(planningListWidget);
    } // setupUi

    void retranslateUi(QWidget *planningListWidget)
    {
        planningListWidget->setWindowTitle(QApplication::translate("planningListWidget", "Form", nullptr));
        button_append->setText(QApplication::translate("planningListWidget", "Append", nullptr));
        button_remove->setText(QApplication::translate("planningListWidget", "Remove", nullptr));
    } // retranslateUi

};

namespace Ui {
    class planningListWidget: public Ui_planningListWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLANNING_LISTWIDGET_H
