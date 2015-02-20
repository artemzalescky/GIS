#ifndef GISPAINTER_H
#define GISPAINTER_H

#include <QtCore>

#include "./gisdata/GISProvider.h"
#include "GISTypes.h"

class QPainter;

class GISPainter : public GISProvider
{
public:
    GISPainter(){}

public:
    int paintMapImage(QPainter*, RECT*);  //Отображение карты ввиде картинки

    long int getPictureWidth();
    long int getPictureHeigth();

    int getShowScale();
    QPoint changeShowScale(QPoint point_, float k_);

    QPoint getScrCoordByMM(DOUBLEPOINT mmpoint_);
    DOUBLEPOINT getMMCoordByScr(DOUBLEPOINT scrpoint_);

    QPoint getScrCoord(DOUBLEPOINT, GISTYPESC, GISVALUETYPE);
    QPoint getScrCoordByWGS84Dgr(DOUBLEPOINT);

    void setMapViewType(const TYPEMAPSHOW);
    void setMtrViewType(const TYPEMTRSHOW);
    void setBrightMapPicture(const int);
    void setContrastMapPicture(const int);
    void setBackColorMapPicture(QColor);

};

#endif // GISPAINTER_H
