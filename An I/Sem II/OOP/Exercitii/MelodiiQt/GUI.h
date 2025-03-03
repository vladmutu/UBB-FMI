#include "service.h"
#include <QtWidgets>
#include <QApplication>
#include "TableModel.h"

class GUI : public QWidget{
private:
    ServiceMelodii& serv;
    QHBoxLayout* mainLayout = new QHBoxLayout{};
    QTableView* tabel = new QTableView{};
    TableModel* tableModel = new TableModel{tabel};
    QWidget* adauga = new QWidget{};
    QFormLayout* linesAdauga = new QFormLayout{};
    QLineEdit* lineId = new QLineEdit{};
    linesAdauga->addWidget(lineID);
public:
    void initGUI(){
        this->setLayout(mainLayout);
        mainLayout->addWidget(tabel);
        tabel->setModel(tableModel);
    }
    void reloadList(){
        tableModel->setList(serv.get_all_service());
    }

    GUI(ServiceMelodii& serv) : serv{serv} {
        initGUI();
        reloadList();
    }

    ~GUI() = default;
};