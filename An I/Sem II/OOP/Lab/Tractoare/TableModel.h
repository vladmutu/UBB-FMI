#pragma once

#include <QtWidgets>
#include "domain.h"
#include <vector>
#include <unordered_map>
using namespace std;

class TableModel : public QAbstractTableModel {
private:
	vector<Tractor> tractoare;
	string tip;
public:
	TableModel(QObject* parent) : QAbstractTableModel(parent) {

	}

	int rowCount(const QModelIndex& parent = QModelIndex()) const override {
		return (int)(tractoare.size());
	}

	int columnCount(const QModelIndex& parent = QModelIndex()) const override {
		return 5;
	}

	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override {
		const int row = index.row();
		const int col = index.column();
		if (role == Qt::DisplayRole)
		{
			switch (index.column()) {
				case 0:
					return QString::fromStdString(to_string(tractoare.at(row).get_id()));
				case 1:
					return QString::fromStdString(tractoare.at(row).get_denumire());
				case 2:
					return QString::fromStdString(tractoare.at(row).get_tip());
				case 3:
					return QString::fromStdString(to_string(tractoare.at(row).get_roti()));
				case 4:
					int k = 0;
					Tractor tractor = tractoare.at(row);
					for (auto& t : tractoare) {
						if (t.get_tip() == tractor.get_tip())
							k++;
					}
					return QString::fromStdString(to_string(k));
			}
		}
		else if (role == Qt::BackgroundRole && tractoare.at(row).get_tip() == tip)
		{
			return QBrush(Qt::red);
		}
		return QVariant();
	}

	void setList(const vector<Tractor>& tractoare) {
		this->tractoare = tractoare;
		const QModelIndex topLeft = createIndex(0, 0);
		const QModelIndex bottomRight = createIndex(rowCount(), columnCount());
		emit dataChanged(topLeft, bottomRight);
		emit layoutChanged();
	}

	void setTip(const string& tip) {
		this->tip = tip;
		qDebug() << this->tip;
	}
};