/******* QDMPOINA.H  ************* Dishlenko S.G.  ****** 22/03/12 *
*                                                                  *
*              Copyright (c) PANORAMA Group 1991-2012              *
*                      All Rights Reserved                         *
*                                                                  *
********************************************************************
*                                                                  *
*                      FOR Qt3-DESIGNER                            *
*                                                                  *
********************************************************************
*                                                                  *
*     �������� �������� ������ ������� � ����������� �����         *
*                     ����������� �����                            *
*                                                                  *
*******************************************************************/

#ifndef QDMPOINA_H
#define QDMPOINA_H

#include <qwidget.h>
#include "qdmviewa.h"
#include "maptype.h"

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++ ������� ����� ������� � ����������� ����� ����������� ����� ++
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
class  QDMapPointAcces : public QWidget
{
    Q_OBJECT

public :
    QDMapPointAcces(QDMapViewAcces* mapview = 0, QWidget * parent = 0, const char * name = 0);
    ~QDMapPointAcces() {};

    // �������������� ���������� �� dframein ������� ��������� placein
    // � ������� ��������� placeout
    MAPDFRAME ConvertDFrame(MAPDFRAME dframein, int placein, int placeout);
    // ������������� ����� ������� � ������������ x, y
    // �� ������� placein � ������� placeout
    int     ConvertMetric(double *x, double *y, int placein, int placeout);
    int     GetPlaceIn() const;
    int     GetPlaceOut() const;
    double  GetX();
    double  GetY();
    QDMapViewAcces *GetMapView() const;
    void SetPlaceIn(int value);
    void SetPlaceOut(int value);
    void SetX(double value);
    void SetY(double value);
    void SetMapView(QDMapViewAcces *value);
    // �������� ���������� � ������� PlaceIn
    bool SetPoint(double x, double y);
    // �������  ���������� � ������� PlaceOut
    bool GetPoint(double *x, double *y);
    // ��� ���������� ����������� !!!!!
    virtual void Assign(QDMapPointAcces *mappoint);
    // ---------------------------------
public  :
    // ������������ ������ �� ������
    QDMapViewAcces  *VarMapView;                                    // 22/03/12
    double          VarX;                // ���������� � ������
    double          VarY;                // ���������� � ������
    int             VarPlaceIn;          // ������� ��������� � ������� MAP API
    int             VarPlaceOut;         // ������� ��������� � ������� MAP API
};

#endif // QDMPOINA_H
