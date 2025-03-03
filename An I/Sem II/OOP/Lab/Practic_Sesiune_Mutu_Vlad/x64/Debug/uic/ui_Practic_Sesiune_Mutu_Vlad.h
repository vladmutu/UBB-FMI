/********************************************************************************
** Form generated from reading UI file 'Practic_Sesiune_Mutu_Vlad.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRACTIC_SESIUNE_MUTU_VLAD_H
#define UI_PRACTIC_SESIUNE_MUTU_VLAD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Practic_Sesiune_Mutu_VladClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Practic_Sesiune_Mutu_VladClass)
    {
        if (Practic_Sesiune_Mutu_VladClass->objectName().isEmpty())
            Practic_Sesiune_Mutu_VladClass->setObjectName("Practic_Sesiune_Mutu_VladClass");
        Practic_Sesiune_Mutu_VladClass->resize(600, 400);
        menuBar = new QMenuBar(Practic_Sesiune_Mutu_VladClass);
        menuBar->setObjectName("menuBar");
        Practic_Sesiune_Mutu_VladClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Practic_Sesiune_Mutu_VladClass);
        mainToolBar->setObjectName("mainToolBar");
        Practic_Sesiune_Mutu_VladClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(Practic_Sesiune_Mutu_VladClass);
        centralWidget->setObjectName("centralWidget");
        Practic_Sesiune_Mutu_VladClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Practic_Sesiune_Mutu_VladClass);
        statusBar->setObjectName("statusBar");
        Practic_Sesiune_Mutu_VladClass->setStatusBar(statusBar);

        retranslateUi(Practic_Sesiune_Mutu_VladClass);

        QMetaObject::connectSlotsByName(Practic_Sesiune_Mutu_VladClass);
    } // setupUi

    void retranslateUi(QMainWindow *Practic_Sesiune_Mutu_VladClass)
    {
        Practic_Sesiune_Mutu_VladClass->setWindowTitle(QCoreApplication::translate("Practic_Sesiune_Mutu_VladClass", "Practic_Sesiune_Mutu_Vlad", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Practic_Sesiune_Mutu_VladClass: public Ui_Practic_Sesiune_Mutu_VladClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRACTIC_SESIUNE_MUTU_VLAD_H
