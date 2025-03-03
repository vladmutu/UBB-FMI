#pragma once
#include <QtWidgets>
#include "service.h"
#include "TableModel.h"
class GUI : public QWidget {
private:
	ServiceUtilaje& service;
	QVBoxLayout* mainLayout = new QVBoxLayout{};
	QTableView* tableUtilaje = new QTableView{};
	TableModel* model = new TableModel(tableUtilaje);

	//pentru update si delete
	QFormLayout* layoutUpdate = new QFormLayout();
	QLabel* labelDenumire = new QLabel("Introduceti denumirea:");
	QLabel* labelTip = new QLabel("Introduceti tipul:");
	QLabel* labelCilindrii = new QLabel("Introduceti numarul de cilindrii:");
	QLineEdit* lineDenumire = new QLineEdit();
	QLineEdit* lineTip = new QLineEdit();
	QLabel* i = new QLabel("1 cilindru");
	QLabel* ii = new QLabel("2 cilindru");
	QLabel* iii = new QLabel("4 cilindru");
	QLabel* iiii = new QLabel("8 cilindru");
	QRadioButton* cilindru1 = new QRadioButton();
	QRadioButton* cilindru2 = new QRadioButton();
	QRadioButton* cilindru4 = new QRadioButton();
	QRadioButton* cilindru8 = new QRadioButton();

	QHBoxLayout* horLayout = new QHBoxLayout{};
	QPushButton* updateBtn = new QPushButton("Update");
	QPushButton* deleteBtn = new QPushButton("Delete");
	QPushButton* btnExit = new QPushButton("Exit");


	//pentru selectare
	int nr_cilindrii = 0;
	int ID;

	QLabel* emptyLabel1 = new QLabel();
	QLabel* emptyLabel2 = new QLabel();
	QLabel* emptyLabel3 = new QLabel();
	QLabel* emptyLabel4 = new QLabel();
	QLabel* emptyLabel5 = new QLabel();


	/*
	functie ce initializeaza widgeturile window-ului
	*/
	void initGUI();


	/*
	functie de conectare a butoanelor si actiunilor
	*/
	void connectSignals();


	/*
	functie ce reseteaza lista
	*/
	void reloadList(const vector<Utilaj>& utilaje);


	/*
	functie painter care deseneaza 4 cerucri cu diametru proportional 
	cu nr de cilindrii respectivi pentru fiecare
	*/
	void paintEvent(QPaintEvent* ev) override {
		QPainter painter{ this };
		QPen pen(Qt::white, 2);
		painter.setPen(pen);
		int x = 50;
		int y = height() - 50;
		int constant = 5;
		int radius;
		for (int i = 0; i < 4; i++)
		{
			if (i == 0) {
				int k = 0;
				for (auto& u : service.get_all_service())
					if (u.get_cilindrii() == 1)
						k++;
				radius = k;
				painter.drawEllipse(QPoint(x+=100, y), 2 * radius * constant, 2 * radius * constant);
			}
			if (i == 1) {
				int k = 0;
				for (auto& u : service.get_all_service())
					if (u.get_cilindrii() == 2)
						k++;
				radius = k;
				painter.drawEllipse(QPoint(x+=100, y), 2 * radius * constant, 2 * radius * constant);
			}
			if (i == 2) {
				int k = 0;
				for (auto& u : service.get_all_service())
					if (u.get_cilindrii() == 4)
						k++;
				radius = k;
				painter.drawEllipse(QPoint(x+=100, y), 2 * radius*constant, 2 * radius * constant);
			}
			if (i == 3) {
				int k = 0;
				for (auto& u : service.get_all_service())
					if (u.get_cilindrii() == 8)
						k++;
				radius = k;
				painter.drawEllipse(QPoint(x+=100, y), 2 * radius * constant, 2 * radius * constant);
			}
		}
	}
public:
	GUI(ServiceUtilaje& serv) : service{ serv } {
		initGUI();
		connectSignals();
		reloadList(serv.get_all_service());
	}
};