/********************************************************************************
** Form generated from reading UI file 'searchdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHDIALOG_H
#define UI_SEARCHDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SearchDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLineEdit *line_search;
    QListView *listView;
    QHBoxLayout *layout_button;
    QPushButton *button_cancel;
    QPushButton *button_valid;

    void setupUi(QDialog *SearchDialog)
    {
        if (SearchDialog->objectName().isEmpty())
            SearchDialog->setObjectName(QString::fromUtf8("SearchDialog"));
        SearchDialog->setWindowModality(Qt::WindowModal);
        SearchDialog->resize(400, 300);
        SearchDialog->setModal(true);
        verticalLayout = new QVBoxLayout(SearchDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        line_search = new QLineEdit(SearchDialog);
        line_search->setObjectName(QString::fromUtf8("line_search"));

        verticalLayout->addWidget(line_search);

        listView = new QListView(SearchDialog);
        listView->setObjectName(QString::fromUtf8("listView"));

        verticalLayout->addWidget(listView);

        layout_button = new QHBoxLayout();
        layout_button->setObjectName(QString::fromUtf8("layout_button"));
        button_cancel = new QPushButton(SearchDialog);
        button_cancel->setObjectName(QString::fromUtf8("button_cancel"));

        layout_button->addWidget(button_cancel);

        button_valid = new QPushButton(SearchDialog);
        button_valid->setObjectName(QString::fromUtf8("button_valid"));

        layout_button->addWidget(button_valid);


        verticalLayout->addLayout(layout_button);


        retranslateUi(SearchDialog);

        QMetaObject::connectSlotsByName(SearchDialog);
    } // setupUi

    void retranslateUi(QDialog *SearchDialog)
    {
        SearchDialog->setWindowTitle(QApplication::translate("SearchDialog", "Dialog", nullptr));
        line_search->setPlaceholderText(QApplication::translate("SearchDialog", "Search", nullptr));
        button_cancel->setText(QApplication::translate("SearchDialog", "Cancel", nullptr));
        button_valid->setText(QApplication::translate("SearchDialog", "Validate", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SearchDialog: public Ui_SearchDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHDIALOG_H
