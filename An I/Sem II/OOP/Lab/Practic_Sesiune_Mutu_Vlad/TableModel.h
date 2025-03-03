#pragma once
#include <QtWidgets>
#include <QWidget>
#include "domain.h"
#include <vector>

using namespace std;

class TableModel : public QAbstractTableModel {
private:
	vector<Utilaj> utilaje;
public:
	TableModel(QObject* parent) : QAbstractTableModel(parent) {

	}
	//returneaza numarul de randuri al tabelului
	int rowCount(const QModelIndex& parent = QModelIndex()) const override {
		return (int)(utilaje.size());
	}
	//returneaza numarul de coloane al tabelului
	int columnCount(const QModelIndex& parent = QModelIndex()) const override {
		return 5;
	}
	//returneaza elementul corespunzator fiecarei celule a tabelului
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override {
		const int row = index.row();
		const int col = index.column();
		if (role == Qt::DisplayRole) {
			switch (index.column())
			{
			case 0:
				return QString::fromStdString(to_string(utilaje.at(row).get_id()));
			case 1:
				return QString::fromStdString(utilaje.at(row).get_denumire());
			case 2:
				return QString::fromStdString(utilaje.at(row).get_tip());
			case 3:
				return QString::fromStdString(to_string(utilaje.at(row).get_cilindrii()));
			case 4:
				int k = 0;
				string tip = utilaje.at(row).get_tip();
				for (auto& u : utilaje)
					if (u.get_tip() == tip)
						k++;
				return QString::fromStdString(to_string(k));
			}
		}
		return QVariant();
	}

	//functie ce seteaza lista tabelului
	void setList(const vector<Utilaj>& u) {
		this->utilaje = u;
		QModelIndex topLeft = createIndex(0, 0);
		QModelIndex bottomRight = createIndex(rowCount()-1, columnCount()-1);
		emit dataChanged(topLeft, bottomRight);
		emit layoutChanged();
	}

};