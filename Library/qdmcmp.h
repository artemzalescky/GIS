/******** QDMCMP.H ************** Dishlenko S.G.  ****** 02/06/06 **
*                                                                  *
*              Copyright (c) PANORAMA Group 1991-2006              *
*                      All Rights Reserved                         *
*                                                                  *
********************************************************************
*                                                                  *
*                      FOR Qt4-DESIGNER                            *
*                                                                  *
********************************************************************
*                                                                  *
*   �������� ������ : "��������� ������� � ����������� �����"      *
*                                                                  *
*******************************************************************/

#ifndef QDMCMP_H
#define QDMCMP_H

#include "qdmwina.h"
#include "qdmlayr.h"
#include "qdmrst.h"
#include "qdmmtr.h"
#include "qdmsite.h"

class QDMapSemantics;
class QDMapWindow;

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// +++ ����� "��������� ������� � ����������� �����          +++
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class QDMapView : public QDMapViewWindow
{
    Q_OBJECT

    // ��� ������������
    // ��� ����� �����
    Q_PROPERTY(QString MapFileName READ GetMapFileName WRITE SetMapFileName)
    // �������������� �����
    Q_PROPERTY(bool MapActive READ GetMapActive WRITE SetMapActive)
    // ������� ����������� ����� (-4..+4)
    Q_PROPERTY(int MapBright READ GetMapBright WRITE SetMapBright)
    // ������������� ����������� ����� (-4..+4)
    Q_PROPERTY(int MapContrast READ GetMapContrast WRITE SetMapContrast)
    // ����������� � ��������� ����
    Q_PROPERTY(bool MapContour READ GetMapContour WRITE SetMapContour)


public :
    QDMapView(QWidget *parent = 0, const char *name = 0);
   ~QDMapView();

public slots:
    // ���������� ����� ��� ����� �����
    void           SetMapFileName(const QString qstring);
    void           SetMapActive(bool active);
    // ����������/c������� ����������� ����� � ��������� ����
    void           SetMapContour(bool value);
    // ���������� ������� �������� ������� �����
    void           SetMapBright(int value);
    // ���������� ������� �������� ������������� �����
    void           SetMapContrast(int value);

public :
    // ������� �� � ������ ������ �����
    bool           GetMapActive() const;
    // ������ ����� ����� �����
    QString        GetMapFileName() const;
    // ���������� �� ����� � ��������� ����
    bool           GetMapContour() const;
    // ������ �������� �������� �������
    int            GetMapBright() const;
    // ������ �������� �������� �������������
    int            GetMapContrast() const;
    //   ��������� ��� �����
    QString        GetMapName();
    //   ��������� ������� ������� �����
    int            GetMapScale();
    //   ��������� ��� �����
    int            GetMapType();
    //   ��������� ������, ������ ����� � �������� � ������� ��������
    void           GetMapHW(long int *height, long int *width);
    // ������� ����� � ������ aMapFileName
    bool MapOpen(const QString filename, bool mapview);
    // ������� �����
    void MapClose();
    HSELECT        GetViewSelectHandle();
    // ��������� ���������� ������  ����������� ������ ��� ��� ���������
    // ��������� � MapView
    void UpdatePictureBorderForAll();
    // ��� ����������� ������������� !!!!
    // ��������� ������� ��������� ������� ���� � �� ����������� �� ������ MapVeiw
    void  AllMapRef(int action);
    // ������ �� ������� ������������ � ��� QDMapWindow
    void AppendMapWindow(QDMapWindow *mapwindow);
    void DeleteMapWindow(QDMapWindow *mapwindow);
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

public :
    QDMapSites           *VarMapSites;
    QDMapMtrs            *VarMapMtrs;
    QDMapRsts            *VarMapRsts;
    QDMapLayers          *VarMapLayers;
    QDMapSemantics       *VarMapSemantics;
    // ��� ����������� �������������
    QString              VarMapFileName;
    QList<QDMapWindow *> VarMapWindows;           
    QString              QStrName;                
};

#endif // QDMCMP_H
