#include "GUI.h"
#include <vector>
#include "domain.h"
#include <unordered_map>
using namespace std;

void GUI::initGUI()
{
	setLayout(mainLayout);
	mainLayout->addLayout(layoutListaSiButoane);
	tableTractoare->setModel(model);
	layoutListaSiButoane->addWidget(tableTractoare);
	
	adaugaLayoutWidget->setLayout(adaugaLayout);
	layoutListaSiButoane->addWidget(adaugaLayoutWidget);
	adaugaLayout->addWidget(lblID);
	adaugaLayout->addWidget(lineID);
	adaugaLayout->addWidget(lblDenumire);
	adaugaLayout->addWidget(lineDenumire);
	adaugaLayout->addWidget(lblTip);
	adaugaLayout->addWidget(lineTip);
	adaugaLayout->addWidget(lblRoti);
	adaugaLayout->addWidget(lineRoti);
	adaugaLayout->addWidget(btnAdauga);
	
	layoutListaSiButoane->addWidget(btnExit);

	layoutListaSiButoane->addWidget(combobox);
	layoutListaSiButoane->addWidget(emptyLabel1);
	layoutListaSiButoane->addWidget(emptyLabel2);
	layoutListaSiButoane->addWidget(emptyLabel3);
	layoutListaSiButoane->addWidget(emptyLabel4);
	this->resize(1600, 1000);
}

void GUI::connectSlots()
{
	QObject::connect(btnExit, &QPushButton::clicked, [this]() {
		this->close();
		});

	QObject::connect(btnAdauga, &QPushButton::clicked, [this]() {
		int id;
		try {
			bool ok;
			id = lineID->text().toInt(&ok);
			if (!ok)
				throw TractorException("Introduceti un id valid!");
		}
		catch (TractorException& ex) {
			QMessageBox::warning(this, "Warning", QString::fromStdString(ex.get_msg()));
		}
		string denumire = lineDenumire->text().toStdString();
		string tip = lineTip->text().toStdString();
		int roti;
		try {
			bool ok;
			roti = lineRoti->text().toInt(&ok);
			if (!ok)
				throw TractorException("Introduceti un rank valid!");
		}
		catch (TractorException& ex) {
			QMessageBox::warning(this, "Warning", QString::fromStdString(ex.get_msg()));
		}
		try {
			serv.adauga_tractor_service(id, denumire, tip, roti);
			reloadList(serv.get_all_service());
		}
		catch (ServiceException& ex) {
			QMessageBox::warning(this, "Warning", QString::fromStdString(ex.get_msg()));
		}
		reloadList(serv.get_all_service());
		});
	QObject::connect(combobox, &QComboBox::currentIndexChanged, [this](){
		tip = combobox->currentText().toStdString();
		model->setTip(tip);
		model->setList(serv.get_all_service());
		});

	QObject::connect(tableTractoare->selectionModel(), &QItemSelectionModel::selectionChanged, [this]() {
		QModelIndexList selectedIndex = tableTractoare->selectionModel()->selectedIndexes();
		int currentRow = selectedIndex.first().row();
		ID = model->data(model->index(currentRow, 0)).toInt();
		for (auto& t : serv.get_all_service())
		{
			if (t.get_id() == ID)
				roti = t.get_roti();
		}
		qDebug() << roti;
		repaint();
		});
}


void GUI::reloadList(const vector<Tractor>& tractoare)
{
	combobox->clear();
	model->setList(tractoare);
	unordered_map<string, int> rez;
	for (auto& tractor : tractoare)
	{
		rez[tractor.get_tip()]++;
	}
	for (auto& pair : rez)
	{
		combobox->addItem(QString::fromStdString(pair.first), QString::fromStdString(to_string(pair.second)));
	}
}
