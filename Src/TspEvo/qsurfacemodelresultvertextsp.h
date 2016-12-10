#ifndef QSURFACEMODELRESULTVERTEXTSP_H
#define QSURFACEMODELRESULTVERTEXTSP_H


#include <QObject>
#include "QVector"
#include <QtCore/QAbstractTableModel>
#include <QtCore/QHash>
#include <QtCore/QRect>

class QSurfaceModelResultVertexTsp : public QObject
{
    Q_OBJECT
      Q_PROPERTY(double length  READ getLength WRITE setLength NOTIFY lengthChanged)
      Q_PROPERTY(double cost READ getCost WRITE setCost NOTIFY costChanged)
      Q_PROPERTY(double generation READ getGeneration WRITE setGeneration NOTIFY generationChanged)
public:
    QSurfaceModelResultVertexTsp(QObject *parent = 0);
    //QSurfaceModelResultVertexTsp();


    void setLength(double a) {
            m_length = a;
            emit lengthChanged();
    }

    double getLength() const {
            return m_length;
    }


    void setCost(double a) {
            m_cost = a;
            emit costChanged();
    }

    double getCost() const {
            return m_cost;
    }


    void setGeneration(double a) {
            m_generation = a;
            emit generationChanged();
    }

    double getGeneration() const {
            return m_generation;
    }

signals:
    void lengthChanged();
    void costChanged();
    void generationChanged();


private:
    double m_length;
    double m_cost;
    double m_generation;

};

#endif // QSURFACEMODELRESULTVERTEXTSP_H
