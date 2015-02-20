/******** QDMDMET.H ************* Dishlenko S.G.  ****** 31/01/03 **
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
*           ����� ������������ �������� ������� �����              *
*                                                                  *
*                                                                  *
*******************************************************************/

#ifndef QDMDMET_H
#define QDMDMET_H

class QDMapObjAcces;
class QDMapPointAcces;

//++++++++++++++++++++++++++++++++++++++++++++++++++
//+++ ����� ������������ �������� ������� �����    *
//++++++++++++++++++++++++++++++++++++++++++++++++++

class QDMapMetric
{
  public :

    QDMapMetric(QDMapObjAcces *mapobj);
    ~QDMapMetric();

    // �������� ����� � ������
    void             Append(int subobj, QDMapPointAcces *mappoint);
    // ������� ����� �������
    void             Delete(int subobj, int number);
    // �������� �����
    void             Insert(int subobj, int number, QDMapPointAcces *mappoint);
    // �������� ����� �������
    void             Update(int subobj, int number, QDMapPointAcces *mappoint);
    // ���������/���������� ���������� �����������
    int              GetSubObjCount();
    void             SetSubObjCount(int value);
    // ���������/���������� ���������� ����� � ����������
    int              GetPointCount(int subobj);
    void             SetPointCount(int subobj, int value);
    // ���������/���������� ����� �������
    QDMapPointAcces  *GetPoints(int subobj, int number);
    void             SetPoints(int subobj, int number, QDMapPointAcces *mappoint);

public :
    QDMapObjAcces   *VarMapObj;
    QDMapPointAcces *VarMapPoint;
};

#endif  // QDMDMET_H
