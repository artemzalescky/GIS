/******** QDMRECT.H ************* Dishlenko S.G.  ***** 22/03/12 ***
*                                                                  *
*              Copyright (c) PANORAMA Group 1991-2012              *
*                      All Rights Reserved                         *
*                                                                  *
********************************************************************
*                                                                  *
*                      FOR QT-DESIGNER                             *
*                                                                  *
********************************************************************
*                                                                  *
*  ���������      : QDMapSelectRect - ����� ������� �������� ����� *
*                                                                  *
*******************************************************************/

#ifndef QDMRECT_H
#define QDMRECT_H

#include "qdmact.h"
#include "mapapi.h"             // 28/11/03

//++++++++++++++++++++++++++++++++++++++++++++++++++
//+++ QDMapSelectRect - ����� ������ ������� ����� +
//++++++++++++++++++++++++++++++++++++++++++++++++++

 class QDMapSelectRect : public QDGtkAction
 {
  Q_OBJECT

  public:

    // ��� ������������
    //---------------------------------
    QDMapSelectRect(QWidget * parent = 0, const char * name = 0);
    ~QDMapSelectRect();

    // ��� ������������
    virtual void StartAction();     // ������������ ���������� � ���������� ����������� �����
    virtual void StopAction();      // �����������
    // ������/��������� ������� ���������     // 01/11/05
    void SetPlaceRect(int pp);
    int  GetPlaceRect();

    // ���������
    //---------------------------------
    virtual void MapAfterPaint(QObject *sender, HWND canvas, RECT mappaintrect);
    virtual void MapBeforePaint(QObject *sender, HWND canvas, RECT mappaintrect);
    virtual void MouseDown(int x, int y, int modkeys);
    virtual void MouseMove(int x, int y, int modkeys);
    virtual void MouseUp(int x, int y, int modkeys);

    //  ��������� ������ ��������� �� ������� ������
    void BuildFrame();
    //  ���������� �� ����� ����� ���������
    void PaintFrame();
    DOUBLEPOINT GetMapPoint(int x, int y);
    int         GetSelRect(MAPDFRAME *dframe, int pp);           // 26/10/05

signals :
    // ��� ������������
    //---------------------------------
    // ������ �� ��������� ���������� �����
    // ��������� - ���������� �������� ������ �
    // ������� ������� ���� �����
    void SignalAfterBuildRect(double left, double top,            // 1/11/05
                              double right, double bottom);

public :
  // ���������
  //---------------------------------
  struct Border                                                   // 22/03/12
  {
    DOUBLEPOINT UpLeft;     // ���������� ������ ����� (Map)
    DOUBLEPOINT UpRight;    // ���������� ������ �����
    DOUBLEPOINT DownRight;  // �ϙϙҙęəΙ�ԙٙ ԙҙřԙؙřʙ ԙϙޙ˙ə
    DOUBLEPOINT DownLeft;   // ���������� ��������� �����
    DOUBLEPOINT UpLeftLast; // �ϙϙҙęəΙ�ԙٙ Йϙә̙řęΙřʙ ԙϙޙ˙ə (Map)
  }
    Border;
  DOUBLEPOINT First;      // ���������� ������� ���� (Map)
  DOUBLEPOINT Second;     // ���������� ������� ���� (Map)
  DOUBLEPOINT PointMap;   // 12/11/07

  PAINTPARM Form;   // ��� ������� ��������� �� ������
                    // (���������� ����� 5/2 ���������)
  PLACEDATA Frame;  // �������� ��������� �����
  int PointCount;         // ����� �����, ����������� ��������       // 21/03/12
  int  SelectedPoints;     // ������� �����

  int FlagClear;          // ������� "������ �����"
  int VarPlace;           // ������� ������� ���������  // 08/11/05
  IMGDOT Image;     // �������� ���������� ����� (������ ���������)
};

#endif
