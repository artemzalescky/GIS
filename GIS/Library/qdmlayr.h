/******* QDMLAYR.H ************** Dishlenko S.G.  ****** 22/03/12 **
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
*                 ������ ������� � ����� �����                     *
*                                                                  *
*******************************************************************/

#ifndef QDMLAYR_H
#define QDMLAYR_H

#include "maptype.h"

class QDMapViewAcces;
class QDMapView;
class QDMapObjAcces;
class QDMapSite;

//++++++++++++++++++++++++++++++++++++++++
//+++  ����� ������� � ����� �����     +++
//++++++++++++++++++++++++++++++++++++++++

class QDMapLayer
{

public :
    QDMapLayer(QDMapViewAcces *mapview, QDMapSite *mapsite);
    ~QDMapLayer();

    HRSC  GetRscHandle();
     // ��������� �� ��������� �����
    QDMapView  *GetMapView();
     // ��������� �� ��������� ���������������� �����
    QDMapSite  *GetMapSite();
     // ������������ ����
    char  *GetLayerName();
    // ���������� ������������ ���� - ����
    char  *GetLayerKey();
    // ���������� �������� ��������� � ��������������
    int    GetObjCount();
    // �������� �������� ��������
    char   *GetObjName(int number);
    // ������� ��� �������
    int    GetObjExCode(int number);
    // ���������� ��� �������
    int    GetObjInCode(int number);
    // �������� ����������� �������
    int    GetObjLocal(int number);
    // ���������� �������� ������� (����)
    char   *GetObjKey(int number);

public :
    // ������������ ������ �� ������
    QDMapViewAcces *VarMapView;
    QDMapSite      *VarMapSite;      // Site � ������� ��������  ����� ������ ��������� �� ��������� � VarRsc
    HRSC           VarHRsc;          // RSC � ������� �������� (���� FMapSite<>nil �� rsc ����������� �� Site)
    int            VarNumber;        // ԽŽ˽սݽɽʽ νϽͽŽҽ ӽ̽Ͻѽ               // 22/03/12
};

//+++++++++++++++++++++++++++++++++++++++++++++++++++
//+++  ����� ������� � ����� ����� - ���������    +++
//+++++++++++++++++++++++++++++++++++++++++++++++++++

class QDMapLayers
{

public :
    QDMapLayers(QDMapViewAcces *mapview, QDMapSite *mapsite);
    QDMapLayers(HRSC rsc);
    ~QDMapLayers();

    // ���������� �����
    int        GetLayerCount();
    // ���� �� ����������� ������
    QDMapLayer *GetMapLayers(int number);
    // ���� �� ������� �����
    QDMapLayer *GetObjLayers(QDMapObjAcces *mapobj);
    // ���� �� ����������� �������� - �����
    QDMapLayer *GetKeyLayers(char *keyname);
    void       SetRscHandle(HRSC rsc);

public :
   // ��� ����������� �������������
   QDMapLayer *VarMapLayer;
};

#endif  // QDMLAYR_H
