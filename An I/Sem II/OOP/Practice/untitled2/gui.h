//
// Created by vladm on 5/21/2024.
//

#ifndef UNTITLED2_GUI_H
#define UNTITLED2_GUI_H
#include <QtWidgets/QHBoxLayout>
#include "service.h"
class GUI : public QWidget{
private:
    EleviService& service;
    QHBoxLayout* mainLayout = new QHBoxLayout{};
    QPushButton* exitBtn = new QPushButton{"Exit"};
public:
    explicit GUI(EleviService& service) : service { service }{
        setLayout(mainLayout);
    }
};

#endif //UNTITLED2_GUI_H
