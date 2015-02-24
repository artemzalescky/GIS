/******** QDMDCMTW.H ************* Dishlenko S.G.  ****** 22/03/12 *
*                                                                  *
*              Copyright (c) PANORAMA Group 1991-2012              *
*                      All Rights Reserved                         *
*                                                                  *
********************************************************************
*                                                                  *
*                      FOR Qt-DESIGNER                             *
*                                                                  *
********************************************************************
*                                                                  *
*        ��������� - ������ "�������� ������� �����"               *
*                                                                  *
*******************************************************************/

#ifndef QDMDCMTW_H
#define QDMDCMTW_H

#include "qdmcmp.h"

//++++++++++++++++++++++++++++++++++++++++++++++++++
//+++ ����� �������                                +
//+++ "�������� ������� �����"                     +
//++++++++++++++++++++++++++++++++++++++++++++++++++

class QDMapCreateMtw : public QDMapComponent
{
    Q_OBJECT

    // ����������\��������� �������� ����� ������ ������� �����  // 22/05/06
    Q_PROPERTY(bool AllRectActive READ GetAllRectActive WRITE SetAllRectActive)

public :
    // ��� ������������
    //------------------------------
    QDMapCreateMtw(QWidget *parent = 0, const char *name = 0);
    ~QDMapCreateMtw() {};
    // ��������� ������
    void         Execute();
    // ��������� �� �����
    virtual void SetMapView(QDMapView *value);
    QDMapView    *GetMapView() const;
    // ����������\��������� �������� ����� ������ ������� �����
    // true  - ��� �����(�� ���������)
    // false - ������������� �������, �������� �������� SetMapRect
    void  SetAllRectActive(bool value);
    bool  GetAllRectActive() const;
    // ���������� ������� ������� ����� � ��������
    // ����� �������������� ������ ������ ����������
    // ���������� ���� ������ ������� ����� � 0
    // left, top     -  ����� ������� ����
    // right, bottom -  ������ ������
    void SetMapRect(int left, int top, int right, int bottom);

public:
    // ���������
    //------------------------------
    // ��������� ��������� ��� ������ ������
    void InitTaskParm(TASKPARM *taskparm, void* mtrparm);

    RECT  MapRect;                                                            // 22/03/12
    // ���� ������ ������� �����
    // true  - ��� ����� (�� ���������)
    // false - ������������� �������, �������� �������� SetMapRect
    bool  AllRectActive;
};

#endif // QDMDCMTW_H
