/******** QDMDGTOB.H   *********** Dishlenko S.G.  ****** 22/03/12 *
*                                                                  *
*              Copyright (c) PANORAMA Group 1991-2022              *
*                      All Rights Reserved                         *
*                                                                  *
********************************************************************
*                                                                  *
*                      FOR Qt-DESIGNER                             *
*                                                                  *
********************************************************************
*                                                                  *
*                     ��������� - ������                           *
*          "������ ���� ������� �� ��������������"                 *
*                                                                  *
*******************************************************************/

#ifndef QDMDGTOB_H
#define QDMDGTOB_H

#include "qdmcompa.h"

class QDMapView;
class QDMapObj;

//++++++++++++++++++++++++++++++++++++++++++++++++++
//+++ ����� �������                                +
//+++ "����� ���� ������� �� ��������������"       +
//++++++++++++++++++++++++++++++++++++++++++++++++++

class QDMapSelectObjectRsc : public QDMapComponent
{
    Q_OBJECT

public :
    // ��� ������������
    //------------------------------
    QDMapSelectObjectRsc(QWidget *parent = 0, const char *name = 0);
    ~QDMapSelectObjectRsc() {};
    // ��������� �� �����
    virtual void SetMapView(QDMapView *value);
    QDMapView    *GetMapView() const;                     
    // ��������� ������ ��� ���������� QDMapObj
    // ���� mapobj  - ��������� QDMapObj - ���� �� �������� �� ����� ���� ��� �������
    //                �� ��������������, �� ��� ������ ������ ����� �������� �� ����
    //   createflag - ���� �� ����� ��������� ���������� ������� ������������ ��������
    //                QDMapObj (��� �������, �������, ���������) ������ ��� �� ����������
    //                ������ ���
    bool         ExecuteForMapObj(QDMapObj *mapobj, bool createflag);

    // ��� ���������� ����������� !!!!!
    //------------------------------
    // ��������� ������ � ��������� ��������� �������� �������
    // ����� = true  - ������� � ��������� objinfo
    //         false - ����������
    bool         Execute(TMAPOBJECTINFO *objinfo);
    //  ����������  ������� ������ ����� � �������  �� �������� ���� � �����������
    //  ���� - sitenumber - ����� ����� � ������ (��� -1 - ������ �� ���� ���������������)
    //       - excode     - ���� ��� �������
    //       - local      - ������������ (��� -1 - ����������� �����)
    bool         SetBeginObjectForExcode(int sitenumber, int excode, int local);
    //  ����������  ������� ������ ����� � ������� �� �������� � �����������
    //  ���� - sitenumber - ����� ����� � ������ (��� -1 - ������ �� ���� ���������������)
    //       - nameobj      - �������� �������
    //       - local      - ������������ (��� -1 - ����������� �����)
    bool         SetBeginObjectForName(int sitenumber, char *nameobj, int local);

public :
    // ��� ������������
    //------------------------------
    HOBJ    ObjH;                      // ������������� ������������ �������                // 22/03/12
    int     FSiteNumber;               // Ρϡ͡šҡ ˡ�ҡԡ١ ס ˡϡԡϡҡϡʡ ס١¡ɡҡ�šԡӡѡ ԡɡС ϡ¡ߡšˡԡ�
    int     FRetIncode;                // לΜ՜ԜҜŜΜΜɜʜ ˜ϜĜ לٜ^ÜҜ�ΜΜϜǜϜ Ϝ^ÜߜŜ˜Ԝ�
    int     FLocals[6];                // ̡ϡˡ�̡ɡڡ�áɡɡ ġϡӡԡաСΡ١š ס ġɡ�̡ϡǡš
    int     FRetSite;                  // ����� ����� ���������� �������
    char    FCaption[256];             // ��������� �������
    bool    FMapEditEnabled;           // ���� ����������� ����, ������� �������� �������������
    bool    FRestoreEnabled;           // ����� �� ��������������� ��������� �������
    bool    FHelpEnabled;              // ���� ����������� ������ ������ � �������
};

#endif // QDMDGTOB_H

