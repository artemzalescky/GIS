/****** MAPFILES.H ************** Belenkov O.V.  ****** 12/10/10 ***
******* MAPFILES.H ************** Dishlenko S.G. ****** 10/08/07 ***
******* MAPFILES.H ************** Shabakov  D.A. ****** 15/12/02 ***
*                                                                  *
*              Copyright (c) PANORAMA Group 1991-2010              *
*                      All Rights Reserved                         *
*                                                                  *
********************************************************************
*                                                                  *
*                 ��������� ��������� ������                       *
*                                                                  *
*******************************************************************/

#if !defined(MAPFILES_H)
#define MAPFILES_H

#ifndef MAPTYPE_H
  #include "maptype.h"
#endif

#ifndef MAPPROF_H
  #include "mapprof.h"   // 15/12/08
#endif

#ifdef LINUXAPI
  #include <stdio.h>
#endif

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++ ��������� ��������� ������ +++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ������������ ��� ��������� ������ �� ���� ������
// (���������������, �����������, ����������� � �.�.)

class _DLLCLASS TPrepareFile
{
 public:

  TPrepareFile()
   {
     File    = 0;
     Buffer  = 0;
     Size    = 0;
     Minimum = 0x8000;
   }

  TPrepareFile(char * name,int access = 0,int mode = 0)
   {
     File    = 0;
     Buffer  = 0;
     Size    = 0;
     Minimum = 0x8000;
     Run(name,access,mode);
   }

  ~TPrepareFile()
   {
     Close();
   }

  // ���������� ���� ������
  // name - ���� � �����
  // ���� ������ �� ���� ���� - ���������� ����

  virtual int Run(const char * name,int access = 0,int mode = 0);


 protected :

  // ���������� ���� ������ �� �����
  // ���� ���������� ���� - ��������� �����������

  virtual int Prepare(char * /*buffer*/,long int /*size*/)
    {
      return 1;
    }

  // ���������� ��������� �������� (������ ������)
  // ���� ���������� ���� - ��������� �����������

  virtual int Terminate()
    {
      return 0;
    }

  // ������� ���� ������
  // ��� ������ ���������� ����

  virtual int Open(const char * name,int access = 0,
                   int mode = 0);

  // ������� ����

  virtual void Close();

 protected:

 HANDLE File;            // ������������� �����
 char * Buffer;          // ����� ������
 unsigned int Size;      // ������ ������
 unsigned int Minimum;   // ����������� ������ ������
 unsigned int Length;    // ������ �����
 unsigned int Offset;    // ������� �������� � �����

};

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++   ������� ��������� � ������ �����   +++++++++++++
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class _DLLCLASS TCopyFile : public TPrepareFile
{
 public :

  TCopyFile() : TPrepareFile()
  {
    OutFile = 0;
    OutName = 0;
  }

  TCopyFile(const char * in, const char * out,
            int access = 0,int mode = 0) : TPrepareFile()
  {
    OutFile = 0;
    OutName = 0;
    Copy(in, out, access, mode);
  }

 ~TCopyFile()
  {
    if (OutFile) ::CloseTheFile(OutFile);
  }

  // ���������� ���� ������
  // in - ���� � ��������� �����,
  // out - ���� � ��������� �����
  // ���� ������� Prepare �� �������������� - ���������
  // ����������� ������
  // ���� ������ �� ���� ���� - ���������� ����

  int Copy(const char * in, const char * out,
           int access = 0,int mode = 0);

 protected:

  // ���������� ���� ������ �� ����� (�����������)
  // ���� ���������� ���� - ��������� �����������

  int Prepare(char * buffer,long int size);

  HANDLE OutFile;
  const char * OutName;
};

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++   ������� ��������� � ������ �����   +++++++++++++
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
class _DLLCLASS TPrepareFileHeader : public TCopyFile
{
 public:

  TPrepareFileHeader() : TCopyFile() {}

 ~TPrepareFileHeader() {}

  // �������� ��������� � ������ �����
  //  in     - ���� � �������� �����
  //  out    - ���� � ��������� �����
  //  record - ������
  //  size   - ������ ������
  // ��� ������ ���������� ����

  int Insert(const char * name,char * record, int size)
     {
       return InsertAndRun(name,name,record,size);
     }

  int InsertAndRun(const char * in,const char * out, char * record, int size);

};



// --------------------------------------------------------
//  ��������������� �������
// --------------------------------------------------------

extern "C"
{
 // ����������� ������ �����
 // oldname - ������ ��� ������
 // newname - ����� ��� ������
 // ��� ������ ���������� ����

 long int _MAPAPI CopyMap(const char * oldname,const char * newname);

 // �������� ������ �����
 // name - ��� ������
 // ��� ������ ���������� ����

 long int _MAPAPI DeleteMap(const char * name);

 // ���������� ����������� ����� � ������
 // ���� ����������� ������ �� ������, ������ �� ������ �����������
 // ������ ����� �� ����� 4 �����
 // name - ��� ������������ �����;
 // size - ������ ���������, ������� ����� �����������,
 //        ���� ����� 0 - ����� �������� ���� ����;
 // offset - �������� �� ������ ������������ ���������,
 //        ���� ����� 0 - ������ � ������ �����.
 // filamap - ����� ��������� ��������� (���� �� ������ ���������������)
 // ��� �������� ���������� ����������� ���� ��������� FILEMAPPING
 // � ������������ ��������� ��������
 // ��� ������ ���������� ����

 long int _MAPAPI mapOpenTheFileMapping(const char * name,
                                        unsigned long int size,
                                        unsigned long int offset,
                                        FILEMAPPING * filemap);

 // ������� ����������� ����� � ������

 void _MAPAPI mapCloseTheFileMapping(FILEMAPPING * filemap);

 // ��������� ����� ������ � ����� �� �������� �� ������ �����
 // offset - �������� �� ������ ������������ ���������,
 // size   - ������ ������������� ������ (��� ��������) ��� 0

 const char * _MAPAPI mapReadTheFileMapping(FILEMAPPING * filemap,
                                            unsigned long offset,
                                            unsigned long size);

}  // extern "C"


inline long int cfCopyFile(const char * in, const char * out,
                           long int access = 0, long int mode = 0)
{
  TCopyFile File;                                       // 05/04/01
  return    File.Copy(in, out, access, mode);
}

 // ���������� ����� ������ ��������� �����
 // inname  - �������� ���� �������� ��������� �����,
 // outname - �������� ���� �������� ��������� �����,
 // ��������� ����������� ������.
 // � ������ ������ ���������� 0

 long int cfCopyMapFiles(const char * inname, const char * outname);  // 10/08/07

 // ��������� ���������� DLL
 HINSTANCE xwLoadLibrary(const char * dllname);

 // ��������� ������� ���������� DLL
 FARPROC xwGetProcAddress(HINSTANCE libinst,const char * funcname);

 // ��������� ���������� DLL
 int xwFreeLibrary(HINSTANCE libinst);

 // ��������� ���������� DLL
 // ��� ������ DLL ����������� � ���������� ����������
 // ��� ������ ���������� ���� � ������ ��������� �� �����

 FARPROC LoadMapLibrary(const char * dllname,
                        HINSTANCE  & libinst,
                        const char * funcname,
                        int message);

#endif
