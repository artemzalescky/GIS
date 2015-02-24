/******* QDMVIEWA.H ************* Dishlenko S.G.  ****** 09/11/07 **
*                                                                  *
*              Copyright (c) PANORAMA Group 1991-2007              *
*                      All Rights Reserved                         *
*                                                                  *
********************************************************************
*                                                                  *
*                      FOR Qt-DESIGNER                             *
*                                                                  *
********************************************************************
*                                                                  *
*       �������� �������� ������ ������� � ��'����                 *
*                     "����������� �����"                          *
*                                                                  *
*******************************************************************/

#ifndef QDMVIEWA_H
#define QDMVIEWA_H

#include <QWidget>                                     // 09/11/07
#include <QTextCodec>                                  // 06/04/06
#include "qdmtype.h"                                   // 28/11/03

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++ ������� ����� "��������� ���������� ����������� ������" ++++
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
class  QDMapViewAcces : public QWidget                 // 09/11/07
{
    Q_OBJECT

public :
    QDMapViewAcces(QWidget *parent = 0, const char *name = 0);

   // �������� ������������� �����
   virtual HMAP GetMapHandle();

   // �������� ������ ������� � �����
   virtual QDMapViewAcces *GetMapViewAcces();

   // �������� �������� ������                // 07/04/06
   const char * GetClassName();

   // ���������� �������� ������              // 07/04/06
   void SetClassName(char *name);

public :
   // ��� ����������� �������������
   HMAP VarMapHandle;         // �������� ������������� �����
   QTextCodec *MainCodec;     // 02/06/06
   char ClassName[260];       // 07/04/06
};

#endif  // QDMVIEWA

