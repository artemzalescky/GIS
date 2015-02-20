/****** MAPPROF.H  ************** Belenkov O.V.  ****** 14/12/11 ***
******* MAPPROF.H  ************** Dishlenko S.G. ****** 04/04/12 ***
******* MAPPROF.H  ************** Shabakov  D.A. ****** 15/12/08 ***
******* MAPPROF.H  ************** Derevyagina Zh.A.**** 11/10/11 ***
*                                                                  *
*              Copyright (c) PANORAMA Group 1991-2012              *
*                      All Rights Reserved                         *
*                                                                  *
********************************************************************
*                                                                  *
*                 ПОТОКОВАЯ ОБРАБОТКА ФАЙЛОВ                       *
*                                                                  *
*******************************************************************/

#if !defined(MAPPROF_H)
#define MAPPROF_H

#ifndef MAPTYPE_H
  #include "maptype.h"
#endif

#include <stdio.h>


// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// +++++++++++ КЛАСС TMapProfile +++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#define MAXSECTIONCOUNT  (64*1024L)
#define MAXSECSTRINGSIZE (4*1024)   // 14/12/11

typedef struct SECTIONDESC
{
  int Key;                 // Смещением на ключ строки                      // 04/04/12
  int Value;               // Смещением на значение строки
}
  SECTIONDESC;


class _DLLCLASS TIniProfile
{
  public:

    TIniProfile(const char * section, const char far* filename = 0, int create = 0);

    ~TIniProfile();

    int IsActive() { return (FileHandle != 0); }

    int _fastcall GetInt(const char far* key, int defaultInt = 0);

    int _fastcall GetString(const char far* key, char far* buff,
                            unsigned buffSize, const char far* defaultString = "");
   
    int _fastcall WriteString(const char far* key, const char far* str);

    double _fastcall GetDouble(const char far* key, double defaultDouble);

    int _fastcall WriteDouble(const char far* key, double value);

    int  WriteInt(const char far* key, int value)
    {
      char buf[32];
#ifdef WINCE
      sprintf(buf, "%i", value);
#else
      itoa(value, buf, 10);
#endif
      return WriteString(key, buf);
    }

    void Flush()
    {
      Update();
    }

  protected:

    // Запросить значение строки по ключу
    const char * GetValueByKey(const char * key);

    // Выделить память или увеличить размер области
    int Realloc();

    // Обновить содержание секции
    int Update(int reopen = 1);
  
  protected:

    char SectionName[MAX_PATH]; // Name of the section to use
    char FileName[1024];        // File name of the .INI file

    char String[MAXSECSTRINGSIZE]; // Строка в INI-файле
    SECTIONDESC  * Section;        // "Разобранная" секция [MAXSECTIONCOUNT]

    char *       Buffer;       // Адрес буфера для строк секции
    int          Size;         // Размер буфера
    int          Length;       // Длина заполненного участка
    FILE *       FileHandle;   // Идентификатор INI-файла
    int          IsWrite;      // Доступ на запись
    int          IsDirty;      // Значения строк были изменены
};


#if defined(LINUXAPI) || defined(WINCE)
class _DLLCLASS TMapProfile : public TIniProfile
#else
class _DLLCLASS TMapProfile
#endif
{
  public:

#if defined(LINUXAPI) || defined(WINCE)
    TMapProfile(const char far* section, const char far* filename = 0); 

    ~TMapProfile() {}          // 12/09/11

    int GetInt(const char * key, int defaultInt = 0)
    {
      return TIniProfile::GetInt(key, defaultInt);
    }

    int GetString(const char * key, char * buff,
                  unsigned buffsize, const char * defaultstr = "")
    {
      return TIniProfile::GetString(key, buff, buffsize, defaultstr);
    }
   
    int WriteString(const char * key, const char * str)
    {
      return TIniProfile::WriteString(key, str);
    }

    double GetDouble(const char * key, double defaultDouble)
    {
      return TIniProfile::GetDouble(key, defaultDouble);
    }

    int WriteDouble(const char far* key, double value)
    {
      return TIniProfile::WriteDouble(key, value);
    }
#else
    TMapProfile(const char far* section, const char far* filename = 0)
    { 
      if (section)
        strncpy(SectionName, section, sizeof(SectionName));
      else
        SectionName[0] = 0;

      FileName[0] = 0;
      if (filename)
        {
          strncpy(FileName, filename, sizeof(FileName));
        }
    }    

    int GetInt(const char far* key, int defaultInt = 0)
    {
      char * section = SectionName[0] ? SectionName : 0;
      return FileName[0]
		  ? ::GetPrivateProfileIntA(section, key, defaultInt, FileName)    // 11/10/11
		  : ::GetProfileIntA(section, key, defaultInt);                     // 11/10/11
    }      

    int  GetString(const char far* key, char far* buff,
                   unsigned buffSize, const char far* defaultString = "")
    {
       char * section = SectionName[0] ? SectionName : 0;
       return FileName[0]
			? ::GetPrivateProfileStringA(section, key, defaultString, buff, buffSize, FileName)    // 11/10/11
			: ::GetProfileStringA(section, key, defaultString, buff, buffSize);                    // 11/10/11
    }               
    
    int  WriteString(const char far* key, const char far* str)
    {
      char * section = SectionName[0] ? SectionName : 0;
      return FileName[0]
		  ? ::WritePrivateProfileStringA(section, key, str, FileName)     // 11/10/11
		  : ::WriteProfileStringA(section, key, str);                     // 11/10/11
    }

    int  WriteInt(const char far* key, int value)
    {
      char buf[32];
      itoa(value, buf, 10);
      return WriteString(key, buf);
    }

    void Flush()
    {
      if (FileName[0])
        ::WritePrivateProfileStringA(0, 0, 0, FileName);                  // 11/10/11
    }
    
  protected:

    char SectionName[MAX_PATH]; // Name of the section to use
    char FileName[1024];        // File name of the .INI file
#endif
};

#endif
