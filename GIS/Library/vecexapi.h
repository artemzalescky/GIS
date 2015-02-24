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
* СТАНДАРТНЫЕ ФУНКЦИИ ГИС КАРТА 2011 ДЛЯ ПРИЛОЖЕНИЙ НА GIS ToolKit *
*                                                                  *
*                 ПРИМЕР ВЫЗОВА ДИАЛОГА:                           *
*                                                                  *
*   // Загрузка библиотеки                                         *
*   HINSTANCE libInst = ::LoadLibrary("gisvecex.dll");             *
*                                                                  *
*   // Вызов функции                                               *
*   typedef long int (WINAPI * MAPSORTING)(HMAP hMap,              *
*                                          HMESSAGE handle,        *
*                                          long int mode);         *
*                                                                  *
*   MAPSORTING mapsorting = (MAPSORTING)                           *
*                   GetProcAddress(libInst, "MapSortProcess");     *
*                                                                  *
*   long int rezult = (*mapsorting)(hMap, hWnd, mode);             *
*                                                                  *
*   // Выгрузка библиотеки                                         *
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
   DATAMETERS       = 0,  // Метрика в метрах
   DATARADIANS      = 4,  // Метрика в радианах
   DATADEGREES      = 8,  // Метрика в градусах
 };


extern "C"
{

 // Запросить имя классификатора (RSC) из файлов SXF, TXF, MAP (SIT)
 // В файлах SXF и TXF имя классификатора (RSC) может отсутствовать
 // При ошибке возвращает ноль

_MAPIMP long int WINAPI GetRscNameFromAnySxf(const char * filename, char * rscname, long int size);
_MAPIMP long int WINAPI GetRscNameFromSxf(const char * name, char * rscname, long int size);

 // Запросить имя карты из файлов SXF, TXF, MAP (SIT)
 // При ошибке возвращает ноль

_MAPIMP long int WINAPI GetSheetNameFromAnySxf(const char * filename, char * sheetname, long int size);


 // Запросить контрольную сумму файла SXF
 // name - имя файла SXF
 // При ошибке возвращает ноль и выдает сообщение на экран
 // Ноль - допустимое значение контрольной суммы

_MAPIMP long int WINAPI GetSxfCheckSum(const char * name);

 // Выполнить контроль структуры данных карты
 // hMap,hSite - идентификаторы карты (см.MAPAPI.H),
 // mode       - режим работы (0 - контроль, 1 - редактирование),
 // handle     - идентификатор окна диалога процесса обработки (HWND для Windows).
 //
 // Окну диалога посылаются следующие сообщения :
 //  WM_LIST   = 0x586   WParam - количество листов в районе
 //                      LParam - номер текущего листа
 //  WM_OBJECT = 0x585   WParam - процент обработанных объектов
 //  WM_ERROR  = 0x587   WParam - порядковый номер объекта или 0
 //                      LParam = 1 - ошибка в карте
 //                             = 2 - ошибка в классификаторе
 //                             = 3 - ошибка в описании объекта
 //                             = 4 - ошибка в метрике
 //                             = 5 - ошибка в семантике
 //                             = 6 - ошибка в графике
 // Возвращает количество ошибок в районе

_MAPIMP long int WINAPI mapStructControl(HMAP hMap,HSITE hSite,
                                         long int mode,HMESSAGE handle);

 // Сортировка всех карт, входящих в документ
 // hmap   - идентификатор сортируемого документа
 // handle - идентификатор окна диалога процесса обработки (HWND)
 // mode   - комбинация флагов способа обработки карты:
 //   0 - сортировать все листы,
 //   1 - только несортированные;
 //   2 - сохранять файлы отката;
 //   4 - повысить точность хранения в метрах, число знаков максимальное;
 //  16 - повысить точность хранения в метрах, формат - см  (2 знака);
 //  32 - повысить точность хранения в метрах, формат - мм  (3 знака);
 //  64 - повысить точность хранения в радианах, число знаков максимальное;
 // При ошибке возвращает ноль

_MAPIMP long int WINAPI MapSortProcess(HMAP hmap, HMESSAGE handle,
                                       long int mode);


 // Запросить паспортные данные из файлов SXF, TXF, MAP (SIT)          // 07/05/10
 // по имени файла 
 // Структуры MAPREGISTER и LISTREGISTER описаны в mapcreat.h
 // При ошибке возвращает ноль
 
_MAPIMP long int WINAPI mapGetAnySxfInfoByName(const char * name,
                                               MAPREGISTEREX * mapreg,
                                               LISTREGISTER * sheet);
                                       

 // Запрос числа элементов (SXF,TXF,MAP,...) в DIR
 // В списке элементов файла DIR могуть быть растры и матрицы           // 05/05/10
 // dirname - полное имя файла DIR
 // При ошибке возвращает ноль
 
_MAPIMP long int WINAPI GetDirItemCount(const char * dirname);

 // Запрос названия района или первой карты в списке (SXF,TXF,MAP,...) в DIR
 // dirname - полное имя файла DIR
 // name    - адрес буфера для размещения запрошенного имени
 // size    - размер буфера
 // При успешном выполнении возвращает число элементов в списке
 // При ошибке возвращает ноль

_MAPIMP long int WINAPI GetDirAreaName(const char * dirname, char * name, long int size);

 // Запрос списка имен файлов данных (SXF,TXF,MAP,...) в DIR
 // dirname - полное имя файла DIR
 // items   - адрес буфера для размещения заполненной структуры NAMESARRAY
 //           (см. mmstruct.h)
 // size    - размер буфера; должен быть не меньше, чем размер струткруры
 //           для числа элементов, равного GetDirItemCount()
 //           size = sizeof(NAMESARRAY) + sizeof(LISTSNAME) * (count - 1);
 // При успешном выполнении возвращает число элементов в списке
 // При ошибке возвращает ноль
 
_MAPIMP long int WINAPI GetDirItemList(const char * dirname,
                                       NAMESARRAY * items, long int size);

                                              
 //========================================================================
 //   Функции импорта, экспорта и обновления карты для форматов SXF, TXF и DIR
 //========================================================================
 //  Окну диалога посылаются следующие сообщения :
 //  WM_LIST   = 0x586   WParam - количество листов в районе
 //                      LParam - номер текущего листа
 //  WM_OBJECT = 0x585   WParam - процент обработанных объектов
 //  WM_INFOLIST = 0x584 LParam - адрес структуры INFOLIST
 // ----------------------------------------------------------------

 // Загрузить (импортировать) карту из файла SXF, TXF или DIR с      // 03/05/10
 // использованием Select с преобразованием топокарты к зоне документа
 // Файлы SXF и TXF могут хранить координаты в метрах, радианах или градусах
 // hmap    - идентификатор открытой карты (рекомендуется указывать
 //           для определения текущей зоны топокарты) или 0;
 // sxfname - имя загружаемого файла типа SXF, TXF или DIR;
 // rscname - имя файла классификатора, с которым загружается карта,
 //           имя классификатора можно запросить из SXF (TXF) функцией GetRscNameFromSxf
 //           или из карты; для файла DIR может быть 0;
 // mapname - имя создаваемой карты (обычно совпадает с именем SXF (TXF))
 //           или ноль или указатель на пустую строку (буфер размером MAX_PATH
 //           c нулевым байтом равным нулю) или указатель на папку для размещения
 //           карты. Если имя карты не задано или задана только папка, то карта
 //           создается с именем SXF (TXF) и расширением ".sit". Если namemap
 //           указывает на буфер достаточной длины (size), то в буфер записывается 
 //           имя созданной карты;
 //           Для файла DIR тип общей карты - MPT (проект данных, включающий все 
 //           открытые карты из DIR) или MAP (многолистовая карта);
 // size    - длина буфера, на который указывает переменная namemap или 0. Обычно длина
 //           равна MAX_PATH (256);
 // handle  - идентификатор окна диалога, которому посылаются уведомительные 
 //           сообщения (HWND для Windows, CALLBACK-Функция для Linux);
 // select  - фильтр загружаемых объектов и слоев, если необходима выборочная 
 //           обработка данных;
 // Для добавления открытой карты в документ необходимо вызвать функцию
 // mapAppendData(hmap, namemap).
 // При ошибке возвращает ноль

_MAPIMP long int WINAPI ImportFromAnySxf(HMAP hmap,
                                         const char * sxfname,
                                         const char * rscname,
                                         char * mapname,
                                         long int size,
                                         HMESSAGE handle,
                                         HSELECT select);

 // Загрузить (импортировать) карту из файла DIR 
 // frscfromsxf - значение флажка "разрешить использование
 // имени классификатора, указанного в файле sxf"

_MAPIMP long int WINAPI ImportFromAnySxfEx(HMAP hmap,
                                         const char * sxfname,
                                         const char * rscname,
                                         char * mapname,
                                         long int size,
                                         HMESSAGE handle,
                                         HSELECT select,
                                         int     frscfromsxf);
                                         

 // Обновить карту из файла SXF, TXF или DIR с использованием Select      // 04/05/10
 // с преобразованием топокарты к зоне документа
 // Файлы SXF и TXF могут хранить координаты в метрах, радианах или градусах
 // hmap    - идентификатор открытой карты (для определения текущей
 //           зоны топокарты) или 0;
 // sxfname - имя загружаемого файла типа SXF, TXF или DIR;
 // mapname - имя обновляемой карты; может быть ноль или указатель на пустую 
 //           строку, в этом случае обновляемая карта в документе ищется 
 //           по совпадению номенклатур.
 //           Если namemap указывает на буфер достаточной длины (size), 
 //           то в буфер записывается имя обновленной карты;
 //           Если карты не было в документе - она может быть создана (добавлена) 
 // size    - длина буфера, на который указывает переменная namemap или 0. Обычно длина
 //           равна MAX_PATH (256);
 // handle  - идентификатор окна диалога, которому посылаются уведомительные 
 //           сообщения (HWND для Windows, CALLBACK-Функция для Linux);
 // select  - фильтр загружаемых объектов и слоев, если необходима выборочная 
 //           обработка данных;
 // mode    - режим обновления данных:
 //           0 - поиск записей по совпадению уникального номера в карте и 
 //               исходном файле и обновление,
 //               если объект не найден, то добавление объекта;
 //           1 - добавление объектов с новыми уникальными номерами в те карты,
 //               номенклатуры которых совпадают с номенклатурой SXF (TXF),
 //               если - номенклатура не найдена, то добавляется новый лист (карта);
 //           2 - добавление объектов с новыми уникальными номерами в заданную
 //               карту без учета номенклатур
 // При ошибке возвращает ноль

_MAPIMP long int WINAPI UpdateFromAnySxf(HMAP hmap,
                                         const char * sxfname,
                                         char * mapname,
                                         long int size,
                                         HMESSAGE handle,
                                         HSELECT select,
                                         long int mode);

 // Сохранить (экспортировать) карту в двоичный формат SXF 
 // mapname - имя файла сохраняемой карты;
 // list    - номер листа для многолистовой карты или 1;
 // sxfname - имя создаваемого файла SXF, обычно совпадает с
 //           именем карты, но имеет расширение SXF;
 // flag    - вид хранимых координат (0 - метры, 4 - радианы
 //           для карты, поддерживающей геодезические координаты,
 //           -1 - определить по виду координат на карте);
 //           Если карты не было в документе - она может быть создана (добавлена) 
 // handle  - идентификатор окна диалога, которому посылаются уведомительные 
 //           сообщения (HWND для Windows, CALLBACK-Функция для Linux);
 // select  - фильтр выгружаемых объектов и слоев, если необходима выборочная 
 //           обработка данных;
 // Для топокарт, хранящих координаты в метрах, координаты всегда хранятся
 // в зоне, указанной в паспорте карты
 // При ошибке возвращает ноль

_MAPIMP long int WINAPI ExportToSxf(const char * mapname,
                                    long int list,
                                    const char * sxfname,
                                    long int flag,
                                    HMESSAGE handle,
                                    HSELECT select);

 // Сохранить (экспортировать) карту в двоичный формат SXF
 // mapname - имя файла сохраняемой карты;
 // list    - номер листа для многолистовой карты или 1;
 // sxfname - имя создаваемого файла SXF, обычно совпадает с
 //           именем карты, но имеет расширение SXF;
 // flag    - вид хранимых координат (0 - метры, 4 - радианы
 //           для карты, поддерживающей геодезические координаты,
 //           -1 - определить по виду координат на карте);
 //           Если карты не было в документе - она может быть создана (добавлена)
 // handle  - идентификатор окна диалога, которому посылаются уведомительные
 //           сообщения (HWND для Windows, CALLBACK-Функция для Linux);
 // select  - фильтр выгружаемых объектов и слоев, если необходима выборочная
 //           обработка данных;
 // flserv  - записать служебный объект c датумом и эллипсоидом и имя классификатора
 //           (поддерживается с версии 10.7 и выше) 
 // Для топокарт, хранящих координаты в метрах, координаты всегда хранятся
 // в зоне, указанной в паспорте карты
 // При ошибке возвращает ноль

_MAPIMP long int WINAPI ExportToSxfEx(const char * mapname,
                                    long int list,
                                    const char * sxfname,
                                    long int flag,
                                    HMESSAGE handle,
                                    HSELECT select,
                                    long int flserv);

 // Сохранить (экспортировать) карту в текстовый формат TXF
 // mapname - имя файла сохраняемой карты;
 // list    - номер листа для многолистовой карты или 1;
 // txfname - имя создаваемого файла TXF, обычно совпадает с
 //           именем карты, но имеет расширение SXF;
 // flag    - вид хранимых координат (0 - метры, 4 - радианы, 8 - градусы,
 //           для карты, поддерживающей геодезические координаты,
 //           -1 - определить по виду координат на карте);
 //           Если карты не было в документе - она может быть создана (добавлена) 
 // precision - число знаков после запятой для координат в метрах или 0;
 //             если карта имеет паспортную точность в см (2 знака) или
 //             в мм (3 знака), то precision игнорируется;
 // handle    - идентификатор окна диалога, которому посылаются уведомительные 
 //             сообщения (HWND для Windows, CALLBACK-Функция для Linux);
 // select    - фильтр выгружаемых объектов и слоев, если необходима выборочная 
 //             обработка данных;
 // Для топокарт, хранящих координаты в метрах, координаты всегда хранятся
 // в зоне, указанной в паспорте карты
 // При ошибке возвращает ноль

_MAPIMP long int WINAPI ExportToTxf(const char * mapname,
                                    long int list,
                                    const char * txfname,
                                    long int flag,
                                    long int precision, 
                                    HMESSAGE handle,
                                    HSELECT select);


 // Сохранить (экспортировать) карту в формат DIR 
 // hmap    - идентификатор открытых данных
 // dirname - имя создаваемого файла DIR, обычно совпадает с
 //           именем открытого проекта или главной карты, но имеет расширение DIR;
 // type    - тип создаваемых файлов (0 - SXF, 1 - TXF);
 // flag    - вид хранимых координат (0 - метры, 4 - радианы, 8 - градусы,
 //           для карты, поддерживающей геодезические координаты,
 //           -1 - определить по виду координат на карте);
 //           Если карты не было в документе - она может быть создана (добавлена) 
 // total   - признак сохранения в DIR только главной карты (0) или всех карт
 //           документа (1);
 // precision - для файлов TXF число знаков после запятой для координат в метрах или 0;
 //           если карта имеет паспортную точность в см (2 знака) или
 //           в мм (3 знака), то precision игнорируется;
 // handle  - идентификатор окна диалога, которому посылаются уведомительные 
 //           сообщения (HWND для Windows, CALLBACK-Функция для Linux);
 // select  - фильтр выгружаемых объектов и слоев, если необходима выборочная 
 //           обработка данных;
 // Для топокарт, хранящих координаты в метрах, координаты всегда хранятся
 // в зоне, указанной в паспорте карты
 // При ошибке возвращает ноль

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
 //                      УСТАРЕВШИЕ ФУНКЦИИ                         // 03/05/10
 //
 //              Реализованы через вызов новых функций
 // ================================================================

 // Загрузить карту из файла SXF
 // При ошибке возвращает ноль

_MAPIMP long int WINAPI LoadSxfToMap(char * namesxf,
                                     char * namemap,
                                     char * namersc,
                                     HMESSAGE handle);

 // Загрузить карту из файла SXF с использованием Select
 // При ошибке возвращает ноль
 
_MAPIMP long int WINAPI LoadSxfToMapSelect(char * namesxf,
                                           char * namemap,
                                           char * namersc,
                                           HMESSAGE handle,
                                           HSELECT select);

 // Загрузить карту из файла SXF с использованием Select 
 // и изменением имени карты
 // Параметры name и namehdr - не обрабатываются
 // При ошибке возвращает ноль

_MAPIMP long int WINAPI LoadSxfToMapSelectName(char * namesxf,
                                               char * namemap,
                                               char * namersc,
                                               HMESSAGE handle,
                                               HSELECT select,
                                               char * name,
                                               char * namehdr);

 // Загрузить карту из файла TXF
 // При ошибке возвращает ноль

_MAPIMP long int WINAPI LoadTxtToMap(char * nametxt,
                                     char * namemap,
                                     char * namersc,
                                     HMESSAGE handle);

 // Загрузить карту из файла TXF с испльзованием Select
 // При ошибке возвращает ноль

_MAPIMP long int WINAPI LoadTxtToMapSelect(char * nametxt,
                                           char * namemap,
                                           char * namersc,
                                           HMESSAGE handle,
                                           HSELECT select);


 // Загрузить карту из файла TXF с испльзованием Select и изменением имени
 // Параметры name и namehdr - не обрабатываются
 // При ошибке возвращает ноль

_MAPIMP long int WINAPI LoadTxtToMapSelectName(char * nametxt,
                                               char * namemap,
                                               char * namersc,
                                               HMESSAGE handle,
                                               HSELECT select,
                                               char * name,
                                               char * namehdr);

 // Загрузить карту по списку DIR
 // При ошибке возвращает ноль

_MAPIMP long int WINAPI LoadDirToMap(char* namedir,
                                     char* namemap,
                                     HMESSAGE handle);

 // Загрузить карту по списку DIR с использованием  Select
 // При ошибке возвращает ноль

_MAPIMP long int WINAPI LoadDirToMapSelect(char* namedir,
                                           char* namemap,
                                           HMESSAGE handle,
                                           HSELECT select);

 // Загрузить карту по списку DIR с использованием  Select и 
 // изменением имени района и имени файла ресурсов
 // При ошибке возвращает ноль

_MAPIMP long int WINAPI LoadDirToMapSelectName(char* namedir,
                                               char* namemap,
                                               HMESSAGE handle,
                                               HSELECT select,
                                               char * name,
                                               char* namersc);

 // Загрузить карту по данным из другого района
 // При ошибке возвращает ноль

_MAPIMP long int WINAPI LoadMapToMap(HMAP  map,
                                     char * namemap,
                                     HMESSAGE handle);

 // Загрузить карту по данным другого района с использованием  Select
 // При ошибке возвращает ноль

_MAPIMP long int WINAPI LoadMapToMapSelect(HMAP map,
                                           char* namemap,
                                           HMESSAGE handle,
                                           HSELECT select);

 // Обновить карту из файла SXF
 // При ошибке возвращает ноль

_MAPIMP long int WINAPI UpdateMapFromSxf(char* namesxf,
                                         char* namemap,
                                         HMESSAGE handle);

 // Обновить карту из файла SXF с использованием Select
 // При ошибке возвращает ноль

_MAPIMP long int WINAPI UpdateMapFromSxfSelect(char* namesxf,
                                               char* namemap,
                                               HMESSAGE handle,
                                               HSELECT select);

 // Обновить карту по данным другого района с использованием  Select
 // При ошибке возвращает ноль

_MAPIMP long int WINAPI UpdateMapToMapSelect(HMAP map,   
                                             const char* namemap,
                                             HMESSAGE handle,
                                             HSELECT select);

 // Добавить в карту данные из файла SXF с использованием Select
 // При ошибке возвращает ноль

_MAPIMP long int WINAPI AppendMapFromSxfSelect(char* namesxf,
                                               char* namemap,
                                               HMESSAGE handle,
                                               HSELECT select);

 // Обновить карту из файла TXF
 // При ошибке возвращает ноль

_MAPIMP long int WINAPI UpdateMapFromTxt(char* nametxt,
                                         char* namemap,
                                         HMESSAGE handle);

 // Обновить карту из файла TXF с использованием Select
 // При ошибке возвращает ноль

_MAPIMP long int WINAPI UpdateMapFromTxtSelect(char* nametxt,
                                               char* namemap,
                                               HMESSAGE handle,
                                               HSELECT select);

 // Добавить в карту данные из файла TXF с использованием Select
 // При ошибке возвращает ноль

_MAPIMP long int WINAPI AppendMapFromTxtSelect(char* namesxf,
                                               char* namemap,
                                               HMESSAGE handle,
                                               HSELECT select);

 // Обновить карту из файла DIR с использованием Select
 // При ошибке возвращает ноль

_MAPIMP long int WINAPI UpdateMapFromDirSelect(char* namedir,
                                               char* namemap,
                                               HMESSAGE handle,
                                               HSELECT select);

 // Добавить в карту данные из файла DIR с использованием Select
 // При ошибке возвращает ноль

_MAPIMP long int WINAPI AppendMapFromDirSelect(char* namedir,
                                               char* namemap,
                                               HMESSAGE handle,
                                               HSELECT select);

 // Запросить паспортные данные векторной карты
 // по имени файла SXF
 // Структуры MAPREGISTER и LISTREGISTER описаны в mapcreat.h
 // При ошибке возвращает ноль

_MAPIMP long int WINAPI mapGetSxfInfoByName(const char * name,
                                            MAPREGISTER * map,
                                            LISTREGISTER * sheet);

_MAPIMP long int WINAPI mapGetSxfInfoByNameEx(const char * name,        // 19/11/09
                                              MAPREGISTEREX * map,
                                              LISTREGISTER * sheet);
                                               
//========================================================================
//   Функции сохранения карты
//========================================================================
//  Идентификатору посылаются следующие сообщения :
//  WM_LIST   = 0x586   WParam - количество листов в районе
//                      LParam - номер текущего листа
//  WM_OBJECT = 0x585   WParam - процент обработанных объектов

// ----------------------------------------------------------------
// Выгрузка из внутреннего формата в формат SXF(Windows)
// ----------------------------------------------------------------

_MAPIMP long int WINAPI SaveSxfFromMap(char * namemap,
                                       int list,
                                       char * namesxf,
                                       HMESSAGE handle);

// ----------------------------------------------------------------
// Выгрузка из внутреннего формата в формат SXF(Windows) с
//          использованием  Select
// ----------------------------------------------------------------

_MAPIMP long int WINAPI SaveSxfFromMapSelect(char * namemap,
                                             int list,
                                             char * namesxf,
                                             HMESSAGE handle,
                                             HSELECT select,
                                             int flag = 0,
                                             char * nameregion = NULL);

// ----------------------------------------------------------------
// Выгрузка из внутреннего формата в формат SXF(Windows) с
//          использованием  Select
// ----------------------------------------------------------------

_MAPIMP long int WINAPI SaveSxfFromHMapSelect(HMAP map,
                                              int list,
                                              char * namesxf,
                                              HMESSAGE handle,
                                              HSELECT select,
                                              int flag = 0,
                                              char * nameregion = NULL);

// ----------------------------------------------------------------
// Выгрузка из внутреннего формата в формат TXT(XY)
// ----------------------------------------------------------------

_MAPIMP long int WINAPI SaveTxtFromMap(char * namemap,
                                       int   list,
                                       char * nametxt,
                                       HMESSAGE handle);

// ----------------------------------------------------------------
// Выгрузка из внутреннего формата в формат TXF(XY) с
//      использованием Select
// ----------------------------------------------------------------

_MAPIMP long int WINAPI SaveTxtFromMapSelect(char * namemap,
                                             int list,
                                             char * nametxt,
                                             HMESSAGE handle,
                                             HSELECT select,
                                             char * nameregion = NULL);

// ----------------------------------------------------------------
// Выгрузка из внутреннего формата в формат TXF(XY) с
// использованием Select
// namemap - имя выгружаемой карты,
// list    - номер листа,
// nametxt - имя файла TXF,
// handle  - идентификатор окна, которому посылаются сообщения о ходе процесса
//           (WM_INFOLIST, WM_OBJECT)
// select  - идентификатор условий поиска объектов, определяющий список
//           экспортируемых в текстовый файл объектов,
// nameregion - имя района (карты),
// precision  - число знаков после запятой для прямоугольных координат
// ----------------------------------------------------------------

_MAPIMP long int WINAPI SaveTxtFromMapSelectEx(const char * namemap,
                                               long int list,
                                               const char * nametxt,
                                               HMESSAGE handle,
                                               HSELECT select,
                                               const char * nameregion,
                                               long int precision);

// ----------------------------------------------------------------
// Выгрузка из внутреннего формата в формат TXF(BL)
// ----------------------------------------------------------------

_MAPIMP long int WINAPI SaveTxtGeoFromMap(char * namemap,
                                          int list,
                                          char * nametxt,
                                          HMESSAGE handle);

// ----------------------------------------------------------------
// Выгрузка из внутреннего формата в формат TXF(BL) с
//      использованием Select
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
// Выгрузка из внутреннего формата в формат SXF(WINDOWS) по DIR
// ----------------------------------------------------------------

_MAPIMP long int WINAPI SaveDirSxfFromMap(char* namemap,
                                          char* namedir,
                                          HMESSAGE handle);

// ----------------------------------------------------------------
// Выгрузка из внутреннего формата в формат SXF(WINDOWS) по DIR
//   с использованием Select
// ----------------------------------------------------------------

_MAPIMP long int WINAPI SaveDirSxfFromMapSelect(char* namemap,
                                                char* namedir,
                                                HMESSAGE handle,
                                                HSELECT select);

// ----------------------------------------------------------------
// Выгрузка из внутреннего формата в формат SXF(WINDOWS) по DIR
//   с использованием Select
// ----------------------------------------------------------------

_MAPIMP long int WINAPI SaveDirSxfIntFromMapSelect(char* namemap,
                                                   char* namedir,
                                                   HMESSAGE handle,
                                                   HSELECT select);

// ----------------------------------------------------------------
// Выгрузка из внутреннего формата в формат TXF(XY) по DIR
// ----------------------------------------------------------------

_MAPIMP long int WINAPI SaveDirTxtFromMap(char* namemap,
                                          char* namedir,
                                          HMESSAGE handle);

// ----------------------------------------------------------------
// Выгрузка из внутреннего формата в формат TXF(XY) по DIR
//   с использованием Select
// ----------------------------------------------------------------

_MAPIMP long int WINAPI SaveDirTxtFromMapSelect(char* namemap,
                                                char* namedir,
                                                HMESSAGE handle,
                                                HSELECT select);

// ----------------------------------------------------------------
// Выгрузка из внутреннего формата в формат TXF(BL) по DIR
// ----------------------------------------------------------------

_MAPIMP long int WINAPI SaveDirTxtGeoFromMap(char* namemap,
                                             char* namedir,
                                             HMESSAGE handle);

// ----------------------------------------------------------------
// Выгрузка из внутреннего формата в формат TXF(BL) по DIR
//   с использованием Select
// ----------------------------------------------------------------

_MAPIMP long int WINAPI SaveDirTxtGeoFromMapSelect(char* namemap,
                                                   char* namedir,
                                                   HMESSAGE handle,
                                                   HSELECT select);

// ----------------------------------------------------------------
// Выгрузка из внутреннего формата в формат TXF(BL градусы) по DIR
//   с использованием Select
// ----------------------------------------------------------------

_MAPIMP long int WINAPI SaveDirTxtGeoGradFromMapSelect(char* namemap,
                                                       char* namedir,
                                                       HMESSAGE handle,
                                                       HSELECT select);

// ----------------------------------------------------------------
//   Трансформирование района по рамкам
// ----------------------------------------------------------------

_MAPIMP long int WINAPI TransVector(HOBJ FrameReal , HOBJ FrameTeor);

//-------------------------------------------------------------------
//  Получение справочной информации о листе из SXF
// ------------------------------------------------------------------

_MAPIMP long int WINAPI GetInfoSxf(char * namesxf,
                                   INFOSXF * infosxf);

//-------------------------------------------------------------------
//  Получение справочной информации из DIR
// ------------------------------------------------------------------

_MAPIMP long int WINAPI GetInfoDir(char * namedir,
                                   INFODIR * infodir);

// ------------------------------------------------------------------
// Получение списка файлов SXF в DIR
// ------------------------------------------------------------------

_MAPIMP long int WINAPI GetDir(char * namedir,
                               NAMESARRAY * sxfdir, long int length);


}       // extern "C"

#endif  // VECEXAPI_H


