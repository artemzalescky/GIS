/****** RSCAPI.H *************** Belenkov   O.V. ****** 20/09/11 ***
******* RSCAPI.H *************** Panteleeva N.A. ****** 17/01/12 ***
******* RSCAPI.H *************** Vitsko     D.A. ****** 23/11/05 ***
*                                                                  *
*              Copyright (c) PANORAMA Group 1991-2012              *
*                      All Rights Reserved                         *
*                                                                  *
********************************************************************
*                                                                  *
*       �������� ������� ������� � ��'���� "������������� ����"    *
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
*    HRSC (WINAPI * lpfn)(HMAP,HSITE);                             *
*    (FARPROC)lpfn = GetProcAddress(libInst, "mapGetRscIdent");    *
*    HRSC hRsc = (*lpfn)(hMap,hSite);                              *
*                                                                  *
*    // �������� ����������                                        *
*    ::FreeLibrary(libInst);                                       *
*                                                                  *
*******************************************************************/

#ifndef RSCAPI_H
#define RSCAPI_H

#ifndef MAPTYPE_H
 #include "maptype.h"
#endif

#ifndef MAPGDI_H
 #include "mapgdi.h"
#endif 

  // ���������� ����� ����� ���������� � 0. ������� ���� - ���������.
  // ��������������� ���� ������ ��� ��������.�������� ���� ���������.
  // �������� ��� ���� (����) - ���������.

  // ���������� ��� (���������� ����� ) �������� ���������� � 1.
  // ���������� ��� ������� �� ����� ���������� ��������.
  // ���� ������� - ��������.

  // ��������������� �������� ������ ���. ��������� � ����� 0 - ���������.
  // ��� ��������� �� �������� �� ���������� ������� .
  // ���������� ����� ��������� ���������� � 1.
  // �������� ��� ��������� (����) - ���������.

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// +++ �������� ������� ������� � �������������� +++++++++++
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
extern "C"
{
  /*********************************************************
  *                                                        *
  * ������� ������� ���������� �� �������������� ��'�����  *
  *                                                        *
  *********************************************************/

  // ��������� ������������� �������������� �����
  // hMap  - ������������� �������� �����
  // hSite - ������������� �������� ���������������� �����
  // ��� ������ ���������� ����

_MAPIMP  HRSC _MAPAPI mapGetRscIdent(HMAP hMap,HSITE hSite);

  // ��������� ��� ����� ��������������
  // hRsc   - ������������� �������������� �����,
  // target - ������ ��� ���������� ������� ����� �����,
  // size   - ������ ������
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetRscFileName(HRSC hRsc,
                                     char * target, long int size);

  // ��������� ��� ��������������
  // hRsc - ������������� �������������� �����
  // ��� ������ ���������� ����

_MAPIMP  const char * _MAPAPI mapGetRscName(HRSC hRsc);

  // ��������� ��� ������ ��������� �������� � ��������������� �����
  // hRsc - ������������� �������������� �����
  // ���� ������ ����������� � maperr.rh

_MAPIMP  long int _MAPAPI mapGetRscError(HRSC hRsc);  

  // ��������� ���� ��������� �������������� �����
  // hRsc - ������������� �������������� �����
  // ��� ��������� ����� ���������� ���� �������� �����������

_MAPIMP  long int _MAPAPI mapGetRscMode(HRSC hRsc);

  // ��������� ����� �������������� �����
  // hRsc - ������������� �������������� �����
  // ��� ��������� ����� ����� ���������� ���������� ���� ��������

_MAPIMP  long int _MAPAPI mapGetRscStyle(HRSC hRsc);

  // ��������� ����� �������� ��������� � ��������������
  // hRsc - ������������� �������������� �����
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetRscObjectCount(HRSC hRsc);

  // ��������� ����� �������� ��������� � ��������������
  // � �������� ����
  // hRsc - ������������� �������������� �����
  // layer - ����� ����
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetRscObjectCountInLayer(HRSC hRsc,
                                               long int layer);

  // ��������� �������� ������� �� ����������� ������
  // � �������� ����
  // hRsc   - ������������� �������������� �����
  // layer  - ����� ����
  // number - ����� ������� � ����
  // ��� ������ ���������� ���� ��� ������ ������

_MAPIMP  const char * _MAPAPI mapGetRscObjectNameInLayer(HRSC hRsc,
                                               long int layer,
                                               long int number);

 // ��������� �������� ������� �� ����������� ������
 // � �������� ����
 // hRsc   - ������������� �������������� �����
 // layer  - ����� ����
 // number - ����� ������� � ����
 // name   - ����� ������ ��� ���������� ����������
 // size   - ������ ������ (�� ������ 32 ����)
 // ��� ������ ���������� ����                                  // 08/05/07

_MAPIMP   long int _MAPAPI mapGetRscObjectNameInLayerEx(HMAP hRsc,
                                                        long int layer,
                                                        long int number,
                                                        char * name, long int size);

  // ��������� ����������������� ��� �������
  // �� ����������� ������ � �������� ����
  // hRsc - ������������� �������������� �����
  // layer - ����� ����
  // number - ����� ������� � ����
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetRscObjectExcodeInLayer(HRSC hRsc,
                                                       long int layer,
                                                       long int number);

  // ��������� ��� ����������� �������
  // �� ����������� ������ � �������� ����
  // hRsc - ������������� �������������� �����
  // layer - ����� ����
  // number - ����� ������� � ����
  // ��� ������ ���������� ���� (���� ��������)

_MAPIMP  long int  _MAPAPI mapGetRscObjectLocalInLayer(HRSC hRsc,
                                            long int layer,
                                            long int number);

  // ��������� ���������� ��� (���������� �����) �������
  // �� ����������� ������ � �������� ����
  // hRsc - ������������� �������������� �����
  // layer - ����� ����
  // number - ����� ������� � ����
  // ��� ������ ���������� ����

_MAPIMP  long int  _MAPAPI mapGetRscObjectCodeInLayer(HRSC hRsc,
                                               long int layer,
                                               long int number);

  // ��������� ������ ������� ������� ��������� ��������������
  // hRsc - ������������� �������������� �����
  // ��� ������ ���������� ����

_MAPIMP  long int  _MAPAPI mapGetRscScaleCount(HRSC hRsc);

  // ��������� �������� (����������� ��������) �� ������� �������
  // ��������� ��������������  �� ����������� ������ (� 1)
  // hRsc - ������������� �������������� �����
  // ��� ������ ���������� ����

_MAPIMP  long int  _MAPAPI mapGetRscScaleItem(HRSC hRsc,
                                       long int number);

  // ����� �������� ��������������                                     // 20/04/06
  // oldnumber - ����� ������� ��� ���������� ������, 0 - ����� � �������
  // seektype - ������� ������  SEEK_RSCOBJECT (maptype.h)
  // example - ������ ��� ������
  // ���������� ���������� ����� ������� ��� 0, ���� ������ ���
_MAPIMP  long int  _MAPAPI mapGetRscSeekObjectCode(HRSC hRsc,long int oldnumber,
                                       long int seektype, char * example);

  /*********************************************************
  *                                                        *
  *        ������� �������� �������������� ��'�����        *
  *                                                        *
  *********************************************************/

  // ������� ������������� ��������� �����
  // name - ��� ������������ ����� ��������������
  // RSCCREATE -   ��������� ������� ������  (��. maptype.h)
  // PALETTE256 -  ��� ������������� �������� ������� (�� ����� 32 ������)
  //               (��. maptype.h)
  // ��� ������ ���������� ����

_MAPIMP  HRSC _MAPAPI mapCreateRsc(const char * name, const RSCCREATE * rsccreate,
                                   const PALETTE256 * palette);

_MAPIMP  HRSC _MAPAPI mapCreateRscUn(const WCHAR * name, const RSCCREATEUN * rsccreate,
                                     const PALETTE256 * palette);

  // ������� ������������� ��������� ����� c �������������� ����� �������
  // �� ����� (��������� ����� �������)
  // name - ��� ������������ ����� ��������������
  // RSCCREATE -   ��������� ������� ������  (��. maptype.h)
  // PALETTE256 -  ��� ������������� �������� ������� (�� ����� 32 ������)
  //               (��. maptype.h)
  // ��� ������ ���������� ����                         // 21/05/02

_MAPIMP  HRSC _MAPAPI mapCreateKeyObjectRsc(char * name, RSCCREATE * rsccreate,
                            PALETTE256 * palette );


  // ��������� ������ �� �������������� ��������� �����
  // hRsc - ������������� �������������� �����
  // RSCCREATE -  �������� ��������������  (��. maptype.h)
  // PALETTE256 - �������� ������� �����   (��. maptype.h)
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetRscDescribe(HRSC hRsc, RSCCREATE * rsccreate,
                                     PALETTE256 * palette);

  // ������� �������������
  // name - ���  ����� ��������������
  // ��� ������ ���������� ����, ����� ������������� �������������� �����

_MAPIMP  HRSC _MAPAPI mapOpenRsc(char * name);

  // ������� �������������
  // hRsc - ������������� �������������� �����
  // ��� ������ ���������� ����

_MAPIMP  HRSC _MAPAPI mapCloseRsc(HRSC hRsc);

  // ��������� ������������� �� ����
  // hRsc - ������������� �������������� �����
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapCommitRsc(HRSC hRsc);

  // ��������� ������������� �� ���������� ���� (������� ���)      // 17/01/12
  // hRsc - ������������� �������������� �����
  // unpath - ���� ( � UNUCODE)
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapSaveRscAs(HRSC hRsc, const WCHAR * unpath);

  // ������������ ������������� � �����
  // hRsc - ������������� �������������� �����
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapRevertRsc(HRSC hRsc);

 /****************************************************************
 *                                                               *
 *     ������ � �������� ����������� ����������� �����           *
 *    ����������� ���������� � 0                                 *
 *                                                               *
 ****************************************************************/

  // ������ ���������� �����������
  // hRsc - ������������� �������������� �����

_MAPIMP  long int  _MAPAPI mapGetRscLocalCount(HRSC hRsc);

  // ������ �������� ����������� �� �� ������ (0 - ��������, ...)
  // hRsc - ������������� �������������� �����
  // local - ��� �����������
  // language - ���� (�� ��������� - �������)
  // �������� �������� �� ���� ������ ...

_MAPIMP  const char * _MAPAPI mapGetRscLocalName(HRSC hRsc,long int local,
                                                 long int language = ML_RUSSIAN);

  // ������ �������� ����������� �� �� ������ (0 - ��������, ...)
  // hRsc - ������������� �������������� �����
  // local - ��� �����������
  // name - ����� ������ ��� ���������� ����������
  // size - ������ ������
  // language - ���� (�� ��������� - �������)
  // �������� �������� �� ���� ������ ...                  // 13/02/07
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetRscLocalNameEx(HRSC hRsc, long int local,
                                               char * name, long int size,
                                               long int language = ML_RUSSIAN);

_MAPIMP  long int _MAPAPI mapGetRscLocalNameUn(HRSC hRsc, long int local,
                                               WCHAR * name, long int size,
                                               long int language);

  // ������ ����� ����� �����������
  // hRsc - ������������� �������������� �����
  // (������ ��� �������� �� 32 ��������)

_MAPIMP  long int _MAPAPI mapGetRscLocalNameSize(HRSC hRsc);


  /*********************************************************
  *                                                        *
  *  ������� ������ �� ������ �� �������������� ��'�����   *
  *                                                        *
  *********************************************************/

  // ��� ������� �������� �����  � ������ ���������������  �����
  // ��������� ������� ������ ����� �� �����, ����� ����������� ���-
  // ����� �� ���� � ���� � ����� �������� ����� ���������� ��������
  // ����� � ������������ � ��������������� - ������� mapAdjustData()
  // � ��� ������������� ������������ �����

  // ������ ���������� �����
  // hRsc - ������������� �������������� �����
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetRscSegmentCount(HRSC hRsc);


  // ������ ����� ���� �� ����������� ������ ���� (� 0)
  // hRsc - ������������� �������������� �����
  // incode - ����� ����
  // ��� ������ ���������� ""

_MAPIMP  const char * _MAPAPI mapGetRscSegmentName(HRSC hRsc,long int incode);

  // ������ ����� ���� � ��������� UNICODE �� ����������� ������ ���� (� 0)
  // hRsc - ������������� �������������� �����
  // incode - ����� ����
  // name - ����� ������ ��� ���������� ����������
  // size - ������ ������ (����� ���� �� 2048 ����)
  // ��� ������ ���������� 0

_MAPIMP  long int _MAPAPI mapGetRscSegmentNameUn(HRSC hRsc,long int incode,
                                                 WCHAR * name, long int size);
_MAPIMP  long int _MAPAPI mapGetRscSegmentNameUnicode(HRSC hRsc,long int incode,
                                                      WCHAR * name, long int size);

  // ������ ����������� ������ ���� �� �����
  // ������ ����� ���������� � 0 !
  // hRsc - ������������� �������������� �����
  // name - ��� ����
  // ��� ���������� ���� ���������� - 0, ��� ������ IDS_NOTFIND

_MAPIMP  long int _MAPAPI mapGetSegmentByName(HRSC hRsc,char * name);


  // ������ ������������ ����� ����� ����
  // hRsc - ������������� �������������� �����
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetRscSegmentNameSize(HRSC hRsc);


  // ������ ������� ������ ���� �� ����� �� ����������� ������ (� 0)
  // hRsc - ������������� �������������� �����
  // incode - ����� ����
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetRscSegmentOrder(HRSC hRsc,long int incode);


  // ������ ���������� �������� ���� ��  ����������� ������ ���� (� 0)
  // hRsc - ������������� �������������� �����
  // incode - ����� ����
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetRscSegmentObjectCount(HRSC hRsc,long int incode);


  // ��������� ����� ���� �� ����������� ������ ���� (� 0)
  // hRsc - ������������� �������������� �����
  // incode - ����� ����
  // name   - ��� ����                                          // 15/07/09
  // ��� ������ ���������� ����, ����� ���������� ����� ����.
  // ���� �������� 0, ��������� ��� ��������� ������ �������� mapGetRscError.
  // ��� ��������� ��� ���������� ����� ����
  // ������� mapGetRscError ���������� IDS_RSCEXITSEGMENTERROR (MAPERR.RH)

_MAPIMP  long int _MAPAPI mapSetRscSegmentName(HRSC hRsc,
                                        long int incode,char * name);


  // ��������� ������� ������ ���� �� ����������� ������ ���� (� 0)
  // hRsc - ������������� �������������� �����
  // incode - ����� ����
  // order  - ������� ������
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapSetRscSegmentOrder(HRSC hRsc,
                                         long int incode,
                                         long int order);


  // ������� ���� �� ����������� ������ ���� (� 0)
  // ���� ���������  ������ � ���������
  // hRsc - ������������� �������������� �����
  // incode - ����� ����
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapDeleteRscSegment(HRSC hRsc,long int incode);


  // ��������� ������� �� ������ ���� � ������
  // hRsc - ������������� �������������� �����
  // oldcode, newcode - ����� ����
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapMoveRscSegmentObjects(HRSC hRsc,
                                            long int oldcode,
                                            long int newcode);


  // ������� ���� � �������������� �����
  // RSCSEGMENT -  ��������� ������� ������  (��. maptype.h)
  // hRsc - ������������� �������������� �����                   // 15/07/09
  // ��� ������ ���������� ����, ����� ���������� ����� ����(� 0)
  // ���� �������� 0, ��������� ��� ��������� ������ �������� mapGetRscError.
  // ��� ��������� ��� ���������� ����� ����
  // ������� mapGetRscError ���������� IDS_RSCEXITSEGMENTERROR (MAPERR.RH)

_MAPIMP  long int _MAPAPI mapAppendRscSegment(HRSC hRsc, RSCSEGMENT * segment);


  // ��������� ��������� �������� �����
  // RSCSEGMENT -  ��������� ������� ������  (��. maptype.h)
  // hRsc - ������������� �������������� �����
  // incode - ���������� ����� ����
  // ��� ������ ���������� ���� � ��� ������
  // ����� ���������� ����� ����  (� 0)

_MAPIMP  long int _MAPAPI mapGetRscSegment(HRSC hRsc, RSCSEGMENT * segment,
                                    long int incode);


  // ��������� �������� ��� (����) ����
  // hRsc - ������������� �������������� �����
  // incode - ���������� ����� ���� (� 0)
  // ��� ������ ���������� ������ ������

_MAPIMP  const char * _MAPAPI mapGetRscSegmentShortName(HRSC hRsc,long int incode);
_MAPIMP  const char * _MAPAPI mapGetRscSegmentKey(HRSC hRsc,long int incode);  //18/09/01


  // ���������� �������� ���(����) ����
  // hRsc - ������������� �������������� �����
  // incode - ���������� ����� ���� (� 0)
  // ��� ������ ���������� 0

_MAPIMP  long int _MAPAPI mapSetRscSegmentShortName(HRSC hRsc,long int incode,
                                             char * shortname );
_MAPIMP  long int _MAPAPI mapSetRscSegmentKey(HRSC hRsc,long int incode,    //18/09/01
                                             char * key);


  // ��������� ���������� ����� ���� (� 0) �� ��������� �����(�����) ����   //11/03/00
  // hRsc - ������������� �������������� �����
  // shortname - �������� ���(����) ����
  // ��� ������ ���������� ���� � ��� ������
  // ����� ���������� ����� ����  (� 0)

_MAPIMP  long int _MAPAPI mapGetRscSegmentByShortName(HRSC hRsc,char * shortname);
_MAPIMP  long int _MAPAPI mapGetRscSegmentByKey(HRSC hRsc,char * key);     //18/09/01


  // ��������� ���������� �������� ����
  // hRsc - ������������� �������������� �����
  // incode - ���������� ����� ���� (� 0)
  // ��� ������ ���������� 0

_MAPIMP  long int _MAPAPI mapGetRscSegmentSemanticCount(HRSC hRsc,long int incode);


  // ��������� ��� ��������� ���� �� ����������� ������
  // number ��������� � ������ (� 1)
  // hRsc - ������������� �������������� �����
  // layer - ���������� ����� ���� (� 0)
  // ��� ������ ���������� 0

_MAPIMP  long int _MAPAPI mapGetRscSegmentSemanticCode(HRSC hRsc,long int layer,
                                                 long int number);


  // �������� ��������� ����
  // semanticcode ��� ����������� ���������
  // hRsc - ������������� �������������� �����
  // layer - ���������� ����� ���� (� 0)
  // ��� ������ ���������� 0

_MAPIMP  long int _MAPAPI mapAppendRscSegmentSemantic(HRSC hRsc,long int layer,
                                                long int semanticcode);


  // ������� ��������� �� ����
  // semanticcode ��� ��������� ���������
  // hRsc - ������������� �������������� �����
  // layer - ���������� ����� ���� (� 0)
  // ��� ������ ���������� 0

_MAPIMP  long int _MAPAPI mapDeleteRscSegmentSemantic(HRSC hRsc,long int layer,
                                                    long int semanticcode);


  // ���������� ��������� ��� ����
  // hRsc - ������������� �������������� �����
  // layer - ���������� ����� ���� (� 0)
  // type = 0 - ������� ��� ���������,1 - ������ ������������
  // ��� ������ ���������� 0

_MAPIMP  long int _MAPAPI mapBuildRscSegmentSemantic(HRSC hRsc,long int layer,
                                              long int type);

  // ���������� ��� ���� � ��������� UNICODE �� ����������� ������ ���� (� 0)
  // hRsc - ������������� �������������� �����
  // incode - ����� ����
  // name - ��� ���� � ��������� UNICODE
  // ��� ������ ���������� 0

_MAPIMP  long int _MAPAPI mapSetRscSegmentNameUn(HRSC hRsc,long int incode,
                                                 const WCHAR * name);

_MAPIMP  long int _MAPAPI mapSetRscSegmentNameUnicode(HRSC hRsc,long int incode,
                                                      const WCHAR * name);

  /***********************************************************
  *                                                          *
  *  ������� ������ � ��'������ �� �������������� ��������   *
  *                                                          *
  ***********************************************************/

  // ������� ������
  // RSCOBJECT -  ��������� ������� ������  (��. maptype.h)
  // hRsc - ������������� �������������� �����
  // ��� ������ ���������� ���� , ����� ���������� ����� ������� (� 1)

_MAPIMP  long int  _MAPAPI mapAppendRscObject(HRSC hRsc, RSCOBJECT * object);


  // ����������� ������
  // hRsc - ������������� �������������� �����
  // oldcode - ���������� ����� ������� � �������� ��������
  // ��� ������ ���������� ���� , ����� ���������� ����� ������ ������� (� 1)
  // ���������� ��������� �������,��� �����������,��������� �������
  // ���  FIRSTSERVEXCODE
  // ��� ����,����� ������ ������ ����������,
  // ������������ ������ �������������� ������� ���

_MAPIMP  long int  _MAPAPI mapCopyRscObject(HRSC hRsc, long int oldcode);


  // �������� ������
  // RSCOBJECT -  ��������� ������� ������  (��. maptype.h)
  // hRsc - ������������� �������������� �����
  // ��� ������ ���������� ���� , ����� ���������� ����� ������� (� 1)
  // ��� ������� ����� ������� ��� � ����������� � ���� - �� ��������
  // ���� ������� ��� ������� �� ������������� ����������� - ������������
  // ������������ ������� ���

_MAPIMP  long int  _MAPAPI mapUpdateRscObject(HRSC hRsc,long int code,
                                       RSCOBJECT * object);


  // ������� ������
  // hRsc - ������������� �������������� �����
  // �ode - ���������� ����� ������� ������� ������� (� 1)
  // ��� ������ ���������� ���� , ����� ���������� ����� ���������� �������
  // ���� ������ ������ � ����� - �������� �� ��������

_MAPIMP  long int  _MAPAPI mapDeleteRscObject(HRSC hRsc,long int code);


  // ��������� ��������� �������� �������
  // RSCOBJECT -  ��������� ������� ������  (��. maptype.h)
  // hRsc - ������������� �������������� �����
  // incode - ���������� ����� ������� (� 1)
  // ��� ������ ���������� ���� , ����� ���������� ����� �������

_MAPIMP  long int  _MAPAPI mapGetRscObject(HRSC hRsc,long int incode,
                                    RSCOBJECT * object);


  // ��������� ���������� ����� ������� � ����� ����������
  // �������� (� ����� ����������������� ����� � ������������)
  // �� ����������� ���� �������
  // (��������������� ������� - mapGetRscObjectCodeByNumber)
  // hRsc - ������������� �������������� �����
  // incode - ���������� ����� ������� (� 1)
  // ��� ������ ��� ���������� ����� ���������� ���� ,
  // ����� ����� ������� � �����

_MAPIMP  long int _MAPAPI mapGetRscObjectNumber(HRSC hRsc,long int incode);


  // ��������� ������� � �������� � �������� ��������� ���� �������
  // hRsc - ������������� �������������� �����
  // incode - ���������� ����� ������� (� 1)
  // IMAGESIZE -  ��������� ������� ������  (��. maptype.h)
  // ������ string ������ length �������� ���
  // ����������� ��������������� ������� �������
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetRscImageSize(HRSC hRsc,
                            long int incode, IMAGESIZE * imagesize,
                            long int length = 0,char * string = 0);

  // ��������� ������� � �������� � �������� ����������� ���� �������
  // hRsc - ������������� �������������� �����
  // incode - ���������� ����� ������� (� 1)
  // IMAGESIZE -  ��������� ������� ������  (��. maptype.h)
  // ������ string ������ length �������� ���
  // ����������� ��������������� ������� �������
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetRscPrnImageSize(HRSC hRsc,
                            long int incode, IMAGESIZE * imagesize,
                            long int length = 0,char * string = 0);


 // ��������� ���������� ����� ����������� ������� (��������, ���������)
 // � ������ �������� ������� (IMAGEFRAME - ��. maptype.h)
 // ��� ������� � �������� �� "��������" ����������� (� ������� ��������)
 // ������������ ������ ����� ������� ������� � ���������������� �������
 // ��� ��������� ���������� ��������� � ����� �� ��������� �����
 // �� �������� �� 1 000 000, �������� �� ������� ������� �����
 // � �������� ���������� ������ ����� �������
 // number - ����� ������� ����������� (mapgdi.h)
 // param  - ��������� ����������� (mapgdi.h)
 // angle  - ���� �������� ������� � �������� �� ������� �������
 // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetRscMarkFrame(HRSC hRsc, long int number,
                                     const char * param,
                                     double angle,
                                     IMAGEFRAME * imageframe);


  // ��������� ���������� ��� (���������� �����) �������
  // �� �������� ���� , �����������  � ����������� ������ ����� �����������
  // ��������(� 1)
  // hRsc - ������������� �������������� �����
  // ��� ������ ���������� ����

_MAPIMP  long int  _MAPAPI mapGetRscObjectCodeByNumber(HRSC hRsc,
                                                long int excode,
                                                long int local,
                                                long int number = 1);

  // ��������� ���������� �������� � �������� ������� ����� � ������������
  // hRsc - ������������� �������������� �����
  // excode - ������� ��� �������
  // local  - ��� �����������
  // ��� ������ ���������� ����

_MAPIMP  long int  _MAPAPI mapGetRscObjectsCount(HRSC hRsc,
                                          long int excode,
                                          long int local);

  // ��������� ��� ������� �� �����������  ���� (����������� ������) ������� (� 1)
  // hRsc - ������������� �������������� �����
  // incode - ���������� ��� ������� (����� �� �������)
  // ��� ������ ���������� ������ ������

_MAPIMP  const char * _MAPAPI mapGetRscObjectName(HRSC hRsc,long int incode);

  // ��������� ��� ������� �� �����������  ���� (����������� ������) ������� (� 1)
  // � ��������� UNICODE
  // hRsc - ������������� �������������� �����                 // 28/05/09
  // incode - ���������� ��� ������� (����� �� �������)
  // name - ����� ������ ��� ���������� ����������
  // size - ����������������� ������ ������ (����� ���� �� 2048 ����)
  // ��� ������ ���������� 0

_MAPIMP  long int _MAPAPI mapGetRscObjectNameUn(HRSC hRsc,long int incode,
                                                WCHAR * name, long int size);

_MAPIMP  long int _MAPAPI mapGetRscObjectNameUnicode(HRSC hRsc,long int incode,
                                                     WCHAR * name, long int size);

  // ��������� ���� ������� �� �����������  ���� (����������� ������)
  // ������� (� 1)
  // hRsc - ������������� �������������� �����
  // incode - ���������� ��� ������� (����� �� �������)
  // ��� ������ ���������� ������ ������

_MAPIMP  const char * _MAPAPI mapGetRscObjectKey(HRSC hRsc,long int incode);

  // ��������� ���� ������� �� �����������  ���� (����������� ������) // 29/05/09
  // ������� (� 1) � ��������� UNICODE
  // hRsc - ������������� �������������� �����
  // incode - ���������� ��� ������� (����� �� �������)
  // ��� ������ ���������� ������ ������

_MAPIMP  long int _MAPAPI mapGetRscObjectKeyUn(HRSC hRsc,long int incode,
                                               WCHAR * name, long int size);

  // ���������� ���� ������� �� �����������  ���� (����������� ������)
  // ������� (� 1)
  // hRsc - ������������� �������������� �����
  // incode - ���������� ��� ������� (����� �� �������)
  // (�������� ��� ������ ���� ���������)
  // ��� ������ ���������� ������ ������

_MAPIMP  const char * _MAPAPI mapSetRscObjectKey(HRSC hRsc,long int incode,
                                                const char * key);

  // ��������� ��� ����������� ������� �� �����������  ���� (����������� ������)
  // ������� (� 1)
  // hRsc - ������������� �������������� �����                 // 28/05/09
  // incode - ���������� ��� ������� (����� �� �������)
  // ��� ������ ���������� ���� (���� ��������)

_MAPIMP  long int  _MAPAPI mapGetRscObjectLocal(HRSC hRsc,
                                                long int incode);

  // ��������� ����� ���� ������� �� �����������  ���� (����������� ������)
  // ������� (� 1)
  // hRsc - ������������� �������������� �����                 // 28/05/09
  // incode - ���������� ��� ������� (����� �� �������)
  // ��� ������ ���������� ���� (���� ��������)

_MAPIMP  long int  _MAPAPI mapGetRscObjectSegment(HRSC hRsc,
                                                  long int incode);

  // ��������� ������������� ������� (���������� ���������� ��������
  // � �������� ������� ��������������) �� �����������  ���� (����������� ������)
  // ������� (� 1)
  // hRsc - ������������� �������������� �����
  // incode - ���������� ��� ������� (����� �� �������)
  // ��� ������ ���������� 0

_MAPIMP  long _MAPAPI mapGetRscObjectIdent(HRSC hRsc,long int incode);


  // ��������� ���������� ��� (���������� �����) �������
  // �� ��������������
  // hRsc - ������������� �������������� �����
  // ident - ������������� �������
  // ��� ������ ���������� 0

_MAPIMP  long _MAPAPI mapGetRscObjectIdentIncode(HRSC hRsc,long int ident);


  // ��������� ���������� ��� (���������� �����) �������
  // �� �����
  // hRsc - ������������� �������������� �����
  // key  - ���� �������
  // ��� ������ ���������� 0

_MAPIMP  long _MAPAPI mapGetRscObjectCodeByKey(HRSC hRsc,const char * key);
_MAPIMP  long _MAPAPI mapGetRscObjectKeyIncode(HRSC hRsc,const char * key);
_MAPIMP  long _MAPAPI mapGetRscObjectCodeByKeyUn(HRSC hRsc, const WCHAR * key);  // 29/05/09

  // ��������� ����������  ��� (���������� �����) �������       //22/06/01
  // �� �����
  // hRsc - ������������� �������������� �����
  // name - ��� �������
  // ��� ������ ���������� 0

_MAPIMP  long _MAPAPI mapGetRscObjectCodeByName(HRSC hRsc,char * name);


  // ��������� ����� �������� �������� �� ������� ��� ������� �� �����������
  // ���� (����������� ������)  ������� (� 1)
  // incode - ���������� ��� ������� (����� �� �������)
  // hRsc   - ������������� �������������� �����

_MAPIMP  long  _MAPAPI mapGetRscImageSemanticCount(HRSC hRsc,long int incode);


  // ������ ���� ��������� �������� �� ����������� �� ����������� ����
  // (����������� ������) ������� � ����������� ������ ����� ��������� (c 1)
  // hRsc - ������������� �������������� �����
  // incode - ���������� ��� ������� (����� �� �������)
  // number - ����� ���������
  // ��� ������ ���������� 0

_MAPIMP  long _MAPAPI mapGetRscImageSemanticCode(HRSC hRsc,long int incode,
                                                 long int number);

  // ���p����� ���������� ��������� �������� �������        //01/11/01
  // �� ����������� ���� (����������� ������) �������
  // hRsc - ������������� �������������� �����
  // incode - ���������� ��� ������� (����� �� �������)

_MAPIMP  long _MAPAPI mapGetRscObjectRelateCount(HRSC hRsc,long int incode);


  // ���p����� �������� ��������� ������� �� ����������� ����   //01/11/01
  // (����������� ������) ������� � �� ����������� ������ ��������� ������� (� 1)
  // hRsc - ������������� �������������� �����
  // incode - ���������� ��� ������� (����� �� �������)
  // relate - �������� ��������� ������� (maptype.h)
  // Order  - ���������� ����� ��������� �������
  // ���������� ������������� �������,
  // ��� ������ ���������� 0

_MAPIMP  long _MAPAPI mapGetRscObjectRelateOrder(HRSC hRsc,long int incode,
                                                 long int order,RSCRELATION * relate);

  // ��������� ��������� ������ ��� ������� ��������� �������   // 14/04/06
  // �� �����������  ���� (����������� ������) ������� (� 1)
  // hRsc - ������������� �������������� �����
  // incode - ���������� ��� ������� (����� �� �������)
  // semanticcode - ��� ��������� �������
  // viewtype - ��� ����������� ������� 0 - ��������, 1 - ����������
  // ��� ������ ��� ���� � ���������� ������� ��� ������� ����������  0

_MAPIMP  long _MAPAPI mapGetRscObjectSemanticFont(HRSC hRsc, long int incode,
                                                  long int semanticcode, LOGFONT * font,
                                                  long int viewtype);

  // ���������� ��� ������� �� �����������  ���� (����������� ������) ������� (� 1)
  // � ��������� UNICODE
  // hRsc - ������������� �������������� �����
  // incode - ���������� ��� ������� (����� �� �������)
  // name - ��� ������� � ��������� UNICODE
  // ��� ������ ���������� 0

_MAPIMP  long int _MAPAPI mapSetRscObjectNameUn(HRSC hRsc,long int incode,
                                                const WCHAR * name);

_MAPIMP  long int _MAPAPI mapSetRscObjectNameUnicode(HRSC hRsc,long int incode,
                                                     const WCHAR * name);


  /**************************************************************
  *                                                             *
  *  ������� ������ � ����������� ����������� ��������          *
  *                                                             *
  **************************************************************/

  // ��������� ����� ������� ����������� ������� �� �����������  ����
  // (����������� ������) ������� (� 1)
  // hRsc - ������������� �������������� �����
  // incode - ���������� ��� ������� (����� �� �������)
  // ��� ������ ���������� 0

_MAPIMP  long  _MAPAPI mapGetRscObjectFunction(HRSC hRsc,long int incode);


  // ��������� ����� ���������� ����������� ������� �� �����������  ����
  // (����������� ������)������� (� 1)
  // hRsc - ������������� �������������� �����
  // incode - ���������� ��� ������� (����� �� �������)
  // ��� ������ ���������� 0

_MAPIMP  long _MAPAPI mapGetRscObjectParametersSize(HRSC hRsc,long int incode);


  // ��������� ��������� ����������� ������� �� �����������  ����
  // (����������� ������) ������� (� 1)
  // hRsc - ������������� �������������� �����
  // incode - ���������� ��� ������� (����� �� �������)
  // ��� ������ ���������� 0

_MAPIMP  const char * _MAPAPI mapGetRscObjectParameters(HRSC hRsc,long int incode);


  // ��������� ���������� ���������� � ���������� ����������� ������� ��
  // ����������� ���� (����������� ������) ������� (� 1) � ���� �����������
  // viewtype: 0 - ��������, 1 - ����������
  // hRsc - ������������� �������������� �����
  // incode - ���������� ��� ������� (����� �� �������)
  // ��� ������ ���������� 0

_MAPIMP  long  _MAPAPI mapGetRscPrimitiveCount(HRSC hRsc,long int incode,
                                               long int viewtype = 0);


  // ��������� ����� ������� ����������� ��������� �� �����������
  // ������ ��������� � ���������� ����������� ������� ,
  // ����������� ���� (����������� ������) ������� (� 1) � ���� �����������
  // viewtype: 0 - ��������, 1 - ����������
  // hRsc - ������������� �������������� �����
  // incode - ���������� ��� ������� (����� �� �������)
  // ��� ������ ���������� 0

_MAPIMP  long  _MAPAPI mapGetRscPrimitiveFunction(HRSC hRsc, long int incode,
                                                  int number,
                                                  long int viewtype = 0);

  // ��������� ����� ���������� ��������� �� �����������
  // ������ ��������� � ���������� ����������� ������� ,
  // ����������� ���� (����������� ������) ������� (� 1) � ���� �����������
  // viewtype: 0 - ��������, 1 - ����������
  // hRsc - ������������� �������������� �����
  // incode - ���������� ��� ������� (����� �� �������)
  // number - ����� ���������
  // ��� ������ ���������� 0

_MAPIMP  long  _MAPAPI mapGetRscPrimitiveLength(HRSC hRsc,long int incode,
                                                int number,
                                                long int viewtype = 0);

  // ��������� ����� ���������� ��������� �� �����������
  // ������ ��������� � ���������� ����������� ������� ,
  // ����������� ���� (����������� ������) ������� (� 1) � ���� �����������
  // viewtype: 0 - ��������, 1 - ����������
  // hRsc - ������������� �������������� �����
  // incode - ���������� ��� ������� (����� �� �������)
  // number - ����� ���������
  // ��� ������ ���������� 0

_MAPIMP  char * _MAPAPI mapGetRscPrimitiveParameters(HRSC hRsc,long int incode,
                                                     int number,
                                                     long int viewtype = 0);

  // �������� ������������ ����������� � ���� ����������� �������
  // �� ����������� ����  ������� (� 1)
  // hRsc - ������������� �������������� �����
  // incode - ���������� ��� ������� (����� �� �������)
  // ��� ������ ���������� 0

_MAPIMP  long _MAPAPI mapGetRscImageSuitable(HRSC hRsc,long int local,
                                     long int incode);


  // ���������� ������� ��� �������
  // hRsc - ������������� �������������� �����
  // incode - ���������� ����� ������� (� 1)
  // length - ����� ����������
  // number - ����� ������� �����������
  // param  - ��������� �� ��������� �������
  // ��� ������ ���������� ���� , ����� ���������� ����� �������

_MAPIMP  long int  _MAPAPI mapSetRscObjectImage(HRSC hRsc,
                                         long int incode,
                                         long int length,
                                         long int number,char * param);


  // ��������� ����� ������� (�����������) ����������� ������� �� ����������� ����
  // (����������� ������) �������
  // hRsc - ������������� �������������� �����
  // incode - ���������� ��� ������� (����� �� �������)
  // ��� ������ ���������� 0

_MAPIMP  long  _MAPAPI mapGetRscPrintObjectFunction(HRSC hRsc,long int incode);   //26/11/01


  // ��������� ����� ���������� (�����������)����������� ������� �� �����������  ����
  //(����������� ������) ������� (� 1)
  // hRsc - ������������� �������������� �����
  // incode - ���������� ��� ������� (����� �� �������)
  // ��� ������ ���������� 0                                              //05/02/02

_MAPIMP  long _MAPAPI mapGetRscPrintObjectParametersSize(HRSC hRsc,long int incode);


  // ��������� ��������� ����������� (�����������)������� �� �����������  ����
  //  �������
  // hRsc - ������������� �������������� �����
  // incode - ���������� ��� ������� (����� �� �������)
  // ��� ������ ���������� 0
                                                       //26/11/01
_MAPIMP  const char * _MAPAPI mapGetRscPrintObjectParameters(HRSC hRsc,long int incode);


  // ���������� ���������� ��� �������
  // hRsc - ������������� �������������� �����
  // incode - ���������� ����� �������
  // length - ����� ����������
  // number - ����� ������� �����������
  // param  - ��������� �� ��������� �������
  // ��� ������ ���������� ���� , ����� ���������� ����� �������
                                                     //26/11/01
_MAPIMP  long int  _MAPAPI mapSetRscPrintObjectImage(HRSC hRsc,
              long int incode,long int length,long int number,char * param);


  // ����� "��������" ���� ����������� �������                  // 11/04/05
  // hRsc - ������������� �������������� �����
  // incode - ���������� ����� �������
  // viewtype - ��� �����������  0 - ��������, 1 - ����������
  // ��� ���������� ����� ���������� 0xFF000000
  // ��� ������ ���������� 0

_MAPIMP  COLORREF  _MAPAPI  mapGetRscObjectBaseColor(HRSC hRsc, long int incode,
                                          long int viewtype);


  // ��������� ��������� ������ ������� �� �����������  ����     // 14/04/06
  // (����������� ������) ������� (� 1)
  // hRsc - ������������� �������������� �����
  // incode - ���������� ��� ������� (����� �� �������)
  // viewtype -��� �����������  0 - ��������, 1 - ����������
  // ��� ������ ��� ���� � ���������� ������� ��� ������� ����������  0

_MAPIMP long int _MAPAPI mapGetRscObjectFont(HRSC hRsc,long int incode,LOGFONT * font,
                                             long int viewtype);

  // ��������� ��������� ������ �� ���������� ������       // 28/01/08
  // hRsc - ������������� �������������� �����
  // text - ����� ���������� ������
  // ��� ������ ����������  0

  long int _MAPAPI mapGetRscTextFont(HRSC hRsc,const IMGTEXT * text,LOGFONT * font);

 // ��������� ������ ����� ��������, ����������� ������� � ��������� ������,
 // ���������� ������ ���� �������
 // incode - ���������� ��� (���������� ����� ������� � 1)        // 15/02/11
 // size - ����������� �������(���������� ���������)
 // code - ����� ������� ����� ���������
 // viewtype -��� �����������  0 - ��������, 1 - ����������, 2 - ���
 // ���������� ����� ��������, �� ������� ������� �������
 // ���� ������ ������� ������, ��� ����� �������� "������" ��������� �� �������

_MAPIMP long int _MAPAPI mapGetRscObjectLabelSemantics(HRSC hrsc, long int incode,
                               long int viewtype, long int size, long int * code);



  /**************************************************************
  *                                                             *
  *     ������� ���������� ���������������� ��������            *
  *                                                             *
  **************************************************************/

  // ��������� ���� ������ ����������� �������                     // 18/04/05
  // hRsc - ������������� �������������� �����
  // incode - ���������� ����� �������
  // ���������� 0 - ����������� ���������, 1 - ���.

_MAPIMP  int _MAPAPI  mapGetRscObjectPressure(HRSC hRsc, long int incode);


  // ���������� ���� ������ ����������� �������
  // hRsc - ������������� �������������� �����
  // incode - ���������� ����� �������
  // flag - ���� ������ ����������� 0 - ���������, 1 - ���.
  // ��� ������ ���������� 0

_MAPIMP  int _MAPAPI  mapSetRscObjectPressure(HRSC hRsc, long int incode,long int flag);

  // ��������� ������ ������������� ������ ����������� �������      // 18/12/07
  // hRsc - ������������� �������������� �����
  // incode - ���������� ����� �������
  // ���������� ����������� ������������� ������, ���������� �� 10.

_MAPIMP  int _MAPAPI  mapGetRscObjectPressLimit(HRSC hRsc, long int incode);

  // ���������� ������ ������������� ������ ����������� �������      // 18/12/07
  // hRsc - ������������� �������������� �����
  // incode - ���������� ����� �������
  // presslimit - ����������� ������������� ������, ���������� �� 10.
  //              � ��������� �� 10 �� 250)
  // ��� ������ ���������� 0

_MAPIMP  int _MAPAPI  mapSetRscObjectPressLimit(HRSC hRsc, long int incode,
                                                 long int presslimit);

  // ��������� ������ ������������� ���������� ����������� �������      // 18/12/07
  // hRsc - ������������� �������������� �����
  // incode - ���������� ����� �������
  // ���������� ����������� ������������� ����������, ���������� �� 10.

_MAPIMP  int _MAPAPI  mapGetRscObjectScaleLimit(HRSC hRsc, long int incode);

  // ���������� ������ ������������� ���������� ����������� �������   // 18/12/07
  // hRsc - ������������� �������������� �����
  // incode - ���������� ����� �������
  // scalelimit - ����������� ������������� ������, ���������� �� 10.
  //              � ��������� �� 10 �� 250)
  // ��� ������ ���������� 0

_MAPIMP  int _MAPAPI  mapSetRscObjectScaleLimit(HRSC hRsc, long int incode,
                                                long int scalelimit);

  // ���������� ������� ��������� ������� �� ����� (�������� ���������    // 02/07/08
  // ��������� ������� �� �����
  // hRsc - ������������� �������������� �����
  // incode - ���������� ����� ������� (���������� ��� � ��������������)
  // bottom - ����������� �������� ����������� �������� ��� ������� �����
  //          ������
  // top    - ������������ �������� ����������� �������� ��� ������� �����
  //          ������
  // ��� ��������� �������� ��������� ��� ����������� �� ���������
  // �������� �� ������� ����������� ��������� � ���������� �������� "�������"
  // ��� "��������" ������� (� ����������� �� ���������������� ��������)
  // ��������, ��� �������� bottom = 1, top = 199999, ������ �����
  // ����� � ��������� ������� 1:200 000 (��� ���������� ����� 200 000),
  // � ������� ������� ����� ���� bottom = 200000, top = 1000000 - ��
  // ����� ����� � ��������� 1:200 000 � ������ � ����� ��������� ����������
  // ������ (������ ��� ������� �� �����������).
  // �� ���� �������� ��������� ������� 160000 � 170000 - ��� ������������
  // � 200 000 �� ���� ����� �����������.
  // ��� ������ ���������� 0

_MAPIMP  int _MAPAPI mapSetRscObjectScaleBorder(HRSC hRsc, long int incode,
                                                long int bottom, long int top);

  // ��������� ������� ��������� ������� �� ����� (�������� ���������
  // ��������� ������� �� �����
  // hRsc - ������������� �������������� �����
  // incode - ���������� ����� ������� (���������� ��� � ��������������)
  // bottom - ����������� �������� ����������� �������� ��� ������� �����
  //          ������
  // top    - ������������ �������� ����������� �������� ��� ������� �����
  //          ������
  // ��� ������ ���������� 0

_MAPIMP  int _MAPAPI mapGetRscObjectScaleBorder(HRSC hRsc, long int incode,
                                                long int * bottom, long int * top);

  /**************************************************************
  *                                                             *
  *  ������� ������ � ����������� �� �������������� ��'�����    *
  *                                                             *
  **************************************************************/

  // ������� ����� ��������� - ����������  ��� ��������� ���������
  // hRsc - ������������� �������������� �����
  // ��������� RSCSEMANTICEX ������� � maptype.h
  // ��� ������ ���������� ����

_MAPIMP  long int  _MAPAPI mapAppendRscSemanticEx(HRSC hRsc,RSCSEMANTICEX * rsem);


  // �������� ��������� - ����������  ��� ����������� ���������
  // code - ��� ����������� ���������
  // classupdate - 1, ������������� ��������� ��������� ��� ������������
  // ����������(�������� ��� ����� ���� ���������), 0 - ��� ��������� ��������
  // ������� � ���������� �������������� ������ ��������� �� �����.
  // hRsc - ������������� �������������� �����
  // ��������� RSCSEMANTICEX ������� � maptype.h
  // ��� ������ ���������� ����

_MAPIMP  long int  _MAPAPI mapUpdateRscSemanticEx(HRSC hRsc,long int code,
                                    RSCSEMANTICEX * rsem,long int classupdate);


  // ������� ���������
  // code - ��� ��������� ���������
  // hRsc - ������������� �������������� �����
  // ��� ������ ���������� ����

_MAPIMP  long int  _MAPAPI mapDeleteRscSemantic(HRSC hRsc,long int code);


  // ��������� ���������� � ���������� ��������� ��� �������� �����
  // code - ��� ���������
  // applysemantic - ��������� ��� ���������� (maptype.h)
  // hRsc - ������������� �������������� �����
  // ��� ������ ���������� ����

_MAPIMP  long int  _MAPAPI mapGetRscApplySemantic(HRSC hRsc,long int code,
                                           APPLYSEMANTIC * applysemantic);


  // �������� �������������� ��������� �������
  // hRsc - ������������� �������������� �����
  // objincode - ���������� ��� �������,
  // code      - ��� ���������,
  // enable    - ��� ������� � ���������
  // (2 - ������������, 1 - ���������)
  // ��� ������ ���������� ����

_MAPIMP  long int  _MAPAPI mapEnableRscSemantic(HRSC hRsc,
                                         long int objincode,
                                         long int code,
                                         long int enable);


  // ��������� ���������� �������� � ��������������
  // hRsc - ������������� �������������� �����
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetRscSemanticCount(HRSC hRsc);


  // ��������� ��� ��������� �� ����������� ������
  // hRsc   - ������������� �������������� �����
  // number - ���������� ����� ��������� � 1
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetRscSemanticCodeByNumber(HRSC hRsc, long int number);


  // ��������� ���������� ����� ���������
  // �� ��������� ����� (�����)���������                                   //11/03/01
  // hRsc      - ������������� �������������� �����
  // shortname - �������� ��� ���������
  // ��� ������ ���������� ����
  // ����� ���������� ����� ��������� (� 1)

_MAPIMP  long int _MAPAPI mapGetRscSemanticByShortName(HRSC hRsc,const char * shortname);
_MAPIMP  long int _MAPAPI mapGetRscSemanticByKey(HRSC hRsc,const char * key);  //18/09/01


  // ��������� �������� ��������� �� ����������� ������
  // hRsc   - ������������� �������������� �����
  // number - ���������� ����� ��������� � 1
  // ��� ������ ���������� ������ ������

_MAPIMP  const char * _MAPAPI mapGetRscSemanticNameByNumber(HRSC hRsc, long int number);

  // ��������� �������� ��������� �� ����������� ������ � ��������� UNICODE
  // hRsc - ������������� �������������� �����
  // number - ����� ���������
  // name   - ����� ������ ��� ���������� ����������
  // size   - ������������ ������ �������� ������
  // ��� ������ ���������� ������ ������

_MAPIMP  long int _MAPAPI mapGetRscSemanticNameByNumberUn(HRSC hRsc, long int number,
                                                          WCHAR * name, long int size);

  // ��������� �������� ��������� �� ���� � ��������� UNICODE
  // hRsc - ������������� �������������� �����                  // 15/06/09
  // code - ��� ���������
  // name - ����� ������ ��� ���������� ����������
  // size - ������������ ������ �������� ������ (����� ���� �� 2048 ����)
  // ��� ������ ���������� 0

_MAPIMP  long int _MAPAPI mapGetRscSemanticNameUn(HRSC hRsc, long int code,
                                                  WCHAR * name, long int size);

_MAPIMP  long int _MAPAPI mapGetRscSemanticNameUnicode(HRSC hRsc, long int code,
                                                       WCHAR * name, long int size);

  // ���������� �������� ��������� �� ���� � ��������� UNICODE
  // hRsc - ������������� �������������� �����                  // 17/04/11
  // code - ��� ���������
  // name - ����� ������ � ����� ���������
  // ��� ������ ���������� 0

_MAPIMP  long int _MAPAPI mapSetRscSemanticNameUn(HRSC hRsc, long int code,
                                                  const WCHAR * name);

_MAPIMP  long int _MAPAPI mapSetRscSemanticNameUnicode(HRSC hRsc, long int code,
                                                       const WCHAR * name);

  // ��������� ��� ��������� �� �� �������� ����
  // ���� ����� �������� - ��. maptype.h (SEMTYPE)
  // hRsc - ������������� �������������� �����
  // code - �������� ��� ���������
  // ��� ������ ���������� ���� (���������� ��������� ����� ��� ����!)

_MAPIMP  long int _MAPAPI mapGetRscSemanticTypeByCode(HRSC hRsc, long int code);


  // ��������� �������� ��� (����) ���������
  // hRsc - ������������� �������������� �����
  // code - ��� ���������
  // ��� ������ ���������� ������ ������

_MAPIMP  const char * _MAPAPI mapGetRscSemanticShortName(HRSC hRsc,long int code);
_MAPIMP  const char * _MAPAPI mapGetRscSemanticKey(HRSC hRsc,long int code); //18/09/01

  // ��������� �������� ��� (����) ��������� � ��������� UNICODE
  // hRsc - ������������� �������������� �����
  // code - ��� ���������
  // name   - ����� ������ ��� ���������� ����������
  // size   - ������������ ������ ������
  // ��� ������ ���������� ������ ������

_MAPIMP  long int _MAPAPI mapGetRscSemanticKeyUn(HRSC hRsc,long int code,
                                                 WCHAR * name, long int size);

  // ���������� �������� ��� (����) ���������
  // hRsc - ������������� �������������� �����
  // code - ��� ���������
  // ��� ������ ���������� 0

_MAPIMP  long int _MAPAPI mapSetRscSemanticShortName(HRSC hRsc, long int code,
                                                     const char * shortname );
_MAPIMP  long int _MAPAPI mapSetRscSemanticKey(HRSC hRsc,long int code,
                                               const char * key );         //18/09/01


  // ���������� ������ � �������� �������� ���������       // 11/03/01
  // hRsc - ������������� �������������� �����
  // size - ������ �������� ��������� (������� ���������� �����)
  // decimal - ���������� ������ ����� ������� (� ���������� - 0)
  // code - ��� ���������
  // ��� ������ ���������� 0

_MAPIMP  long int _MAPAPI mapSetRscSemanticDecimal(HRSC hRsc,long int code,
                                                   long int size,long int decimal);


  // ��������� ��������� �������� ������������� ��������������      // 21/01/02
  // �� ���� ���������
  // hRsc - ������������� �������������� �����
  // code - ������� ��� ���������
  // ��������� RSCSEMANTICEX ������� � maptype.h
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetRscSemanticExByCode(HRSC hRsc,RSCSEMANTICEX * semtype,
                                                    long int code);


  // ��������� ���������� �������� �������������� �������������
  // �������������� �� ���� ��������� (���� �� ��� TCODE)
  // hRsc - ������������� �������������� �����
  // code - ��� ���������
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetRscSemanticClassificatorCount(HRSC hRsc,
                                                    long int code);

  //  ��������� �������� �������� �������������� ��
  //  �������������� ��������� �� ���� ��������� �
  //  ����������������� ������ � ��������������
  //  hRsc - ������������� �������������� �����
  //  code - ��� ���������
  //  number - ���������������� ����� � ��������������(1,2,3...)
  //  ��� ������ ���������� ������ ������

_MAPIMP  const char * _MAPAPI mapGetRscSemanticClassificatorName(HRSC hRsc,long int code,
                                                                 long int number);

  //  ��������� �������� �������� �������������� ��
  //  �������������� ��������� �� ���� ��������� �
  //  ����������������� ������ � �������������� � ��������� UNICODE
  //  hRsc - ������������� �������������� �����
  //  code   - ��� ���������
  //  number - ���������������� ����� � ��������������(1,2,3...)
  //  name   - ����� ������ ��� ���������� ����������
  //  size   - ������������ ������ ������ (����� ���� �� 2048 ����)
  //  ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetRscSemanticClassificatorNameUn(HRSC hRsc,long int code,
                                                               long int number,
                                                               WCHAR * name, long int size);

  // ��������� ��� �������� �������������� ��
  // �������������� ��������� �� ���� ��������� �
  // ����������������� ������ � ��������������
  // hRsc - ������������� �������������� �����
  // number - ���������������� ����� � ��������������(1,2,3...)
  // code - ��� ���������
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetRscSemanticClassificatorCode(HRSC hRsc,
                                                             long int code,
                                                             long int number);

  // �������� ����� "�������" ��������������
  // (�������� �������� � ����������) ����������
  // ����� ���������� ������ � 1
  // hRsc - ������������� �������������� �����
  // code - ��� ������������� ��������������
  // value - �������� ��������
  // name  - ���������� �������� ������������� ��������������
  // ��� ������ ���������� ����

_MAPIMP  long int  _MAPAPI mapAppendRscClassificator(HRSC hRsc,
                                                     long int code,
                                                     long int value, const char * name);

  // �������� ���������� �������� �������������� �� ������ ������ (� 1)   //10/12/01
  // ���������� ����� ������������ ������ � 1
  // hRsc - ������������� �������������� �����
  // code - ��� ������������� ��������������
  // index - ����� ������
  // name  - ���������� �������� ������������� ��������������
  // ��� ������ ���������� ����

_MAPIMP  long int  _MAPAPI mapUpdateRscClassificatorName(HRSC hRsc,
                                                         long int code,
                                                         long int index, const char * name);

  // ������� ��� ��������� ��� �������������� �� ���������� �������� ��������
  // hRsc - ������������� �������������� �����
  // code - ��� ������������� ��������������
  // name  - ���������� �������� ������������� ��������������, ������� ����� �����
  // ���� �� ����� ���������� 0, ����� - �������� �������� �������������� ���������

_MAPIMP  long int  _MAPAPI mapFindRscClassificatorCode(HRSC hRsc,
                                                       long int code, const char * name);

 // ��������� ���� ������ �������������� ���������  16/02/10
 // hRsc - ������������� �������������� �����
 // code - ��� ���������
 // value - �������� ��������������

_MAPIMP  const char * _MAPAPI mapGetRscClsKey(HRSC hRsc,long code,long value);

 // �������� ���� �������������� ���������                       16/02/10
 // ��� ����� ��������� ���� �������������� ������ ���� ��������
 // hRsc - ������������� �������������� �����
 // code - ��� ���������
 // value - �������� ��������������
 // ���������� �������� �������������� � ������ ������, ���� ��� ��������
 // �� ��������� � ������� - ���� ���������� � �� �������

_MAPIMP  long int _MAPAPI mapSetRscClsKey(HRSC hRsc,long code,long value,
                                           const char * key);

 // ������ ������� ����� �������������� ��������� (� UNICODE)
 // �� ���� ��������� � �������� ��������������
 // hRsc - ������������� �������������� �����
 // code - ��� ���������
 // value - �������� ��������������
 // size - ������ ������ ��� ���������� ������         // 16/02/10
 // buffer - ����� ��� ���������� ������
 // ���������� ����� ������� ����� ��� 0

_MAPIMP  long int _MAPAPI mapGetRscClsFullNameUn(HRSC hRsc, int code,int value,
                                                 int size, char * buffer);

 // �������� ������ ��� �������������� ��������� (� UNICODE)
 // �� ���� ��������� � �������� ��������������
 // hRsc - ������������� �������������� �����
 // code - ��� ���������
 // value - �������� ��������������
 // buffer - ������ ��� ������� (� UNICODE)           // 16/02/10
 // ���������� ����� ������� ����� ��� 0

_MAPIMP  long int _MAPAPI mapSetRscClsFullNameUn(HRSC hRsc,int code,int value,
                                                 WCHAR * buffer);

 // ��������� �������� �������������� ��������� �� �����   16/02/10
 // hRsc - ������������� �������������� �����
 // code - ��� ���������
 // value - �������� ��������������
_MAPIMP  long int _MAPAPI mapGetRscClsKeyValue(HRSC hRsc,long code,char * key);


  /**************************************************************
  *                                                             *
  *  ������� ������ � ����������� ��� ���������  ��'�����       *
  *                                                             *
  **************************************************************/

  // ��������� ���������� �������� ��� ������� �������
  // �� ���������� ��������� - ��. maptype.h (SEMANTIC_FOR_OBJECT )
  // �� ����������� ���� (����������� ������) ������� (c 1)
  // hRsc - ������������� �������������� �����
  // ���������� ���������� �������� ��������� ����������
  // hRsc - ������������� �������������� �����
  // incode - ���������� ����� �������
  // importance - ��������

_MAPIMP  long int  _MAPAPI mapGetRscSemanticObjectCount( HRSC hRsc,long int incode,
                                                  long int importance);


  // ��������� ������������� ��������� ��� ������� ������� -
  // incode - ���������� ��� (���������� �����)�������
  // semanticcode - ��� ���������
  // hRsc - ������������� �������������� �����
  // ���������� ���������� ���������  ��. maptype.h (SEMANTIC_FOR_OBJECT )

_MAPIMP  long int  _MAPAPI mapGetRscSemanticObjectUsed(HRSC hRsc,long int incode,
                                      long int semanticcode);

  // ��������� ������������� ��������� ��� ������� ������� -    // 19/02/09
  // ��� ����� ����� �������� � �������� ����
  // incode - ���������� ���(������)�������
  // semanticcode - ��� ���������
  // hRsc - ������������� �������������� �����
  // ���������� ���������� ���������  ��. maptype.h (SEMANTIC_FOR_OBJECT )

_MAPIMP  long int  _MAPAPI mapGetRscSemanticOnlyObjectUsed(HRSC hRsc,long int incode,
                                      long int semanticcode);


  // ��������� ��� ���������  ��� ������� ������� �� ����������� ������
  // ������ ��������� ��� ������� (� 1) � ���������� ���������
  // ��. maptype.h (SEMANTIC_FOR_OBJECT ) ��� ���������� ���������
  // ALL_SEMANTIC - ���������� ��������� � ������� ����������
  // incode - ���������� ��� (���������� �����) �������
  // importance - ���������� ���������
  // hRsc - ������������� �������������� �����
  // ���������� ��� ���������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetRscSemanticObjectCode(HRSC hRsc,long int incode,
                                                     long int number,long int importance);

  // ��������� ������ ���� ����� ��������� ��� ������� �������
  // incode - ���������� ���(������)�������
  // hRsc   - ������������� �������������� �����
  // code   - ����� ������� ��������
  // countlimit - ������ �������
  // ���������� ����� ��������� ����� ���������
  // ��� ������ ���������� ����

_MAPIMP long int _MAPAPI mapGetRscSemanticObjectCodeList(HRSC hRsc,long int incode,
                                                         long int * code, long int countlimit);
                                                           
  // �������� ��� ���������  ��� ������� ������� �� ���������� ���������
  // (POSSIBLE_SEMANTIC ��� MUST_SEMANTIC)
  // semanticcode - ��� ���������
  // incode - ���������� ��� (���������� �����) �������
  // hRsc - ������������� �������������� �����
  // ���������� ����� ����������� ��������� � ���������� ������� ����
  // ��� ������ ���������� ����

_MAPIMP   long int  _MAPAPI mapAppendRscSemanticObject(HRSC hRsc,long int incode,
                                     long int semanticcode,long int importance);


  // �������� ���������� ��������� ��� ������� �������
  // (POSSIBLE_SEMANTIC ��� MUST_SEMANTIC)
  // semanticcode - ��� ���������
  // incode - ���������� ��� (���������� �����) �������
  // hRsc - ������������� �������������� �����
  // ���������� ����� �������� ��������� ����������
  // ��� ������ ���������� ����

_MAPIMP   long int  _MAPAPI mapUpdateRscSemanticObject(HRSC hRsc,long int incode,
                                     long int semanticcode,long int importance);


  // ������� ��������� ��� ������� �������
  // (POSSIBLE_SEMANTIC ��� MUST_SEMANTIC)
  // semanticcode - ��� ���������
  // incode - ���������� ��� (���������� �����) �������
  // hRsc - ������������� �������������� �����
  // ���������� ����� ����� �������� �������
  // ��� ������ ���������� ����

_MAPIMP   long int  _MAPAPI mapDeleteRscSemanticObject(HRSC hRsc,long int incode,
                                     long int semanticcode);


   // ��������������� ������ �������� ��� ������� � ������������ �  // 16/02/04
   // ����������� ��������
   // incode - ���������� ��� (���������� �����) �������
   // hRsc - ������������� �������������� �����
   // count - ������ ������� �������� ������� ��� ����������
   // semantics - ��������� �� ������ ������� ��������� �������� �������.
   // order     - ��������� �� �������� ������ �������� ����������������
   // ����������� �������� ������� ��������(� 1 )
   // ��� ���������� ���������� ���������� 1

_MAPIMP   long int  _MAPAPI mapSortRscObjSemantic(HRSC hRsc,long int incode,
                            long int count,long int * semantics,long int * order);


   // �������� ������� �������� ��� ������� � ������������ � �������
   // �������
   // incode - ���������� ��� (���������� �����) �������
   // hRsc - ������������� �������������� �����
   // count - ������ ������� �������� �������
   // semantics - ��������� �� ������������� ������ �������� �������.
   // ��������� ������� �� �������� ������� - ������������,
   // ���� ����� - �� ��������� ��������� ������� � ����� ������
   // ��� ���������� ���������� ���������� ���������� �������� �������

_MAPIMP   long int  _MAPAPI mapSetRscObjSemanticOrder(HRSC hRsc,long int incode,
                                       long int count,long int * semantics);


  /**************************************************************
  *                                                             *
  *  ������� ������ � ��������� ���������������                 *
  *                                                             *
  **************************************************************/

  // ��������� ���� �� �������
  // color - ���� � COLORREF
  // index - ���������� ����� ����� � ������� (� 1)
  // number - ���������� ����� ������� (� 1)
  // hRsc - ������������� �������������� �����
  // ���������� ���� � COLORREF

_MAPIMP  COLORREF _MAPAPI mapGetRscColor(HRSC hRsc,long int index,
                                         long int number = 1);


  // ���������� ���� � ������ �������
  // color - ���� � COLORREF
  // index - ���������� ����� ����� � ������� (� 1)
  // number - ���������� ����� ������� (� 1)
  // hRsc - ������������� �������������� �����
  // ���������� �������
  // ��� ������ ���������� ����

_MAPIMP   long int  _MAPAPI mapSetRscColor(HRSC hRsc,COLORREF color,long int index,
                                           long int number = 1);

  // ��������� ���������� ������ � ������� ��������������
  // hRsc - ������������� �������������� �����

_MAPIMP  long int  _MAPAPI mapGetRscColorCount(HRSC hRsc);


  // ��������� ���������� ������ ��������������
  // hRsc - ������������� �������������� �����

_MAPIMP  long int  _MAPAPI mapGetRscPaletteCount(HRSC hRsc);


  // ������ ����� ������� �� �� ������
  // number - ���������� ����� ������� (� 1)
  // hRsc - ������������� �������������� �����

_MAPIMP  char * _MAPAPI mapGetRscPaletteName(HRSC hRsc,int number);

  // ��������� ���� �� CMYK - �������                       // 13/10/06
  // index - ���������� ����� ����� � ������� (� 1)
  // hRsc - ������������� �������������� �����
  // ���������� ���� �� 4 ������������ (�,M,Y,K)
  // (������ � ��������� �� 0 �� 255)

_MAPIMP unsigned long _MAPAPI mapGetRscCMYKColor(HRSC hRsc,long int index);

  // ���������� ���� � CMYK - �������                      // 13/10/06
  // color - 4 ������������ (�,M,Y,K)
  // (������ � ��������� �� 0 �� 255)
  // index - ���������� ����� ����� � ������� (� 1)
  // hRsc - ������������� �������������� �����
  // ���������� �������
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapSetRscCMYKColor(HRSC hRsc,unsigned long int color,
                                             long int index);


  /************************************************************
  *                                                           *
  *  ������� ������ � �������� ���������������  //04/10/01    *
  *                                                           *
  ************************************************************/

  // K�� ������ - ������������� � ��������� ������� (IMGTEXT: ���� Type)
  // (��. mapgdi.h) ��� ������ �� ������� �������.

  // ������ ���������� �������
  // ��� ������ ���������� ����
  // hRsc - ������������� �������������� �����

_MAPIMP  long int _MAPAPI mapGetFontCount(HRSC hRsc);


  // �������� ����� - ���������� ��� ������
  // hRsc - ������������� �������������� �����
  // RSCFONT - ��. maptype.h
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapAppendFont(HRSC hRsc,RSCFONT * font);


  // �������� ����� - ���������� ��� ������
  // hRsc - ������������� �������������� �����
  // index - ���������� ����� ������ (� 1)
  // RSCFONT - ��. maptype.h
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapReplaceFont(HRSC hRsc,int index,RSCFONT * font);


  // ������ ���� ������ �� ����������� ������(c 1)
  // hRsc - ������������� �������������� �����
  // number - ����� ������
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetFontCode(HRSC hRsc,int number);


  // ������ ������ �� ����������� ������ (c 1)
  // ���������� ��� ������
  // hRsc - ������������� �������������� �����
  // number - ����� ������
  // RSCFONT - ��. maptype.h
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetFont(HRSC hRsc,int number,RSCFONT * font);


  // ������ ������ �� ����
  // ���������� ���������� ����� ������ (� 1)
  // hRsc - ������������� �������������� �����
  // code - ��� ������
  // RSCFONT - ��. maptype.h
  // ��� ������ ���������� ����

_MAPIMP  long int _MAPAPI mapGetFontByCode(HRSC hRsc,int code,RSCFONT * font);

#ifdef WIN32API                                         // 06/10/06
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++  // 19/07/06
// +++++     �������� ������� �������� � ���������� ������           ++++
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// �������� ���������� ������� � ���������� �� ��������
// ���������� ��������: +,  -,  *,  /,
// (����������� ����� ���������� ������� ,)
// MAX(... ,...,   ),MIN(... ,...,   )- ��������, �������
// ARM(... ,...,   ) - ������� ��������������
// (����������� ����� ���������� � MAX, MIN, ARM - ������� ,)
// SIN,COS,TG,CTG - ������������������ ������� �� ����� � �������� � ����� �������
// SQRT2(),SQRT3(),POW2(),POW3() - ������ � ���������� �� 2,3 �������
// PI - ����� PI
// P - �������� �������,
// S - ������� �������
// # - ���������, ��� ������ ���� ��� ���������, � ������� ����� ��������,
//     ����� � ()�������� �� ���������.
// (������: #1(0) - ����� �������� ��������� 1, ��� ���������� ����� 0)
// ����� 0- 9,(����������� ����� .)
// ������ (),[],{}
// ���������� 0 ��� ������, � � ���������� errcode - ��� ������


// ���������� �������
// HOBJ info - ������������� ������� �����
// formula - ������, ���������� �������
// value - �������� �������
// ��� ������ � errcode (maperror.rh)
// ���������� 0 ��� ������, � � ���������� errno - ��� ������

long int WINAPI GetFormulaValue(HOBJ info, const char * formula,
                                double * value,  long * errcode);

// �������� ���������� �������
// HRSC rsc - ������������� �������������� �����
// formula - ������, ���������� �������
// ���������� 0 ��� ������, � � ���������� errno - ��� ������

long int WINAPI CheckFormula(HRSC rsc, const char * formula, long * errcode);

// �������� ���������� ������ � ��������� �� ��������� ���������
// �� ����� ���������� ������ ������ ���������� source, � ������� ������� �����
// ��� ������� ��������� ��������� �������
// # - ���������, ��� ������ ���� ��� ���������, � ������� ����� ��������
//     ������ ����
//     ����� � ()�������� �� ���������.
// (������: #9(��� ��������) - ����� �������� ��������� 9, ��� ����������
// �������� ������� "��� ��������"
// dest - ��������� �� ����� ��� ���������� ������
//        ������ ������ - ������ ������ + 256*���������� �������
// ���������� 0 ��� ������, � � ���������� errcode - ��� ������

long int WINAPI  AgregateString(HRSC hrsc, HOBJ info, const char * source,     // 15/05/09
                              char * dest,long destlength,long int * errcode);

#endif // WIN32API

} // extern "C"


#endif

