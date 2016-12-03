#include "tsppathgraphview.h"

//![0]
TspPathGraphView::TspPathGraphView(QQuickItem *parent): QQuickPaintedItem(parent)
{
       //QLinearGradient gradient(QPointF(50, -20), QPointF(80, 20));
       //gradient.setColorAt(0.0, Qt::red);
       //gradient.setColorAt(1.0, Qt::green);

       background = QBrush(Qt::transparent);
       circleBrush = QBrush(Qt::transparent);

       circlePen = QPen(Qt::black);
       circlePen.setWidth(1);

       textPen = QPen(Qt::cyan);
       textFont.setPointSize(16);
}
//![0]

 int TspPathGraphView::length()
{
    return m_length;
}

void TspPathGraphView::redraw()
{
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

     // painter->fillRect(event->rect(), background);

      m_painter->save();
      m_painter->setBrush(circleBrush);
      m_painter->setPen(GraphPen);
      m_painter->setFont(textFont);

     // int verts = data->AdjacencyMatrix.size();
   //   vector<vector<int> > RevertedAdjMatrix;
      int verts = Graph::size();

      if ( verts > 0)
      {
          QVector<QPoint> vertPos;
          int frameWidth = 200, frameHeight = 200;
          int posMaxX = 50;
          int posMaxY = 50;


          //draw verticles
          int vertX = 0 , vertY = 0;
          int vertNo = 0;

          //get first route
          if(TspRoutes.size() < 1){
              return;
          }
          Route rt = TspRoutes[0];

          if(rt.size() < verts){
              return;
          }

          //draw graph
          QPoint from, to;
          m_painter->setPen(GraphPen);
          for (vertNo = 0; vertNo < verts/2; vertNo++)
          {
             std::pair <double, double> coordsFrom = Graph::getCityCoords(rt[vertNo*2]);
             std::pair <double, double> coordsTo = Graph::getCityCoords(rt[vertNo*2+1]);
              from.setX( coordsFrom.first);
              from.setY(coordsFrom.second);
              to.setX( coordsTo.first);
              to.setY(coordsTo.second);
              m_painter->drawLine(from, to);
        }
      }

}

//![1]
void TspPathGraphView::paint(QPainter *painter)
{
    QColor color = QColor("#439911");
    QPen pen(color, 2);
    painter->setPen(pen);
    painter->setRenderHints(QPainter::Antialiasing, true);
     m_painter = painter;

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
       painter->save();
       painter->setBrush(circleBrush);
       painter->setPen(GraphPen);
       painter->setFont(textFont);
       int verts = Graph::size();

       if ( verts > 0)
       {
           QVector<QPoint> vertPos;
           int frameWidth = 400, frameHeight = 400;
           int posMaxX = 50;
           int posMaxY = 50;


           //draw verticles
           int vertX = 0 , vertY = 0;
           int vertNo = 0;

           //get first route
           if(BestTspRoutes.size() < 1){
               return;
           }
           Route rt = BestTspRoutes[0];

           if(rt.size() < verts){
               return;
           }



           //draw graph
           QPoint from, to, prev;
           painter->setPen(GraphPen);


              //store first point
           std::pair <double, double> coordsFrom = Graph::getCityCoords(rt[0]);
           prev.setX(coordsFrom.first*3);
           prev.setY(coordsFrom.second*3);
           painter->drawText( to, QString::number(0) );

           int sumLen = 0;

           for (vertNo = 1; vertNo < verts; vertNo++)
           {
               to = QPoint();
             // std::pair <double, double> coordsFrom = Graph::getCityCoords(rt[vertNo*2]);
              std::pair <double, double> coordsTo = Graph::getCityCoords(rt[vertNo]);
              // from.setX( coordsFrom.first *3);
             //  from.setY(coordsFrom.second *3);
             //    painter->drawText( from, QString::number(vertNo) );
               to.setX( coordsTo.first *3);
               to.setY(coordsTo.second *3);
               painter->drawText( to, QString::number(vertNo) );
               painter->drawLine(prev, to);

               int diffX = abs( to.x() - prev.x());
               int diffY = abs( to.y() - prev.y());

               sumLen += (int) ( sqrt( pow(diffX,2) + pow(diffY,2) ) );

               prev = to;
         }

           m_length = sumLen;

           QPoint resPt;
           resPt.setX( 22);
           resPt.setY(22);
            painter->drawText( resPt, QString::number(sumLen) );

       }


}

//![1]
