//
// Created by vladm on 5/29/2024.
//

#ifndef LAB13_14_MODELS_H
#define LAB13_14_MODELS_H
#include <QtWidgets>
#include <QApplication>
#include "domain.h"
#include <vector>

#define ROWS 100
#define COLS 4

using std::vector;


class TableModel : public QAbstractTableModel {
private:
    vector<Masina> masini;
public:
    TableModel(QObject* parent) : QAbstractTableModel{ parent } {

    }
    int rowCount(const QModelIndex &parent = QModelIndex()) const override {
        return (int)(masini.size());
    }
    int columnCount(const QModelIndex &parent = QModelIndex()) const override {
        return COLS;
    }
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override {
        const int row = index.row();
        const int col = index.column();
        if (role == Qt::DisplayRole) {
            switch (index.column()) {
                case 0:
                    return QString::fromStdString(masini.at(row).get_nr_inmatriculare());
                case 1:
                    return QString::fromStdString(masini.at(row).get_producator());
                case 2:
                    return QString::fromStdString(masini.at(row).get_model());
                case 3:
                    return QString::fromStdString(masini.at(row).get_tip());
            }
            return QString("R%1, C%2").arg(index.row() + 1).arg(index.column() + 1);
        }
        return QVariant();
    }
    void setList(const vector<Masina>& masini) {
        this->masini = masini;
        const QModelIndex topLeft = createIndex(0, 0);
        const QModelIndex bottomRight = createIndex(rowCount(), columnCount());
        emit dataChanged(topLeft, bottomRight);
        emit layoutChanged();
    }
};
#endif //LAB13_14_MODELS_H
