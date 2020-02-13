/********************************************************************************
** Form generated from reading UI file 'product_panel.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRODUCT_PANEL_H
#define UI_PRODUCT_PANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProductPanel
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QFrame *frame_product;
    QGridLayout *layout_products;
    QFrame *frame_order;
    QVBoxLayout *layout_order;
    QFrame *frame_button;
    QHBoxLayout *layout_button;
    QPushButton *button_cancel;
    QPushButton *button_validate;

    void setupUi(QWidget *ProductPanel)
    {
        if (ProductPanel->objectName().isEmpty())
            ProductPanel->setObjectName(QString::fromUtf8("ProductPanel"));
        ProductPanel->resize(812, 369);
        verticalLayout = new QVBoxLayout(ProductPanel);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        frame_product = new QFrame(ProductPanel);
        frame_product->setObjectName(QString::fromUtf8("frame_product"));
        frame_product->setMinimumSize(QSize(200, 0));
        frame_product->setMaximumSize(QSize(16677777, 16777215));
        frame_product->setStyleSheet(QString::fromUtf8(""));
        frame_product->setFrameShape(QFrame::StyledPanel);
        frame_product->setFrameShadow(QFrame::Raised);
        layout_products = new QGridLayout(frame_product);
        layout_products->setObjectName(QString::fromUtf8("layout_products"));

        horizontalLayout->addWidget(frame_product);

        frame_order = new QFrame(ProductPanel);
        frame_order->setObjectName(QString::fromUtf8("frame_order"));
        frame_order->setMaximumSize(QSize(400, 16777215));
        frame_order->setFrameShape(QFrame::StyledPanel);
        frame_order->setFrameShadow(QFrame::Raised);
        layout_order = new QVBoxLayout(frame_order);
        layout_order->setSpacing(2);
        layout_order->setObjectName(QString::fromUtf8("layout_order"));
        layout_order->setContentsMargins(0, 0, 0, 0);

        horizontalLayout->addWidget(frame_order);


        verticalLayout->addLayout(horizontalLayout);

        frame_button = new QFrame(ProductPanel);
        frame_button->setObjectName(QString::fromUtf8("frame_button"));
        frame_button->setFrameShape(QFrame::NoFrame);
        frame_button->setFrameShadow(QFrame::Raised);
        layout_button = new QHBoxLayout(frame_button);
        layout_button->setObjectName(QString::fromUtf8("layout_button"));
        button_cancel = new QPushButton(frame_button);
        button_cancel->setObjectName(QString::fromUtf8("button_cancel"));

        layout_button->addWidget(button_cancel);

        button_validate = new QPushButton(frame_button);
        button_validate->setObjectName(QString::fromUtf8("button_validate"));
        button_validate->setEnabled(false);

        layout_button->addWidget(button_validate);


        verticalLayout->addWidget(frame_button);


        retranslateUi(ProductPanel);

        QMetaObject::connectSlotsByName(ProductPanel);
    } // setupUi

    void retranslateUi(QWidget *ProductPanel)
    {
        ProductPanel->setWindowTitle(QApplication::translate("ProductPanel", "Form", nullptr));
        button_cancel->setText(QApplication::translate("ProductPanel", "Cancel", nullptr));
        button_validate->setText(QApplication::translate("ProductPanel", "Validate", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProductPanel: public Ui_ProductPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRODUCT_PANEL_H
