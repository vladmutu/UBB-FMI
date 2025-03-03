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
	Spalatorie& spalatorie;
public:
	SpalatorieLabelEditGUI(Spalatorie& _spalatorie) : spalatorie{spalatorie } {
		lbl = new QLabel{ "Numar masini:" };
		edit = new QLineEdit;
		layout = new QHBoxLayout;
		setLayout(layout);
		layout->addWidget(lbl);
		layout->addWidget(edit);
		lbl->setFont(QFont{ "arial", 24 });
		spalatorie.addObserver(this);
		setAttribute(Qt::WA_DeleteOnClose);
		update();
	}
	void update() override {
		QString numarMasini = QString::fromStdString(std::to_string(spalatorie.getAllMasiniSpalatorie().size()));
		edit->setText(numarMasini);
	}

	~SpalatorieLabelEditGUI() {
		spalatorie.removeObserver(this);
	}
};

class SpalatorieDrawGUI : public QWidget, public Observer {
private:
	Spalatorie& spalatorie;
public:

	void paintEvent(QPaintEvent*) override {
		QPainter p{ this };
		int x = rand() % 50;
		int y = rand() % 50;
		p.drawImage(x, y, QImage{ "pic.png" });
	}
public:
	SpalatorieDrawGUI(Spalatorie& _spalatorie) : spalatorie{ spalatorie } {
		spalatorie.addObserver(this);
		setAttribute(Qt::WA_DeleteOnClose);

		update();
	};
	void update() override {
		repaint();
	}
	~SpalatorieDrawGUI() {
		spalatorie.removeObserver(this);
	}


};