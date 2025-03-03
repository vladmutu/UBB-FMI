#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Practic_Sesiune_Mutu_Vlad.h"

class Practic_Sesiune_Mutu_Vlad : public QMainWindow
{
    Q_OBJECT

public:
    Practic_Sesiune_Mutu_Vlad(QWidget *parent = nullptr);
    ~Practic_Sesiune_Mutu_Vlad();

private:
    Ui::Practic_Sesiune_Mutu_VladClass ui;
};
