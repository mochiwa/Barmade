/********************************************************************************
** Form generated from reading UI file 'entity_panel.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENTITY_PANEL_H
#define UI_ENTITY_PANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EntityPanel
{
public:

    void setupUi(QWidget *EntityPanel)
    {
        if (EntityPanel->objectName().isEmpty())
            EntityPanel->setObjectName(QString::fromUtf8("EntityPanel"));
        EntityPanel->resize(400, 300);

        retranslateUi(EntityPanel);

        QMetaObject::connectSlotsByName(EntityPanel);
    } // setupUi

    void retranslateUi(QWidget *EntityPanel)
    {
        EntityPanel->setWindowTitle(QApplication::translate("EntityPanel", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EntityPanel: public Ui_EntityPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENTITY_PANEL_H
