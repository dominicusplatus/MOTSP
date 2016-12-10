#include "tspdualsolverresultsurfaceviewmodel.h"


TspDualSolverResultSurfaceViewModel::TspDualSolverResultSurfaceViewModel(QObject *parent) : QAbstractListModel(parent)
{
   // m_vertices = QList<QSurfaceModelResultVertexTsp>();
}

 QHash<int, QByteArray> TspDualSolverResultSurfaceViewModel::roleNames() const
 {
     QHash<int, QByteArray> roles;
        roles[Length] = "length";
        roles[Cost] = "cost";
        roles[Generation] = "generation";
        return roles;
 }

QVariant TspDualSolverResultSurfaceViewModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    QString qs = "testdata";
    if(role==Length){
        qs = "length";
    }
    else if ( role== Cost){
        qs = "cost";
    }
    else if (role == Generation )
    {
      qs = "generation";
    }
    QVariant qv(qs);

    return qv;
}

bool TspDualSolverResultSurfaceViewModel::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role)
{
    if (value != headerData(section, orientation, role)) {
        emit headerDataChanged(orientation, section, section);
        return true;
    }
    return false;
}

int TspDualSolverResultSurfaceViewModel::rowCount(const QModelIndex &parent) const
{
    //if (!parent.isValid())
  //      return 0;

     return m_vertices.size();

     //MORouteGraph::size();


     /*
    if(parent.data == "length"){
        return MORouteGraph::size();
    }
    else if (parent.data == "cost"){
        return MORouteGraph::size();
    }
    else if (parent.data == "generation"){
        return tspGenerations;
    }
*/
   //return TspRoutePopulationsHistory.size();
}


void TspDualSolverResultSurfaceViewModel::reloadVertices()
{
    m_vertices.clear();
    TspDualEval eval;

    for (unsigned geninc = 0; geninc<TspRoutePopulationsHistory.size();geninc++)
    {
        eoPop<TspDRoute> pop =  TspRoutePopulationsHistory[geninc];
        for (unsigned popinc = 0; popinc<pop.size();popinc++)
        {
            QSurfaceModelResultVertexTsp* vert = new QSurfaceModelResultVertexTsp();
            vert->setGeneration(geninc);
            TspDRoute route = pop[popinc];
            double rcost = eval.cost(route);
            double rlength = eval.length(route);
            vert->setCost(rcost);
            vert->setLength(rlength);
            m_vertices.push_back(vert);
        }
    }

}

QVariant TspDualSolverResultSurfaceViewModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= m_vertices.count())
           return QVariant();

    QVariant res;
    QSurfaceModelResultVertexTsp* vert = m_vertices[index.row()];

    if(role==Length){
        res =vert->getLength();   //eval.length(pop[index.row()]);
    }
    else if ( role== Cost){
        res = vert->getCost(); //eval.cost(pop[index.row()]);
    }
    else if (role == Generation )
    {
        res = vert->getGeneration();        //index.row();
    }
    return res;
}

void TspDualSolverResultSurfaceViewModel::updateData()
{
    this->beginResetModel();
        reloadVertices();
    this->endResetModel();
}




/*
bool TspDualSolverResultSurfaceViewModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (data(index, role) != value) {
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}

Qt::ItemFlags TspDualSolverResultSurfaceViewModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable;
}
*/




