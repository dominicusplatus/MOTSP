#include "tsppathgraphview.h"

//![0]
TspPathGraphView::TspPathGraphView(QQuickItem *parent): QQuickPaintedItem(parent)
{
    QLinearGradient gradient(QPointF(50, -20), QPointF(80, 20));
       gradient.setColorAt(0.0, Qt::red);
       gradient.setColorAt(1.0, Qt::green);

       background = QBrush(Qt::transparent);
       circleBrush = QBrush(Qt::transparent);

       circlePen = QPen(Qt::black);
       circlePen.setWidth(1);

       textPen = QPen(Qt::cyan);
       textFont.setPointSize(16);
}
//![0]

Route TspPathGraphView::graph() const
{
    return m_route;
}

void TspPathGraphView::setGraph(const Route &r)
{
    m_route = r;
}

//![1]
void TspPathGraphView::paint(QPainter *painter)
{
    QColor color = QColor("#439911");
    QPen pen(color, 2);
    painter->setPen(pen);
    painter->setRenderHints(QPainter::Antialiasing, true);
   // painter->drawPie(boundingRect().adjusted(1, 1, -1, -1), 90 * 16, 290 * 16);

    QPen GraphPen;
       QPen GraphComplementPen;
       QPen VerticleDescPen;

       GraphPen = QPen(Qt::black);
       GraphPen.setWidth(1);

       GraphComplementPen = QPen(Qt::red);
       GraphComplementPen.setWidth(1);

       VerticleDescPen = QPen(Qt::darkGreen);
       VerticleDescPen.setWidth(1);

       textFont.setPointSize(16);

       painter->fillRect(event->rect(), background);
       painter->save();
       painter->setBrush(circleBrush);
       painter->setPen(GraphPen);
       painter->setFont(textFont);

      // int verts = data->AdjacencyMatrix.size();
    //   vector<vector<int> > RevertedAdjMatrix;

       if ( verts > 0)
       {
           QVector<QPoint> vertPos;
           int frameWidth = 400, frameHeight = 400;
            int verts = 0;
           //draw verticles
           int vertX = 0 , vertY = 0;
           int vertNo = 0;
           painter->setPen(VerticleDescPen);
           for (vertNo = 0; vertNo < verts; vertNo++)
           {
               //draw point in a circle
               vertX = StartX + (Radius * cos(CurrentAngle));
               vertY = StartY + (Radius * sin(CurrentAngle));
               QPoint point(vertX,vertY);
               vertPos.append(point);
               painter->drawText( point, QString::number(vertNo) );
               CurrentAngle += PointDistanceAngle;
           }

           //draw graph
           QPoint from, to;
           painter->setPen(GraphPen);
           for (vertNo = 0; vertNo < verts; vertNo++)
           {
               int adjInc = 0;
               for (adjInc = 0; adjInc < verts; adjInc++)
               {
                   int val = data->AdjacencyMatrix[vertNo][adjInc];
                   if ( (adjInc != vertNo) //dont draw verticle loop
                                &&
                        (val== 1)

                        )
                   {
                       from = vertPos[vertNo];
                       to = vertPos[adjInc];
                       painter->drawLine(from, to);
                   }
               }
           }


}
//![1]
