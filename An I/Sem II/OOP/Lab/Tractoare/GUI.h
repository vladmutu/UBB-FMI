#pragma once
#include <QtWidgets>
#include <QWidget>
#include "service.h"
#include "TableModel.h"
class GUI : public QWidget {
private:
	ServiceTractoare& serv;

	QVBoxLayout* mainLayout = new QVBoxLayout{};
	QVBoxLayout* layoutListaSiButoane = new QVBoxLayout{};


	QTableView* tableTractoare = new QTableView{};
	TableModel* model = new TableModel{ tableTractoare };
	
	QWidget* adaugaLayoutWidget = new QWidget{};
	QFormLayout* adaugaLayout = new QFormLayout{};
	QLabel* lblID = new QLabel{ "Introduceti id-ul" };
	QLineEdit* lineID = new QLineEdit{};
	QLabel* lblDenumire = new QLabel{ "Introduceti denumirea" };
	QLineEdit* lineDenumire = new QLineEdit{};
	QLabel* lblTip = new QLabel{ "Introduceti tipul" };
	QLineEdit* lineTip = new QLineEdit{};
	QLabel* lblRoti = new QLabel{ "Introduceti numarul de roti" };
	QLineEdit* lineRoti = new QLineEdit{};
	QPushButton* btnAdauga = new QPushButton{ "Adauga" };

	QPushButton* btnExit = new QPushButton{ "Exit" };
	QLabel* emptyLabel1 = new QLabel{};
	QLabel* emptyLabel2 = new QLabel{};
	QLabel* emptyLabel3 = new QLabel{};
	QLabel* emptyLabel4 = new QLabel{};

	QComboBox* combobox = new QComboBox{};

	

	string tip="";
	int roti=0;
	int ID;

	void initGUI();
	void connectSlots();
	void reloadList(const vector<Tractor>& tractoare);

	void mousePressEvent(QMouseEvent* ev) override{
		if (ev->button() == Qt::LeftButton) {
			QPoint clickPos = ev->pos();
			int elipseWidth = 40;
			int elipseHeight = 40;
			int x = 50-elipseWidth/2;
			qDebug() << x;
			int y = height() - elipseHeight/2- 30;
			qDebug() << y;
			for (int i = 0; i < roti; i++)
			{
				QRect ellipseRect(x+=50, y, elipseWidth, elipseHeight);
				if (ellipseRect.contains(clickPos))
				{
					QMessageBox::warning(this, "ta", "sdas");
					serv.modifica_tractor_service(ID);
					roti -= 2;
					model->setList(serv.get_all_service());
					update();
					break;
				}
			}
		}
		reloadList(serv.get_all_service());
		repaint();
	}

	void paintEvent(QPaintEvent* ev) override {
		QPainter painter{ this };
		QPen pen(Qt::white, 2);
		painter.setPen(pen);
		int radius = 20;
		int x = 50;
		int y = height() - 30;
		for(int i = 0; i <roti;i++)
			painter.drawEllipse(QPoint(x += 50, y), radius, radius);
	}
public:
	GUI(ServiceTractoare& service) : serv{ service } {
		initGUI();
		connectSlots();
		reloadList(serv.get_all_service());
	}
};