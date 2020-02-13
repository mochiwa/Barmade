/********************************************************************************
** Form generated from reading UI file 'entitywidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENTITYWIDGET_H
#define UI_ENTITYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EntityWidget
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame_form;
    QWidget *widgetButtons;
    QHBoxLayout *horizontalLayout;
    QPushButton *button_cancel;
    QPushButton *button_validate;

    void setupUi(QWidget *EntityWidget)
    {
        if (EntityWidget->objectName().isEmpty())
            EntityWidget->setObjectName(QString::fromUtf8("EntityWidget"));
        EntityWidget->resize(735, 554);
        EntityWidget->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(EntityWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(-1, -1, -1, 0);
        frame_form = new QFrame(EntityWidget);
        frame_form->setObjectName(QString::fromUtf8("frame_form"));
        frame_form->setStyleSheet(QString::fromUtf8(""));
        frame_form->setFrameShape(QFrame::StyledPanel);
        frame_form->setFrameShadow(QFrame::Raised);

        verticalLayout->addWidget(frame_form);

        widgetButtons = new QWidget(EntityWidget);
        widgetButtons->setObjectName(QString::fromUtf8("widgetButtons"));
        widgetButtons->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout = new QHBoxLayout(widgetButtons);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, -1);
        button_cancel = new QPushButton(widgetButtons);
        button_cancel->setObjectName(QString::fromUtf8("button_cancel"));

        horizontalLayout->addWidget(button_cancel);

        button_validate = new QPushButton(widgetButtons);
        button_validate->setObjectName(QString::fromUtf8("button_validate"));
        button_validate->setStyleSheet(QString::fromUtf8("border-left: 1px solid white;"));

        horizontalLayout->addWidget(button_validate);


        verticalLayout->addWidget(widgetButtons);


        retranslateUi(EntityWidget);

        QMetaObject::connectSlotsByName(EntityWidget);
    } // setupUi

    void retranslateUi(QWidget *EntityWidget)
    {
        EntityWidget->setWindowTitle(QApplication::translate("EntityWidget", "Form", nullptr));
        button_cancel->setText(QApplication::translate("EntityWidget", "Cancel", nullptr));
        button_validate->setText(QApplication::translate("EntityWidget", "Validate", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EntityWidget: public Ui_EntityWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENTITYWIDGET_H
