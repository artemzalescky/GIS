/******* QDMSITE.H ************** Dishlenko S.G.  ****** 12/02/03 **
*                                                                  *
*              Copyright (c) PANORAMA Group 1991-2003              *
*                      All Rights Reserved                         *
*                                                                  *
********************************************************************
*                                                                  *
*                      FOR Qt3-DESIGNER                            *
*                                                                  *
********************************************************************
*                                                                  *
*       �������� ������� ������� � ���������������� �����          *
*                                                                  *
*******************************************************************/

#ifndef QDMSITE_H
#define QDMSITE_H

#include "maptype.h"
#include "qdmlayr.h"

class QDMapPointAcces;
class QDMapViewAcces;

//++++++++++++++++++++++++++++++++++++++++++++++
//+++ ����� ������� � ���������������� ����� +++
//++++++++++++++++++++++++++++++++++++++++++++++

class  QDMapSite
{
public :
    QDMapSite(QDMapViewAcces *mapview);
    ~QDMapSite();

    HSITE  GetSiteHandle();
    // ��� ���������������� ����� ����������
    char   *GetSiteName();
    // ����� ���������������� ����� ���������� � �������
    int    GetNumber();
    // ��� ����� ���������������� ����� ����������
    char   *GetSiteFileName();
    // ������� ������� ���������������� ����� ����������
    int    GetSiteScale();
    // ��� ���������������� ����� ����������
    int    GetSiteType();
    // ����������� �����
    void   SetSiteVisible(bool visible);
    bool   GetSiteVisible();
    // ����������/�������� ����� �������� ���������������� ����� � ���������� ���������� ���������
    int    SetSiteBorder(MAPDFRAME *frame, int place);
    MAPDFRAME GetSiteBorder(int place);

public :
// ��� ���������� ����������� !!!!!
    QDMapViewAcces  *VarMapView;
    HSITE           VarSite;
    QDMapPointAcces *VarMapPoint;
    QDMapLayers     *VarSiteLayers;
};


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++ ����� ������� � ���������������� ����� - ��������� +++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class QDMapSites
{
public :
    QDMapSites(QDMapViewAcces *mapview);
    ~QDMapSites();
    // ���������� ���������������� ���� ���������� � ������
    int       GetSiteCount();
    // ������ � ���������������� ����� ���������� �� ����������� ������
    QDMapSite *GetMapSites(int number);
    // ������ � ���������������� ����� ���������� �� ������������
    QDMapSite *GetSitesForName(char *sitename);
    // ������ � ���������������� ����� ���������� ������� ����� �����
    QDMapSite *GetSitesForFileName(char *sitefilename);
    // �������� ���������������� ����� ����������
    int       Append(char *sitefilename);
    // ������� ���������������� ����� ���������� �� ������������
    void      DeleteSiteName(char *sitename);
    // ������� ���������������� ����� ���������� �� ������� ����� �����
    void      DeleteFileName(char *sitefilename);
    // ������� ���������������� ����� ���������� �� ����������� ������
    // ��������! ��� ��������� ��������� ����� � ������� �������
    // ������� ������ ���������.
    void      Delete(int number);
public :
// ��� ���������� ����������� !!!!!
    QDMapSite *VarMapSite;
};

#endif  //  QDMSITE_H

