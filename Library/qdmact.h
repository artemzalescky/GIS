/******** QDMACT.H ************* Dishlenko S.G.  ***** 11/11/05 ****
*                                                                  *
*              Copyright (c) PANORAMA Group 1991-2005              *
*                      All Rights Reserved                         *
*                                                                  *
********************************************************************
*                                                                  *
*                      FOR QT-DESIGNER                             *
*                                                                  *
********************************************************************
*                                                                  *
*    QDGtkAction -  ������� ����� ��������� ������� �� ����������  *
*                         ����������� �����                        *
*                                                                  *
*******************************************************************/

#ifndef QDMACT_H
#define QDMACT_H

#include "qdmcompa.h"

//++++++++++++++++++++++++++++++++++++++++++++++++++
//+++ QDGtkAction - ����� ��������� ������� ��     +
//+++ ���������� ����������� �����                 +
//++++++++++++++++++++++++++++++++++++++++++++++++++

class QDMapView;
class QDMapWindow;

 class QDGtkAction : public QDMapComponent
 {
  Q_OBJECT

  public:

    QDGtkAction(QWidget * parent = 0, const char * name = 0);
    ~QDGtkAction();

    // ���������
    //---------------------------------------------
    virtual void MapAfterPaint(QObject *sender, HWND canvas, RECT mappaintrect);
    virtual void MapBeforePaint(QObject *sender, HWND canvas, RECT mappaintrect);
    // ������ - ����� �� ��������� ����������
    // ��������� �� ���������� ���������� QDMapViewWindow
    // ����� ������ StopAction
    bool DoStopActionQuery();
    // ���������� ����� ��������
    // ��������� �� ���������� ���������� QDMapViewWindow
    // ����� ������ StopAction
    virtual void DoStopAction();
    virtual void DblClick();
    virtual void KeyUp(int key, int count, int state);
    virtual void KeyDown(int key, int count, int state);
    virtual void MouseDown(int x, int y, int modkeys);
    virtual void MouseMove(int x, int y, int modkeys);
    virtual void MouseUp(int x, int y, int modkeys);

    // ��� ������������
    //---------------------------------------------
    // ������� �� � ������ ������ ����������   // 11/11/05
    // false - �� �������;
    // true  - �������;
    bool GetActive();      
    virtual void   SetMapView(QDMapView *value);
    QDMapView      *GetMapView() const;
    virtual void   SetMapWindow(QDMapWindow *value);
    QDMapWindow    *GetMapWindow() const;
    virtual void   StartAction();     // ������������ ���������� � ���������� ����������� �����
    virtual void   StopAction();      // �����������

 public :
    bool VarActive;

};

#endif
