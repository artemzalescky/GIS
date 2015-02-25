#ifndef PLANE_H
#define PLANE_H

#include <QScrollArea>
#include <QString>
#include <QPixmap>
#include <QtCore>


#include "../Library/mapapi.h"


class QWidget;
class QPainter;
class QFileInfo;

class Plane
{

public:
    Plane();

    double getX();
    double getY();

    void setX(double x);
    void setY(double y);

    void draw(QPainter* p);

private:
    DOUBLEPOINT coord;

    int pointRadius = 5;
};

#endif // PLANE_H
