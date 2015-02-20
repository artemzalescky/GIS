/******** QDMDLIST.H ************* Dishlenko S.G.  ****** 14/11/05 *
*                                                                  *
*              Copyright (c) PANORAMA Group 1991-2005              *
*                      All Rights Reserved                         *
*                                                                  *
********************************************************************
*                                                                  *
*                      FOR Qt-DESIGNER                             *
*                                                                  *
********************************************************************
*                                                                  *
*        ��������� - ������ "������ ������ ����������� �����"      *
*                                                                  *
*******************************************************************/

#ifndef QDMDLIST_H
#define QDMDLIST_H

#include "qdmcmp.h"
#include "listapi.h"

//++++++++++++++++++++++++++++++++++++++++++++++++++
//+++ ����� �������                                +
//+++ "������ ������ ����������� �����"            +
//++++++++++++++++++++++++++++++++++++++++++++++++++

class QDMapDataList : public QDMapComponent
{
    Q_OBJECT

// �������������� ��� �� "�����������"
// Q_PROPERTY(QDMapView MapView READ GetMapView WRITE SetMapView FROMSTRL def TOSTRL def ORDER 1)

public :
    // ��� ������������
    //------------------------------
    QDMapDataList(QWidget *parent = 0, const char *name = 0);
    ~QDMapDataList() {};
    // ��������� ������ 
    void         Execute();
    // ��������� �� �����
    virtual void SetMapView(QDMapView *value);
    QDMapView    *GetMapView() const;                     

    // ���������
    //------------------------------
    // ��������� ��������� ��� ������ ������
    void InitTaskParm(TASKPARM *taskparm, MAPLISTPARM* maplistparm);
};

#endif // QDMDLIST_H
