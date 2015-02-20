/******* QDMOBJA.H  ************* Dishlenko S.G.   ****** 31/01/03 *
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
*     �������� �������� ������ ������� ����������� �����           *
*                                                                  *
*******************************************************************/

#ifndef QDMOBJA_H
#define QDMOBJA_H

#include "qdmcompa.h"

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++ ������� ����� ������� ����������� �����                  +++++
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class QDMapObjAcces : public QDMapComponent
{
  Q_OBJECT

  public :
    QDMapObjAcces(QWidget * parent = 0, const char * name = 0);
    ~QDMapObjAcces();
     // ���������� ������������� �������
     HOBJ GetObjHandle();

  public :
   // ��� ���������� �����������
   HOBJ  VarObjHandle;  // ������������� ������� �����
};

#endif  //  QDMOBJA_H
