/******** QDMDSEM.H ************* Dishlenko S.G.  ****** 22/03/12 **
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
*                  ������ ������� � ���������                      *
*                                                                  *
*                                                                  *
*******************************************************************/

#ifndef QDMDSEM_H
#define QDMDSEM_H

#include "qdmtype.h"                               // 28/11/03

class QDMapObjAcces;
class QDMapViewAcces;

//++++++++++++++++++++++++++++++++++++++++++++++++++
//+++  ����� ������� � ��������� ������� �����     *
//++++++++++++++++++++++++++++++++++++++++++++++++++

class QDMapSemantic
{
  public :

    QDMapSemantic(QDMapObjAcces *mapobj);
    ~QDMapSemantic();

    // �������� ��������� �� �� ������ � �������
    RSCSEMANTICEX GetDescribe(int number);
    // ���������� ������� � �������������� �������� ��������� �� �� ������ � �������
    int          GetClassificatorCount(int number);
    // �������� �������� ��������� �� �������������� �������� �� ������ ��������� � �������
    // � ������ ��������
    char         *GetClassificatorName(int number1, int numbervalue);
    // ��� �������� ��������� �� �������������� �������� �� ������ ��������� � �������
    // � ������ ��������
    int          GetClassificatorCode(int number1, int numbervalue);
    // ���������� ������������� �������������
    int          GetSemanticCount();
    // �������� ������������� ��������������
    char         *GetSemanticName(int number);
    // ��� ������������� ��������������
    int          GetSemanticCode(int number);
    // ���������/���������� �������� ������������� ��������������
    char         *GetSemanticValue(int number);
    void         SetSemanticValue(int number, char *value);
    // ���������� ���������� ����� ���������
    int          GetAvailabelSemanticCount();
    // ���������� ������� ���� ���������
    int          GetAvailabelSemanticCode(int number);
    // ������������ ���������� ��������
    char        *GetAvailabelSemanticName(int code);
    // ���������� �������� � �������������� �������� ��������
    int         GetSemanticValueCount(int code);
    // �������� ���������� ��������
    char        *GetSemanticValueName(int code, int number);
    // �������� ����� ��������������
    int         Add(int code);
    // ������� ��������������
    void        Delete(int number);
    // ����� ����� ��������� � ������� �� �� ����
    int         FindByCode(int code);
    // ������� ��������� � ������� �� �� ���� ���� ��� ���
    void        DeleteByCode(int code, bool all);
    // ������/��������� ������ �������������� �������� ���������
    void           SetSemanticStyle(int value);
    int            GetSemanticStyle();

public :
    // ������ �� ������ !!!!!!!!!
    QDMapObjAcces  *VarMapObj;
    RSCSEMANTICEX  VarSemanticType;
    int            VarSemanticStyle;  // ������ �������������� �������� ���������  // 22/03/12
    char           Value[256];         // 18/10/05  
};

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++  ����� ������� � �������� �������� � �������������� +
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class  QDMapSemantics
{
  public :
    QDMapSemantics(QDMapViewAcces *mapview);
    ~QDMapSemantics();

    // ���������� ����� ��������� � �������������
    int           GetSemanticCount();
    // ��� ���������
    int           GetSemanticCode(int number);
    // ������������ ���������
    char          *GetSemanticName(int number);
    // ������������ ��������� �� ����
    char          *GetSemanticNameCode(int code);
    // ��� ��������� �� �� ������������
    int           GetSemanticCodeName(char *name);
    // ���������� ����� ��������� �� �����
    int           GetNumberByKey(char *key);
    // ��� ��������� �� �� ����
    int           GetTypeByCode(int code);
    // ���������� ��������-���� ��������� �� �� ����
    char          *GetKeyByCode(int code);
    // ���������� �������� �������������� ������������� �������������� �� ���� ���������
    // (���� �� ��� TCODE) ��� ������ ���������� ����
    int           GetClassificatorValueCount(int code);
    // �������� �������� �������������� �� �������������� ��������� �� ���� ��������� �
    // ����������������� ������ � ��������������
    char          *GetClassificatorValueName(int code, int valuenumber);
    // ��� �������� �������������� �� �������������� ��������� �� ���� ��������� �
    // ����������������� ������ � ��������������
    int           GetClassificatorValueCode(int code, int valuenumber);
    // �������� �������� ��������� �� �� ����
    RSCSEMANTICEX GetDescribeByCode(int code);

    // ��� ���������� �����������  !!!!
    void          SetRscHandle(HRSC rsch);
    HRSC          GetRscHandle();

public :
    QDMapViewAcces *VarMapView;
    HRSC           VarHRsc;
    // ---------------------------------
    // ��� ������������
    int            VarSiteNumber;      // ����� ���������������� ����� � ������� ��������
                                       // � ������ ������ ���������
    char           Value[256];         // 18/10/05  
};

#endif   // QDMDSEM_H

