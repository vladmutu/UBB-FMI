#include "GUI.h"
#include <QtWidgets>
#include <qobject.h>
#include "SpalatorieGUI.h"

void GUI::initGUI()
{
    setLayout(mainLayout);
    initButtons();
    QVBoxLayout* layoutDreapta = new QVBoxLayout;
    QWidget* windowDetalii = new QWidget;
    QFormLayout* formLayoutDetalii = new QFormLayout;
    tabelMasini->setModel(tableModel);
    layoutDreapta->addWidget(tabelMasini);
    layoutDreapta->addWidget(listaMasini);

    //creaza mi un algotitm de sortare


    btnAdauga = new QPushButton{ "Adauga" };
    btnSterge = new QPushButton{ "Sterge" };
    btnModifica = new QPushButton{ "Modifica" };
    btnFiltrare = new QPushButton{ "Filtrare" };
    btnSortare = new QPushButton{ "Sortare" };
    btnSpalatorie = new QPushButton{ "Spalatorie" };
    btnSpalatorieLabelEdit = new QPushButton{ "Spalatorie Label Window" };
    btnSpalatorieDraw = new QPushButton{ "Spalatorie Draw Window" };
    btnRaport = new QPushButton{ "Raport" };
    btnUndo = new QPushButton{ "Undo" };
    btnExit = new QPushButton{ "Exit" };

    formLayoutDetalii->addWidget(btnAdauga);
    formLayoutDetalii->addWidget(btnSterge);
    formLayoutDetalii->addWidget(btnModifica);
    formLayoutDetalii->addWidget(btnFiltrare);
    formLayoutDetalii->addWidget(btnSortare);
    formLayoutDetalii->addWidget(btnSpalatorie);
    formLayoutDetalii->addWidget(btnSpalatorieLabelEdit);
    formLayoutDetalii->addWidget(btnSpalatorieDraw);
    formLayoutDetalii->addWidget(btnRaport);
    formLayoutDetalii->addWidget(btnUndo);
    formLayoutDetalii->addWidget(btnExit);

    windowDetalii->setLayout(formLayoutDetalii);

    mainLayout->addWidget(windowDetalii);
    this->resize(800, 600);
    mainLayout->addLayout(layoutDreapta);
    mainLayout->addLayout(btnsLayout);
}

void GUI::connectSignals()
{
    QObject::connect(btnAdauga, &QPushButton::clicked, this, &GUI::adaugaMasina);
    QObject::connect(btnSterge, &QPushButton::clicked, this, &GUI::stergeMasina);
    QObject::connect(btnModifica, &QPushButton::clicked, this, &GUI::modificaMasina);
    QObject::connect(btnFiltrare, &QPushButton::clicked, this, &GUI::filtrare);
    QObject::connect(btnSortare, &QPushButton::clicked, this, &GUI::sortare);
    QObject::connect(btnSpalatorie, &QPushButton::clicked, [this]() {
        SpalatorieGUI* spalatorieGUI = new SpalatorieGUI{ service };
        spalatorieGUI->show();
    });
    QObject::connect(btnSpalatorieLabelEdit, &QPushButton::clicked, this, [&]() {
        SpalatorieLabelEditGUI* spalatorieLabelEditGUI = new SpalatorieLabelEditGUI{ service.getSpalatorie() };
        spalatorieLabelEditGUI->show();
    });
    QObject::connect(btnSpalatorieDraw, &QPushButton::clicked, this, [&]() {
        SpalatorieDrawGUI* spalatorieDrawGUI = new SpalatorieDrawGUI{ service.getSpalatorie() };
        spalatorieDrawGUI->show();
    });
    QObject::connect(btnRaport, &QPushButton::clicked, this, &GUI::raport);
    QObject::connect(btnUndo, &QPushButton::clicked, this, &GUI::undo);
    QObject::connect(btnExit, &QPushButton::clicked, this, &GUI::exit);
}

void GUI::reloadList(vector<Masina> masini)
{
    for(int i = 0; i < masini.size(); i++)
    {
        QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(masini[i].get_nr_inmatriculare() + "," + masini[i].get_producator() + "," + masini[i].get_model() + "," + masini[i].get_tip()));
        this->listaMasini->addItem(item);
    }
    tableModel->setList(masini);
    initButtons();
}

void GUI::adaugaMasina()
{
    QDialog* dialog = new QDialog{};
    QFormLayout* formLayout = new QFormLayout{};
    QLineEdit* lineNrInmatriculare = new QLineEdit{};
    QLineEdit* lineProducator = new QLineEdit{};
    QLineEdit* lineModel = new QLineEdit{};
    QLineEdit* lineTip = new QLineEdit{};
    QPushButton* btnAdauga = new QPushButton{ "Adauga" };
    formLayout->addRow("Nr inmatriculare", lineNrInmatriculare);
    formLayout->addRow("Producator", lineProducator);
    formLayout->addRow("Model", lineModel);
    formLayout->addRow("Tip", lineTip);
    formLayout->addRow(btnAdauga);
    QObject::connect(btnAdauga, &QPushButton::clicked, [this, dialog, lineNrInmatriculare, lineProducator, lineModel, lineTip](){
        std::string nr_inmatriculare = lineNrInmatriculare->text().toStdString();
        std::string producator = lineProducator->text().toStdString();
        std::string model = lineModel->text().toStdString();
        std::string tip = lineTip->text().toStdString();
        try {
            service.adaugaMasinaService(nr_inmatriculare, producator, model, tip);
            reloadList(service.getAllMasiniService());
        }
        catch (ServiceException& e) {
            QMessageBox::information(this, "Warning", QString::fromStdString(e.get_msg()));
        }
        catch (RepoException& e) {
            QMessageBox::information(this, "Warning", QString::fromStdString(e.get_msg()));
        }
        catch (MasinaException& e) {
            QMessageBox::information(this, "Warning", QString::fromStdString(e.get_msg()));
        }
        dialog->close();
    });
    dialog->setLayout(formLayout);
    dialog->show();
}

void GUI::stergeMasina()
{
    QDialog* dialog = new QDialog{};
    QFormLayout* formLayout = new QFormLayout{};
    QLineEdit* lineNrInmatriculare = new QLineEdit{};
    QPushButton* btnSterge = new QPushButton{ "Sterge" };
    formLayout->addRow("Nr inmatriculare", lineNrInmatriculare);
    formLayout->addRow(btnSterge);
    QObject::connect(btnSterge, &QPushButton::clicked, [this, dialog, lineNrInmatriculare]() {
        std::string nr_inmatriculare = lineNrInmatriculare->text().toStdString();
        try {
            service.stergeMasinaService(nr_inmatriculare);
            reloadList(service.getAllMasiniService());
        }
        catch (ServiceException& e) {
            QMessageBox::information(this, "Warning", QString::fromStdString(e.get_msg()));
        }
        catch (RepoException& e) {
            QMessageBox::information(this, "Warning", QString::fromStdString(e.get_msg()));
        }
        catch (MasinaException& e) {
            QMessageBox::information(this, "Warning", QString::fromStdString(e.get_msg()));
        }
        dialog->close();
    });
    dialog->setLayout(formLayout);
    dialog->show();
}

void GUI::modificaMasina()
{
    QDialog* dialog = new QDialog{};
    QFormLayout* formLayout = new QFormLayout{};
    QLineEdit* lineNrInmatriculare = new QLineEdit{};
    QLineEdit* lineProducator = new QLineEdit{};
    QLineEdit* lineModel = new QLineEdit{};
    QLineEdit* lineTip = new QLineEdit{};
    QPushButton* btnModifica = new QPushButton{ "Modifica" };
    formLayout->addRow("Nr inmatriculare", lineNrInmatriculare);
    formLayout->addRow("Producator", lineProducator);
    formLayout->addRow("Model", lineModel);
    formLayout->addRow("Tip", lineTip);
    formLayout->addRow(btnModifica);
    QObject::connect(btnModifica, &QPushButton::clicked, [this, dialog, lineNrInmatriculare, lineProducator, lineModel, lineTip]() {
        std::string nr_inmatriculare = lineNrInmatriculare->text().toStdString();
        std::string producator = lineProducator->text().toStdString();
        std::string model = lineModel->text().toStdString();
        std::string tip = lineTip->text().toStdString();
        try {
            service.modificaMasinaService(nr_inmatriculare, producator, model, tip);
            reloadList(service.getAllMasiniService());
        }
        catch (ServiceException& e) {
            QMessageBox::information(this, "Warning", QString::fromStdString(e.get_msg()));
        }
        catch (RepoException& e) {
            QMessageBox::information(this, "Warning", QString::fromStdString(e.get_msg()));
        }
        catch (MasinaException& e) {
            QMessageBox::information(this, "Warning", QString::fromStdString(e.get_msg()));
        }
        dialog->close();
    });
    dialog->setLayout(formLayout);
    dialog->show();
}

void GUI::sortare()
{
    QDialog* dialog = new QDialog{};
    QFormLayout* formLayout = new QFormLayout{};
    QPushButton* btnSortareNrInmatriculare = new QPushButton{ "Sortare numar de inmatriculare" };
    QPushButton* btnSortareTip = new QPushButton{ "Sortare dupa tip" };
    QPushButton* btnSortareProducatorModel = new QPushButton{ "Sortare dupa producator si model" };
    formLayout->addRow(btnSortareNrInmatriculare);
    formLayout->addRow(btnSortareTip);
    formLayout->addRow(btnSortareProducatorModel);
    dialog->setLayout(formLayout);
    dialog->show();
    QDialog* window2 = new QDialog;
    QListWidget* sorted = new QListWidget;
    QFormLayout* formLayout2 = new QFormLayout;
    QPushButton* btnClose = new QPushButton("Close");
    formLayout2->addRow(sorted);
    formLayout2->addRow(btnClose);
    window2->setLayout(formLayout2);
    QObject::connect(btnClose, &QPushButton::clicked, [window2]() {
        window2->close();
    });
    QObject::connect(btnSortareNrInmatriculare, &QPushButton::clicked, [this, window2, sorted]() {
        window2->setWindowTitle("Sortare dupa numar de inmatriculare");
        vector<Masina> masini = service.sortMasini(sortNrInmatriculare);
        reloadList(masini);
        window2->show();
    });
    QObject::connect(btnSortareTip, &QPushButton::clicked, [this, window2, sorted]() {
        window2->setWindowTitle("Sortare dupa tip");
        vector<Masina> masini = service.sortMasini(sortTip);
        reloadList(masini);
        window2->show();
    });
    QObject::connect(btnSortareProducatorModel, &QPushButton::clicked, [this, window2, sorted]() {
        window2->setWindowTitle("Sortare dupa producator si model");
        vector<Masina> masini = service.sortMasini(sortProducatorModel);
        reloadList(masini);
        window2->show();
    });
}

void GUI::undo()
{
    try {
        service.undo();
        reloadList(service.getAllMasiniService());
    }
    catch (ServiceException& e) {
        QMessageBox::information(this, "Warning", QString::fromStdString(e.get_msg()));
    }
    catch (RepoException& e) {
        QMessageBox::information(this, "Warning", QString::fromStdString(e.get_msg()));
    }
    catch (MasinaException& e) {
        QMessageBox::information(this, "Warning", QString::fromStdString(e.get_msg()));
    }
}

void GUI::raport()
{
    QDialog* newWindow = new QDialog;
    newWindow->setWindowTitle("Raportare");
    QFormLayout* formLayout = new QFormLayout;
    QListWidget* lst_to_print = new QListWidget;
    QPushButton* btnOk = new QPushButton("Ok");
    formLayout->addRow(lst_to_print);
    formLayout->addRow(btnOk);
    newWindow->setLayout(formLayout);
    newWindow->show();
    QObject::connect(btnOk, &QPushButton::clicked, [newWindow]() {
        newWindow->close();
    });

    lst_to_print->clear();
    unordered_map<string, int> raport;
    service.filterWithMap(raport);
    for (const auto& r : raport) {
        QListWidgetItem* item = new QListWidgetItem(QString::fromStdString("Tip: " + r.first + " Numar masini de acest tip: " + std::to_string(r.second)));
        lst_to_print->addItem(item);
    }
}

void GUI::filtrare()
{
    QDialog* newWindow = new QDialog;
    newWindow->resize(200, 200);
    newWindow->setWindowTitle("Filter films");
    QFormLayout* formLayout = new QFormLayout;
    QPushButton* btn_filter_by_producator = new QPushButton("Filter dupa producator");
    QPushButton* btn_filter_by_tip = new QPushButton("Filtrare dupa tip");
    formLayout->addRow(btn_filter_by_producator);
    formLayout->addRow(btn_filter_by_tip);
    newWindow->setLayout(formLayout);
    newWindow->show();

    QObject::connect(btn_filter_by_producator, &QPushButton::clicked, [this, newWindow]() {
        QDialog* newWindow2 = new QDialog;
        newWindow2->setWindowTitle("Filter by producator");
        QFormLayout* formLayout = new QFormLayout;
        QListWidget* filtered = new QListWidget;
        QLineEdit* txtGen = new QLineEdit;
        QPushButton* btnOk = new QPushButton("Ok");
        QPushButton* closeButton = new QPushButton("Close");
        formLayout->addRow(new QLabel("Producator:"), txtGen);
        formLayout->addRow(btnOk);
        formLayout->addRow(closeButton);
        formLayout->addRow(filtered);
        newWindow2->setLayout(formLayout);
        newWindow2->show();
        newWindow->close();
        QObject::connect(closeButton, &QPushButton::clicked, [newWindow2]() {
            newWindow2->close();
        });
        QObject::connect(btnOk, &QPushButton::clicked, [this, newWindow, filtered, txtGen]() {
            std::string gen = txtGen->text().toStdString();
            string txt_filter = txtGen->text().toStdString();
            vector<Masina> masini = service.filterMasiniProducer(txt_filter);
            reloadList(masini);
        });
    });

    QObject::connect(btn_filter_by_tip, &QPushButton::clicked, [this, newWindow]() {
        QDialog* newWindow2 = new QDialog;
        newWindow2->setWindowTitle("Filter by tip");
        QFormLayout* formLayout = new QFormLayout;
        QListWidget* filtered = new QListWidget;
        QLineEdit* txtTip = new QLineEdit;
        QPushButton* btnOk = new QPushButton("Ok");
        QPushButton* closeButton = new QPushButton("Close");
        formLayout->addRow(new QLabel("tip:"), txtTip);
        formLayout->addRow(btnOk);
        formLayout->addRow(closeButton);
        formLayout->addRow(filtered);
        newWindow2->setLayout(formLayout);
        newWindow2->show();
        newWindow->close();
        QObject::connect(closeButton, &QPushButton::clicked, [newWindow2]() {
            newWindow2->close();
        });
        //QObject::connect(closeButton, &QPushButton::clicked,[newWindow2], QDialog::reject);

        QObject::connect(btnOk, &QPushButton::clicked, [this, newWindow, filtered, txtTip]() {
            std::string tip = txtTip->text().toStdString();
            string txt_filter = txtTip->text().toStdString();
            vector<Masina> masini = service.filterMasiniType(txt_filter);
            reloadList(masini);
        });
    });
}

void GUI::exit()
{
    this->close();
}

void GUI::initButtons()

{
    QLayoutItem* item;
    while ((item = btnsLayout->takeAt(0)) != nullptr)
    {
        delete item->widget();
        delete item;
    }

    unordered_map<string, int> raport;
    raport.clear();
    service.filterWithMap(raport);
    for (auto& pair : raport)
    {
        QPushButton* btn = new QPushButton(QString::fromStdString(pair.first));
        btnsLayout->addWidget(btn);
        QObject::connect(btn, &QPushButton::clicked, [pair]() { QMessageBox::information(nullptr, "Info", QString::number(pair.second)); });
    }
}