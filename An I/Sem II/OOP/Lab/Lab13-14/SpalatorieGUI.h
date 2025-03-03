#pragma once
#include "service.h"
#include <QtWidgets>

class SpalatorieGUI : public QWidget {
private:
    ServiceMasina& srv;
    QHBoxLayout* mainLayout;
    QWidget* leftWidget;
    QVBoxLayout* leftLayout;

    QFormLayout* addFormLayout;
    QWidget* addFormWidget;
    QLabel* labelNrInmatriculare;
    QLineEdit* editNrInmatriculare;
    QPushButton* addBtn;
    QSlider* sliderAddRandom;
    QLineEdit* editValueSlider;
    QPushButton* addRandomBtn;
    QPushButton* clearSpalatorieBtn;
    QPushButton* closeWindowBtn;

    QListWidget* masiniList;

    void initializeGUIComponents();
    void connectSignalsSlots();
    void addByTitleAndArtist();
    void reloadData(const vector<Masina>& masiniSpalatorie);
public:
    SpalatorieGUI(ServiceMasina& _srv) : srv{ _srv } {
        initializeGUIComponents();
        connectSignalsSlots();
        reloadData(srv.getAllSpalatorie());
    };

};

class SpalatorieLabelEditGUI : public QWidget, public Observer {
private:
    QHBoxLayout* layout;
    QLabel* lbl;
    QLineEdit* edit;
    Spalatorie& s;
public:
    explicit SpalatorieLabelEditGUI(Spalatorie& _spalatorie) : s{_spalatorie } {
        lbl = new QLabel{ "Numar masini:" };
        edit = new QLineEdit;
        layout = new QHBoxLayout;
        setLayout(layout);
        layout->addWidget(lbl);
        layout->addWidget(edit);
        lbl->setFont(QFont{ "arial", 24 });
        s.addObserver(this);
        setAttribute(Qt::WA_DeleteOnClose);
        update();
    }
    void update() override {
        QString numarMasini = QString::fromStdString(std::to_string(s.getAllMasiniSpalatorie().size()));
        edit->setText(numarMasini);
    }

    ~SpalatorieLabelEditGUI() {
        s.removeObserver(this);
    }
};

class SpalatorieDrawGUI : public QWidget, public Observer {
private:
    Spalatorie& s;
public:

    void paintEvent(QPaintEvent*) override {
        QPainter p{ this };
        int x,y;
        x=y=0;
        for(auto& m : s.getAllMasiniSpalatorie()) {
            x = rand()%400;
            p.drawRect( x, 10, rand()%100, rand()%100+50);
        }
    }
public:
    explicit SpalatorieDrawGUI(Spalatorie& _spalatorie) : s{ _spalatorie } {
        s.addObserver(this);
        setAttribute(Qt::WA_DeleteOnClose);

        update();
    };
    void update() override {
        repaint();
    }
    ~SpalatorieDrawGUI() {
        s.removeObserver(this);
    }


};