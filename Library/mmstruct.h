/****** MMSTRUCT.H ***********   Belenkov O.V. ******** 03/05/10 ***
******* MMSTRUCT.H ***********   Dishlenko S.G.******** 26/03/12 ***
*                                                                  *
*              Copyright (c) PANORAMA Group 1991-2012              *
*                     All Rights Reserved                          *
*                                                                  *
********************************************************************
*                                                                  *
*                   FOR WINDOWS95 & WINDOWS NT                     *
*                                                                  *
********************************************************************
*                                                                  *
*                                                                  *
*            ����� �������� ����� �� ��������                      *
*                                                                  *
*******************************************************************/

#if !defined(MMSTRUCT_H)
#define MMSTRUCT_H

typedef struct INFOLIST 
{
  char  Nomenclature[32];     // ������������
  int   Scale;                // �������                          // 26/03/12
  int   CountObject;          // ���������� ��������
  int   Type;                 // ��� �����
} 
  INFOLIST;

typedef struct INFOSXF 
{
  char  SheetName[32];
  char  Nomenclature[32];
  int   RealCoordinate;
  int   Scale;
  int   RecordCount;
  int   MapType;
} 
  INFOSXF;

typedef struct INFODIR 
{
  char  SheetName[32];
  char  NameRsc[MAX_PATH];
  int   CountList;
} 
  INFODIR;

typedef struct ARRAYNAME
{
  int   Code;          // ��� ��������� ��� ������
  int   Title;         // ������� ����� ��������
  int   Count;         // ���������� ��������� ��������
  char       Name[16][256]; // ������ ��������� �������� ��� ������ �� �����
}
 ARRAYNAME;

typedef struct MYSEMCHOICE
{
  int    Code;
  char        Value[256];
  int    Data;
}
  MYSEMCHOICE;

// �������� ��������� ���������� ��� ������� ������                   25/11/02

typedef  char LISTSNAME[260];   // ��� �����

typedef struct  NAMESARRAY
{
   int   Size;          // ������ ���������
   int   Count;         // ���������� ������� LISTSNAME
   LISTSNAME  Record[1];     // ������
}
   NAMESARRAY;

typedef struct INFOCOORD 
{
  double  CoordPsp;
  double  CoordCalc;
  double  Delta;
  int     Number;
  int     Reserve;
}
  INFOCOORD;
 
//#define IDN_STAFFD                  6703
//#define IDN_SEARCHD                 6704

// ��� ������ ������ � �������� ���������� � ��������� TASKPARM
// ���������� ���� � ����� *.hlp,������� �������� ������
// � ���������������� "6703" ��� ������� ������������ ��������
// � "6704" ��� ������� ������ �������� �����

// �������� ��������� ���������� ��� �������������� ���������� ������ ��������.
// ������������ ��� ��������� ������������ �������������� ���������� ������
// �������� ����� �������� selSetObjectSearchEx(...)

typedef struct RESTOREMODE
{
   int    Note;          // ���������� ��� ��������������/����������� ��������� �������
   int    VisualSeek;    // ���� ������ ����� ������� �� ����� ��������.
   int    MapSeek;       // ���� ������ �� ������.
   int    RestoreSelect; // ���� �������������� ��������� ������.
}
   RESTOREMODE;

// ���������        ��������

// Note             ����� �������� �������� ������� ������ ��� ������ ���������
// VisualSeek
//                  "-1" - ���������� ������������ ��������;
//                  "0"  - ���������� ����� ��� ����� ��������� ��������;
//                  "1"  - ���������� ����� � ������ ��������� ��������.
// MapSeek
//                  "-1" - ���������� ������������ ��������;
//                  "-2" - ���������� ����� �� ���� ������;
//                  "0...n" - ���������� ����� � ����� � ��������� �������.
// RestoreSelect
//                  "-1" - ���������� ������������ �������� ������;
//                  "0"  - ������������ ������� ��������� ��������� ������.


// �������� ��������� ���������� ��� ������� ������ �������� �� �������.

typedef struct AREASEEKPARM
{
   int Size;          // ������ ���������.
   int RestoreSelect; // ���� �������������� ��������� ������ �� �������.
   int ToSelectArea;  // ���� ������ ������� ������
   int VisualSeek;    // ���� ������ ����� ������� �� ����� ��������.
   int MapSeek;       // ���� ������ �� ������.
   int AreaType;      // ��� ������� ������: ������/�������� �����.
   int InsideFlag;    // ���� ������ ������.
   int FilterFlag;    // ���� ������������� ������� ��������.
   int AreaAction;    // ������� ������ �������� �����.
   int InversionFlag; // ���� ���������� ��������� ��������       26/02/02
   double   Distance;      // ���������� ������ (� ������).
}
   AREASEEKPARM;

// ���������        ��������

// RestoreSelect
//                  "-1" - ���������� ������������ �������� ������;
//                  "0"  - ������������ ������� ��������� ��������� ������.
// VisualSeek
//                  "-1" - ���������� ������������ ��������;
//                  "0"  - ���������� ����� ��� ����� ��������� ��������;
//                  "1"  - ���������� ����� � ������ ��������� ��������.
// MapSeek
//                  "-1" - ���������� ������������ ��������;
//                  "-2" - ���������� ����� �� ���� ������;
//                  "0...n" - ���������� ����� � ����� � ��������� �������.
// ToSelectArea
//                  "0"  - �� ��������� ����� �������;
//                  "1"  - ��������� ����� �������.
// AreaType
//                  "0"  - ������� ������ ���������� �����;
//                  "1"  - ������� ������ �������� �����.
// InsideFlag
//                  "0"  - ������ ������� ��� �������;
//                  "1"  - ������ �������, �������� � ������� ���� �� ����� ������;
//                  "2"  - ������ �������, ����������� ������� ������ �������.
// FilterFlag
//                  "0"  - �� ������������ ������ ��������;
//                  "1"  - ������������ ������������� ������ ��������.
// AreaAction
//                  "0"  - ���������������� ����� �� ���� ������� ��������;
//                  "1"  - ��������������� ����� ���� ��������, ���������������
//                         ������� ���������� �����.
// Distance              - ���������� ������ � ������.


#endif  // MMSTRUCT_H
