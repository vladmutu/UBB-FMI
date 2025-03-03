#pragma once
#include <QtWidgets>

#include "service.h"
class GUI : public QWidget {
private:
	ServiceMasina& service;
	QHBoxLayout* mainLayout = new QHBoxLayout{};
	QVBoxLayout* btnsLayout = new QVBoxLayout{};
	QListWidget* listaMasini;
	QPushButton* btnAdauga = new QPushButton{ "Adauga" };
	QPushButton* btnSterge = new QPushButton{ "Sterge" };
	QPushButton* btnModifica = new QPushButton{ "Modifica" };
	QPushButton* btnFiltrare = new QPushButton{ "Filtrare" };
	QPushButton* btnSortare = new QPushButton{ "Sortare" };
	QPushButton* btnSpalatorie = new QPushButton{ "Spalatorie" };
	QPushButton* btnSpalatorieLabelEdit = new QPushButton{ "Spalatorie Label Window" };
	QPushButton* btnSpalatorieDraw = new QPushButton{ "Spalatorie Draw Window" };
	QPushButton* btnRaport = new QPushButton{ "Raport" };
	QPushButton* btnUndo = new QPushButton{ "Undo" };
	QPushButton* btnExit = new QPushButton{ "Exit" };

	void initGUI();
	void connectSignals();
	void reloadList(QListWidget* listaMasini, const vector<Masina>& masini);
	void adaugaMasina();
	void stergeMasina();
	void modificaMasina();
	void filtrare();
	void sortare();
	void raport(); 
	void undo();
	void exit();
	void initButtons();
public:
	GUI(ServiceMasina& service) : service{ service } {
		initGUI();
		connectSignals();
		reloadList(listaMasini, service.getAllMasiniService());
	}
};