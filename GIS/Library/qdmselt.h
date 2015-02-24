/******** QDMSELT.H ************* Dishlenko S.G.  ****** 22/03/12 **
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
*        ����� ��������� ������� ������/�����������                *
*                                                                  *
*******************************************************************/

#ifndef QDMSELT_H
#define QDMSELT_H

#include "maptype.h"

#define MAX_STRING 256
#define MAX_SELECT 256           // 16/03/10

class QDMapViewAcces;
class QDMapPointAcces;
class QDMapObjAcces;

class QDMapSelect
{

public :
    QDMapSelect(QDMapViewAcces *mapview);
    ~QDMapSelect();

    void SetCountListSelect();
    // ��������� ��������� ��������
    bool GetCheckKey(int key);
    // ��������/��������� ������� �� ����������� ����
    bool GetIncode(int incode);
    void SetIncode(int incode, bool value);
    // ��������/��������� ������� �� �������� ���� � �����������
    bool GetExcode(int excode, int local);
    void SetExcode(int excode, int local, bool value);
    // ��������/��������� ������� �� ����� (����������� �������� ������� � ��������������)
    bool GetKeyObject(char *keyobject);
    void SetKeyObject(char *keyobject, bool value);
    // ��������/��������� ���� (�������)
    bool GetLayers(int number);
    void SetLayers(int number, bool value);
    // ��������/��������� ������� �� ��������� �����������
    bool GetLocal(int objlocal);
    void SetLocal(int objlocal, bool value);
    // ���������� ������������ ������� ������� ��������
    DWORD GetMaxKey();
    void  SetMaxKey(DWORD value);
    // ���������� ����������� ������� ������� ��������
    DWORD GetMinKey();
    void  SetMinKey(DWORD value);
    // ���������� ������ � �������� � ��������� ��������     // 09/12/09
    // ���� ��� ����� ����� -1, �� ��������������� ������ �� ���� �������.
    void SetSelectKey(int aMin, int aMax);
    // ���������� ������ �����������/������ (� ��������)
    void GetLeftTop(double *left, double *top);
    void SetLeftTop(double left, double top);
    void GetRightBottom(double *right, double *bottom);
    void SetRightBottom(double right, double bottom);
    // ������� ��������� �� ������
    int  GetPlaceIn();
    void SetPlaceIn(int value);
    // ������� ��������� �� ������
    int  GetPlaceOut();
    void SetPlaceOut(int value);
    // ��������/��������� ���� �����
    bool GetLists(int number);
    void SetLists(int number, bool value);
    // �������� ���������
    char *GetSemanticValue(int number);
    // ��� ���������
    int GetSemanticCode(int number);

    int GetSemanticCondition(int number);
    int GetSemanticCount();
    // ��������/��������� � ����� ����������
    bool GetMapSites(int number);
    void SetMapSites(int number, bool value);

    // ����� �����, ��� ������ ������������ �������������� ���������
    void SetSiteNumber(int value);
    void SetMapView(QDMapViewAcces *value);
    // ��� ���� �� ���� ������������ ��������� ������
    bool GetAllFindSites();       // ��� �� Sites ������������
    void SetAllFindSites(bool value);
    // ��������� ���� �� � ������ �������� ���� �� ����
    bool GetIsSample(int sitenumber);
    // ������� ������������� � Select �������� �������� � ��������
    RECT GetRect(bool notnull);
    // ������� ������������� � Select �������� �������� � ������� PlaceOut
    MAPDFRAME GetDFrame(bool notnull);
    // ��������� Hselect ��� ������� �����
    HSELECT GetHSelect(int number);
    // ��������� ������� �����
    void MapAction(int action);

    // ��� ����������� �������� QDMapSelect
    void Assign(QDMapSelect *source);
    // �������� ��� ������� ������/����������� ��� ������� �����
    void Clear();
    // �������� ��� ������� ������/����������� ��� ���� ����
    void ClearAll();
    // �������� ��� ������� ������ �� ���������
    void ClearSemantic();
    // �������� ������� �� ���������
    int AddSemantic(int Code, char *value, int condition);
    // ������� ������� �� ���������
    void DeleteSemantic(int number);
    // ������� ������� �������� ����������� // ����������
    void  SetSelect();
    // �������� ������ �������� �� ���� ���������� ������� ������/�����������
    void ClearSampleAll();
    // ����������/����� ������ � ��������� ������� ��������� ����� �����.
    int  SelectSample(bool seting, char *listname, int key);
    // ���������� ����������� ��� ������� � ������/��������� ��� ����, ��� ������� ��������
    // ���� �� ���� ������ � ������(���� ��������� ������� SelectSample)
    void SetSiteEnabledForSample();
    // ���������� � ��������� ��������� ������ �������� �� �������.
    int  SelectSeekArea(int siten, QDMapObjAcces *object, double distance,
                        int filter, int inside, int visible, int action);
    // �������� � ��������� ��������� ������ �������� �� �������
    void UnselectSeekArea(int sitenumber);
    // ������� ������� �������� ������ �����   // 09/12/09
    void GetSeekSelect(int aSite);
    // ���������� ������� �������� ������ �����
    void SetSeekSelect(int aSite);
    // ������� ������� �������� ����������� �����   // 09/12/09
    void GetViewSelect(int aSite);
    // ���������� ������� �������� ����������� �����
    void SetViewSelect(int aSite);
    // ������ ����� �������� �� �����, ��������������� �������� ������   // 09/12/09
    // ���� aSiteNumber = -1 �� ������� ��� ���� ����
    int GetSelectObjectCount(int aSiteNumber);
    // �������� select �� ������ �����                    // 16/03/10
    void DeleteSiteFromListSelect(int numsite);
    
public :
    // ��� ����������� �����������   !!!!!!!!
    QDMapViewAcces  *VarMapView;                                                    // 22/03/12
    QDMapPointAcces *VarMapPoint;
    HSELECT         VarListSelect[MAX_SELECT]; // ���������� Select �� ����� ����   // 16/03/10
    MAPDFRAME       VarMapRect;
    int             VarSite;       // ����� ����� � ������� �������� ������� ������
    int             CountSelect;               // ���������� select = ���-�� ����. ������
    bool            VarEdit;       // ������� ������������ ���������
    bool            VarListUses[MAX_SELECT];   // ���/���� (������������ ��� ������)
    char            StringOut[MAX_STRING];
};

#endif // QDMSELT_H
