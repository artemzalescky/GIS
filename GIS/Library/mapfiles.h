/****** MAPFILES.H ************** Belenkov O.V.  ****** 12/10/10 ***
******* MAPFILES.H ************** Dishlenko S.G. ****** 10/08/07 ***
******* MAPFILES.H ************** Shabakov  D.A. ****** 15/12/02 ***
*                                                                  *
*              Copyright (c) PANORAMA Group 1991-2010              *
*                      All Rights Reserved                         *
*                                                                  *
********************************************************************
*                                                                  *
*                 ПОТОКОВАЯ ОБРАБОТКА ФАЙЛОВ                       *
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
// ++++++++ ПОТОКОВАЯ ОБРАБОТКА ФАЙЛОВ +++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Предназначен для обработки данных за один проход
// (конвертирование, кодирование, копирование и т.п.)

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

  // Обработать файл данных
  // name - путь к файлу
  // Если считан не весь файл - возвращает ноль

  virtual int Run(const char * name,int access = 0,int mode = 0);


 protected :

  // Обработать блок данных из файла
  // Если возвращает ноль - обработка завершается

  virtual int Prepare(char * /*buffer*/,long int /*size*/)
    {
      return 1;
    }

  // Обработать аварийную ситуацию (ошибка чтения)
  // Если возвращает ноль - обработка завершается

  virtual int Terminate()
    {
      return 0;
    }

  // Открыть файл данных
  // При ошибке возвращает ноль

  virtual int Open(const char * name,int access = 0,
                   int mode = 0);

  // Закрыть файл

  virtual void Close();

 protected:

 HANDLE File;            // Идентификатор файла
 char * Buffer;          // Адрес буфера
 unsigned int Size;      // Размер буфера
 unsigned int Minimum;   // Минимальный размер буфера
 unsigned int Length;    // Размер файла
 unsigned int Offset;    // Текущее смещение в файле

};

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++   ВСТАВКА ЗАГОЛОВКА В НАЧАЛО ФАЙЛА   +++++++++++++
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

  // Копировать файл данных
  // in - путь к исходному файлу,
  // out - путь к выходному файлу
  // Если функция Prepare не переопределена - выполняет
  // копирование файлов
  // Если считан не весь файл - возвращает ноль

  int Copy(const char * in, const char * out,
           int access = 0,int mode = 0);

 protected:

  // Обработать блок данных из файла (копирование)
  // Если возвращает ноль - обработка завершается

  int Prepare(char * buffer,long int size);

  HANDLE OutFile;
  const char * OutName;
};

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++   ВСТАВКА ЗАГОЛОВКА В НАЧАЛО ФАЙЛА   +++++++++++++
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
class _DLLCLASS TPrepareFileHeader : public TCopyFile
{
 public:

  TPrepareFileHeader() : TCopyFile() {}

 ~TPrepareFileHeader() {}

  // Вставить заголовок в начало файла
  //  in     - путь к входному файлу
  //  out    - путь к выходному файлу
  //  record - запись
  //  size   - размер записи
  // При ошибке возвращает ноль

  int Insert(const char * name,char * record, int size)
     {
       return InsertAndRun(name,name,record,size);
     }

  int InsertAndRun(const char * in,const char * out, char * record, int size);

};



// --------------------------------------------------------
//  Вспомогательные функции
// --------------------------------------------------------

extern "C"
{
 // Копирование района работ
 // oldname - старое имя района
 // newname - новое имя района
 // При ошибке возвращает ноль

 long int _MAPAPI CopyMap(const char * oldname,const char * newname);

 // Удаление района работ
 // name - имя района
 // При ошибке возвращает ноль

 long int _MAPAPI DeleteMap(const char * name);

 // Установить отображение файла в память
 // Файл открывается только на чтение, доступ на запись блокируется
 // Размер файла не более 4 Гбайт
 // name - имя открываемого файла;
 // size - размер фрагмента, который будет считываться,
 //        если равен 0 - будет читаться весь файл;
 // offset - смещение на начало считываемого фрагмента,
 //        если равно 0 - чтение с начала файла.
 // filamap - адрес служебной структуры (поля не должны редактироваться)
 // При успешном выполнении заполняются поля структуры FILEMAPPING
 // и возвращается ненулевое значение
 // При ошибке возвращает ноль

 long int _MAPAPI mapOpenTheFileMapping(const char * name,
                                        unsigned long int size,
                                        unsigned long int offset,
                                        FILEMAPPING * filemap);

 // Закрыть отображение файла в память

 void _MAPAPI mapCloseTheFileMapping(FILEMAPPING * filemap);

 // Запросить адрес данных в файле по смещению от начала файла
 // offset - смещение от начала запрошенного фрагмента,
 // size   - размер запрашиваемой записи (для контроля) или 0

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

 // Копировать файлы данных векторной карты
 // inname  - исходный файл паспорта векторной карты,
 // outname - выходной файл паспорта векторной карты,
 // Выполняет копирование файлов.
 // В случае ошибки возвращает 0

 long int cfCopyMapFiles(const char * inname, const char * outname);  // 10/08/07

 // Загрузить библиотеку DLL
 HINSTANCE xwLoadLibrary(const char * dllname);

 // Загрузить функцию библиотеки DLL
 FARPROC xwGetProcAddress(HINSTANCE libinst,const char * funcname);

 // Выгрузить библиотеку DLL
 int xwFreeLibrary(HINSTANCE libinst);

 // Загрузить библиотеку DLL
 // При поиске DLL проверяется и директория приложения
 // При ошибке возвращает ноль и выдает сообщение на экран

 FARPROC LoadMapLibrary(const char * dllname,
                        HINSTANCE  & libinst,
                        const char * funcname,
                        int message);

#endif
