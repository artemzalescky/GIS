/******* QDMOBJ.H  ************* Dishlenko S.G.   ****** 22/03/12  *
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
*     �������� ������ "��������� - ������ ����������� �����"       *
*                                                                  *
*******************************************************************/

#ifndef QDMOBJ_H
#define QDMOBJ_H

#include "qdmobja.h"
#include "qdmcmp.h"
#include "qdmpoint.h"
#include "mapapi.h"             // 28/11/03

class QDMapSemantic;
class QDMapMetric;

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++ ����� "��������� - ������ ����������� �����"                ++
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class QDMapObj : public QDMapObjAcces
{
  Q_OBJECT

// �������������� ��� �� "�����������"                        // 18/11/03
//  Q_PROPERTY(QDMapView MapView READ GetMapView WRITE SetMapView FROMSTRL def TOSTRL def ORDER 1)  // 24/07/03

  public :
    QDMapObj(QWidget * parent = 0, const char * name = 0);
    ~QDMapObj();

    // ������� ������ ����� �� ��� �������� (��� ������������� �� ������� ��������)
    void CreateObject(int site, int kind, bool text, int list, int excode, int local);
    // ������� ������ ������
    void CreateNullObj(int sitenumber);
    // �������� ��������� � �����
    void Commit();
    // ������� ������ �� �����
    void Delete();
    // ����� ������ ����� �� ��� ���������� ����������
    int  SeekObject(char *listname, int key);
    // ����������� ����������� ������� ����� � ����� ����
    void Center();

    enum  TOBJECTSTYLE   // ������ ������������ �������� �����
    {
      OS_NOVIEW = 1,       // ������ �� ������������
      OS_NORMAL = 2,       // ������������ � ��������� ����
      OS_SELECT = 3        // ������ ���������� �������� ��������
    };

    enum TOBJECTSTYLESELECT   // ��� ������������ (�����������) ����������� ������� �����
    {
      SEL_LINE     = 1    // ��������� ������. ��������� Image, Mode, Parm ������������
                           // ������������� ���������� Image, Mode, Parm
                           // �������� ���������� ������ � 2 ������� (������� IMGLINE)
    };


    int            GetKey();
    int            GetExCode();
    int            GetInCode();
    int            GetLocal();
    char *         GetObjName();
    int            GetImage();
    int            GetMode();
    char *         GetParm();
    char *         GetListName();
    char *         GetText(int subobj);
    bool           GetTextType();
    double         GetSquare();
    double         GetPerimeter();
    double         GetLength();
    int            GetSiteNumber();
    // ���������� ������������� ���������������� �����
    HSITE          GetSiteHandle();
    int            GetListNumber();
    int            GetPlaceOut();
    // ���������� �������� ������� � ��������� ������� ���������
    MAPDFRAME      GetObjFrame(int place);
    int            GetLayerNumber();
    void           SetStyle(int value);
    void           SetColorImage(int value);
    // ���������� ��� ����������� ����������� ������� �����
    void           SetStyleSelect(int value);
    void           SetText(int subobj, char * value);
    void           SetObjHandle(HOBJ value);
    // ����������/��������� ������� � ������ ������� ��������
    void           SetBotTopScale(int bot, int top);
    void           GetBotTopScale(int *bot, int *top);
    virtual void   SetMapView(QDMapView *value);
    QDMapView      *GetMapView() const;          
    // ���������� �������� ������� ��������� ������              
    // ����    acreate - ���� �� ����� ��������� ���������� ������� ������������ ��������
    //                QDMapObj (��� �������, �������, ���������) ������ ��� �� ����������
    //                ������ ���
    // ����� = true - ��� ������� � ����� �����������
    bool           SetObjectByDLg(bool acreate);

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// ���� ������� ��� ����������� �������������
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // ������������ ������ �����
    void           Repaint();
    void           MapAction(int acttype);
    void           Paint(HDC dc, RECT rect);
    void           RepaintPrivate(QDMapViewAcces *mapview);
    // ���������� ������� ������ �����
    void           FreeCurrentObj();

public :
    // ������������ ������ �� ������ !!!!!!!!
    QDMapSemantic    *VarSemantic;        // 22/03/12
    QDMapMetric      *VarMetric;
    MAPDFRAME        VarObjFrame;
    PAINTPARM        VarImage;
    int              VarStyle;
    int              VarPlace;           // ������� ��������� �� MapApi PP_
    int              VarColorImage;
    int              VarColorImageLin;
    int              VarInCodeImage;
    int              VarStyleSelect;     // ��� ���������
    bool             VarOldFrame;
    char             StrVal[256];        // 18/10/05
};

#endif // QDMOBJ_H
