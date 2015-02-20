/*******  QDMCOMPA.H ************* Dishlenko S.G.  ****** 07/04/06 *
*                                                                  *
*              Copyright (c) PANORAMA Group 1991-2006              *
*                      All Rights Reserved                         *
*                                                                  *
********************************************************************
*                                                                  *
*                      FOR QT-DESIGNER                             *
*                                                                  *
********************************************************************
*                                                                  *
*     �������� �������� ������ ��������� ������� �                 *
*                     ����������� �����                            *
*                                                                  *
*******************************************************************/

#ifndef QDMCOMPA_H
#define QDMCOMPA_H

#include <Qt/qwidget.h>                           // 07/04/06
#include "qdmviewa.h"

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++ ������� ����� ��������� ������� � ����������� �����         ++
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
class  QDMapComponent : public QWidget
{
    Q_OBJECT

public :
    QDMapComponent(QWidget *parent = 0, const char *name = 0);
    ~QDMapComponent();
    void SetMapViewAcces(QDMapViewAcces *value);
    // ��������� ������� ��������� ������� ���� �� ������ MapViewWindow
    virtual void    MapAction(int typeaction) {};
    // ��� ���������� �����������  !!!!!!!!!
    void SetMapWindowAcces(QDMapViewAcces *value); // ��������� VarMapWindow      // 21/11/03
    // �������� ������ ���� QDMapViewWindow � ������� ����������� ����� (QDMapView or QDMapWindow)
    QDMapViewAcces *GetMapViewWindow();                                           // 21/11/03
    virtual void    Notification(QObject *component, int operation);

public :
    //  ��� ������������ ������ �� ������
    QDMapViewAcces *VarMapView;
    // ��� ���������� �����������  !!!!!!!!!
    // ������ ���� TMapWindow � �������� ��������� ������ ��������� � � ������� ���� �����������
    QDMapViewAcces *VarMapWindow;
};

#endif  // QDMCOMPA_H
