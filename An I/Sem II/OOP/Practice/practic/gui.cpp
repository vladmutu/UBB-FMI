//
// Created by vladm on 5/22/2024.
//
#include "gui.h"
#include <cstring>
#include <string>

void GUI::initGUI() {
    setLayout(mainLayout);
    mainLayout->addWidget(logTable);
    btnLayout->addWidget(btnAdauga);
    btnLayout->addWidget(btnModifica);
    btnLayout->addWidget(btnSterge);
    btnLayout->addWidget(btnExit);
    mainLayout->addLayout(btnLayout);
}

void GUI::reloadList() {
    logTable->setColumnCount(4);
    logTable->setRowCount(service.getAllLogsService().size());
    int row = 0;
    int column = 0;
    for(auto& l : service.getAllLogsService())
    {
        auto* id = new QTableWidgetItem(QString::fromStdString(l.get_id()));
        logTable->setItem(row, column, id);
        column++;
        auto* content = new QTableWidgetItem(QString::fromStdString(l.get_content()));
        logTable->setItem(row, column, content);
        column++;
        auto* pid = new QTableWidgetItem(QString::fromStdString(to_string(l.get_pid())));
        logTable->setItem(row, column, pid);
        column++;
        auto* level = new QTableWidgetItem(QString::fromStdString(l.get_level()));
        logTable->setItem(row, column, level);
        column = 0;
        row++;
    }
}

void GUI::connectSignals() {
    QObject::connect(btnExit, &QPushButton::clicked, [this]{
       QCoreApplication::quit();
    });
    QObject::connect(btnAdauga, &QPushButton::clicked, [this]{
       adaugaLog();
    });
    QObject::connect(btnAdauga, &QPushButton::clicked, [this]{
       modificaLog();
    });
    QObject::connect(btnAdauga, &QPushButton::clicked, [this]{
       stergeLog();
    });

}

void GUI::adaugaLog() {
    QWindow* window = new QWindow{};
    window->setTitle("Adauga log");
    QLineEdit* lineID = new QLineEdit{"ID"};
    QLineEdit* lineContent = new QLineEdit{"Content"};
    QLineEdit* linePID = new QLineEdit{"PID"};
    QLineEdit* lineLevel = new QLineEdit{"Level"};
    QPushButton* btn = new QPushButton{"OK"};
    QObject::connect(btn, &QPushButton::clicked, [this, lineID, lineContent, linePID, lineLevel]{
        try{

        }catch(ServiceException& e){
            QDialog* error = new QDialog{};
        }
    });
    window->show();
}

void GUI::modificaLog() {
    QWindow* window = new QWindow{};
    window->setTitle("Modifica log");
    QLineEdit* lineID = new QLineEdit{"ID"};
    QLineEdit* lineContent = new QLineEdit{"Content"};
    QLineEdit* linePID = new QLineEdit{"PID"};
    QLineEdit* lineLevel = new QLineEdit{"Level"};
    QPushButton* btn = new QPushButton{"OK"};
    window->show();
}

void GUI::stergeLog() {
    QWindow* window = new QWindow{};
    window->setTitle("Sterge log");
    QLineEdit* lineID = new QLineEdit{"ID"};
    window->show();
}

