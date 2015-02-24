/****** RSTAPI.H *************** Belenkov O.V.   ****** 31/01/12 ***
******* RSTAPI.H *************** Shabakov D.A.   ****** 01/03/12 ***
******* RSTAPI.H *************** Dishlenko S.G.  ****** 27/04/01 ***
******* RSTAPI.H *************** Gorbunov A.V.   ****** 14/07/10 ***
******* RSTAPI.H *************** Kruzhkov A.E.   ****** 31/05/10 ***
******* RSTAPI.H *************** Vitsko D.A.     ****** 23/11/05 ***
******* RSTAPI.H *************** Derevyagina Zh.A.***** 12/10/09 ***
******* RSTAPI.H *************** Borzov A.U.      ***** 31/01/12 ***
*                                                                  *
*                                                                  *
*              Copyright (c) PANORAMA Group 1991-2012              *
*                      All Rights Reserved                         *
*                                                                  *
********************************************************************
*                                                                  *
*       �������� ������ ������� � ��'���� "����������� �����"      *
*        ��������� ��� �������� �� ������ C, PASCAL, BASIC         *
*                                                                  *
********************************************************************
*                                                                  *
*    �������������� ������� � Windows :                            *
*                                                                  *
*    // �������� ����������                                        *
*    HINSTANCE libInst = ::LoadLibrary("gisacces.dll");            *
*                                                                  *
*    // ����� �������                                              *
*    HMAP (WINAPI * lpfn_OpenMap)(const char*, long int);          *
*    (FARPROC)lpfn_OpenMap = GetProcAddress(libInst, "OpenMap");   *
*    HMAP hMap = (*lpfn_OpenMap)("Noginsk.map",0);                 *
*                                                                  *
*    // �������� ����������                                        *
*    ::FreeLibrary(libInst);                                       *
*                                                                  *
*******************************************************************/

#ifndef RSTAPI_H
#define RSTAPI_H

#ifndef MAPTYPE_H
  #include "maptype.h"   // �������� �������� ���������� MAPAPI
#endif

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// +++++ �������� ������� ������� � ��������� ����� ++++++++
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C"
{

  // ������� ��������� ������
  // ���������� ������������� �������� ��������� ����� (TMapAccess*)
  // rstname - ��� ����� ��������� �����
  // mode    - ����� ������/������ (GENERIC_READ, GENERIC_WRITE ��� 0)
  // GENERIC_READ - ��� ������ ������ �� ������
  // ��� ������ ���������� ����

_MAPIMP  HMAP _MAPAPI mapOpenRst(const char * rstname,
                                 long int mode = 0);  // 27/04/01


  // ������� ��������� ������ � �������� ������ �����
  // (�������� � ������� �������)
  // ���������� ����� ����� � ������� �������
  // hMap    - ������������� �������� ��������� �����
  // rstname - ��� ����� ��������� �����
  // mode    - ����� ������/������ (GENERIC_READ, GENERIC_WRITE ��� 0)
  // GENERIC_READ - ��� ������ ������ �� ������
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapOpenRstForMap(HMAP hMap,
                                    const char * rstname,
                                    long int mode);


  // �������� ����� ���������� �����������
  // rstname    - ��� ������������ �����
  // width      - ������ ���������� ����������� � ���������
  // height     - ������ ���������� ����������� � ���������
  // nbits      - ������ �������� (��� �� ������)
  // palette    - ����� ��������������� �������
  // colorcount - ����� ��������� � ����� �������
  // scale      - �������
  // precision  - ���������� ������
  // ��� �������� ���������� ������� ������� ���� rstname � �����������
  // ��������� � �������� ������.
  //  ��� ������ ���������� 0
  
_MAPIMP  HMAP _MAPAPI mapCreateRst(const char * rstname,
                                long int width, long int height,
                                long int nbits,
                                COLORREF* palette, long int colorcount,
                                double scale=0, double precision=0);  // 27/04/01


  // �������� ����� ��������� �����
  // name            - ������ ��� ������
  // width           - ������ ����������� � ��������
  // height          - ������ ����������� � ��������
  // nbits           - ���������� ��� �� ������� (1,4,8,24)
  // palette         - ��������� �� ������� ������ (����������� ��� 1,4,8 ��� �� �������)
  // scale           - ������ ������
  // precisionMet    - ���������� ������ (����� �� ����)
  // meterInElementX - ������ ������� ������ � ������ �� ��������� �� ��� X (�� ���������)
  // meterInElementY - ������ ������� ������ � ������ �� ��������� �� ��� Y (�� �����������)
  //                   meterInElementX � meterInElementY ����� ����� ������ ��������
  // location        - ���������� ���-��������� ���� ������ � ������, ��������������� �� � mapregister
  // mapregister     - �������� ��������� ���������
  // �����!!!
  // ��� ����������� �������� ������� � 10-�� � ����� ������ ������� ���������� ��������� �������:
  //                            meterInElementX = scale/precisionMet;
  // ����� ������� � ���������� ����� �����������!!!
  //
  // ��� ������ ����������

_MAPIMP  HMAP _MAPAPI mapCreateRstEx(char * rstname, long width, long height, long nbits,  
                             COLORREF* palette, long int colorcount,
                             double scale, double precisionMet,
                             double meterInElementX, double meterInElementY,
                             DOUBLEPOINT *location, MAPREGISTEREX* mapregister);

                             
  // �������� ����� ��������� �����   // 23/02/12
  // name            - ������ ��� ������
  // width           - ������ ����������� � ��������
  // height          - ������ ����������� � ��������
  // nbits           - ���������� ��� �� ������� (1,4,8,24)
  // palette         - ��������� �� ������� ������ (����������� ��� 1,4,8 ��� �� �������)
  // meterInElementX - ������ ������� ������ � ������ �� ��������� �� ��� X (�� ���������)
  // meterInElementY - ������ ������� ������ � ������ �� ��������� �� ��� Y (�� �����������)
  //                   meterInElementX � meterInElementY ����� ����� ������ ��������
  // location        - ���������� ���-��������� ���� ������ � ������, ��������������� �� � mapregister
  // mapregister     - ��������� �� ���������, ���������� ��������� �������� ��������� ���������
  // datumparam      - ��������� �� ���������, ���������� ������������ ����������������� ������������� ���������
  // ellipsoidparam  - ��������� �� ���������, ���������� ��������� ����������
  //
  // ��� ������ ����������

_MAPIMP  HMAP _MAPAPI mapCreateRaster(const char * rstname, long width, long height, long nbits,            // 01/03/12
                             COLORREF* palette, long int colorcount,
                             double meterInElementX, double meterInElementY,
                             DOUBLEPOINT *location,
                             MAPREGISTEREX* mapregister, DATUMPARAM * datum, ELLIPSOIDPARAM * ellipsoid);


  // �������� ����� ���������� �����������
  // hMap       - ������������� �������� ��������� �����
  // rstname    - ��� ������������ �����
  // width      - ������ ���������� ����������� � ���������
  // height     - ������ ���������� ����������� � ���������
  // nbits      - ������ �������� (��� �� ������)
  // palette    - ����� ��������������� �������
  // colorcount - ����� ��������� � ����� �������
  // scale      - �������
  // precision  - ���������� ������
  // location   - �������� ���-��������� ���� ������ � ������(� ������)
  // ��� �������� ���������� ������� ������� ���� rstname � �����������
  // ��������� � �������� ������ � ��������� ��� � ������� �������
  // �������� ��������� ����� (hMap).
  // ����������  ����� ����� (������� � 1) � ������� ������� �������� ��������� �����
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapCreateAndAppendRst(HMAP hMap,const char * rstname,
                                long int width, long int height,
                                long int nbits,
                                COLORREF* palette, long int colorcount,
                                double scale, double precision,
                                DOUBLEPOINT location);


  // �������� ����� ���������� �����������                                      // 18/05/10
  // hMap       - ������������� �������� ��������� �����
  // rstname    - ��� ������������ �����
  // width      - ������ ���������� ����������� � ���������
  // height     - ������ ���������� ����������� � ���������
  // nbits      - ������ �������� (��� �� ������)
  // palette    - ����� ��������������� �������
  // colorcount - ����� ��������� � ����� �������
  // scale      - �������
  // precision  - ���������� ������ (����� �� ����)
  // meterInElementX - ������ ������� ������ � ������ �� ��������� �� ��� X (�� ���������)
  // meterInElementY - ������ ������� ������ � ������ �� ��������� �� ��� Y (�� �����������)
  //                   meterInElementX � meterInElementY ����� ����� ������ ��������
  // location        - ���������� ���-��������� ���� ������ � ������, ��������������� �� � mapregister
  // mapregister     - �������� ��������� ���������
  // �����!!!
  // ��� ����������� �������� ������� � 10-�� � ����� ������ ������� ���������� ��������� �������:
  //                            meterInElementX = scale/precision;
  // ����� ������� � ���������� ����� �����������!!!
  // ��� �������� ���������� ������� ������� ���� rstname � �����������
  // ��������� � �������� ������ � ��������� ��� � ������� �������
  // �������� ��������� ����� (hMap).
  // ����������  ����� ����� (������� � 1) � ������� ������� �������� ��������� �����
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapCreateAndAppendRstEx(HMAP hMap,const char * rstname,
                                long int width, long int height, long int nbits,
                                COLORREF* palette, long int colorcount,
                                double scale, double precision,
                                double meterInElementX, double meterInElementY,
                                DOUBLEPOINT* location, MAPREGISTEREX* mapregister);


  // �������� ����� ���������� �����������                                      // 01/03/12
  // hMap       - ������������� �������� ��������� �����
  // rstname    - ��� ������������ �����
  // width      - ������ ���������� ����������� � ���������
  // height     - ������ ���������� ����������� � ���������
  // nbits      - ������ �������� (��� �� ������)
  // palette    - ����� ��������������� �������
  // colorcount - ����� ��������� � ����� �������
  // scale      - �������
  // precision  - ���������� ������ (����� �� ����)
  // meterInElementX - ������ ������� ������ � ������ �� ��������� �� ��� X (�� ���������)
  // meterInElementY - ������ ������� ������ � ������ �� ��������� �� ��� Y (�� �����������)
  //                   meterInElementX � meterInElementY ����� ����� ������ ��������
  // location        - ���������� ���-��������� ���� ������ � ������, ��������������� �� � mapregister
  // mapregister     - ��������� �� ���������, ���������� ��������� �������� ��������� ���������
  // datumparam      - ��������� �� ���������, ���������� ������������ ����������������� ������������� ���������
  // ellipsoidparam  - ��������� �� ���������, ���������� ��������� ����������
  // �����!!!
  // ��� ����������� �������� ������� � 10-�� � ����� ������ ������� ���������� ��������� �������:
  //                            meterInElementX = scale/precision;
  // ����� ������� � ���������� ����� �����������!!!
  // ��� �������� ���������� ������� ������� ���� rstname � �����������
  // ��������� � �������� ������ � ��������� ��� � ������� �������
  // �������� ��������� ����� (hMap).
  // ����������  ����� ����� (������� � 1) � ������� ������� �������� ��������� �����
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapCreateAndAppendRaster(HMAP hMap, const char * rstname, // 01/03/12
                                long int width, long int height, long int nbits,
                                COLORREF* palette, long int colorcount,
                                double meterInElementX, double meterInElementY,
                                DOUBLEPOINT* location,
                                MAPREGISTEREX* mapregister, DATUMPARAM * datum, ELLIPSOIDPARAM * ellipsoid);


  // ������ ����e�������� ����� ����� ��������� ����� �� �� ��������  // 09/04/01
  // hMap       - ������������� �������� ��������� �����
  // width      - ������ ���������� ����������� � ���������
  // height     - ������ ���������� ����������� � ���������
  // nbits      - ������ �������� (��� �� ������)
  // ����������  ����e�������� ����� ����� ��������� ����� (����)
  // ��� ������ ���������� ����

_MAPIMP  double _MAPAPI mapRstFileLengthCalculation(HMAP hMap, long int width,  // 04/09/03
                                                        long int height,
                                                        long int nbits);
  // ���������� �������
_MAPIMP  double _MAPAPI mapRtsFileLengthCalculation(HMAP hMap, long int width,
                                                        long int height,
                                                        long int nbits);


  // ��������� ����� ������ � ������� �� ����� �����  // 28/04/10
  // name        - ��� ����� ������
  // � ������� ������ ������� ���������� � 1.
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetRstNumberByName(HMAP hMap, const char* name);


  // ������� ��������� ������ � �������� ������ �����
  // hMap   - ������������� �������� ��������� �����
  // number - ����� ���������� ����� � �������
  // ���� number == 0, ����������� ��� ��������� ������
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapCloseRstForMap(HMAP hMap,
                                     long int number);


  // ������� ��������� ������
  // hMap   - ������������� �������� ��������� �����
  // number - ����� ������������ ������
  // ���� number == 0, ����������� ��� ������ � ����

_MAPIMP  void _MAPAPI mapCloseRst(HMAP hMap,
#ifdef __cplusplus  // 27/04/01
                           long int number = 0);  // 27/04/01
#else
                           long int number);  // 27/04/01
#endif


  // ��������� ��� ����� ��������� ������
  // hMap   - ������������� �������� ��������� �����
  // number - ����� ����� � �������
  // ��� ������ ���������� ������ ������

_MAPIMP  const char * _MAPAPI mapGetRstName(HMAP hMap,long int number);


  // ��������� ��� ����� ��������� ������ � ��������� UNICODE
  // hMap   - ������������� �������� ��������� �����
  // number - ����� ����� � �������
  // name - ����� ������ ��� ���������� ����������
  // size - ������ ������
  // ��� ������ ���������� ������ ������

_MAPIMP  long int _MAPAPI mapGetRstNameUn(HMAP hMap,long int number,
                                          WCHAR * name, long int size);

                                          
  // ��������� ����� �������� ������ ��������� ������
  // hMap    - ������������� �������� ��������� �����
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetRstCount(HMAP hMap);


  // ������ �������� ������ ������  // 06/05/00
  // hMap    - ������������� �������� ��������� �����
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetRstCurrentNumber(HMAP hMap);


  // ��������� �������� ������ ������  // 06/05/00
  // hMap    - ������������� �������� ��������� �����
  // number  - ����� ������
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapSetRstCurrentNumber(HMAP hMap,long int number);


  // ���������/���������� ������� ��������� ������
  //  hMap   - ������������� �������� ��������� �����
  //  number - ����� ����� � �������
  //  view = 0 - �� �����
  //  view = 1 - ������ ���������
  //  view = 2 - ����������
  //  view = 3 - ��������������
  //  view = 4 - �������
  //  view = 5 - ����������

_MAPIMP  long int _MAPAPI mapGetRstView(HMAP hMap,long int number);
_MAPIMP  long int _MAPAPI mapSetRstView(HMAP hMap,long int number,
                                           long int view);


  // ���������� ������� ��������� ������ �������
  //  userLabel  - ���������������� ����� ������
  //                -1             - ��� ������
  //                RSW_QUALITY    - ������ �������
  //                RSW_VISIBILITY - ������ ���������
  //                RSW_WEB        - ��������� ����� ��� WEB
  //  view - ������� ���������
  //                0 - �� �����
  //                1 - ������
  //                2 - ����������
  //                3 - ��������������
  //                4 - �������
  //                5 - ����������
  // ��� ������ ���������� 0

_MAPIMP  long int _MAPAPI mapSetRstGroupView(HMAP hMap,long int userLabel,
                                                long int view);      // 27/05/08

  // ���������/���������� ������� ����������� ������
  // hMap   - ������������� �������� ��������� �����
  // number - ����� ���������� ����� � �������
  //  (0 - ��� ������, 1 - ��� ������)
  // ��� ������ ���������� 0

_MAPIMP  long int _MAPAPI mapSetRstViewOrder(HMAP hMap, long int number,
                                      long int order);
_MAPIMP  long int _MAPAPI mapGetRstViewOrder(HMAP hMap, long int number);


  // �������� ����������� ����������� ������� (rst) � �������  // 04/12/07
  // ��������� ����� � ������� ������������ � ��������� �������
  // ��������� ������� � ������� ���������� � 1 � ������������� ������� mapGetRstCount(..)
  //   oldNumber - ����� ����� � �������
  //   newNumber - ��������������� ����� ����� � �������
  //  ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapChangeOrderRstShow(HMAP hMap, long int oldNumber,
                                                          long int newNumber);

_MAPIMP  long int _MAPAPI mapChangOrderRstInChain(HMAP hMap, long int oldNumber,
                                                             long int newNumber);

  // ���������������� �������� ������� ��� ������
  // ���� ��� ������ ������������ ��� ������, ��
  // ������ ����� ����� ��������� ��� ������. ��� ���������
  // ������ ������ ����� ����� ��������� ��� ������, ��������� -
  // ��� ������. ����� ���������� ������ � ������ ��� ������ -
  // ��� ������ ��� ������. ����� - ����� ������ ����� ��� ������.
  // ���������� ����� ������ ������������� ��� ������ ��� ����.
  // ��� ��������� ���������� �� ������ - ����� ����� ������������
  // hMap    - ������������� �������� ��������� �����

_MAPIMP  long int _MAPAPI mapTurnRstViewOrder(HMAP hMap);


  // ��������� ���������� ������ � ������� ������
  // hMap   - ������������� �������� ��������� �����
  // number - ����� ����� � �������
  // ��� ������ ������������ 0

_MAPIMP  long int _MAPAPI mapGetRstColorCount (HMAP hMap, long int number);


  // ��������� �������� ������� ������
  // hMap    - ������������� �������� ��������� �����
  // palette - ����� ������� ��� ���������� �������
  // count   - ����� ����������� ��������� �������
  //           (���� count > 256, �� ������������ ����)
  // number  - ����� ����� � �������
  // (������ ������� � ������ / 4)
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetRstPalette(HMAP hMap, COLORREF * palette,
                                    long int count,
                                    long int number);


  // ���������� �������� ������� ������
  // hMap    - ������������� �������� ��������� �����
  // palette - ����� ��������������� �������
  // count   - ����� ��������� � ����� �������
  // number  - ����� ����� � �������
  // ���� palette ����� 0, ��������������� ������� �� ���������  // 18/06/02
  // count �� ����� 256
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapSetRstPalette(HMAP hMap, COLORREF * palette,
                                    long int count,
                                    long int number);


  // ��������� �������� ��������� ������� ������
  // (��� ����� ������� � ������������)
  // hMap    - ������������� �������� ��������� �����
  // palette - ����� ������� ��� ���������� �������
  // count   - ����� ����������� ��������� �������
  //           (���� count > 256, �� ������������ ����)
  // number  - ����� ����� � �������
  // (������ ������� � ������ / 4)
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetRstStandardPalette(HMAP hMap, COLORREF * palette,
                                    long int count,
                                    long int number);


  // ��������� �������� ������� �� ��������� ������    // 12/10/09
  // hMap   - ������������� �������� ��������� �����
  // palette - ����� ������� ��� ���������� �������
  // count   - ����� ����������� ��������� �������
  //           (���� count > 256, �� ������������ ����)
  // number  - ����� ����� � �������
  // (������ ������� � ������ / 4)
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetRstPaletteFromHeader(HMAP hMap, COLORREF * palette,
                                    long int count,
                                    long int number);

  // ��������� ������� ������� ������
  // hMap   - ������������� �������� ��������� �����
  // number - ����� ����� � �������

_MAPIMP  long int _MAPAPI mapGetRstBright (HMAP hMap,long int number);


  // ��������� ������������� ������� ������
  // hMap   - ������������� �������� ��������� �����
  // number - ����� ����� � �������

_MAPIMP  long int _MAPAPI mapGetRstContrast (HMAP hMap,long int number);


  // ��������� �������������� ������� ������
  // hMap   - ������������� �������� ��������� �����
  // number - ����� ����� � �������

_MAPIMP  long int _MAPAPI mapGetRstGamma (HMAP hMap,long int number);


  // ���������� ������� ������� ������
  // hMap   - ������������� �������� ��������� �����
  // number - ����� ����� � �������
  // bright - �������
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapSetRstBright (HMAP hMap, long int bright,
                                               long int number);


  // ���������� ������������� ������� ������
  // hMap     - ������������� �������� ��������� �����
  // number   - ����� ����� � �������
  // contrast - ��������
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapSetRstContrast (HMAP hMap, long int contrast,
                                                 long int number);


  // ���������� �������������� ������� ������
  // hMap   - ������������� �������� ��������� �����
  // number - ����� ����� � �������
  // gamma  - �������������� �������
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapSetRstGamma (HMAP hMap, long int gamma,
                                              long int number);


  //  �������� �������� ������� � ������� �������� � ��������������
  //  hMap   - ������������� �������� ��������� �����
  //  number - ����� ����� � �������
  //  ��� ������ ���������� 0

_MAPIMP  long int _MAPAPI mapRestoreRstPalette(HMAP hMap, long int number);


  // ��������� �������� �������� ������
  // hMap   - ������������� �������� ��������� �����
  // number - ����� ����� � �������
  // ���� ����������� ������ ���������� - ���������� ����
  // ���� ����������� ������ ���������� - ���������� 1
  // ��� ������ ���������� -1

_MAPIMP  long int _MAPAPI mapCheckInversionRst(HMAP hMap,long int number);


  // ������������� ��������� �����
  // hMap   - ������������� �������� ��������� �����
  // number - ����� ����� � �������
  // value:
  // 0 - ���������� ����������� ������ ����������
  // 1 - ���������� ����������� ������ ����������
  //  ��� ������ ���������� 0

_MAPIMP  long int _MAPAPI mapInvertRst(HMAP hMap,long int number, long int value);


  // ��������� ��������� ����� (��� 16- � 256-������� �������)  //16/05/00
  //  hMap   - ������������� �������� ��������� �����
  //  number - ����� ����� � �������
  //  index  - ������ ����� � ������� ������(������� � 0)
  //  ����������: 1 - ���� � ������ �������� ������������
  //              0 - ���� � ������ �������� �� ������������
  //  ��� ������ ���������� -1

_MAPIMP  long int _MAPAPI mapCheckVisibilityColor(HMAP hMap, long int number,
                                                      long int index);


  // ���������� ��������� ����� (��� 16- � 256-������� �������)  //16/05/00
  //  hMap   - ������������� �������� ��������� �����
  //  number - ����� ����� � �������
  //  index  - ������ ����� � ������� ������(������� � 0)
  //  value: 1 - �������� ����������� ����� � ������ ��������
  //         0 - ��������� ����������� ����� � ������ ��������
  //  ���������� ��������� ������ � INI-�����
  //                                  (�� ��������� � �������� ����� ������)
  //  ��� ������ ���������� 0

_MAPIMP  long int _MAPAPI mapSetVisibilityColor(HMAP hMap, long int number,
                                                    long int index,
                                                    long int value);


  // ���������� ��������� ����� (��� 16- � 256-������� �������)  //30/10/02
  //  hMap   - ������������� �������� ��������� �����
  //  number - ����� ����� � �������
  //  index  - ������ ����� � ������� ������(������� � 0)
  //  value: 1 - �������� ����������� ����� � ������ ��������
  //         0 - ��������� ����������� ����� � ������ ��������
  //  ���������� ��������� ������ � ��������� ����� ������(� ����� � INI-�����)
  //  ��� ������ ���������� 0

_MAPIMP  long int _MAPAPI mapSetVisibilityColorInRstFile(HMAP hMap, long int number,
                                                  long int index,
                                                  long int value);

  // ���������� ���������� ���� ������ (��� 16-,24-,32-������ �������)  //31/05/10
  //  hMap   - ������������� �������� ��������� �����
  //  number - ����� ����� � �������
  //  color  - �������� ����������� ����� � ������� RGB (�� 0 �� 0x00FFFFFF)
  // ��� ��������� IMGC_TRANSPARENT (0xFFFFFFFF) ���������� ���� �� ������������
  // ��� ������ ���������� IMGC_TRANSPARENT

_MAPIMP  COLORREF _MAPAPI mapSetRstTransparentColor(HMAP hMap, long int number,
                                                    COLORREF color);


  // ��������� ���������� ���� ������ (��� 16-,24-,32-������ �������)   //31/05/10
  //  hMap   - ������������� �������� ��������� �����
  //  number - ����� ����� � �������
  // ���������� ���� � ������� RGB (�� 0 �� 0x00FFFFFF)
  // ��� �������� IMGC_TRANSPARENT (0xFFFFFFFF) ���������� ���� �� ������������
  // ��� ������ ���������� IMGC_TRANSPARENT

_MAPIMP  COLORREF _MAPAPI mapGetRstTransparentColor(HMAP hMap, long int number);

  // ��������� ���� � ��� ����� ������  // 16/04/04
  // hMap      - ������������� �������� ��������� �����
  // maskType  - ���� �����(0 - ����� �����������)
  // maskStep  - ��� �����
  // number - ����� ����� � �������

_MAPIMP  long int _MAPAPI mapGetRstMaskType (HMAP hMap,long int number,
                                      long int* maskType, long int* maskStep);


  // ���������� ���� � ��� ����� ������  // 16/04/04
  // hMap      - ������������� �������� ��������� �����
  // maskType  - ���� �����(0 - ����� �����������)
  // maskStep  - ��� �����
  // number - ����� ����� � �������

_MAPIMP  long int _MAPAPI mapSetRstMaskType (HMAP hMap,long int number,
                                      long int maskType, long int maskStep);


  // ��������� ��������������� ���������� ������      // 01/06/10
  // scale           - ����������� ��������
  // precision       - ���������� (����� �� ����)
  // meterinelementX - ���������� ������ �� �������  �� ��� X
  // meterinelementY - ���������� ������ �� �������  �� ��� Y
  // meterinelementX � meterinelementY ����� ����������
  // �����!!!
  // ��� ����������� ����������� ������� � 10-�� � ����� ������ ������� ����������:
  //                         meterinelementX = scale / precision;
  // ���� ������� �� �����������, �� meterinelementX � meterinelementY ������������ � ������������� �� �������.
_MAPIMP  long int _MAPAPI mapSetRstParameters(HMAP hMap, long int number,
                                           double scale, double precision,
                                           double meterinelementX, double meterinelementY);

  // ���������� ������� ������
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // scale      - ����������� ��������
  // ��� ������ ���������� 0

_MAPIMP  long int _MAPAPI mapSetRstScale(HMAP hMap,long int number,double scale);


  // ��������� ������� ������
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // scale      - ��������� ����������, ���� �������� �������� ��������
  // ��� ������ ���������� 0

_MAPIMP  long int _MAPAPI mapGetRstScale(HMAP hMap,long int number,double *scale);


  // ��������� �������� �������� ������ � ������� ������ ��������� ������
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // �� ������ bottomScale ������������ ����������� �������� ������ ������� ��������� ������
  // �� ������ topScale ������������ ����������� �������� ������� ������� ��������� ������
  // ��� ������ ���������� 0

_MAPIMP  long int _MAPAPI mapGetRstRangeScaleVisible(HMAP hMap,long int number,
                       long int *bottomScale, long int *topScale);  // 08/12/03


  // ���������� �������� �������� ������ � ������� ������ ��������� ������
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // bottomScale   - ����������� �������� ������ ������� ��������� ������
  // topScale   - ����������� �������� ������� ������� ��������� ������
  //              bottomScale <= topScale, ����� ���������� 0
  // ��� ������ ���������� 0

_MAPIMP  long int _MAPAPI mapSetRstRangeScaleVisible(HMAP hMap,long int number,
                      long int bottomScale, long int topScale);   // 08/12/03


  // ���������� ���������� ������
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // precision  - ���������� ������, ���������� ��� ������������ (����� �� ����)
  // ��� ������ ���������� 0

_MAPIMP  long int _MAPAPI mapSetRstPrecision(HMAP hMap,long int number,double precision);


  // ��������� ���������� ������
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // precision  - ���������� ������ (����� �� ����)
  // ��� ������ ���������� 0

_MAPIMP  long int _MAPAPI mapGetRstPrecision(HMAP hMap,long int number,double *precision);


  // ���������� ����� ������ �� ������� ���������� �������
  // ��������� ������ ������ ����� �� ����� 4-� �����
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // info       - ��������� ������ �����
  // ����� ���������� ������� ����������� ������ ����������� �������� ��������
  // ��� ������ ���������� 0

_MAPIMP  long int _MAPAPI mapSetRstBorder(HMAP hMap,long int number,HOBJ info);


  // ��������� ������ ����� ������               // 15/03/01
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // info       - ������������� ������� �����
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetRstBorder(HMAP hMap,long int number,HOBJ info);


  // ������� ����� ������
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // ����� ���������� ������� ����������� ������ ����� ������
  // ��� ������ ���������� 0

_MAPIMP  long int _MAPAPI mapDeleteRstBorder(HMAP hMap,long int number);


  // ����������� ������������� ����� ������               // 24/06/09
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // ��� ������ ���������� 0

_MAPIMP  long int _MAPAPI mapGetRstMask(HMAP hMap,long int number);

  // ����������� ������� ����������� ������(������������ �����)  // 24/06/09
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // ���������� 1 - ��� ����������� ������ �� �����
  //            0 - ��� ����������� ������ ��� ����� �����
  // ��� ������ ���������� 0

_MAPIMP  long int _MAPAPI mapGetShowRstByMask(HMAP hMap,long int number);

  // ��������� ����������� ������ �� �����                      // 24/06/09
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // value  = 1 - ���������� ����� �� �����
  //        = 0 - ���������� ����� ��� ����� �����

_MAPIMP  long int _MAPAPI mapSetShowRstByMask(HMAP hMap,long int number, long int value);

  // ����������� ������������� ����� ������
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // ��� ������ ���������� 0

_MAPIMP  long int _MAPAPI mapCheckExistenceRstBorder(HMAP hMap,long int number);


  // ��������� ����������� ������ �� �����
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // value  = 1 - ���������� ����� �� �����
  //        = 0 - ���������� ����� ��� ����� �����

_MAPIMP  long int _MAPAPI mapShowRstByBorder(HMAP hMap,long int number, long int value);

  // ����������� ������� ����������� ������(������������ �����)
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // ���������� 1 - ��� ����������� ������ �� �����
  //            0 - ��� ����������� ������ ��� ����� �����
  // ��� ������ ���������� -1

_MAPIMP  long int _MAPAPI mapCheckShowRstByBorder(HMAP hMap,long int number);

  // ���������� ���������� ����� �����, �������  // 02/10/03
  // ������ � ������������� �������� ������(�������) �
  // ����� ���������� �������� �� ����� pointIn (���������� � ������).
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // �� ������ pointOut ������������ ���������� ��������� ����� � ������
  // ��� ������ ��� ���������� ����� ���������� 0.

_MAPIMP  long int _MAPAPI mapGetImmediatePointOfRstBorder(HMAP hMap, long int number,
                                           DOUBLEPOINT* pointIn,
                                           DOUBLEPOINT* pointOut);


  // ��������� ������ � �������� ������  // 11/04/06
  // number      - ����� ����� � �������
  // mapregister - ����� ���������, � ������� ����� ���������
  // ������ � ��������
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetRstProjectionData(HMAP hMap, int number,
                                                  MAPREGISTEREX* mapregister);


  // ��������� ������ � �������� ������ �� ����� �����  // 08/11/06
  // name        - ��� ����� ������
  // mapregister - ����� ���������, � ������� ����� ���������
  // ������ � ��������
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetRstProjectionDataByName(const char* name,
                                                  MAPREGISTEREX* mapregister);

  // ���������� ������ � �������� ������  // 11/04/06
  // number - ����� ����� � �������
  // mapregister - ����� ���������
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapSetRstProjectionData(HMAP hMap, int number,
                                                  MAPREGISTEREX* mapregister);

  // ��������� ��������� ���������� ������
  // hMap   - ������������� �������� �������� ��������� �����
  // number - ����� ����� ������ � �������
  // ellipsoidparam - ����� ���������, � ������� ����� ���������
  // ��������� ����������
  // ��������a ELLIPSOIDPARAM ������a � mapcreat.h
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetRstEllipsoidParam(HMAP hMap, long int number,  // 14/07/10
                                                 ELLIPSOIDPARAM * ellipsoidparam);

  // ���������� ��������� ���������� ������
  // hMap    - ������������� �������� �������� ��������� �����
  // number  - ����� ����� ������ � �������.
  // ellipsoidparam - ����� ���������, ���������� ��������� ����������
  // ��������a ELLIPSOIDPARAM ������a � mapcreat.h
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSetRstEllipsoidParam(HMAP hMap, long int number,  // 14/07/10
                                                 const ELLIPSOIDPARAM * ellipsoidparam);

  // ��������� ������������ ����������������� ������������� ��������� ������
  // hMap   - ������������� �������� �������� ��������� �����
  // number - ����� ����� ������ � �������
  // datumparam - ����� ���������, � ������� ����� ���������
  // ������������ ����������������� ������������� ���������
  // ��������a DATUMPARAM ������a � mapcreat.h
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetRstDatumParam(HMAP hMap, long int number,  // 14/07/10
                                             DATUMPARAM * datumparam);

  // ���������� ������������ ����������������� ������������� ��������� ������
  // hMap    - ������������� �������� �������� ��������� �����
  // number  - ����� ����� ������ � �������.
  // datumparam - ����� ���������, ���������� ������������ �����������������
  // ������������� ���������
  // ��������a DATUMPARAM ������a � mapcreat.h
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapSetRstDatumParam(HMAP hMap, long int number,  // 14/07/10
                                             const DATUMPARAM * datumparam);

  // ��������� �������� ������ � ������ � ������ �����
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // frame      - ������������ �������� ������
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetRstFrameMeters(HMAP hMap,DFRAME *frame, long int number);


  // ��������� ����������� �������� ������������� ������ � ������ � ������ �����   // 14/05/03
  // ��� ����������� ������ �� ����� ������������ �������� �����
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // frame      - ������������ �������� ������
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetActualRstFrame(HMAP hMap,DFRAME *frame, long int number);


  // ���������� �������� ������ � ������ �����(� ������)
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // location   - ���������� ���-��������� ���� ������(� ������)
  // ��� ������ ���������� 0

_MAPIMP  long int _MAPAPI mapSetRstLocation(HMAP hMap,long int number, DOUBLEPOINT* location);


  // ��������� �������� ������ � ������ �����(� ������)
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // location   - ���������� ���-��������� ���� ������(� ������)
  // ��� ������ ���������� 0

_MAPIMP  long int _MAPAPI mapGetRstLocation(HMAP hMap,long int number, DOUBLEPOINT *location);


  // ��������� ���� ������������� �������� ������
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // ��� ������ ���������� 0

_MAPIMP  long int _MAPAPI mapCheckExistenceRstLocation(HMAP hMap,long int number);




  //**********************************************************************
  // ��� ��������� ����� �� ������� (Dx,Dy)?
  //    ��������� �������� ������ - mapGetRstLocation(...)
  //    �������� ����� �������� �� ������� (Dx,Dy)
  //    ���������� ����� ����� �������� - mapSetRstLocation(...)
  //    ����������� ����.
  //**********************************************************************
  // ��� ��������� ����� � ���������� �������� ?
  //    ��������� �������� ������ - mapGetRstLocation(...)
  //    ��������� ����������� �������� ������ - mapGetRstScale(...)
  //    �������� ����� �������� � ���������� ����������� ��������
  //    ���������� ����� ����� �������� - mapSetRstLocation(...)
  //    ���������� ����� ����������� �������� - mapSetRstScale(...)
  //    ����������� ����.
  //**********************************************************************

  // 05/05/10  ���������� �������
  // ��������� ������ �������� ������ � ������ �� ���������
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // metinelem  - ������ �������� ������ � ������ �� ���������
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetRstMeterInElement(HMAP hMap,long int number,double *metinelem);

  // ��������� ������ �������� ������ � ������ �� ��� X // 05/05/10
  // number    - ����� ����� � �������
  // metinelemX - ������ �������� ������ � ������ �� ��������� �� ��� X
  // ��� ������ ���������� ����
_MAPIMP  long int _MAPAPI mapGetRstMeterInElementX(HMAP hMap,long int number, double *metinelemX);

  // ��������� ������ �������� ������ � ������ �� ��� Y // 05/05/10
  // number    - ����� ����� � �������
  // metinelemY - ������ �������� ������ � ������ �� ��������� �� ��� Y
  // ��� ������ ���������� ����
_MAPIMP  long int _MAPAPI mapGetRstMeterInElementY(HMAP hMap,long int number, double *metinelemY);

  // 05/05/10  ���������� �������
  // ��������� ������ ����� ������ � ��������� ������
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // eleminpix  - ������ ����� ������ � ��������� ������
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetSizeRstElemInPix(HMAP hMap,long int number,double *eleminpix);

  // ��������� ������ �������� ������ � �������� ������ �� ��� X  // 05/05/10
  // number - ����� ����� � �������
  // ��� ������ ���������� ����
_MAPIMP  long int _MAPAPI mapGetSizeRstElemXInPix(HMAP hMap,long int number,double *eleminpix);

  // ��������� ������ �������� ������ � �������� ������ �� ��� Y  // 05/05/10
  // number - ����� ����� � �������
  // ��� ������ ���������� ����
_MAPIMP  long int _MAPAPI mapGetSizeRstElemYInPix(HMAP hMap,long int number,double *eleminpix);

  // ��������� ������ ������ � ���������
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetRstWidth(HMAP hMap,long int number);


  // ��������� ������ ������ � ���������
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetRstHeight(HMAP hMap,long int number);


  // ��������� ����� ������ � ������        // 18/06/01
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // ��� ������ ���������� ����

_MAPIMP  unsigned long int _MAPAPI mapGetRstLength(HMAP hMap,long int number);


  // ��������� ������ �������� ������ � �����
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetRstElementSize(HMAP hMap,long int number);


  // ��������� ���� ��������������� ������
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetRstEdit(HMAP hMap,long int number);
_MAPIMP  long int _MAPAPI mapCheckRstEdit(HMAP hMap,long int number);


  // ��������� ����� ��������� ������ ������ (0 - ����� �� ����)
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapCheckRstCompressNumber(HMAP hMap,long int number);


  // ������ �������� �� ���������� ��������
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // string, column - ������ � ������� ��������
  // value      - �������� ��������
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetRstPoint(HMAP hMap, long int number,long int *value, long int string, long int column);


  // ������ �������� �� ���������� ��������
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // string, column - ������ � ������� ��������
  // value      - �������� ��������
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapPutRstPoint(HMAP hMap, long int number,long int value, long int string, long int column);


  // ������ ��������  �� ��� ������������� �����������
  // (� ������) �� ������
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // x,y        - ���������� ��������
  // value      - �������� ��������
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetRstPlanePoint(HMAP hMap, long int number,long int *value, double x, double y);


  // ������ �������� �� ��� ������������� ����������� �� ������ �������������
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // x,y        - ���������� ��������
  // value      - �������� ��������
  // ��� ������ ���������� ����              // 12/11/02

_MAPIMP  long int _MAPAPI mapGetRstPlanePointTriangle(HMAP hMap, long int number,long int *value, double x, double y);


  // ����������� ����� ����� ������ �� ������������� ����������� ����� // 19/03/02
  // (� ������)
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // x,y        - ���������� ��������
  // color      - ���� ��������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetRstPlanePointColor(HMAP hMap, long int number,
                                                  COLORREF* color, double x, double y);

 // ���������� ������������ - ����������� ����� ����� �� 4 �������� �������� ������ //12/08/10
 // hMap       - ������������� �������� ��������� �����
 // number     - ����� ����� � �������
 // color      - ����������� ����������� ������
 // indexColor - ����������� �������� ���������� ����� � ������������ �� ������� ������
 //              (��� 1,4 � 8 ��� �� �������)
 // x, y       - ������������� ���������� ����� � ������� ��������� ������ � ������ �� ���������
 // ��� ��������� � ������� ������� ������ ������������ ���� ���������� �������
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetRstBilinearInterpolationColor(HMAP hMap, long int number,
                                                             COLORREF* color, long int *indexcolor,
                                                             double x, double y);

 // ������������ ������������ - ����������� ����� ����� �� 16 �������� �������� ������ //12/08/10
 // hMap       - ������������� �������� ��������� �����
 // number     - ����� ����� � �������
 // color      - ����������� ����������� ������
 // indexColor - ����������� �������� ���������� ����� � ������������ �� ������� ������
 //              (��� 1,4 � 8 ��� �� �������)
 // x, y       - ������������� ���������� ����� � ������� ��������� ������ � ������ �� ���������
 // ��� ��������� � ������� 2 ������� ������ ������������ ���� ���������� �������
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetRstBicubicInterpolationColor(HMAP hMap, long int number,
                                                            COLORREF* color, long int *indexcolor,
                                                            double x, double y);

  // ������ ��������  �� ��� ������������� �����������
  // (� ������) � �����
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // x,y        - ���������� ��������
  // value      - �������� ��������
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapPutRstPlanePoint(HMAP hMap, long int number,long int value, double x, double y);


  // ������ ������� � ����������� ��������� ������ �� ������������� ����������� (� ������)  // 16/04/04
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // color - ���� ������� ���� COLORREF ��� ������� � 16,24,32 ����� �� �������;
  //         ������ ����� � ������� ��� ������� � 1,4,8 ����� �� �������.
  //  point1 - ���������� ��������� ����� �������
  //  point2 - ���������� �������� ����� �������
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapPutRstPlaneLine(HMAP hMap, long int number, long color,
                                             DOUBLEPOINT *point1, DOUBLEPOINT *point2);


  // ��������� ���������� ������ ������
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetRstBlockCount(HMAP hMap,long int number);


  // ��������� ����� ����� ������ ������
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetRstBlockRow(HMAP hMap,long int number);


  // ��������� ����� �������� ������ ������
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetRstBlockColumn(HMAP hMap,long int number);


  // ��������� ������ ������������ ����� ������ � ������
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetRstBlockSize(HMAP hMap,long int number);


  // ��������� ������ �������� ����� {string,column} ������ � ������
  // (� ������ ��������� ������)
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // string, column - ���������� �����
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetRstCurrentBlockSize(HMAP hMap,long int number,
                                             long int string,long int column);


  // ��������� ������ ������������ ����� ������ � ���������
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetRstBlockWidth(HMAP hMap,long int number);


  // ��������� ������ ������������ ����� ������ � ���������
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetRstBlockHeight(HMAP hMap,long int number);


  // ��������� ������ �������� ����� {string,column} ������ � ���������
  // (� ������ ��������� ������)
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // column     - ������� �����
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetRstCurrentBlockWidth(HMAP hMap,long int number,
                                              long int column);


  // ��������� ������ �������� ����� {string,column} ������ � ���������
  // (� ������ ��������� ������)
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // string     - ������ �����
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetRstCurrentBlockHeight(HMAP hMap,long int number,
                                               long int string);


  // ��������� ����� ����� ������ �� ������ ������ � �������
  // ����� ���������� ���� ����� ����� ��������� ������
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // string     - ������ �����
  // column     - ������� �����
  // ��� ������� ���������� ����� ����� ������� ������� �����
  // ��� ������ ���������� ����, ����� - ����� ���������� �����

_MAPIMP  char *  _MAPAPI mapGetRstBlock(HMAP hMap,long int number,
                                 long int string,
                                 long int column);


  // ��������� ����� ����� ������ �� ������ ������ � �������
  // ��� ���������� � ����� - ���������
  // ��� ������� ���������� ����� ����� ������� ������� �����
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // string     - ������ �����
  // column     - ������� �����
  // ��� ������ ���������� ����
_MAPIMP  char *  _MAPAPI mapGetRstBlockAndCreate(HMAP hMap,long int number,
                                 long int string,
                                 long int column);


  // ��������� ������� ����� ������ � �����
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // i          - ���������� ����� �����
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapCheckRstBlockExistence(HMAP hMap,long int number,long int i);


  // ������� ����� ����������� �����
  // (0 - �� ������������, 1- ������������, 2 - �������� ������ )
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // i          - ���������� ����� �����
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapCheckRstBlockVisible(HMAP hMap,long int number,long int i);  // 09/04/01


  // ������ ����� {string,column} � ���� ���������� �����������  �� ������ bits.
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // string     - ������ �����
  // column     - ������� �����
  // bits       - ��������� �� ������ ����������� ������� �������
  // sizebits   - ������ ������� bits � ������
  // ���������� ���������� ���������� ����.
  // ��� ������ ���������� ����.

_MAPIMP  long int _MAPAPI mapWriteRstBlock(HMAP hMap,long int number,
                                long int string, long int column,
                                char * bits, long int sizebits);


  // ������ ����� {string,column} �������� "size" �� DIB-����� "mask"
  // �������� "value"
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // string     - ������ �����
  // column     - ������� �����
  // mask       - ��������� �� ������ �����
  // size       - ������ ������� mask � ������
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapPutRstBlockByMask(HMAP hMap,long int number,
                                long int string, long int column,
                                char* mask, long int size,
                                long int width,long int height,
                                long value);


  // �������� ��������� ������ � ����
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapSaveRst(HMAP hMap,long int number);


  // ������ �������������� ������� ������
  //  hMap    - ������������� �������� ��������� �����
  //  number  - ����� ����� � �������
  //  bits    - ��������� �� ������ ����������� ������� �������
  //  left    - �������� ����� � ��������� (��������� �� ������� �����)
  //  top     - �������� ������ � ���������
  //  width   - ������ � ��������� (��������� �� ������� �����)
  //  height  - ������ � ���������
  //  begining  - ������ �����������:
  //    ==  1  - (bits - ��������� �� ������ ������ ������� �������)
  //    == -1  - (bits - ��������� �� ��������� ������ ������� �������,
  //                           � BMP ����������� �������� ����� - �����)
  //  widthinbyte    - ������ �������������� ������� ������ � ������
  // ������� ������������:
  //  ��� ElementSize() == 1 (���) - left,width ������ 8,
  //                    == 4 (���) - left,width ������ 2
  // ��� ������ ���������� 0

_MAPIMP  long int _MAPAPI mapPutRstFrame(HMAP hMap, long int number, char* bits,
                                  long int left, long int top,
                                  long int width, long int height,
                                  long int begining/* = 1*/,
                                  long int widthinbyte /*= 0*/);  // 27/04/01

  // ������ �������������� ������� ������
  //  hMap       - ������������� �������� ��������� �����
  //  number     - ����� ����� � �������
  //  bits    - ��������� �� ������ ����������� ������� �������
  //  left    - �������� ����� � ��������� (��������� �� ������� �����)
  //  top     - �������� ������ � ���������
  //  width   - ������ � ��������� (��������� �� ������� �����)
  //  height  - ������ � ���������
  //  widthinbyte    - ������ �������������� ������� ������ � ������
  // ������� ������������:
  //  ��� ElementSize() == 1 (���) - left,width ������ 8,
  //                    == 4 (���) - left,width ������ 2
  // ��� ������ ���������� 0

_MAPIMP  long int _MAPAPI mapGetRstFrame(HMAP hMap, long int number, char* bits,
                                  long int left, long int top,
                                  long int width, long int height,
                                  long int widthinbyte = 0);

  // ������ �������� ���������� �������������� ������� ������
  //  hMap       - ������������� �������� ��������� �����
  //  number     - ����� ����� � �������
  //  bitsR,bitsG - ��������� �� ������ ����������� �������� ��������
  //  bitsB         �������, ������� � ����� ���������
  //  left    - �������� ����� � ���������
  //  top     - �������� ������ � ���������
  //  width   - ������ � ���������
  //  height  - ������ � ���������
  //  ������������ ������ 8-������ ������ (����)
  // ��� ������ ���������� 0

_MAPIMP  long int _MAPAPI mapGetRstFrameRGB(HMAP hMap, long int number,
                          char* bitsR, char* bitsG, char* bitsB,
                          long int left, long int top,
                          long int width, long int height);


  // ����������� �������������� ������� ��������� ������    22/05/03
  // � �������������� ������, ������������� � ������� ������.
  //   hMap   - ������������� �������� ��������� �����
  //   number - ����� ����� � �������
  //   bits   - ��������� �� ������ ������� ������;
  //   width  - ������ ������� ������ � ��������� COLORREF
  //            (���������� �������� ��������������� ������);
  //   height - ������ ������� ������ � ���������
  //            (���������� ����� ��������������� ������);
  //   StrL,ColL,StrR,ColR - ���������� ������ � ������� ���������
  //                         ��������� ������, ������� ����������
  //                         ������� ��������� ������� ��������������
  //                         �������.
  // ��� ������ ���������� ����.

_MAPIMP  long int _MAPAPI mapGetRstFrameTurn(HMAP hMap,        // 22/05/03
                      long int number, COLORREF* bits,
                      long int width, long int height,
                      double StrL, double ColL,
                      double StrR, double ColR);


  // ����������� �������� ������ � ������� 
  // ��� �������� �������� �����������
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // element    - �������� ������
  // pixel      - ��������� � ��������
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapRstElementToPixel(HMAP hMap, long int number,
                                        double element,double *pixel);


  // ����������� ������� � �������� ������
  // ��� �������� �������� �����������
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // element    - ��������� � ��������� ������
  // pixel      - �������
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapPixelToRstElement(HMAP hMap, long int number,
                                        double pixel, double *element);


  // ������������ ������� ����� �������� ����� {string,column} // 26/06/01
  // � ������ ����� ������
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // string     - ������ �����
  // column     - ������� �����
  // bits       - ������� ������� �����
  // size       - ������ ������� ������� ����� � ������
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapBuildRstBlockMask(HMAP hMap, long int number,
                                        char * bits, long int size,
                                        long int string, long int column);

  // ���������� ����� ����������� ������ �� ������� �������    // 09/11/04
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // info       - ������ ����� � ������������
  // ����� ���������� ������� ����������� ������ ����������� �������� ��������
  // ��� ������ ���������� 0

_MAPIMP  long int _MAPAPI mapSetRstMask(HMAP hMap,long int number,HOBJ info);

  // ������� ������ ����� ������, ������������ ������.  // 12/07/05
  // hMap       - ������������� �������� ��������� �����
  // number     - ����� ����� � �������
  // ��� ������ ���������� 0

_MAPIMP  long int _MAPAPI mapFillRstVisiblePart (HMAP hMap, long int number, long int color);

  // �������� ����������� �����   // 26/11/04
  // ���� ����������� ����� �� ����������, ��������� ��� �����   
  // hMap   - ������������� �������� ��������� �����
  // number - ����� ����� � �������

_MAPIMP  long int _MAPAPI mapUpdateRstDuplicates (HMAP hMap, long int number);

  // �������� ����������� ����� ����� (string,column) ������       // 04/10/09
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapUpdateRstDuplicateOfBlock(HMAP hMap, long int number,
                                          int string, int column);

  // ��������� ���������������� ������������� ������
  // number    - ����� ����� � �������
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetRstUserLabel(HMAP hMap, long int number);   // 27/05/08

  // ���������� ���������������� ������������� ������
  // number    - ����� ����� � �������
  // userLabel - ������������� ������
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapSetRstUserLabel(HMAP hMap, long int number,
                                             long int userLabel);           // 27/05/08

  // ��������� ���������� ���-��������� ���� ������ � ������
  // hMap    - ������������� �������� �������� ��������� �����
  // number  - ����� ����� � �������
  // �� ������ x,y ������������ ���������� ��������� ����� � ������
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapWhereSouthWestRstPlane(HMAP hMap,long int number,
                                                   double * x, double * y);  // 24/06/09

  // ������� ���� RSW
  // ������� ������������� ��� �������� ������ � ��� ��������� ������
  // ��������� ����� �������� ����� 4Gb ������� �� 2-� ������: *.rsw � *.rsw.01
  // ������ ������� DeleteTheFile()
_MAPIMP  long int _MAPAPI mapDeleteRstFile(const char * name);       // 26/11/08

  // ������������� ��� ����� RSW
  // ������� ������������� ��� ���������������� ������ � ��� ��������� ������
  // ��������� ����� �������� ����� 4Gb ������� �� 2-� ������: *.rsw � *.rsw.01
  // ������ ������� MoveTheFile()

_MAPIMP  long int _MAPAPI mapMoveRstFile(const char * oldname,const char * newname); // 26/11/08

  // ����������� ���� RSW
  // ������� ������������� ��� ����������� ������ � ��� ��������� ������
  // ��������� ����� �������� ����� 4Gb ������� �� 2-� ������: *.rsw � *.rsw.01
  // ������ ������� CopyTheFile()

_MAPIMP  long int _MAPAPI mapCopyRstFile(const char * oldname, const char * newname, int exist = 0); // 26/11/08

  // ���������� ������� ��������� ��������� TIFF-�������  // 23/06/11

_MAPIMP  long int _MAPAPI mapSetRstPaintCoordSys(HMAP hMap, MAPREGISTEREX* mapreg,
                                                 DATUMPARAM * datum, ELLIPSOIDPARAM * ellipsoid);

  // ��������� ��� ������   // 31/08/11
  // hMap   - ������������� �������� ��������� �����
  // number - ����� ����� � �������
  // ����������: 0 - ������� �����
  //             1 - �����-�������� � ������ �������� � ����� TIFF

_MAPIMP  long int _MAPAPI mapRstIsAccessTiff(HMAP hMap, long int number);

  // ��������� ��� TIFF-����� ��� ������ � �������  number                      
  // hMap   - ������������� �������� ��������� �����
  // number - ����� ����� � �������

_MAPIMP  long int _MAPAPI mapGetRstFileName_Tiff(HMAP hMap, long int number, char * name);

  // ��������� ���������� ������� TIFF-������ � �������  number                      
  // hMap   - ������������� �������� ��������� �����
  // number - ����� ����� � �������

_MAPIMP  long int _MAPAPI mapGetRstBandCount_Tiff(HMAP hMap, long int number);

  // ��������� ����� ������ TIFF-������ � �������  number, ������������� �������  
  // hMap   - ������������� �������� ��������� �����
  // number - ����� ����� � �������

_MAPIMP  long int _MAPAPI mapGetRstRedBand_Tiff(HMAP hMap, long int number);

  // ��������� ����� ������ TIFF-������ � �������  number, ������������� �������  
  // hMap   - ������������� �������� ��������� �����
  // number - ����� ����� � �������

_MAPIMP  long int _MAPAPI mapGetRstGreenBand_Tiff(HMAP hMap, long int number);

  // ��������� ����� ������ TIFF-������ � �������  number, ������������� �����  
  // hMap   - ������������� �������� ��������� �����
  // number - ����� ����� � �������

_MAPIMP  long int _MAPAPI mapGetRstBlueBand_Tiff(HMAP hMap, long int number);

  // ���������� ����� ������ TIFF-������ � �������  number, ������������� �������  
  // (���� ���������� -1, �� ����� ����� �� ������������)
  // hMap   - ������������� �������� ��������� �����
  // number - ����� ����� � �������

_MAPIMP  long int _MAPAPI mapSetRstRedBand_Tiff(HMAP hMap, long int number, int redband);

  // ���������� ����� ������ TIFF-������ � �������  number, ������������� �������  
  // (���� ���������� -1, �� ����� ����� �� ������������)
  // hMap   - ������������� �������� ��������� �����
  // number - ����� ����� � �������

_MAPIMP  long int _MAPAPI mapSetRstGreenBand_Tiff(HMAP hMap, long int number, int greenband);

  // ���������� ����� ������ TIFF-������ � �������  number, ������������� �����  
  // (���� ���������� -1, �� ����� ����� �� ������������)
  // hMap   - ������������� �������� ��������� �����
  // number - ����� ����� � �������

_MAPIMP  long int _MAPAPI mapSetRstBlueBand_Tiff(HMAP hMap, long int number, int blueband);

  // ���������� ����������� ������������������� ������ �� �������������� �������  
  // ����� ������� ���������� ��������� ��� ������ ������� mapRstIsAccessTiff, ���
  // ��� ������ � ������� number �������������� ������ ������ � ����� TIFF
  // ������� ����������� ��� ������������������ ����������� (mapGetRstBandCount_Tiff() >= 3)

_MAPIMP long int _MAPAPI mapSetRstVegIndex_Tiff(HMAP hMap, long int number, VEGINDEX *vegindex);

  // ���������� ��������� ����������� �������������� �������  
  // ���� ����������� �� �������������� ������� �� ����������� ���������� 0
  // ����� ������� ���������� ��������� ��� ������ ������� mapRstIsAccessTiff, ���
  // ��� ������ � ������� number �������������� ������ ������ � ����� TIFF
  // ������� ����������� ��� ������������������ ����������� (mapGetRstBandCount_Tiff() >= 3)

_MAPIMP long int _MAPAPI mapGetRstVegIndex_Tiff(HMAP hMap, long int number, VEGINDEX *vegindex);

  // ���������� ������� ������� ����������� �� ����� bandnum 
  // x, y  - ���������� ������� � ������� ��������� ������ (� ��������)
  // color - ������������ �������� ������� ���������� � ������ (����� ���� 1,4,8,16 ���)
  // bandnum - ����� ������ (�� 0 �� mapGetRstBandCount_Tiff - 1)
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapGetRstBandPixel_Tiff(HMAP hMap, long int number, 
                                                 long int x, long int y,
                                                 long int bandnum, long int *color);

  // ������������� ������ ������ � ����� ������� �������� ��������� �����������
  // �� ������� �������� ��� ��������� ������ � ������� ���������, �������� ��
  // ������� ��������� ������.
  // ����� ������ �������� ��������� ����������� �������� �������������. ������������
  // ��������� ��������� ������ ������ ����������� �� ���� ������� ����� ������.
  // ��� ���������� ������� ������������� �������� ���������, �� ���������� ��������
  // ����������� ��� ������������ ���������� ������� ��������� ��������� ������������
  // ������� ��������� ������ (����������� �������������� �� ������� ������).
  // ���� �������� �������� ����������, �.�. � ������� ��������� ��� ������
  // �������������� � �������������� ����� ���������
  // radius - ��������������� ������ ������ � �������� (�� ����� ���� ������ 0).
  //          ���� ����� 0, �� ��� ������� ����������� �� ������� ��������.
  //          �������� �� ��������� 3.
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapSetRstPaintCellRadius_Tiff(long int radius);

  // ���������� ������ ������ � ����� ������� �������� ��������� �����������
  // �� ������� �������� ��� ��������� ������ � ������� ���������, �������� ��
  // ������� ��������� ������.

_MAPIMP long int _MAPAPI mapGetRstPaintCellRadius_Tiff();

  // ���������� ������� ����� �� ����� (1, 4, 8, 16) // 31/01/12
  // hMap   - ������������� �������� ��������� �����
  // number - ����� ����� � �������
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapGetRstBitInBand_Tiff(HMAP hMap, long int number);

  // ���������� �����������              // 31/01/12
  // ����������� - ����������� ������ ���������� ��������, �������������� � ������
  // hMap   - ������������� �������� ��������� �����
  // number - ����� ����� � �������
  // count     - ���������� ��������� � ������� histogram
  //             ���������� ��������� ����������� �� �������
  //             count = BandCount * (1 << BitInBand)
  //             ��� ���������� ������� BandCount = 1
  //             ��� 1 ������ ������� (����������) count = 2
  //             ��� 4 ������ ������� (����������) count = 16
  //             ��� 8 ������ ������� (����������) count = 256
  //             ��� RGB                           count = 3 * 256 = 768
  //             ��� 8  ������ ������������������  count = BandCount * 256
  //             ��� 16 ������ ������������������  count = BandCount * 65536
  // histogram - ������������ �����������
  // ��� ������ ���������� 0

_MAPIMP long int _MAPAPI mapGetRstHistogram_Tiff(HMAP hMap, long int number, 
                                                 int count, int *histogram);



}  // extern "C"


#endif  // RSTAPI_H