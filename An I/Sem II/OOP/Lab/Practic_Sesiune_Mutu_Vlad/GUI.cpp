#include "GUI.h"

void GUI::initGUI()
{
	setLayout(mainLayout);

	tableUtilaje->setModel(model);

	
	horLayout->addWidget(tableUtilaje);

	layoutUpdate->addWidget(labelDenumire);
	layoutUpdate->addWidget(lineDenumire);
	layoutUpdate->addWidget(labelTip);
	layoutUpdate->addWidget(lineTip);
	layoutUpdate->addWidget(i);
	layoutUpdate->addWidget(cilindru1);
	layoutUpdate->addWidget(ii);
	layoutUpdate->addWidget(cilindru2);
	layoutUpdate->addWidget(iii);
	layoutUpdate->addWidget(cilindru4);
	layoutUpdate->addWidget(iiii);
	layoutUpdate->addWidget(cilindru8);
	layoutUpdate->addWidget(updateBtn);
	layoutUpdate->addWidget(deleteBtn);

	horLayout->addLayout(layoutUpdate);

	mainLayout->addLayout(horLayout);
	mainLayout->addWidget(btnExit);
	mainLayout->addWidget(emptyLabel1);
	mainLayout->addWidget(emptyLabel2);
	mainLayout->addWidget(emptyLabel3);
	mainLayout->addWidget(emptyLabel4);
	mainLayout->addWidget(emptyLabel5);
	this->resize(1500, 1000);
}

void GUI::connectSignals()
{
	connect(btnExit, &QPushButton::clicked, [this]() {
		this->close();
		});
	connect(updateBtn, &QPushButton::clicked, [this]() {
		string denumire = lineDenumire->text().toStdString();
		string tip = lineTip->text().toStdString();
		try {
			service.modifica_utilaj_service(ID, denumire, tip, nr_cilindrii);
			reloadList(service.get_all_service());
		}
		catch (ServiceException& e) {
			QMessageBox::warning(this, "Warnign", QString::fromStdString(e.get_msg()));
		}
		});
	connect(cilindru1, &QRadioButton::clicked, [this]() {
		nr_cilindrii = 1;
		});
	connect(cilindru2, &QRadioButton::clicked, [this]() {
		nr_cilindrii = 2;
		});
	connect(cilindru4, &QRadioButton::clicked, [this]() {
		nr_cilindrii = 4;
		});
	connect(cilindru8, &QRadioButton::clicked, [this]() {
		nr_cilindrii = 8;
		});
	connect(tableUtilaje->selectionModel(), &QItemSelectionModel::selectionChanged, [this]() {
		QModelIndexList selectedIndex = tableUtilaje->selectionModel()->selectedIndexes();
		int currentRow = selectedIndex.first().row();
		ID = model->data(model->index(currentRow, 0)).toInt();
		});

	connect(deleteBtn, &QPushButton::clicked, [this]() {
		try {
			service.sterge_utilaj_service(ID);
			reloadList(service.get_all_service());
		}
		catch (ServiceException& e)
		{
			QMessageBox::warning(this, "Warning", QString::fromStdString(e.get_msg()));
		}
		});
}

void GUI::reloadList(const vector<Utilaj>& utilaje)
{
	model->setList(utilaje);
	repaint();
}
