#include "SpalatorieGUI.h"

void SpalatorieGUI::initializeGUIComponents()
{
	mainLayout = new QHBoxLayout;
	this->setLayout(mainLayout);
	QWidget* leftWidget = new QWidget;
	leftLayout = new QVBoxLayout;
	leftWidget->setLayout(leftLayout);

	addFormLayout = new QFormLayout;
	addFormWidget = new QWidget;
	addFormWidget->setLayout(addFormLayout);
	labelNrInmatriculare = new QLabel{ "Numar inmatriculare" };
	editNrInmatriculare = new QLineEdit;
	addBtn = new QPushButton{ "Adauga" };
	addFormLayout->addRow(labelNrInmatriculare, editNrInmatriculare);
	addFormLayout->addWidget(addBtn);

	leftLayout->addWidget(addFormWidget);

	sliderAddRandom = new QSlider;
	sliderAddRandom->setMaximum(100);
	sliderAddRandom->setMinimum(1);
	editValueSlider = new QLineEdit;


	addRandomBtn = new QPushButton{ "Adaugare masini random" };
	leftLayout->addWidget(sliderAddRandom);
	leftLayout->addWidget(editValueSlider);
	leftLayout->addWidget(addRandomBtn);
	clearSpalatorieBtn = new QPushButton{ "Golire spalatorie" };
	leftLayout->addWidget(clearSpalatorieBtn);

	closeWindowBtn = new QPushButton{ "Inchidere fereastra" };
	leftLayout->addWidget(closeWindowBtn);

	mainLayout->addWidget(leftWidget);

	masiniList = new QListWidget;
	mainLayout->addWidget(masiniList);
}

void SpalatorieGUI::connectSignalsSlots()
{
	connect(addBtn, &QPushButton::clicked, this, &SpalatorieGUI::addByTitleAndArtist);
	QObject::connect(addRandomBtn, &QPushButton::clicked, this, [&]() {
		int sliderValue = sliderAddRandom->value();
		srv.generateRandom(sliderValue);
		reloadData(srv.getAllSpalatorie());
		});
	QObject::connect(clearSpalatorieBtn, &QPushButton::clicked, this, [&]() {
		srv.clearAllSpalatorie();
		reloadData(srv.getAllSpalatorie());
		});
	connect(closeWindowBtn, &QPushButton::clicked, this, &SpalatorieGUI::close);
}

void SpalatorieGUI::addByTitleAndArtist()
{
	string nr_inmatriculare = editNrInmatriculare->text().toStdString();
	srv.addMasinaSpalatorie(nr_inmatriculare);
	reloadData(srv.getAllSpalatorie());
}

void SpalatorieGUI::reloadData(const vector<Masina>& masiniSpalatorie)
{
	masiniList->clear();
	for (const auto& masina : masiniSpalatorie) {
		QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(masina.get_nr_inmatriculare()));
		masiniList->addItem(item);
	}
}
