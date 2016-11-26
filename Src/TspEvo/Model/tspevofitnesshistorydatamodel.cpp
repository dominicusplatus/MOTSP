#include "tspevofitnesshistorydatamodel.h"
#include <QtCore/QVector>
#include <QtCore/QTime>
#include <QtCore/QRect>
#include <QtGui/QColor>
#include "tspevosolverviewmodel.h"

TspEvoFitnessHistoryDataModel::TspEvoFitnessHistoryDataModel(QObject *parent) : QAbstractTableModel(parent)
{

    /*
    TspEvoSolverViewModel model;
    model.Solve();

    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));

    m_columnCount = 2;
    m_rowCount = model.m_data.count();

    for (int i = 0; i < m_rowCount; i++) {

       // QVector<qreal>* dataVec = new QVector<qreal>(m_columnCount);
       // dataVec[0] = model.m_data[i];
       // m_data.append(dataVec);
        m_data.append(model.m_data[i]);
    }
    */
}

void TspEvoFitnessHistoryDataModel::bindToModel( QList<QVector<qreal>> data)
{
    m_columnCount = 2;
    m_rowCount = data.count();
    m_data = data;
}

int TspEvoFitnessHistoryDataModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_data.count();
}

int TspEvoFitnessHistoryDataModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_columnCount;
}

QVariant TspEvoFitnessHistoryDataModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal) {
        if (section % 2 == 0)
            return "x";
        else
            return "y";
    } else {
        return QString("%1").arg(section + 1);
    }
}

QVariant TspEvoFitnessHistoryDataModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole) {
        return m_data[index.row()][index.column()];     //->at(index.column());
    } else if (role == Qt::EditRole) {
        return m_data[index.row()][index.column()]; //->at(index.column());
    } else if (role == Qt::BackgroundRole) {
        foreach (QRect rect, m_mapping) {
            if (rect.contains(index.column(), index.row()))
                return QColor(m_mapping.key(rect));
        }
        // cell not mapped return white color
        return QColor(Qt::white);
    }
    return QVariant();
}

bool TspEvoFitnessHistoryDataModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid() && role == Qt::EditRole) {
        m_data[index.row()][index.column()] =  value.toDouble();
        emit dataChanged(index, index);
        return true;
    }
    return false;
}

Qt::ItemFlags TspEvoFitnessHistoryDataModel::flags(const QModelIndex &index) const
{
    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}

void TspEvoFitnessHistoryDataModel::addMapping(QString color, QRect area)
{
    m_mapping.insertMulti(color, area);
}



