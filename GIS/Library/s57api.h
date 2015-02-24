/****** S57API.CPP   *********** Dishlenko S.G.  ****** 19/01/10 ***
*                                                                  *
*              Copyright (c) PANORAMA Group 1991-2010              *
*                      All Rights Reserved                         *
*                                                                  *
********************************************************************
*                                                                  *
*                            FOR  LINUX                            *
*                                                                  *
********************************************************************
*                                                                  *
*          �������� API-���������� ��������� ��������� S57.ED3     *
*                                                                  *
*******************************************************************/


#ifndef S57API_H
#define S57API_H

#ifndef MAPTYPE_H
  #include "maptype.h"   // �������� �������� ���������� MAPAPI
#endif

extern "C"
{
  // ��������� S57-���� � ����� (����� �� ����������)
  // s57name - �������� ����� S57
  // mapname - �������� ����� �������� �����
  // parm    - ��������� (���� ��������� ����� ���� ���������������� � 0)
  // ��� ������ ���������� 0
  long int WINAPI _export LoadS57ToMap(const char* s57name, char* mapname, TASKPARM* parm);

  // ��������� ����� � S57-����
  // hmap    - ������������� �����
  // s57name - �������� ����� S57
  // parm    - ��������� (���� ��������� ����� ���� ���������������� � 0)
  // ��� ������ ���������� 0
  long int WINAPI _export LoadMapToS57(HMAP hmap, char* s57name, TASKPARM* parm);

  // ����� ������� "��������� ���������� ������� ���� ������� S57"   // 19/01/10
  // hmap    - ������������� �����
  // parm    - ��������� (���� ��������� ����� ���� ���������������� � 0)
  // ��� ������ ���������� 0  
  long int WINAPI _export CallS57SetupDialog(long int hmap,TASKPARM * parm);
}

#endif  // S57API_H
