//
// Created by vladm on 6/21/2024.
//

#ifndef MELODIIQT_TABLEMODEL_H
#define MELODIIQT_TABLEMODEL_H
#include <QtWidgets>
#include "domain.h"
#include <vector>

using namespace std;

class TableModel : public QAbstractTableModel{
private:
    vector<Melodie> melodii;
public:
    explicit TableModel(QObject* parent) : QAbstractTableModel{parent} {

    }

    int rowCount(const QModelIndex &parent = QModelIndex()) const override{
        return (int)(melodii.size());
    }

    int columnCount(const QModelIndex &parent = QModelIndex()) const override{
        return 5;
    }

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override{
        const int row = rowCount();
        const int col = columnCount();
        if(role == Qt::DisplayRole){
            switch(index.column()){
                case 0:
                    return QString::fromStdString(to_string(melodii.at(row).get_id()));
                case 1:
                    return QString::fromStdString(melodii.at(row).get_titlu());
                case 2:
                    return QString::fromStdString(melodii.at(row).get_artist());
                case 3:
                    return QString::fromStdString(to_string(melodii.at(row).get_rank()));
                case 4:
                    Melodie m = melodii.at(row);
                    int k = 0;
                    for(auto melodie : melodii)
                        if(m.get_rank() == melodie.get_rank())
                            k++;
                    return QString::fromStdString(to_string(k));
            }
            return QString("R%1, C%2").arg(index.row()+1).arg(index.column()+1);
        }
        return QVariant();
    }

    void setList(vector<Melodie>& melodii){
        this->melodii = melodii;
        const QModelIndex topLeft = createIndex(0, 0);
        const QModelIndex bottomRight = createIndex(rowCount(), columnCount());
        emit dataChanged(topLeft, bottomRight);
        emit layoutChanged();
    }
};

#endif //MELODIIQT_TABLEMODEL_H
