#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Lab1011_Qt.h"

class Lab1011_Qt : public QMainWindow
{
    Q_OBJECT

public:
    Lab1011_Qt(QWidget *parent = nullptr);
    ~Lab1011_Qt();

private:
    Ui::Lab1011_QtClass ui;
};
