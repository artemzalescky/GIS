/******* QDMNET.H     ************* Dishlenko S.G. ***** 22/03/12 **
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
*     �������� ������ "��������� ������� ������"                   *
*                                                                  *
*******************************************************************/

#ifndef QDMNET_H
#define QDMNET_H

#include "qdmcmp.h"
#include "netapi.h"

class QDMapSelect;

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++ ����� "��������� ������� ������"                            ++
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class QDMapNet : public QDMapComponent
{
    Q_OBJECT

//    Q_PROPERTY(QDMapView MapView READ GetMapView WRITE SetMapView FROMSTRL def TOSTRL def ORDER 1)  // 24/07/03
//    Q_PROPERTY(QDMapObj  MapObj  READ GetMapObj  WRITE SetMapObj  FROMSTRL def TOSTRL def ORDER 2)  // 24/07/03

public  :
    QDMapNet(QWidget * parent = 0, const char * name = 0);
    ~QDMapNet();

    virtual void SetMapView(QDMapView *value);
    QDMapView    *GetMapView() const;

    void         SetRscName(char *rscname);
    void         SetNetName(char *netname);
    void         SetSelect(QDMapSelect *mapselect);
    int          GetNetSitNumber();
    // ��������� ������ �� ����������� � �������� ���-�� �����
    int          GetSelectResult(); 
    // ��������� ���� - ������� handle Sit-� � �����
    HSITE        BuildNet(bool ShowDialog);
    // ����� ���������� ���� ����� ������ � ��������
    int          GetShotWayDlg(HOBJ NodeStart, HOBJ NodeFinish);
    // ����� ���������� ���� ����� ������ ��� ������a �� �������
    int          GetFastWay(HOBJ NodeStart, HOBJ NodeFinish, double speed);
    // ����� ���������� ���� ����� ������ ��� ������a �� ���������
    int          GetShotWay(HOBJ NodeStart, HOBJ NodeFinish);
    // ����� ����� �� �������� �������� �� ����
    int          GetEdgesFromNode(HOBJ Node, double Meters);
    // ����� ��������� ���� � �����
    int          GetNodeByPoint(HOBJ ObjHandle,  DOUBLEPOINT *PlanePoint);
    //-------  HGRAPH ---------------------
    // �������� ��� �������� �������� �����
    HGRAPH       OpenGraph(HMAP Map, HSITE Site);
    //   �������
    int          CloseGraph(HGRAPH Graph);
    // ����� ���������� ���� ����� ������ ��� ������a �� ������� c ��������� ������� , ���������� ���������
    int          GetFastWayAndCreateObject(HOBJ Info, HOBJ NodeStart, HOBJ NodeFinish, double speed);
    // ����� ���������� ���� ����� ������ ��� ������a �� ��������� c ��������� ������� , ���������� ���������
    int          GetShotWayAndCreateObject(HOBJ Info, HOBJ NodeStart, HOBJ NodeFinish);
    // ����� ���������� ���� ����� ������ � �������� �� ������� c ��������� ������� , ���������� ���������
    int          GetShotWayDlgAndCreateObject(HOBJ Info, DOUBLEPOINT *PointStart, DOUBLEPOINT *PointFinish);
     // ����� ���������� ���� ����� ������ ��� ������a �� ������� c ��������� ������� , ���������� ���������
    int          GetShotWayByPointAndCreateObject(HOBJ Info, DOUBLEPOINT *PointStart, 
                                                  DOUBLEPOINT *PointFinish);
    // ����������� ����������� ���������� ����� ����� ������� � ������ ��������������
    // �������� � ����������� ����� (��������� ��������)
    int          GetShotWayByPointExAndCreateObject(HOBJ Info, DOUBLEPOINT *PointStart, 
                                                    DOUBLEPOINT *PointFinish, HSELECT select);
    // ���������� ������������ ���� ����� ������� (������ ����)
    int          GetMinimalPath(DOUBLEPOINT *arraypoint, int count);
    // ���������� ������������ ���� ����� ������� (������ ����)
    int          GetMinimalPathSite(HSITE tempsite, DOUBLEPOINT *arraypoint, int count);
    // ���������� ������������ ���� ����� ������� (������ ����)
    double       GetMinimalPathEx(DOUBLEPOINT *arraypoint, int *arraynumber, int count,
                                  int flagreturn, int flagcalc);
    // �������� ������������� �����
    virtual HGRAPH GetGraphHandle();
    // ��������� ��������� ��� ������ ������
    void         InitTaskParmEx(TASKPARMEX *taskparm);
    // ��������� ������� �����    // 18/03/10
    void         MapAction(int action);

public:
   QDMapSelect *FSelect;                           // 22/03/12
   HSITE       FHSite;
   HGRAPH      FGraph;
   char        FNetName[MAX_PATH];
   char        FRscName[MAX_PATH];
   int         FColor;
};

#endif // QDMAPNET_H
