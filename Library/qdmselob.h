/******* QDMSELOB.H ************ Dishlenko S.G. ******** 09/11/05 **
*                                                                  *
*              Copyright (c) PANORAMA Group 1991-2005              *
*                      All Rights Reserved                         *
*                                                                  *
********************************************************************
*                                                                  *
*                            FOR QT3-DESIGNER                      *
*                                                                  *
********************************************************************
*                                                                  *
*   �������� ������ "��������� - ������ ������ ������� �����"      *
*                                                                  *
*******************************************************************/

#ifndef QDMSELOB_H
#define QDMSELOB_H

#include "qdmcmp.h"       // 24/07/03

class QDMapView;
class QDMapObj;
class QDMapSelect;

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++ ����� "��������� ������ ������ ��'���� ����������� �����"   ++
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class QDMapDlgObj : public QDMapComponent
{
    Q_OBJECT

// �������������� ��� �� "�����������"                        // 18/11/03
//    Q_PROPERTY(QDMapView MapView READ GetMapView WRITE SetMapView FROMSTRL def TOSTRL def ORDER 1)  // 24/07/03

public  :
    QDMapDlgObj(QWidget * parent = 0, const char * name = 0);
    ~QDMapDlgObj();

    virtual void   SetMapView(QDMapView *value);
    QDMapView *    GetMapView() const;                     // 24/07/03
    // ������� ������ ����� � �����, ��������� ������
    // x,y    - ���������� ����� � �������� � ���������� �������
    //                 ������� ���������� TMapView, �� ������� �������� TMapObj
    // radius - ������ ������ � �������� (�� ����� 10)
    // ����� = true  - ������� � ��������� mapobj
    //         false - ����������
    bool SelectObjectInPoint(QDMapObj *mapobj, int x, int y, int radius);
    // ����� ������� ��������� � �������
    // mapselect - �������� ������ :
    //       ���� AllMaps �� ����������, �� ����� ����� ��������
    //       ��� ������ ��������� ��� ������ � ������;
    // next      - ���� �� ��������� ����������� ������ � ��������;
    // ����� = true  - ������� � ��������� mapobj
    //         false - ����������
    bool ExecuteDlgFind(QDMapObj *mapobj, QDMapSelect *mapselect, bool next);
    // �������� �������������� ������ �� �������
    // ����� = false - �����
    bool ShowDialogInfo(QDMapObj *mapobj);
};

#endif // QDMSELOB_H
