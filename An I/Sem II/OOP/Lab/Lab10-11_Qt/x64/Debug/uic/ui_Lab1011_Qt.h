/********************************************************************************
** Form generated from reading UI file 'Lab1011_Qt.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LAB1011_QT_H
#define UI_LAB1011_QT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Lab1011_QtClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Lab1011_QtClass)
    {
        if (Lab1011_QtClass->objectName().isEmpty())
            Lab1011_QtClass->setObjectName("Lab1011_QtClass");
        Lab1011_QtClass->resize(600, 400);
        menuBar = new QMenuBar(Lab1011_QtClass);
        menuBar->setObjectName("menuBar");
        Lab1011_QtClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Lab1011_QtClass);
        mainToolBar->setObjectName("mainToolBar");
        Lab1011_QtClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(Lab1011_QtClass);
        centralWidget->setObjectName("centralWidget");
        Lab1011_QtClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Lab1011_QtClass);
        statusBar->setObjectName("statusBar");
        Lab1011_QtClass->setStatusBar(statusBar);

        retranslateUi(Lab1011_QtClass);

        QMetaObject::connectSlotsByName(Lab1011_QtClass);
    } // setupUi

    void retranslateUi(QMainWindow *Lab1011_QtClass)
    {
        Lab1011_QtClass->setWindowTitle(QCoreApplication::translate("Lab1011_QtClass", "Lab1011_Qt", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Lab1011_QtClass: public Ui_Lab1011_QtClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LAB1011_QT_H
