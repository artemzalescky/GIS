/******** QDMWINW.H ************** Dishlenko S.G.  ****** 09/11/07 *
*                                                                  *
*              Copyright (c) PANORAMA Group 1991-2007              *
*                      All Rights Reserved                         *
*                                                                  *
********************************************************************
*                                                                  *
*                      FOR Qt3-DESIGNER                            *
*                                                                  *
********************************************************************
*                                                                  *
*   �������� ������ : "��������� ����������� �������� ������       *
*                      ����������� �����"                          *
*                                                                  *
*******************************************************************/

#ifndef QDMWINW_H
#define QDMWINW_H

#include "qdmwina.h"

class QDMapView;         // 09/11/07

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// +++ ����� "��������� ������� � ����������� �����          +++
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class QDMapWindow : public QDMapViewWindow
{
    Q_OBJECT

// �������������� ��� �� "�����������"                        // 18/11/03
//    Q_PROPERTY(QDMapView MapView READ GetMapView WRITE SetMapView FROMSTRL def TOSTRL def ORDER 1)  // 24/07/03

public :
    QDMapWindow(QWidget *parent = 0, const char *name = 0);
   ~QDMapWindow();

    // ��������� �� �����
    void         SetMapView(QDMapView *value);
    QDMapView    *GetMapView() const;           // 24/07/03
    // �������� ������ ������� � �����
    QDMapViewAcces *GetMapViewAcces();
    // ���������� ����������� ������� ������������ ��� ����
    int          RestoreViewScaleWin();
    // ������������ ������� ������������ ��� MapView
    void         RestoreViewScale(int scale);
    // ����������� � ��������� ����
    bool         GetMapContour();
    void         SetMapContour(bool value);
    // ������� ����������� ����� (-4..+4)
    int          GetMapBright();
    void         SetMapBright(int value);
    // ������������� ����������� ����� (-4..+4)
    int          GetMapContrast();
    void         SetMapContrast(int value);
    // ������� ������� �����������
    int          GetViewScale();
    int          SetViewScale(int value);
    // ������������� �����
    HMAP         GetMapHandle();
    // ����������� ����
    virtual void Repaint();
    // ������������� ����� ������� � ������������ x, y �� ������� placein � ������� placeout
    int          ConvertMetric(double *x, double *y, int placein, int placeout);
    // �������������� ���������� �� dframein ������� ��������� placein
    virtual MAPDFRAME ConvertDFrame(MAPDFRAME dframein, int placein, int placeout);
    //   ��������� ������, ������ ����� � �������� � ������� ��������
    void           GetMapHW(long int *height, long int *width);
    // ���������� �������� ����� ������ ���� � ��������
    virtual RECT   GetRegionRect();
    // ���������� �������� ����� ������ ���� � ��������� ������� ���������
    virtual MAPDFRAME GetRegionDFrame(int pointplace);
    // ������������� �����
//    property     MapHandle : HMap read GetMapHandle; // ��������� MapView.MapHandle
    // ������� ������� �����������
//    property     ViewScale : integer read GetViewScale write SetViewScale;
    // ��� ����������� �����
//    property     ViewType : integer read GetViewType write SetViewType;

//  published

    // ��������� �� �����
//    property     MapView : TMapView read FMapView write SetMapView;
    // ������� ����������� ����� (-4..+4)
//    property     MapBright : integer read GetMapBright write SetMapBright;
    // ������������� ����������� ����� (-4..+4)
//    property     MapContrast : integer read GetMapContrast write SetMapContrast;
    // ����������� � ��������� ����
//    property     MapContour : boolean read GetMapContour write SetMapContour;

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// ���� ������� � ���������� ��� ����������� �������������
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    void         MapAction(int action);
    virtual void Notification(QObject *component, int operation);

protected :
    virtual void drawContents(QPainter* p, int cx, int cy, int cw, int ch);

protected :
    QDMapView   *VarMapView;          // ��������� �� �����
    int         VarViewScaleInWindow; // ������� ����������� � ������ ����
    int         VarMapBright;
    int         VarMapContrast;
    bool        VarMapContour;
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
};

#endif // QDMWINW_H
