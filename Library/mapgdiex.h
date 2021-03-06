/****** MAPGDIEX.H ************* Belenkov O.V.   ****** 24/11/09 ***
******* MAPGDIEX.H ************* Dishlenko S.G.  ****** 26/03/12 ***
*                                                                  *
*              Copyright (c) PANORAMA Group 1991-2012              *
*                      All Rights Reserved                         *
*                                                                  *
********************************************************************
*                                                                  *
*      �������� ���������� ������� ������������ ������������       *
*             ����������� �� ����� ����������� �����               *
*                                                                  *
*******************************************************************/

#ifndef MAPGDIEX_H
#define MAPGDIEX_H

#ifndef MAPGDI_H
  #include "mapgdi.h"
#endif

#if defined(BUILD_DLL64) && defined(LINUXAPI)            // 26/03/12
#pragma pack(push,1)
#endif

#define  IMLIDENT      0x7EEE7EEE // ������������� ������
#define  IMLPARMCOUNT  16         // ����� ���������� (����������)
#define  IMLLISTCOUNT  32         // ����� ������� (����������)

#define  IMG_DRAWLINE    1        // ������������ ����� ���������� ����� � IML
#define  IMG_DRAWSQUARE  3        // ������������ ����� ���������� �������� � IML

#if defined(_M_X64) || defined(BUILD_DLL64)       // 20/07/09
 typedef __int64  HVIEW;
#else
 typedef long int HVIEW;
#endif

typedef struct IMLPARM  // �������� ���������� ���� ��������
{                       // ��� ���������� ��������� IMGDRAW
  int       Ident;      // ������������� ������ 0x7EEE7EEE
  int       Count;      // ����� ���������� � ��������

#if defined(_M_X64) || defined(BUILD_DLL64)       // 16/08/09
  short     Semantic;   // ������� ������� ��������� ��� ����������� �������
  short     Reserv1;    // ������ ���� 0
  short     Reserv2;    // ������ ���� 0
  short     Reserv3;    // ������ ���� 0
#else
  char      Semantic;   // ������� ������� ��������� ��� ����������� �������
  char      Reserv1;    // ������ ���� 0
  char      Reserv2;    // ������ ���� 0
  char      Reserv3;    // ������ ���� 0
#endif

  struct
  {
#if defined(_M_X64) || defined(BUILD_DLL64)       // 16/08/09
    __int64  Type;      // ������ ���������� (IMG_LINE,IMG_DOT..,IMG_DRAW)
                        // ��. mapgdi.h
#else
    long     Type;      // ������ ���������� (IMG_LINE,IMG_DOT..,IMG_DRAW)
                        // ��. mapgdi.h
#endif
    char  *  Name[4];   // �������� �������� (����������) ���������
                        // Name[0]-ML_ENGLISH, Name[1]-ML_RUSSIAN...
  }
    Element[IMLPARMCOUNT];
}
  IMLPARM;

typedef struct IMLLIST
{
  int       Ident;      // ������������� ������ 0x7EEE7EEE
  int       Count;      // ����� ����� �������� � ��������
  struct
  {
#if defined(_M_X64) || defined(BUILD_DLL64)       // 16/08/09
    __int64   Type;     // ��� ���� ������� (�������)
#else
    long      Type;     // ��� ���� ������� (�������)
#endif
    IMLPARM * View;     // ����� �������� ���������� �����������
    char * Name[4];     // �������� �������� (����������) �������
                        // Name[0]-ML_ENGLISH, Name[1]-ML_RUSSIAN...
  }
    Element[IMLLISTCOUNT];
}
  IMLLIST;

// �������� ����������� �����
// Hdc   -  ��� Windows - "HDC", ��� UNIX - "XCONTEXT*", ��.mapapi.h
// Size  -  ������ ������� ������, ���������� ������ ����� 0,0
// View  -  ��� ���������� ������ (�����/�������)
// HView -  ��������� �� ��������� ��������� (�� ������ ���������� !)
// Scale -  ������� ����������� ������������ �������� �������� �����
//   (����� 1, ����� ������� ����������� ����� �������� �����,
//   ��� ���������������� �������� ��� ���������� ����� ����� 1,
//   �� ����, �� ���������� ���������� �����).
//   ��������, ��� ����������� �����  �������� 1:200000
//   � �������� 1:500000, ������������� ������� ����� 0.4 .
//   ����������� ��� ������������� ����������� ��������.
//   ���� ������ �� �������������� - �������� �������� �� ����� 1.
// (�������� ������������� ������� ���������� (!) ��� "����������������"
//  ��������������� ����� ���������� ���: Real = 2 * Scale - 1;
//  ���� ���������� "���������" ������ ��������������� ����� ���
//  ����� ��������� (Scale < 1.0),
//  �� Scale ������������� ��������� ��������� ��������;
//  ScaleMethod - c����� ���������������.

typedef struct IMGCONTEXT
{
  int        Length;    // ����� ��������� ��� �������� (64 ����)

#if defined(_M_X64) || defined(BUILD_DLL64)       // 16/08/09
  int        View;      // ��� ����������� VT_SCREEN, VT_PRINT (maptype.h)

  HDC        Hdc;       // �������� ���������� ������ (��� ������ � UNIX = 0)
#else
  HDC        Hdc;       // �������� ���������� ������ (��� ������ � UNIX = 0)

  int        View;      // ��� ����������� VT_SCREEN, VT_PRINT (maptype.h)
#endif
  HVIEW      HView;     // ������������� ���������� ���������� (����� HMAP ��� 0)

  DRAWSIZE   Size;      // ������ ������� �����������

  float      Scale;     // ������� ����������� ������������ ��������
                        // �������� ����� (��� ���������������� ��������
                        // ��� ���������� ����� ������ ����� 1)
  int   ScaleMethod;    // ������ ��������������� (0 - ����������������,
                        // 1 - ���������, ����� "����")

  double     PixelX;    // ����������� ��������� ������ � ������� ����������
                        // �� �����������
  double     PixelY;    // ����������� ��������� ������ � ������� ����������
                        // �� ���������

  double     SinAngle;  // Sin ���� �������� �����       // 19/09/01
  double     CosAngle;  // Cos ���� �������� �����
  double     Angle;     // ���� �������� ����� (������ ������� �������)

  int    Reserv[2];     // ������ = 0
}
  IMGCONTEXT;

// ��� ������ ����� �������� ����� ��� ������� (�������)
// ���������� ����������� ������� � ����� ���������� ������.
// ��� ����� ����������� ���� PixelX � PixelY.
// ��������, ���������� ����� ����� �� ����������� � ������� 1 �� :
// 1 �� = 1000 ��� => 1000 * PixelX (����� ����������)

// ���� ����� ���������� ����� ����� ���������� ��� �������������
// ���������� �� ��������� (�����) � ������ �������� �����������,
// �� ������������� ��������� �������� ���� ShowScale �� ���������
// POLYDATAEX (maptype.h).
// ��������, ���������� ����� ����� �� ��������� � ������� 1 ��
// �� ��������� ��� ����������� � ������� �������� (��������, 1 : 50 000) :
// 1 �� = 10**9 ��� => 10**9/ShowScale = 2 * 10**4 (��� �� �����������)
// => 2 * 10**4 * PixelY (����� ����������)

#ifndef LINUXAPI      // 09/07/01

#ifdef BUILD_DLL      // ������ ���� ���
 #ifndef __BORLANDC__
   #define _IMLAPI WINAPI                      // 09/04/07
 #else
   #define _IMLAPI _import __stdcall
 #endif

 #define _IMLIMP

#else                 // ������ ���������� IML
 #ifndef __BORLANDC__
   #define _IMLAPI WINAPI
   #define _IMLIMP __declspec( dllexport )
 #else
   #define _IMLAPI _export __stdcall
   #define _IMLIMP
#endif
#endif

#else
 #define _IMLAPI
 #define _IMLIMP
#endif

// --------------------------------------------------------
//  �������� ������� ���������� ���������� "IML"
//  ��� ��������� ����� ���� ��������� � ��������� ��
//  ������ � � �++
// --------------------------------------------------------

extern "C"
{
 // ��������� ������ ����� ����������� ��������,
 // �������������� �����������
_IMLIMP const IMLLIST * _IMLAPI imlGetImageList(void);

 // ��������� �������� ����������� ������� � ��������� � ������� ��������
 // type - ��� ������� (IMLLIST),
 // data - ���������� ������� � ��������� (maptype.h);
 // parm - ��������� ����������� (MAPGDI.H);
 // context - �������������� ��������� �����������,
 // border  - ������������ �������� ����������� � ���������.
 // ���� ������� �� �������������� - ���������� ����,
 // ����� - ��������� ��������
 _IMLIMP long int _IMLAPI imlGetImageBorder(long int type,
                                    const POLYDATAEX* data,
                                    const IMGDRAW * parm,
                                    const IMGCONTEXT * context,
                                    FRAME * border);

 // ���������� ������
 // type - ��� ������� (IMLLIST);
 // data - ���������� ������� (maptype.h);
 //   �������� data �������� ���������� ������������� �������
 //   � ������� ���������� ������ (�������)
 //   ������������ ������ �������� ���� ������������ �������.
 //   (���������� ����� ���� (!) :
 //     - ��������������,  ����� ������ ��������
 //       ��� ��������� �� �����;
 //     - �� ��������������� �������� ��������� ��������
 //       ��� �������� ������� ���� :
 //       ����������� ��������� ������ � �.�.;
 //     - ... ������ ������������ ).
 // parm - ��������� ����������� (MAPGDI.H);
 // context - �������������� ��������� �����������.
 // ������������ �������� :
 //  0  - ������ �� ����� (������� ������ �������
 //       ��� ������ �� ����� �� ����������� ...),
 //       ��� ��� ������� �� ��������������;
 //  +1 - ������ ���������.
 _IMLIMP long int _IMLAPI imlPaintImage(long int type,
                                const POLYDATAEX* data,
                                const IMGDRAW * parm,
                                const IMGCONTEXT * context);

 // ���������� ������� ������� � �������� ����
 // �� ���������� ������� (1,2-5 �����), �����������
 // ����� ��������.
 // ����������� ��� ������ ���� ������� � ������
 // "�������" ���� ���������� � �.�.
 // ������ "������ ������" � ��������� size.
 _IMLIMP long int _IMLAPI imlPaintExample(long int type,
                                  const IMGDRAW * parm,
                                  const IMGCONTEXT * context);


 // ��������� ��������� ������������ ������� � ������������ �������
 // type - ��� ������� (IMLLIST);
 // data - ���������� ����� � ������� ������ ��
 //        �������� ������ ����,
 // parm - ��������� ����������� (MAPGDI.H);
 // context - �������������� ��������� �����������.
 // ������������ �������� :
 //  0  - ������ �� ����� (������� ������ �������
 //       ��� ������ �� ����� �� ����������� ...),
 //       ��� ��� ������� �� ��������������;
 //  +1 - ������ ���������.
 // ��� ������ ���������� ����
 _IMLIMP long int _IMLAPI imlTestVisible(long int type,
                                 const POLYDATAEX * data,
                                 const IMGDRAW * parm,
                                 const IMGCONTEXT * context);

} // extern "C"

#if defined(BUILD_DLL64) && defined(LINUXAPI)            // 26/03/12
#pragma pack(pop)
#endif

#endif // MAPGDIEX_H

