/******** QDMTYPE.H ************* Dishlenko S.G.  *****  31/01/07 **
*                                                                  *
*              Copyright (c) PANORAMA Group 1991-2007              *
*                      All Rights Reserved                         *
*                                                                  *
********************************************************************
*                                                                  *
*                      FOR Qt4-DESIGNER                            *
*                                                                  *
********************************************************************
*                                                                  *
*               ���������� ����� � ����������                      *
*                                                                  *
*******************************************************************/

#ifndef QDMTYPE_H
#define QDMTYPE_H

#include "maptype.h"

// ��� ������������� ��������� ��� QDMapSelectDialog
enum MAPSELECTDIALOGRETCODE
{
   MRCANCEL  = 0,
   MROK      = 1,
   MRALLMARK = 2
};

// ���� ������� ��� ��������� �����
typedef enum MAPACTIONTYPE
{
    ACTBEFOREPAINT            = 1,
    ACTAFTERPAINT             = 2,
    ACTBEFORECLOSE            = 3,
    ACTAFTEROPEN              = 4,
    ACTAFTERAPPENDSITE        = 5,
    ACTBEFOREDELETESITE       = 6,
    ACTDOREPAINTFORCHANGEDATA = 7, // ���������� ������ � ���� �����������
    ACTAFTERCHANGEBORDER      = 8
} MAPACTIONTYPE;

// ���� �������� ��� ��������� �����
typedef enum MAPOPERATION
{
    OPREMOVE           = 1,
} MAPOPERATION;

enum  TSEMANTICSTYLE // ������ ������ �������� ��������� �������� �����
{
   SS_NODECODE     = 0,     // �������� �� �������������
   SS_NORMALDECODE = 1,     // �������� �������������
   SS_FULLDECODE   = 2      // �������� ������������� � ����������� ������� ���������
};

// ���� �������������� ������ ����������
enum TCONVERTERTYPESOURCE
{
  TS_VIEW      = 0,
  TS_MAP       = 1,
  TS_DIRSXFWIN = 2,
  TS_SXFWIN    = 3,
};

// ���� �������������� ������ ����������
enum TCONVERTERTYPEDEST
{
  TD_VIEW      = 0,
  TD_MAP       = 1,
  TD_DIRSXFWIN = 2,
  TD_SXFWIN    = 3,
};

// �������� ���������� ������� �� �������������� �����
typedef struct
{
   int             NumbSite;  // ����� ����� (��� �������� = 0)
   int             Incode;    // ���������� ��� �������
   int             ExCode;    // ����������������� ���
   int             Local;     // �������� �����������
   int             Segment;   // �O��� ����
   char            *Name;     // �������� �������
   char            *KeyName;  // ���������� ��� ������� � �����-��
   char            *Key;      // ����
}
  TMAPOBJECTINFO;


// �������� SXF, DIR � ������ MAP
typedef long int (* QDLoadSxf2Map)(char* lpszsource,
                                   char* lpsztarget,
                                   TASKPARM* parm);
typedef long int (* QDLoadDir2Map)(char* lpszsource,
                                   char* lpsztarget,
                                   TASKPARM* parm);

// �������� DIR
typedef long int (* QDSaveMap2Dir)(HMAP hmap,
                                   const char* lpsztarget, TASKPARM* parm);
// �������� SXF
typedef long int (* QDSaveMap2Sxf)(HMAP hmap,
                                   const char* lpsztarget, TASKPARM* parm);

#endif // QDMTYPE_H
