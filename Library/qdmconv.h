/******** QDMCONV.H ************* Dishlenko S.G.  *****  14/11/05 **
*                                                                  *
*              Copyright (c) PANORAMA Group 1991-2005              *
*                      All Rights Reserved                         *
*                                                                  *
********************************************************************
*                                                                  *
*                      FOR Qt3-DESIGNER                            *
*                                                                  *
********************************************************************
*                                                                  *
*  ���������      : QDMapConvertor - ��������� ����������� �����   *
*                                                                  *
*******************************************************************/

#ifndef QDMCONV_H
#define QDMCONV_H

#include "qdmcompa.h"

//++++++++++++++++++++++++++++++++++++++++++++++++++
//+++ �����  - ���������� ����������� �����        +
//++++++++++++++++++++++++++++++++++++++++++++++++++

class QDMapView;

class QDMapConvertor : public QDMapComponent
{
    Q_OBJECT

// ������� ��� �� �����������
//    Q_PROPERTY(QDMapView MapView READ GetMapView WRITE SetMapView FROMSTRL def TOSTRL def ORDER 1)

public :

    // ��� ������������
    //-------------------------------------------
    QDMapConvertor(QWidget *parent = 0, const char *name = 0);
    ~QDMapConvertor();
    // ��������� �� �����
    void SetMapView(QDMapView *value);
    QDMapView    *GetMapView() const;
    // ���������/���������� �������� ����� ������� ������
    void         SetSourceName(const QString value);
    QString      GetSourceName();                     // 11/11/05
    // ���������/���������� �������� ����� �������� ������
    void         SetDestName(const QString value);
    QString      GetDestName();
    // ���������/���������� ��� ������� ������
    void         SetSourceType(int value);
    int          GetSourceType();
    // ���������/���������� ��� �������� ������
    void         SetDestType(int value);
    int          GetDestType();
    // ��������� ������� ��������������� ������
    void         Convert();

    // ������� ������� � ����������
    //-------------------------------------------

public :
    QString VarSourceName;
    QString VarDestName;
    int     VarSourceType;
    int     VarDestType;
};

#endif // QDMCONV_H
