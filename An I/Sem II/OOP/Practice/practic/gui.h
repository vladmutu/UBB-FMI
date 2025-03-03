//
// Created by vladm on 5/22/2024.
//

#ifndef PRACTIC_GUI_H
#define PRACTIC_GUI_H
#include <QCoreApplication>
#include <QtWidgets>
#include "service.h"
class GUI : public QWidget{
private:
    ServiceLogs& service;
    QHBoxLayout* mainLayout = new QHBoxLayout{};
    QTableWidget* logTable = new QTableWidget{};
    QVBoxLayout* btnLayout = new QVBoxLayout{};
    QPushButton* btnAdauga = new QPushButton{"Adauga"};
    QPushButton* btnModifica = new QPushButton{"Modifica"};
    QPushButton* btnSterge = new QPushButton{"Sterge"};
    QPushButton* btnExit = new QPushButton{"Exit"};
    void initGUI();
    void reloadList();
    void connectSignals();
    void adaugaLog();
    void modificaLog();
    void stergeLog();
public:
    explicit GUI(ServiceLogs& service) : service{service}{
        initGUI();
        connectSignals();
        reloadList();
    }
    ~GUI() = default;
};

#endif //PRACTIC_GUI_H
