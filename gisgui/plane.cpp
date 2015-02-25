#include "plane.h"
#include "QPainter"

Plane::Plane()
{
    this->coord.x = 0;
    this->coord.y = 0;
}

double Plane::getX() {
    return this->coord.x;
}

double Plane::getY() {
    return this->coord.y;
}

void Plane::setX(double x) {
    this->coord.x = x;
}

void Plane::setY(double y) {
    this->coord.y = y;
}

void Plane::draw(QPainter* p) {
    p->drawEllipse(QPoint(coord.x, coord.y), pointRadius, pointRadius);
}
