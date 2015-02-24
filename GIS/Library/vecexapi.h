/****  VECEXAPI.H    **********  Savochkin V.N.  *****  11/04/03 ***
*****  VECEXAPI.H    **********  Belenkov  O.V.  *****  02/08/10 ***
*****  VECEXAPI.H    **********  Konon  V.N.     *****  15/03/12 ***
*                                                                  *
*              Copyright (c) PANORAMA Group 1991-2010              *
*                     All Rights Reserved                          *
*                                                                  *
********************************************************************
*                                                                  *
*                     FOR  WINDOWS & LINUX                         *
*                                                                  *
********************************************************************
*                                                                  *
* ����������� ������� ��� ����� 2011 ��� ���������� �� GIS ToolKit *
*                                                                  *
*                 ������ ������ �������:                           *
*                                                                  *
*   // �������� ����������                                         *
*   HINSTANCE libInst = ::LoadLibrary("gisvecex.dll");             *
*                                                                  *
*   // ����� �������                                               *
*   typedef long int (WINAPI * MAPSORTING)(HMAP hMap,              *
*                                          HMESSAGE handle,        *
*                                          long int mode);         *
*                                                                  *
*   MAPSORTING mapsorting = (MAPSORTING)                           *
*                   GetProcAddress(libInst, "MapSortProcess");     *
*                                                                  *
*   long int rezult = (*mapsorting)(hMap, hWnd, mode);             *
*                                                                  *
*   // �������� ����������                                         *
*   ::FreeLibrary(libInst);                                        *
*                                                                  *
*******************************************************************/

#if !defined(VECEXAPI_H)
#define VECEXAPI_H

#ifndef MMSTRUCT_H
  #include "mmstruct.h"
#endif

#ifndef MAPTYPE_H
  #include "maptype.h"
#endif

#ifndef MAPCREAT_H
  #include "mapcreat.h"
#endif

#ifdef WIN32API
   #define HMESSAGE HWND
#else
   #define HMESSAGE MSGHANDLER
#endif

 enum SXFFORMATFLAG
 {
   DATAMETERS       = 0,  // ������� � ������
   DATARADIANS      = 4,  // ������� � ��������
   DATADEGREES      = 8,  // ������� � ��������
 };


extern "C"
{

 // ��������� ��� �������������� (RSC) �� ������ SXF, TXF, MAP (SIT)
 // � ������ SXF � TXF ��� �������������� (RSC) ����� �������������
 // ��� ������ ���������� ����

_MAPIMP long int WINAPI GetRscNameFromAnySxf(const char * filename, char * rscname, long int size);
_MAPIMP long int WINAPI GetRscNameFromSxf(const char * name, char * rscname, long int size);

 // ��������� ��� ����� �� ������ SXF, TXF, MAP (SIT)
 // ��� ������ ���������� ����

_MAPIMP long int WINAPI GetSheetNameFromAnySxf(const char * filename, char * sheetname, long int size);


 // ��������� ����������� ����� ����� SXF
 // name - ��� ����� SXF
 // ��� ������ ���������� ���� � ������ ��������� �� �����
 // ���� - ���������� �������� ����������� �����

_MAPIMP long int WINAPI GetSxfCheckSum(const char * name);

 // ��������� �������� ��������� ������ �����
 // hMap,hSite - �������������� ����� (��.MAPAPI.H),
 // mode       - ����� ������ (0 - ��������, 1 - ��������������),
 // handle     - ������������� ���� ������� �������� ��������� (HWND ��� Windows).
 //
 // ���� ������� ���������� ��������� ��������� :
 //  WM_LIST   = 0x586   WParam - ���������� ������ � ������
 //                      LParam - ����� �������� �����
 //  WM_OBJECT = 0x585   WParam - ������� ������������ ��������
 //  WM_ERROR  = 0x587   WParam - ���������� ����� ������� ��� 0
 //                      LParam = 1 - ������ � �����
 //                             = 2 - ������ � ��������������
 //                             = 3 - ������ � �������� �������
 //                             = 4 - ������ � �������
 //                             = 5 - ������ � ���������
 //                             = 6 - ������ � �������
 // ���������� ���������� ������ � ������

_MAPIMP long int WINAPI mapStructControl(HMAP hMap,HSITE hSite,
                                         long int mode,HMESSAGE handle);

 // ���������� ���� ����, �������� � ��������
 // hmap   - ������������� ������������ ���������
 // handle - ������������� ���� ������� �������� ��������� (HWND)
 // mode   - ���������� ������ ������� ��������� �����:
 //   0 - ����������� ��� �����,
 //   1 - ������ ���������������;
 //   2 - ��������� ����� ������;
 //   4 - �������� �������� �������� � ������, ����� ������ ������������;
 //  16 - �������� �������� �������� � ������, ������ - ��  (2 �����);
 //  32 - �������� �������� �������� � ������, ������ - ��  (3 �����);
 //  64 - �������� �������� �������� � ��������, ����� ������ ������������;
 // ��� ������ ���������� ����

_MAPIMP long int WINAPI MapSortProcess(HMAP hmap, HMESSAGE handle,
                                       long int mode);


 // ��������� ���������� ������ �� ������ SXF, TXF, MAP (SIT)          // 07/05/10
 // �� ����� ����� 
 // ��������� MAPREGISTER � LISTREGISTER ������� � mapcreat.h
 // ��� ������ ���������� ����
 
_MAPIMP long int WINAPI mapGetAnySxfInfoByName(const char * name,
                                               MAPREGISTEREX * mapreg,
                                               LISTREGISTER * sheet);
                                       

 // ������ ����� ��������� (SXF,TXF,MAP,...) � DIR
 // � ������ ��������� ����� DIR ������ ���� ������ � �������           // 05/05/10
 // dirname - ������ ��� ����� DIR
 // ��� ������ ���������� ����
 
_MAPIMP long int WINAPI GetDirItemCount(const char * dirname);

 // ������ �������� ������ ��� ������ ����� � ������ (SXF,TXF,MAP,...) � DIR
 // dirname - ������ ��� ����� DIR
 // name    - ����� ������ ��� ���������� ������������ �����
 // size    - ������ ������
 // ��� �������� ���������� ���������� ����� ��������� � ������
 // ��� ������ ���������� ����

_MAPIMP long int WINAPI GetDirAreaName(const char * dirname, char * name, long int size);

 // ������ ������ ���� ������ ������ (SXF,TXF,MAP,...) � DIR
 // dirname - ������ ��� ����� DIR
 // items   - ����� ������ ��� ���������� ����������� ��������� NAMESARRAY
 //           (��. mmstruct.h)
 // size    - ������ ������; ������ ���� �� ������, ��� ������ ����������
 //           ��� ����� ���������, ������� GetDirItemCount()
 //           size = sizeof(NAMESARRAY) + sizeof(LISTSNAME) * (count - 1);
 // ��� �������� ���������� ���������� ����� ��������� � ������
 // ��� ������ ���������� ����
 
_MAPIMP long int WINAPI GetDirItemList(const char * dirname,
                                       NAMESARRAY * items, long int size);

                                              
 //========================================================================
 //   ������� �������, �������� � ���������� ����� ��� �������� SXF, TXF � DIR
 //========================================================================
 //  ���� ������� ���������� ��������� ��������� :
 //  WM_LIST   = 0x586   WParam - ���������� ������ � ������
 //                      LParam - ����� �������� �����
 //  WM_OBJECT = 0x585   WParam - ������� ������������ ��������
 //  WM_INFOLIST = 0x584 LParam - ����� ��������� INFOLIST
 // ----------------------------------------------------------------

 // ��������� (�������������) ����� �� ����� SXF, TXF ��� DIR �      // 03/05/10
 // �������������� Select � ��������������� ��������� � ���� ���������
 // ����� SXF � TXF ����� ������� ���������� � ������, �������� ��� ��������
 // hmap    - ������������� �������� ����� (������������� ���������
 //           ��� ����������� ������� ���� ���������) ��� 0;
 // sxfname - ��� ������������ ����� ���� SXF, TXF ��� DIR;
 // rscname - ��� ����� ��������������, � ������� ����������� �����,
 //           ��� �������������� ����� ��������� �� SXF (TXF) �������� GetRscNameFromSxf
 //           ��� �� �����; ��� ����� DIR ����� ���� 0;
 // mapname - ��� ����������� ����� (������ ��������� � ������ SXF (TXF))
 //           ��� ���� ��� ��������� �� ������ ������ (����� �������� MAX_PATH
 //           c ������� ������ ������ ����) ��� ��������� �� ����� ��� ����������
 //           �����. ���� ��� ����� �� ������ ��� ������ ������ �����, �� �����
 //           ��������� � ������ SXF (TXF) � ����������� ".sit". ���� namemap
 //           ��������� �� ����� ����������� ����� (size), �� � ����� ������������ 
 //           ��� ��������� �����;
 //           ��� ����� DIR ��� ����� ����� - MPT (������ ������, ���������� ��� 
 //           �������� ����� �� DIR) ��� MAP (������������� �����);
 // size    - ����� ������, �� ������� ��������� ���������� namemap ��� 0. ������ �����
 //           ����� MAX_PATH (256);
 // handle  - ������������� ���� �������, �������� ���������� �������������� 
 //           ��������� (HWND ��� Windows, CALLBACK-������� ��� Linux);
 // select  - ������ ����������� �������� � �����, ���� ���������� ���������� 
 //           ��������� ������;
 // ��� ���������� �������� ����� � �������� ���������� ������� �������
 // mapAppendData(hmap, namemap).
 // ��� ������ ���������� ����

_MAPIMP long int WINAPI ImportFromAnySxf(HMAP hmap,
                                         const char * sxfname,
                                         const char * rscname,
                                         char * mapname,
                                         long int size,
                                         HMESSAGE handle,
                                         HSELECT select);

 // ��������� (�������������) ����� �� ����� DIR 
 // frscfromsxf - �������� ������ "��������� �������������
 // ����� ��������������, ���������� � ����� sxf"

_MAPIMP long int WINAPI ImportFromAnySxfEx(HMAP hmap,
                                         const char * sxfname,
                                         const char * rscname,
                                         char * mapname,
                                         long int size,
                                         HMESSAGE handle,
                                         HSELECT select,
                                         int     frscfromsxf);
                                         

 // �������� ����� �� ����� SXF, TXF ��� DIR � �������������� Select      // 04/05/10
 // � ��������������� ��������� � ���� ���������
 // ����� SXF � TXF ����� ������� ���������� � ������, �������� ��� ��������
 // hmap    - ������������� �������� ����� (��� ����������� �������
 //           ���� ���������) ��� 0;
 // sxfname - ��� ������������ ����� ���� SXF, TXF ��� DIR;
 // mapname - ��� ����������� �����; ����� ���� ���� ��� ��������� �� ������ 
 //           ������, � ���� ������ ����������� ����� � ��������� ������ 
 //           �� ���������� �����������.
 //           ���� namemap ��������� �� ����� ����������� ����� (size), 
 //           �� � ����� ������������ ��� ����������� �����;
 //           ���� ����� �� ���� � ��������� - ��� ����� ���� ������� (���������) 
 // size    - ����� ������, �� ������� ��������� ���������� namemap ��� 0. ������ �����
 //           ����� MAX_PATH (256);
 // handle  - ������������� ���� �������, �������� ���������� �������������� 
 //           ��������� (HWND ��� Windows, CALLBACK-������� ��� Linux);
 // select  - ������ ����������� �������� � �����, ���� ���������� ���������� 
 //           ��������� ������;
 // mode    - ����� ���������� ������:
 //           0 - ����� ������� �� ���������� ����������� ������ � ����� � 
 //               �������� ����� � ����������,
 //               ���� ������ �� ������, �� ���������� �������;
 //           1 - ���������� �������� � ������ ����������� �������� � �� �����,
 //               ������������ ������� ��������� � ������������� SXF (TXF),
 //               ���� - ������������ �� �������, �� ����������� ����� ���� (�����);
 //           2 - ���������� �������� � ������ ����������� �������� � ��������
 //               ����� ��� ����� �����������
 // ��� ������ ���������� ����

_MAPIMP long int WINAPI UpdateFromAnySxf(HMAP hmap,
                                         const char * sxfname,
                                         char * mapname,
                                         long int size,
                                         HMESSAGE handle,
                                         HSELECT select,
                                         long int mode);

 // ��������� (��������������) ����� � �������� ������ SXF 
 // mapname - ��� ����� ����������� �����;
 // list    - ����� ����� ��� ������������� ����� ��� 1;
 // sxfname - ��� ������������ ����� SXF, ������ ��������� �
 //           ������ �����, �� ����� ���������� SXF;
 // flag    - ��� �������� ��������� (0 - �����, 4 - �������
 //           ��� �����, �������������� ������������� ����������,
 //           -1 - ���������� �� ���� ��������� �� �����);
 //           ���� ����� �� ���� � ��������� - ��� ����� ���� ������� (���������) 
 // handle  - ������������� ���� �������, �������� ���������� �������������� 
 //           ��������� (HWND ��� Windows, CALLBACK-������� ��� Linux);
 // select  - ������ ����������� �������� � �����, ���� ���������� ���������� 
 //           ��������� ������;
 // ��� ��������, �������� ���������� � ������, ���������� ������ ��������
 // � ����, ��������� � �������� �����
 // ��� ������ ���������� ����

_MAPIMP long int WINAPI ExportToSxf(const char * mapname,
                                    long int list,
                                    const char * sxfname,
                                    long int flag,
                                    HMESSAGE handle,
                                    HSELECT select);

 // ��������� (��������������) ����� � �������� ������ SXF
 // mapname - ��� ����� ����������� �����;
 // list    - ����� ����� ��� ������������� ����� ��� 1;
 // sxfname - ��� ������������ ����� SXF, ������ ��������� �
 //           ������ �����, �� ����� ���������� SXF;
 // flag    - ��� �������� ��������� (0 - �����, 4 - �������
 //           ��� �����, �������������� ������������� ����������,
 //           -1 - ���������� �� ���� ��������� �� �����);
 //           ���� ����� �� ���� � ��������� - ��� ����� ���� ������� (���������)
 // handle  - ������������� ���� �������, �������� ���������� ��������������
 //           ��������� (HWND ��� Windows, CALLBACK-������� ��� Linux);
 // select  - ������ ����������� �������� � �����, ���� ���������� ����������
 //           ��������� ������;
 // flserv  - �������� ��������� ������ c ������� � ����������� � ��� ��������������
 //           (�������������� � ������ 10.7 � ����) 
 // ��� ��������, �������� ���������� � ������, ���������� ������ ��������
 // � ����, ��������� � �������� �����
 // ��� ������ ���������� ����

_MAPIMP long int WINAPI ExportToSxfEx(const char * mapname,
                                    long int list,
                                    const char * sxfname,
                                    long int flag,
                                    HMESSAGE handle,
                                    HSELECT select,
                                    long int flserv);

 // ��������� (��������������) ����� � ��������� ������ TXF
 // mapname - ��� ����� ����������� �����;
 // list    - ����� ����� ��� ������������� ����� ��� 1;
 // txfname - ��� ������������ ����� TXF, ������ ��������� �
 //           ������ �����, �� ����� ���������� SXF;
 // flag    - ��� �������� ��������� (0 - �����, 4 - �������, 8 - �������,
 //           ��� �����, �������������� ������������� ����������,
 //           -1 - ���������� �� ���� ��������� �� �����);
 //           ���� ����� �� ���� � ��������� - ��� ����� ���� ������� (���������) 
 // precision - ����� ������ ����� ������� ��� ��������� � ������ ��� 0;
 //             ���� ����� ����� ���������� �������� � �� (2 �����) ���
 //             � �� (3 �����), �� precision ������������;
 // handle    - ������������� ���� �������, �������� ���������� �������������� 
 //             ��������� (HWND ��� Windows, CALLBACK-������� ��� Linux);
 // select    - ������ ����������� �������� � �����, ���� ���������� ���������� 
 //             ��������� ������;
 // ��� ��������, �������� ���������� � ������, ���������� ������ ��������
 // � ����, ��������� � �������� �����
 // ��� ������ ���������� ����

_MAPIMP long int WINAPI ExportToTxf(const char * mapname,
                                    long int list,
                                    const char * txfname,
                                    long int flag,
                                    long int precision, 
                                    HMESSAGE handle,
                                    HSELECT select);


 // ��������� (��������������) ����� � ������ DIR 
 // hmap    - ������������� �������� ������
 // dirname - ��� ������������ ����� DIR, ������ ��������� �
 //           ������ ��������� ������� ��� ������� �����, �� ����� ���������� DIR;
 // type    - ��� ����������� ������ (0 - SXF, 1 - TXF);
 // flag    - ��� �������� ��������� (0 - �����, 4 - �������, 8 - �������,
 //           ��� �����, �������������� ������������� ����������,
 //           -1 - ���������� �� ���� ��������� �� �����);
 //           ���� ����� �� ���� � ��������� - ��� ����� ���� ������� (���������) 
 // total   - ������� ���������� � DIR ������ ������� ����� (0) ��� ���� ����
 //           ��������� (1);
 // precision - ��� ������ TXF ����� ������ ����� ������� ��� ��������� � ������ ��� 0;
 //           ���� ����� ����� ���������� �������� � �� (2 �����) ���
 //           � �� (3 �����), �� precision ������������;
 // handle  - ������������� ���� �������, �������� ���������� �������������� 
 //           ��������� (HWND ��� Windows, CALLBACK-������� ��� Linux);
 // select  - ������ ����������� �������� � �����, ���� ���������� ���������� 
 //           ��������� ������;
 // ��� ��������, �������� ���������� � ������, ���������� ������ ��������
 // � ����, ��������� � �������� �����
 // ��� ������ ���������� ����

_MAPIMP long int WINAPI ExportToDir(HMAP hmap,
                                    const char * dirname,
                                    long int type,
                                    long int flag,
                                    long int total,
                                    long int precision,
                                    HMESSAGE handle,
                                    HSELECT select);
                                    
                                          
 // ================================================================
 //
 //                      ���������� �������                         // 03/05/10
 //
 //              ����������� ����� ����� ����� �������
 // ================================================================

 // ��������� ����� �� ����� SXF
 // ��� ������ ���������� ����

_MAPIMP long int WINAPI LoadSxfToMap(char * namesxf,
                                     char * namemap,
                                     char * namersc,
                                     HMESSAGE handle);

 // ��������� ����� �� ����� SXF � �������������� Select
 // ��� ������ ���������� ����
 
_MAPIMP long int WINAPI LoadSxfToMapSelect(char * namesxf,
                                           char * namemap,
                                           char * namersc,
                                           HMESSAGE handle,
                                           HSELECT select);

 // ��������� ����� �� ����� SXF � �������������� Select 
 // � ���������� ����� �����
 // ��������� name � namehdr - �� ��������������
 // ��� ������ ���������� ����

_MAPIMP long int WINAPI LoadSxfToMapSelectName(char * namesxf,
                                               char * namemap,
                                               char * namersc,
                                               HMESSAGE handle,
                                               HSELECT select,
                                               char * name,
                                               char * namehdr);

 // ��������� ����� �� ����� TXF
 // ��� ������ ���������� ����

_MAPIMP long int WINAPI LoadTxtToMap(char * nametxt,
                                     char * namemap,
                                     char * namersc,
                                     HMESSAGE handle);

 // ��������� ����� �� ����� TXF � ������������� Select
 // ��� ������ ���������� ����

_MAPIMP long int WINAPI LoadTxtToMapSelect(char * nametxt,
                                           char * namemap,
                                           char * namersc,
                                           HMESSAGE handle,
                                           HSELECT select);


 // ��������� ����� �� ����� TXF � ������������� Select � ���������� �����
 // ��������� name � namehdr - �� ��������������
 // ��� ������ ���������� ����

_MAPIMP long int WINAPI LoadTxtToMapSelectName(char * nametxt,
                                               char * namemap,
                                               char * namersc,
                                               HMESSAGE handle,
                                               HSELECT select,
                                               char * name,
                                               char * namehdr);

 // ��������� ����� �� ������ DIR
 // ��� ������ ���������� ����

_MAPIMP long int WINAPI LoadDirToMap(char* namedir,
                                     char* namemap,
                                     HMESSAGE handle);

 // ��������� ����� �� ������ DIR � ��������������  Select
 // ��� ������ ���������� ����

_MAPIMP long int WINAPI LoadDirToMapSelect(char* namedir,
                                           char* namemap,
                                           HMESSAGE handle,
                                           HSELECT select);

 // ��������� ����� �� ������ DIR � ��������������  Select � 
 // ���������� ����� ������ � ����� ����� ��������
 // ��� ������ ���������� ����

_MAPIMP long int WINAPI LoadDirToMapSelectName(char* namedir,
                                               char* namemap,
                                               HMESSAGE handle,
                                               HSELECT select,
                                               char * name,
                                               char* namersc);

 // ��������� ����� �� ������ �� ������� ������
 // ��� ������ ���������� ����

_MAPIMP long int WINAPI LoadMapToMap(HMAP  map,
                                     char * namemap,
                                     HMESSAGE handle);

 // ��������� ����� �� ������ ������� ������ � ��������������  Select
 // ��� ������ ���������� ����

_MAPIMP long int WINAPI LoadMapToMapSelect(HMAP map,
                                           char* namemap,
                                           HMESSAGE handle,
                                           HSELECT select);

 // �������� ����� �� ����� SXF
 // ��� ������ ���������� ����

_MAPIMP long int WINAPI UpdateMapFromSxf(char* namesxf,
                                         char* namemap,
                                         HMESSAGE handle);

 // �������� ����� �� ����� SXF � �������������� Select
 // ��� ������ ���������� ����

_MAPIMP long int WINAPI UpdateMapFromSxfSelect(char* namesxf,
                                               char* namemap,
                                               HMESSAGE handle,
                                               HSELECT select);

 // �������� ����� �� ������ ������� ������ � ��������������  Select
 // ��� ������ ���������� ����

_MAPIMP long int WINAPI UpdateMapToMapSelect(HMAP map,   
                                             const char* namemap,
                                             HMESSAGE handle,
                                             HSELECT select);

 // �������� � ����� ������ �� ����� SXF � �������������� Select
 // ��� ������ ���������� ����

_MAPIMP long int WINAPI AppendMapFromSxfSelect(char* namesxf,
                                               char* namemap,
                                               HMESSAGE handle,
                                               HSELECT select);

 // �������� ����� �� ����� TXF
 // ��� ������ ���������� ����

_MAPIMP long int WINAPI UpdateMapFromTxt(char* nametxt,
                                         char* namemap,
                                         HMESSAGE handle);

 // �������� ����� �� ����� TXF � �������������� Select
 // ��� ������ ���������� ����

_MAPIMP long int WINAPI UpdateMapFromTxtSelect(char* nametxt,
                                               char* namemap,
                                               HMESSAGE handle,
                                               HSELECT select);

 // �������� � ����� ������ �� ����� TXF � �������������� Select
 // ��� ������ ���������� ����

_MAPIMP long int WINAPI AppendMapFromTxtSelect(char* namesxf,
                                               char* namemap,
                                               HMESSAGE handle,
                                               HSELECT select);

 // �������� ����� �� ����� DIR � �������������� Select
 // ��� ������ ���������� ����

_MAPIMP long int WINAPI UpdateMapFromDirSelect(char* namedir,
                                               char* namemap,
                                               HMESSAGE handle,
                                               HSELECT select);

 // �������� � ����� ������ �� ����� DIR � �������������� Select
 // ��� ������ ���������� ����

_MAPIMP long int WINAPI AppendMapFromDirSelect(char* namedir,
                                               char* namemap,
                                               HMESSAGE handle,
                                               HSELECT select);

 // ��������� ���������� ������ ��������� �����
 // �� ����� ����� SXF
 // ��������� MAPREGISTER � LISTREGISTER ������� � mapcreat.h
 // ��� ������ ���������� ����

_MAPIMP long int WINAPI mapGetSxfInfoByName(const char * name,
                                            MAPREGISTER * map,
                                            LISTREGISTER * sheet);

_MAPIMP long int WINAPI mapGetSxfInfoByNameEx(const char * name,        // 19/11/09
                                              MAPREGISTEREX * map,
                                              LISTREGISTER * sheet);
                                               
//========================================================================
//   ������� ���������� �����
//========================================================================
//  �������������� ���������� ��������� ��������� :
//  WM_LIST   = 0x586   WParam - ���������� ������ � ������
//                      LParam - ����� �������� �����
//  WM_OBJECT = 0x585   WParam - ������� ������������ ��������

// ----------------------------------------------------------------
// �������� �� ����������� ������� � ������ SXF(Windows)
// ----------------------------------------------------------------

_MAPIMP long int WINAPI SaveSxfFromMap(char * namemap,
                                       int list,
                                       char * namesxf,
                                       HMESSAGE handle);

// ----------------------------------------------------------------
// �������� �� ����������� ������� � ������ SXF(Windows) �
//          ��������������  Select
// ----------------------------------------------------------------

_MAPIMP long int WINAPI SaveSxfFromMapSelect(char * namemap,
                                             int list,
                                             char * namesxf,
                                             HMESSAGE handle,
                                             HSELECT select,
                                             int flag = 0,
                                             char * nameregion = NULL);

// ----------------------------------------------------------------
// �������� �� ����������� ������� � ������ SXF(Windows) �
//          ��������������  Select
// ----------------------------------------------------------------

_MAPIMP long int WINAPI SaveSxfFromHMapSelect(HMAP map,
                                              int list,
                                              char * namesxf,
                                              HMESSAGE handle,
                                              HSELECT select,
                                              int flag = 0,
                                              char * nameregion = NULL);

// ----------------------------------------------------------------
// �������� �� ����������� ������� � ������ TXT(XY)
// ----------------------------------------------------------------

_MAPIMP long int WINAPI SaveTxtFromMap(char * namemap,
                                       int   list,
                                       char * nametxt,
                                       HMESSAGE handle);

// ----------------------------------------------------------------
// �������� �� ����������� ������� � ������ TXF(XY) �
//      �������������� Select
// ----------------------------------------------------------------

_MAPIMP long int WINAPI SaveTxtFromMapSelect(char * namemap,
                                             int list,
                                             char * nametxt,
                                             HMESSAGE handle,
                                             HSELECT select,
                                             char * nameregion = NULL);

// ----------------------------------------------------------------
// �������� �� ����������� ������� � ������ TXF(XY) �
// �������������� Select
// namemap - ��� ����������� �����,
// list    - ����� �����,
// nametxt - ��� ����� TXF,
// handle  - ������������� ����, �������� ���������� ��������� � ���� ��������
//           (WM_INFOLIST, WM_OBJECT)
// select  - ������������� ������� ������ ��������, ������������ ������
//           �������������� � ��������� ���� ��������,
// nameregion - ��� ������ (�����),
// precision  - ����� ������ ����� ������� ��� ������������� ���������
// ----------------------------------------------------------------

_MAPIMP long int WINAPI SaveTxtFromMapSelectEx(const char * namemap,
                                               long int list,
                                               const char * nametxt,
                                               HMESSAGE handle,
                                               HSELECT select,
                                               const char * nameregion,
                                               long int precision);

// ----------------------------------------------------------------
// �������� �� ����������� ������� � ������ TXF(BL)
// ----------------------------------------------------------------

_MAPIMP long int WINAPI SaveTxtGeoFromMap(char * namemap,
                                          int list,
                                          char * nametxt,
                                          HMESSAGE handle);

// ----------------------------------------------------------------
// �������� �� ����������� ������� � ������ TXF(BL) �
//      �������������� Select
// ----------------------------------------------------------------

_MAPIMP long int WINAPI SaveTxtGeoFromMapSelect(char * namemap,
                                                int list,
                                                char * nametxt,
                                                HMESSAGE handle,
                                                HSELECT select,
                                                char * nameregion = NULL);
_MAPIMP long int WINAPI SaveTxtGeoGradFromMapSelect(char * namemap,
                                                int list,
                                                char * nametxt,
                                                HMESSAGE handle,
                                                HSELECT select,
                                                char * NameRegion = NULL);

// ----------------------------------------------------------------
// �������� �� ����������� ������� � ������ SXF(WINDOWS) �� DIR
// ----------------------------------------------------------------

_MAPIMP long int WINAPI SaveDirSxfFromMap(char* namemap,
                                          char* namedir,
                                          HMESSAGE handle);

// ----------------------------------------------------------------
// �������� �� ����������� ������� � ������ SXF(WINDOWS) �� DIR
//   � �������������� Select
// ----------------------------------------------------------------

_MAPIMP long int WINAPI SaveDirSxfFromMapSelect(char* namemap,
                                                char* namedir,
                                                HMESSAGE handle,
                                                HSELECT select);

// ----------------------------------------------------------------
// �������� �� ����������� ������� � ������ SXF(WINDOWS) �� DIR
//   � �������������� Select
// ----------------------------------------------------------------

_MAPIMP long int WINAPI SaveDirSxfIntFromMapSelect(char* namemap,
                                                   char* namedir,
                                                   HMESSAGE handle,
                                                   HSELECT select);

// ----------------------------------------------------------------
// �������� �� ����������� ������� � ������ TXF(XY) �� DIR
// ----------------------------------------------------------------

_MAPIMP long int WINAPI SaveDirTxtFromMap(char* namemap,
                                          char* namedir,
                                          HMESSAGE handle);

// ----------------------------------------------------------------
// �������� �� ����������� ������� � ������ TXF(XY) �� DIR
//   � �������������� Select
// ----------------------------------------------------------------

_MAPIMP long int WINAPI SaveDirTxtFromMapSelect(char* namemap,
                                                char* namedir,
                                                HMESSAGE handle,
                                                HSELECT select);

// ----------------------------------------------------------------
// �������� �� ����������� ������� � ������ TXF(BL) �� DIR
// ----------------------------------------------------------------

_MAPIMP long int WINAPI SaveDirTxtGeoFromMap(char* namemap,
                                             char* namedir,
                                             HMESSAGE handle);

// ----------------------------------------------------------------
// �������� �� ����������� ������� � ������ TXF(BL) �� DIR
//   � �������������� Select
// ----------------------------------------------------------------

_MAPIMP long int WINAPI SaveDirTxtGeoFromMapSelect(char* namemap,
                                                   char* namedir,
                                                   HMESSAGE handle,
                                                   HSELECT select);

// ----------------------------------------------------------------
// �������� �� ����������� ������� � ������ TXF(BL �������) �� DIR
//   � �������������� Select
// ----------------------------------------------------------------

_MAPIMP long int WINAPI SaveDirTxtGeoGradFromMapSelect(char* namemap,
                                                       char* namedir,
                                                       HMESSAGE handle,
                                                       HSELECT select);

// ----------------------------------------------------------------
//   ����������������� ������ �� ������
// ----------------------------------------------------------------

_MAPIMP long int WINAPI TransVector(HOBJ FrameReal , HOBJ FrameTeor);

//-------------------------------------------------------------------
//  ��������� ���������� ���������� � ����� �� SXF
// ------------------------------------------------------------------

_MAPIMP long int WINAPI GetInfoSxf(char * namesxf,
                                   INFOSXF * infosxf);

//-------------------------------------------------------------------
//  ��������� ���������� ���������� �� DIR
// ------------------------------------------------------------------

_MAPIMP long int WINAPI GetInfoDir(char * namedir,
                                   INFODIR * infodir);

// ------------------------------------------------------------------
// ��������� ������ ������ SXF � DIR
// ------------------------------------------------------------------

_MAPIMP long int WINAPI GetDir(char * namedir,
                               NAMESARRAY * sxfdir, long int length);


}       // extern "C"

#endif  // VECEXAPI_H


