#ifndef TSPPATHGRAPHVIEW_H
#define TSPPATHGRAPHVIEW_H

#include <QPainter>
#include <QtQuick/QQuickPaintedItem>
#include <QColor>


#include "graph.h"
#include "route.h"

class TspPathGraphView : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(Route graph READ graph WRITE setGraph)

public:
    TspPathGraphView(QQuickItem *parent = 0);

    Route graph() const;
    void setGraph(const Route &name);

    void paint(QPainter *painter);

    void paint(QPainter *painter, QPaintEvent *event, int elapsed);
    bool DrawComplement;
    bool DrawGraph;
private:
    Route m_route;
    QBrush background;
    QBrush circleBrush;
    QFont textFont;
    QPen circlePen;
    QPen textPen;

};

//![0]
//!

#endif // TSPPATHGRAPHVIEW_H
