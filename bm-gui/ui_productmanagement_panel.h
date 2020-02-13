/********************************************************************************
** Form generated from reading UI file 'productmanagement_panel.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRODUCTMANAGEMENT_PANEL_H
#define UI_PRODUCTMANAGEMENT_PANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProductManagementPanel
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QFrame *frame_list;
    QVBoxLayout *layout_list;
    QFrame *frame_widget;
    QVBoxLayout *layout_widget;

    void setupUi(QWidget *ProductManagementPanel)
    {
        if (ProductManagementPanel->objectName().isEmpty())
            ProductManagementPanel->setObjectName(QString::fromUtf8("ProductManagementPanel"));
        ProductManagementPanel->resize(744, 465);
        verticalLayout_2 = new QVBoxLayout(ProductManagementPanel);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        frame_list = new QFrame(ProductManagementPanel);
        frame_list->setObjectName(QString::fromUtf8("frame_list"));
        frame_list->setMinimumSize(QSize(200, 0));
        frame_list->setMaximumSize(QSize(400, 16777215));
        frame_list->setStyleSheet(QString::fromUtf8("border-radius:5px;\n"
"border-bottom-left-radius:0px;\n"
"border-bottom-right-radius:0px;"));
        frame_list->setFrameShape(QFrame::NoFrame);
        frame_list->setFrameShadow(QFrame::Plain);
        layout_list = new QVBoxLayout(frame_list);
        layout_list->setSpacing(0);
        layout_list->setObjectName(QString::fromUtf8("layout_list"));
        layout_list->setContentsMargins(0, 0, 0, 0);

        horizontalLayout->addWidget(frame_list);

        frame_widget = new QFrame(ProductManagementPanel);
        frame_widget->setObjectName(QString::fromUtf8("frame_widget"));
        frame_widget->setFrameShape(QFrame::NoFrame);
        frame_widget->setFrameShadow(QFrame::Raised);
        layout_widget = new QVBoxLayout(frame_widget);
        layout_widget->setSpacing(0);
        layout_widget->setObjectName(QString::fromUtf8("layout_widget"));
        layout_widget->setContentsMargins(0, 0, 0, 0);

        horizontalLayout->addWidget(frame_widget);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(ProductManagementPanel);

        QMetaObject::connectSlotsByName(ProductManagementPanel);
    } // setupUi

    void retranslateUi(QWidget *ProductManagementPanel)
    {
        ProductManagementPanel->setWindowTitle(QApplication::translate("ProductManagementPanel", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProductManagementPanel: public Ui_ProductManagementPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRODUCTMANAGEMENT_PANEL_H
