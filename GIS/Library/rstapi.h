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
*       ОПИСАНИЕ КЛАССА ДОСТУПА К ОБ'ЕКТУ "ЭЛЕКТРОННАЯ КАРТА"      *
*        ИНТЕРФЕЙС ДЛЯ ПРОГРАММ НА ЯЗЫКАХ C, PASCAL, BASIC         *
*                                                                  *
********************************************************************
*                                                                  *
*    Импортирование функций в Windows :                            *
*                                                                  *
*    // Загрузка библиотеки                                        *
*    HINSTANCE libInst = ::LoadLibrary("gisacces.dll");            *
*                                                                  *
*    // Вызов функции                                              *
*    HMAP (WINAPI * lpfn_OpenMap)(const char*, long int);          *
*    (FARPROC)lpfn_OpenMap = GetProcAddress(libInst, "OpenMap");   *
*    HMAP hMap = (*lpfn_OpenMap)("Noginsk.map",0);                 *
*                                                                  *
*    // Выгрузка библиотеки                                        *
*    ::FreeLibrary(libInst);                                       *
*                                                                  *
*******************************************************************/

#ifndef RSTAPI_H
#define RSTAPI_H

#ifndef MAPTYPE_H
  #include "maptype.h"   // Описание структур интерфейса MAPAPI
#endif

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// +++++ ОПИСАНИЕ ФУНКЦИЙ ДОСТУПА К РАСТРОВОЙ КАРТЕ ++++++++
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++

extern "C"
{

  // Открыть растровые данные
  // Возвращает идентификатор открытой растровой карты (TMapAccess*)
  // rstname - имя файла растровой карты
  // mode    - режим чтения/записи (GENERIC_READ, GENERIC_WRITE или 0)
  // GENERIC_READ - все данные только на чтение
  // При ошибке возвращает ноль

_MAPIMP  HMAP _MAPAPI mapOpenRst(const char * rstname,
                                 long int mode = 0);  // 27/04/01


  // Открыть растровые данные в заданном районе работ
  // (добавить в цепочку растров)
  // Возвращает номер файла в цепочке растров
  // hMap    - идентификатор открытой векторной карты
  // rstname - имя файла растровой карты
  // mode    - режим чтения/записи (GENERIC_READ, GENERIC_WRITE или 0)
  // GENERIC_READ - все данные только на чтение
  // При ошибке возвращает ноль

_MAPIMP  long int _MAPAPI mapOpenRstForMap(HMAP hMap,
                                    const char * rstname,
                                    long int mode);


  // Создание файла растрового изображения
  // rstname    - имя создаваемого файла
  // width      - ширина растрового изображения в элементах
  // height     - высота растрового изображения в элементах
  // nbits      - размер элемента (бит на пиксел)
  // palette    - адрес устанавливаемой палитры
  // colorcount - число элементов в новой палитре
  // scale      - масштаб
  // precision  - разрешение растра
  // При успешном завершении функция создает файл rstname с заполненным
  // паспортом и палитрой растра.
  //  При ошибке возвращает 0
  
_MAPIMP  HMAP _MAPAPI mapCreateRst(const char * rstname,
                                long int width, long int height,
                                long int nbits,
                                COLORREF* palette, long int colorcount,
                                double scale=0, double precision=0);  // 27/04/01


  // Создание файла растровой карты
  // name            - полное имя растра
  // width           - ширина изображения в пикселях
  // height          - высота изображения в пикселях
  // nbits           - количество бит на пиксель (1,4,8,24)
  // palette         - указатель на палитру растра (справедливо для 1,4,8 бит на пиксель)
  // scale           - мастаб растра
  // precisionMet    - разрешения растра (точек на метр)
  // meterInElementX - размер пикселя растра в метрах на местности по оси X (по вертикали)
  // meterInElementY - размер пикселя растра в метрах на местности по оси Y (по горизонтали)
  //                   meterInElementX и meterInElementY могут иметь разные значения
  // location        - координаты юго-западного угла растра в метрах, соответствующие СК в mapregister
  // mapregister     - проекции исходного материала
  // Важно!!!
  // Для корректного открытия растров в 10-ой и более ранних версиях необходимо выполнить условие:
  //                            meterInElementX = scale/precisionMet;
  // Иначе масштаб и разрешение будут пересчитаны!!!
  //
  // При ошибке возвращает

_MAPIMP  HMAP _MAPAPI mapCreateRstEx(char * rstname, long width, long height, long nbits,  
                             COLORREF* palette, long int colorcount,
                             double scale, double precisionMet,
                             double meterInElementX, double meterInElementY,
                             DOUBLEPOINT *location, MAPREGISTEREX* mapregister);

                             
  // Создание файла растровой карты   // 23/02/12
  // name            - полное имя растра
  // width           - ширина изображения в пикселях
  // height          - высота изображения в пикселях
  // nbits           - количество бит на пиксель (1,4,8,24)
  // palette         - указатель на палитру растра (справедливо для 1,4,8 бит на пиксель)
  // meterInElementX - размер пикселя растра в метрах на местности по оси X (по вертикали)
  // meterInElementY - размер пикселя растра в метрах на местности по оси Y (по горизонтали)
  //                   meterInElementX и meterInElementY могут иметь разные значения
  // location        - координаты юго-западного угла растра в метрах, соответствующие СК в mapregister
  // mapregister     - указатель на структуру, содержащую параметры проекции исходного материала
  // datumparam      - указатель на структуру, содержащую коэффициенты трансформирования геодезических координат
  // ellipsoidparam  - указатель на структуру, содержащую параметры эллипсоида
  //
  // При ошибке возвращает

_MAPIMP  HMAP _MAPAPI mapCreateRaster(const char * rstname, long width, long height, long nbits,            // 01/03/12
                             COLORREF* palette, long int colorcount,
                             double meterInElementX, double meterInElementY,
                             DOUBLEPOINT *location,
                             MAPREGISTEREX* mapregister, DATUMPARAM * datum, ELLIPSOIDPARAM * ellipsoid);


  // Создание файла растрового изображения
  // hMap       - идентификатор открытой векторной карты
  // rstname    - имя создаваемого файла
  // width      - ширина растрового изображения в элементах
  // height     - высота растрового изображения в элементах
  // nbits      - размер элемента (бит на пиксел)
  // palette    - адрес устанавливаемой палитры
  // colorcount - число элементов в новой палитре
  // scale      - масштаб
  // precision  - разрешение растра
  // location   - привязка юго-западного угла растра в районе(в метрах)
  // При успешном завершении функция создает файл rstname с заполненным
  // паспортом и палитрой растра и добавляет его в цепочку растров
  // открытой векторной карты (hMap).
  // Возвращает  номер файла (начиная с 1) в цепочке растров открытой векторной карты
  // При ошибке возвращает ноль

_MAPIMP  long int _MAPAPI mapCreateAndAppendRst(HMAP hMap,const char * rstname,
                                long int width, long int height,
                                long int nbits,
                                COLORREF* palette, long int colorcount,
                                double scale, double precision,
                                DOUBLEPOINT location);


  // Создание файла растрового изображения                                      // 18/05/10
  // hMap       - идентификатор открытой векторной карты
  // rstname    - имя создаваемого файла
  // width      - ширина растрового изображения в элементах
  // height     - высота растрового изображения в элементах
  // nbits      - размер элемента (бит на пиксел)
  // palette    - адрес устанавливаемой палитры
  // colorcount - число элементов в новой палитре
  // scale      - масштаб
  // precision  - разрешение растра (точек на метр)
  // meterInElementX - размер пикселя растра в метрах на местности по оси X (по вертикали)
  // meterInElementY - размер пикселя растра в метрах на местности по оси Y (по горизонтали)
  //                   meterInElementX и meterInElementY могут иметь разные значения
  // location        - координаты юго-западного угла растра в метрах, соответствующие СК в mapregister
  // mapregister     - проекции исходного материала
  // Важно!!!
  // Для корректного открытия растров в 10-ой и более ранних версиях необходимо выполнить условие:
  //                            meterInElementX = scale/precision;
  // Иначе масштаб и разрешение будут пересчитаны!!!
  // При успешном завершении функция создает файл rstname с заполненным
  // паспортом и палитрой растра и добавляет его в цепочку растров
  // открытой векторной карты (hMap).
  // Возвращает  номер файла (начиная с 1) в цепочке растров открытой векторной карты
  // При ошибке возвращает ноль

_MAPIMP  long int _MAPAPI mapCreateAndAppendRstEx(HMAP hMap,const char * rstname,
                                long int width, long int height, long int nbits,
                                COLORREF* palette, long int colorcount,
                                double scale, double precision,
                                double meterInElementX, double meterInElementY,
                                DOUBLEPOINT* location, MAPREGISTEREX* mapregister);


  // Создание файла растрового изображения                                      // 01/03/12
  // hMap       - идентификатор открытой векторной карты
  // rstname    - имя создаваемого файла
  // width      - ширина растрового изображения в элементах
  // height     - высота растрового изображения в элементах
  // nbits      - размер элемента (бит на пиксел)
  // palette    - адрес устанавливаемой палитры
  // colorcount - число элементов в новой палитре
  // scale      - масштаб
  // precision  - разрешение растра (точек на метр)
  // meterInElementX - размер пикселя растра в метрах на местности по оси X (по вертикали)
  // meterInElementY - размер пикселя растра в метрах на местности по оси Y (по горизонтали)
  //                   meterInElementX и meterInElementY могут иметь разные значения
  // location        - координаты юго-западного угла растра в метрах, соответствующие СК в mapregister
  // mapregister     - указатель на структуру, содержащую параметры проекции исходного материала
  // datumparam      - указатель на структуру, содержащую коэффициенты трансформирования геодезических координат
  // ellipsoidparam  - указатель на структуру, содержащую параметры эллипсоида
  // Важно!!!
  // Для корректного открытия растров в 10-ой и более ранних версиях необходимо выполнить условие:
  //                            meterInElementX = scale/precision;
  // Иначе масштаб и разрешение будут пересчитаны!!!
  // При успешном завершении функция создает файл rstname с заполненным
  // паспортом и палитрой растра и добавляет его в цепочку растров
  // открытой векторной карты (hMap).
  // Возвращает  номер файла (начиная с 1) в цепочке растров открытой векторной карты
  // При ошибке возвращает ноль

_MAPIMP  long int _MAPAPI mapCreateAndAppendRaster(HMAP hMap, const char * rstname, // 01/03/12
                                long int width, long int height, long int nbits,
                                COLORREF* palette, long int colorcount,
                                double meterInElementX, double meterInElementY,
                                DOUBLEPOINT* location,
                                MAPREGISTEREX* mapregister, DATUMPARAM * datum, ELLIPSOIDPARAM * ellipsoid);


  // Оценка теорeтической длины файла растровой карты до ее создания  // 09/04/01
  // hMap       - идентификатор открытой векторной карты
  // width      - ширина растрового изображения в элементах
  // height     - высота растрового изображения в элементах
  // nbits      - размер элемента (бит на пиксел)
  // Возвращает  теорeтическую длину файла растровой карты (Байт)
  // При ошибке возвращает ноль

_MAPIMP  double _MAPAPI mapRstFileLengthCalculation(HMAP hMap, long int width,  // 04/09/03
                                                        long int height,
                                                        long int nbits);
  // Устаревшая функция
_MAPIMP  double _MAPAPI mapRtsFileLengthCalculation(HMAP hMap, long int width,
                                                        long int height,
                                                        long int nbits);


  // Запросить номер растра в цепочке по имени файла  // 28/04/10
  // name        - имя файла растра
  // В цепочке номера растров начинаются с 1.
  // При ошибке возвращает ноль

_MAPIMP  long int _MAPAPI mapGetRstNumberByName(HMAP hMap, const char* name);


  // Закрыть растровые данные в заданном районе работ
  // hMap   - идентификатор открытой векторной карты
  // number - номер растрового файла в цепочке
  // Если number == 0, закрываются все растровые данные
  // При ошибке возвращает ноль

_MAPIMP  long int _MAPAPI mapCloseRstForMap(HMAP hMap,
                                     long int number);


  // Закрыть растровые данные
  // hMap   - идентификатор открытой векторной карты
  // number - номер закрываемого растра
  // если number == 0, закрываются все растры в окне

_MAPIMP  void _MAPAPI mapCloseRst(HMAP hMap,
#ifdef __cplusplus  // 27/04/01
                           long int number = 0);  // 27/04/01
#else
                           long int number);  // 27/04/01
#endif


  // Запросить имя файла растровых данных
  // hMap   - идентификатор открытой векторной карты
  // number - номер файла в цепочке
  // При ошибке возвращает пустую строку

_MAPIMP  const char * _MAPAPI mapGetRstName(HMAP hMap,long int number);


  // Запросить имя файла растровых данных в кодировке UNICODE
  // hMap   - идентификатор открытой векторной карты
  // number - номер файла в цепочке
  // name - адрес строки для размещения результата
  // size - размер строки
  // При ошибке возвращает пустую строку

_MAPIMP  long int _MAPAPI mapGetRstNameUn(HMAP hMap,long int number,
                                          WCHAR * name, long int size);

                                          
  // Запросить число открытых файлов растровых данных
  // hMap    - идентификатор открытой векторной карты
  // При ошибке возвращает ноль

_MAPIMP  long int _MAPAPI mapGetRstCount(HMAP hMap);


  // Запрос текущего номера растра  // 06/05/00
  // hMap    - идентификатор открытой векторной карты
  // При ошибке возвращает ноль

_MAPIMP  long int _MAPAPI mapGetRstCurrentNumber(HMAP hMap);


  // Установка текущего номера растра  // 06/05/00
  // hMap    - идентификатор открытой векторной карты
  // number  - номер растра
  // При ошибке возвращает ноль

_MAPIMP  long int _MAPAPI mapSetRstCurrentNumber(HMAP hMap,long int number);


  // Запросить/Установить степень видимости растра
  //  hMap   - идентификатор открытой векторной карты
  //  number - номер файла в цепочке
  //  view = 0 - не виден
  //  view = 1 - полная видимость
  //  view = 2 - насыщенная
  //  view = 3 - полупрозрачная
  //  view = 4 - средняя
  //  view = 5 - прозрачная

_MAPIMP  long int _MAPAPI mapGetRstView(HMAP hMap,long int number);
_MAPIMP  long int _MAPAPI mapSetRstView(HMAP hMap,long int number,
                                           long int view);


  // Установить степень видимости группы растров
  //  userLabel  - пользовательская метка растра
  //                -1             - все растры
  //                RSW_QUALITY    - растры качеств
  //                RSW_VISIBILITY - растры видимости
  //                RSW_WEB        - растровые карты для WEB
  //  view - степень видимости
  //                0 - не виден
  //                1 - полная
  //                2 - насыщенная
  //                3 - полупрозрачная
  //                4 - средняя
  //                5 - прозрачная
  // При ошибке возвращает 0

_MAPIMP  long int _MAPAPI mapSetRstGroupView(HMAP hMap,long int userLabel,
                                                long int view);      // 27/05/08

  // Запросить/Установить порядок отображения растра
  // hMap   - идентификатор открытой векторной карты
  // number - номер растрового файла в цепочке
  //  (0 - под картой, 1 - над картой)
  // При ошибке возвращает 0

_MAPIMP  long int _MAPAPI mapSetRstViewOrder(HMAP hMap, long int number,
                                      long int order);
_MAPIMP  long int _MAPAPI mapGetRstViewOrder(HMAP hMap, long int number);


  // Поменять очередность отображения растров (rst) в цепочке  // 04/12/07
  // Последний растр в цепочке отображается в последнюю очередь
  // Нумерация растров в цепочке начинается с 1 и заканчивается номером mapGetRstCount(..)
  //   oldNumber - номер файла в цепочке
  //   newNumber - устанавливаемый номер файла в цепочке
  //  При ошибке возвращает 0

_MAPIMP long int _MAPAPI mapChangeOrderRstShow(HMAP hMap, long int oldNumber,
                                                          long int newNumber);

_MAPIMP  long int _MAPAPI mapChangOrderRstInChain(HMAP hMap, long int oldNumber,
                                                             long int newNumber);

  // Последовательный просмотр растров над картой
  // Если все растры отображаются под картой, то
  // первый растр будет отображен над картой. При следующем
  // вызове второй растр будет отображен над картой, остальные -
  // под картой. После последнего растра в списке над картой -
  // все растры под картой. Далее - опять первый растр над картой.
  // Возвращает номер растра отображаемого над картой или ноль.
  // Для получения результата на экране - карту нужно перерисовать
  // hMap    - идентификатор открытой векторной карты

_MAPIMP  long int _MAPAPI mapTurnRstViewOrder(HMAP hMap);


  // Запросить количество цветов в палитре растра
  // hMap   - идентификатор открытой векторной карты
  // number - номер файла в цепочке
  // При ошибке возвращается 0

_MAPIMP  long int _MAPAPI mapGetRstColorCount (HMAP hMap, long int number);


  // Запросить описание палитры растра
  // hMap    - идентификатор открытой векторной карты
  // palette - адрес области для размещения палитры
  // count   - число считываемых элементов палитры
  //           (если count > 256, то возвращается ноль)
  // number  - номер файла в цепочке
  // (размер области в байтах / 4)
  // При ошибке возвращает ноль

_MAPIMP  long int _MAPAPI mapGetRstPalette(HMAP hMap, COLORREF * palette,
                                    long int count,
                                    long int number);


  // Установить описание палитры растра
  // hMap    - идентификатор открытой векторной карты
  // palette - адрес устанавливаемой палитры
  // count   - число элементов в новой палитре
  // number  - номер файла в цепочке
  // Если palette равно 0, устанавливается палитра из заголовка  // 18/06/02
  // count не более 256
  // При ошибке возвращает ноль

_MAPIMP  long int _MAPAPI mapSetRstPalette(HMAP hMap, COLORREF * palette,
                                    long int count,
                                    long int number);


  // Запросить описание эталонной палитры растра
  // (без учета яркости и контрасности)
  // hMap    - идентификатор открытой векторной карты
  // palette - адрес области для размещения палитры
  // count   - число считываемых элементов палитры
  //           (если count > 256, то возвращается ноль)
  // number  - номер файла в цепочке
  // (размер области в байтах / 4)
  // При ошибке возвращает ноль

_MAPIMP  long int _MAPAPI mapGetRstStandardPalette(HMAP hMap, COLORREF * palette,
                                    long int count,
                                    long int number);


  // Запросить описание палитры из заголовка растра    // 12/10/09
  // hMap   - идентификатор открытой векторной карты
  // palette - адрес области для размещения палитры
  // count   - число считываемых элементов палитры
  //           (если count > 256, то возвращается ноль)
  // number  - номер файла в цепочке
  // (размер области в байтах / 4)
  // При ошибке возвращает ноль

_MAPIMP  long int _MAPAPI mapGetRstPaletteFromHeader(HMAP hMap, COLORREF * palette,
                                    long int count,
                                    long int number);

  // Запросить яркость палитры растра
  // hMap   - идентификатор открытой векторной карты
  // number - номер файла в цепочке

_MAPIMP  long int _MAPAPI mapGetRstBright (HMAP hMap,long int number);


  // Запросить контрастность палитры растра
  // hMap   - идентификатор открытой векторной карты
  // number - номер файла в цепочке

_MAPIMP  long int _MAPAPI mapGetRstContrast (HMAP hMap,long int number);


  // Запросить параболическую яркость растра
  // hMap   - идентификатор открытой векторной карты
  // number - номер файла в цепочке

_MAPIMP  long int _MAPAPI mapGetRstGamma (HMAP hMap,long int number);


  // Установить яркость палитры растра
  // hMap   - идентификатор открытой векторной карты
  // number - номер файла в цепочке
  // bright - яркость
  // При ошибке возвращает ноль

_MAPIMP  long int _MAPAPI mapSetRstBright (HMAP hMap, long int bright,
                                               long int number);


  // Установить контрастность палитры растра
  // hMap     - идентификатор открытой векторной карты
  // number   - номер файла в цепочке
  // contrast - контраст
  // При ошибке возвращает ноль

_MAPIMP  long int _MAPAPI mapSetRstContrast (HMAP hMap, long int contrast,
                                                 long int number);


  // Установить параболическую яркость растра
  // hMap   - идентификатор открытой векторной карты
  // number - номер файла в цепочке
  // gamma  - параболическая яркость
  // При ошибке возвращает ноль

_MAPIMP  long int _MAPAPI mapSetRstGamma (HMAP hMap, long int gamma,
                                              long int number);


  //  Обновить активную палитру с нулевой яркостью и контрастностью
  //  hMap   - идентификатор открытой векторной карты
  //  number - номер файла в цепочке
  //  При ошибке возвращает 0

_MAPIMP  long int _MAPAPI mapRestoreRstPalette(HMAP hMap, long int number);


  // Запросить значение инверсии растра
  // hMap   - идентификатор открытой векторной карты
  // number - номер файла в цепочке
  // Если изображение растра позитивное - возвращает ноль
  // Если изображение растра негативное - возвращает 1
  // При ошибке возвращает -1

_MAPIMP  long int _MAPAPI mapCheckInversionRst(HMAP hMap,long int number);


  // Инвертировать растровую карту
  // hMap   - идентификатор открытой векторной карты
  // number - номер файла в цепочке
  // value:
  // 0 - установить изображение растра позитивным
  // 1 - установить изображение растра негативным
  //  При ошибке возвращает 0

_MAPIMP  long int _MAPAPI mapInvertRst(HMAP hMap,long int number, long int value);


  // Запросить видимость цвета (для 16- и 256-цветных растров)  //16/05/00
  //  hMap   - идентификатор открытой векторной карты
  //  number - номер файла в цепочке
  //  index  - индекс цвета в палитре растра(начиная с 0)
  //  Возвращает: 1 - цвет с данным индексом отображается
  //              0 - цвет с данным индексом не отображается
  //  При ошибке возвращает -1

_MAPIMP  long int _MAPAPI mapCheckVisibilityColor(HMAP hMap, long int number,
                                                      long int index);


  // Установить видимость цвета (для 16- и 256-цветных растров)  //16/05/00
  //  hMap   - идентификатор открытой векторной карты
  //  number - номер файла в цепочке
  //  index  - индекс цвета в палитре растра(начиная с 0)
  //  value: 1 - включить отображение цвета с данным индексом
  //         0 - отключить отображение цвета с данным индексом
  //  Сохранение видимости цветов в INI-файле
  //                                  (не заносится в заголовк файла растра)
  //  При ошибке возвращает 0

_MAPIMP  long int _MAPAPI mapSetVisibilityColor(HMAP hMap, long int number,
                                                    long int index,
                                                    long int value);


  // Установить видимость цвета (для 16- и 256-цветных растров)  //30/10/02
  //  hMap   - идентификатор открытой векторной карты
  //  number - номер файла в цепочке
  //  index  - индекс цвета в палитре растра(начиная с 0)
  //  value: 1 - включить отображение цвета с данным индексом
  //         0 - отключить отображение цвета с данным индексом
  //  Сохранение видимости цветов в заголовке файла растра(а также в INI-файле)
  //  При ошибке возвращает 0

_MAPIMP  long int _MAPAPI mapSetVisibilityColorInRstFile(HMAP hMap, long int number,
                                                  long int index,
                                                  long int value);

  // Установить прозрачный цвет растра (для 16-,24-,32-битных растров)  //31/05/10
  //  hMap   - идентификатор открытой векторной карты
  //  number - номер файла в цепочке
  //  color  - значение прозрачного цвета в формате RGB (от 0 до 0x00FFFFFF)
  // При установке IMGC_TRANSPARENT (0xFFFFFFFF) прозрачный цвет не используется
  // При ошибке возвращает IMGC_TRANSPARENT

_MAPIMP  COLORREF _MAPAPI mapSetRstTransparentColor(HMAP hMap, long int number,
                                                    COLORREF color);


  // Запросить прозрачный цвет растра (для 16-,24-,32-битных растров)   //31/05/10
  //  hMap   - идентификатор открытой векторной карты
  //  number - номер файла в цепочке
  // Возвращает цвет в формате RGB (от 0 до 0x00FFFFFF)
  // При возврате IMGC_TRANSPARENT (0xFFFFFFFF) прозрачный цвет не используется
  // При ошибке возвращает IMGC_TRANSPARENT

_MAPIMP  COLORREF _MAPAPI mapGetRstTransparentColor(HMAP hMap, long int number);

  // Запросить типа и шаг маски растра  // 16/04/04
  // hMap      - идентификатор открытой векторной карты
  // maskType  - типа маски(0 - маска отсутствует)
  // maskStep  - шаг маски
  // number - номер файла в цепочке

_MAPIMP  long int _MAPAPI mapGetRstMaskType (HMAP hMap,long int number,
                                      long int* maskType, long int* maskStep);


  // Установить типа и шаг маски растра  // 16/04/04
  // hMap      - идентификатор открытой векторной карты
  // maskType  - типа маски(0 - маска отсутствует)
  // maskStep  - шаг маски
  // number - номер файла в цепочке

_MAPIMP  long int _MAPAPI mapSetRstMaskType (HMAP hMap,long int number,
                                      long int maskType, long int maskStep);


  // Установка взаимосвязанных параметров растра      // 01/06/10
  // scale           - знаминатель масштаба
  // precision       - разрешение (точек на метр)
  // meterinelementX - количества метров на элемент  ПО ОСИ X
  // meterinelementY - количества метров на элемент  ПО ОСИ Y
  // meterinelementX и meterinelementY могут отличаться
  // Важно!!!
  // Для правильного отображения растров в 10-ой и более ранних версиях необходимо:
  //                         meterinelementX = scale / precision;
  // Если условие не выполняется, то meterinelementX и meterinelementY игнорируются и расчитываются по формуле.
_MAPIMP  long int _MAPAPI mapSetRstParameters(HMAP hMap, long int number,
                                           double scale, double precision,
                                           double meterinelementX, double meterinelementY);

  // Установить масштаб растра
  // hMap       - идентификатор открытой векторной карты
  // number     - номер файла в цепочке
  // scale      - знаменатель масштаба
  // При ошибке возвращает 0

_MAPIMP  long int _MAPAPI mapSetRstScale(HMAP hMap,long int number,double scale);


  // Запросить масштаб растра
  // hMap       - идентификатор открытой векторной карты
  // number     - номер файла в цепочке
  // scale      - указатель переменной, куда вносится значение масштаба
  // При ошибке возвращает 0

_MAPIMP  long int _MAPAPI mapGetRstScale(HMAP hMap,long int number,double *scale);


  // Запросить значения масштаба нижней и верхней границ видимости растра
  // hMap       - идентификатор открытой векторной карты
  // number     - номер файла в цепочке
  // По адресу bottomScale записывается знаменатель масштаба нижней границы видимости растра
  // По адресу topScale записывается знаменатель масштаба верхней границы видимости растра
  // При ошибке возвращает 0

_MAPIMP  long int _MAPAPI mapGetRstRangeScaleVisible(HMAP hMap,long int number,
                       long int *bottomScale, long int *topScale);  // 08/12/03


  // Установить значения масштаба нижней и верхней границ видимости растра
  // hMap       - идентификатор открытой векторной карты
  // number     - номер файла в цепочке
  // bottomScale   - знаменатель масштаба нижней границы видимости растра
  // topScale   - знаменатель масштаба верхней границы видимости растра
  //              bottomScale <= topScale, иначе возвращает 0
  // При ошибке возвращает 0

_MAPIMP  long int _MAPAPI mapSetRstRangeScaleVisible(HMAP hMap,long int number,
                      long int bottomScale, long int topScale);   // 08/12/03


  // Установить разрешение растра
  // hMap       - идентификатор открытой векторной карты
  // number     - номер файла в цепочке
  // precision  - разрешение растра, полученное при сканировании (точек на метр)
  // При ошибке возвращает 0

_MAPIMP  long int _MAPAPI mapSetRstPrecision(HMAP hMap,long int number,double precision);


  // Запросить разрешение растра
  // hMap       - идентификатор открытой векторной карты
  // number     - номер файла в цепочке
  // precision  - разрешение растра (точек на метр)
  // При ошибке возвращает 0

_MAPIMP  long int _MAPAPI mapGetRstPrecision(HMAP hMap,long int number,double *precision);


  // Установить рамку растра по метрике замкнутого объекта
  // Замкнутый объект должен иметь не менее 4-х точек
  // hMap       - идентификатор открытой векторной карты
  // number     - номер файла в цепочке
  // info       - замкнутый объект карты
  // После выполнения функции отображение растра ограничится заданной областью
  // При ошибке возвращает 0

_MAPIMP  long int _MAPAPI mapSetRstBorder(HMAP hMap,long int number,HOBJ info);


  // Запросить объект рамки растра               // 15/03/01
  // hMap       - идентификатор открытой векторной карты
  // number     - номер файла в цепочке
  // info       - идентификатор объекта рамки
  // При ошибке возвращает ноль

_MAPIMP  long int _MAPAPI mapGetRstBorder(HMAP hMap,long int number,HOBJ info);


  // Удалить рамку растра
  // hMap       - идентификатор открытой векторной карты
  // number     - номер файла в цепочке
  // После выполнения функции отображение растра будет полным
  // При ошибке возвращает 0

_MAPIMP  long int _MAPAPI mapDeleteRstBorder(HMAP hMap,long int number);


  // Определение существования маски растра               // 24/06/09
  // hMap       - идентификатор открытой векторной карты
  // number     - номер файла в цепочке
  // При ошибке возвращает 0

_MAPIMP  long int _MAPAPI mapGetRstMask(HMAP hMap,long int number);

  // Определение способа отображения растра(относительно маски)  // 24/06/09
  // hMap       - идентификатор открытой векторной карты
  // number     - номер файла в цепочке
  // Возвращает 1 - при отображении растра по маске
  //            0 - при отображении растра без учета маски
  // При ошибке возвращает 0

_MAPIMP  long int _MAPAPI mapGetShowRstByMask(HMAP hMap,long int number);

  // Установка отображения растра по маске                      // 24/06/09
  // hMap       - идентификатор открытой векторной карты
  // number     - номер файла в цепочке
  // value  = 1 - отобразить растр по маске
  //        = 0 - отобразить растр без учета маски

_MAPIMP  long int _MAPAPI mapSetShowRstByMask(HMAP hMap,long int number, long int value);

  // Определение существования рамки растра
  // hMap       - идентификатор открытой векторной карты
  // number     - номер файла в цепочке
  // При ошибке возвращает 0

_MAPIMP  long int _MAPAPI mapCheckExistenceRstBorder(HMAP hMap,long int number);


  // Установка отображения растра по рамке
  // hMap       - идентификатор открытой векторной карты
  // number     - номер файла в цепочке
  // value  = 1 - отобразить растр по рамке
  //        = 0 - отобразить растр без учета рамки

_MAPIMP  long int _MAPAPI mapShowRstByBorder(HMAP hMap,long int number, long int value);

  // Определение способа отображения растра(относительно рамки)
  // hMap       - идентификатор открытой векторной карты
  // number     - номер файла в цепочке
  // Возвращает 1 - при отображении растра по рамке
  //            0 - при отображении растра без учета рамки
  // При ошибке возвращает -1

_MAPIMP  long int _MAPAPI mapCheckShowRstByBorder(HMAP hMap,long int number);

  // Определить координаты точки рамки, которая  // 02/10/03
  // входит в прямоугольник Габариты растра(матрицы) и
  // имеет наименьшее удаление от точки pointIn (координаты в метрах).
  // hMap       - идентификатор открытой векторной карты
  // number     - номер файла в цепочке
  // По адресу pointOut записываются координаты найденной точки в метрах
  // При ошибке или отсутствии рамки возвращает 0.

_MAPIMP  long int _MAPAPI mapGetImmediatePointOfRstBorder(HMAP hMap, long int number,
                                           DOUBLEPOINT* pointIn,
                                           DOUBLEPOINT* pointOut);


  // Запросить данные о проекции растра  // 11/04/06
  // number      - номер файла в цепочке
  // mapregister - адрес структуры, в которой будут размещены
  // данные о проекции
  // При ошибке возвращает ноль

_MAPIMP  long int _MAPAPI mapGetRstProjectionData(HMAP hMap, int number,
                                                  MAPREGISTEREX* mapregister);


  // Запросить данные о проекции растра по имени файла  // 08/11/06
  // name        - имя файла растра
  // mapregister - адрес структуры, в которой будут размещены
  // данные о проекции
  // При ошибке возвращает ноль

_MAPIMP  long int _MAPAPI mapGetRstProjectionDataByName(const char* name,
                                                  MAPREGISTEREX* mapregister);

  // Установить данные о проекции растра  // 11/04/06
  // number - номер файла в цепочке
  // mapregister - адрес структуры
  // При ошибке возвращает ноль

_MAPIMP  long int _MAPAPI mapSetRstProjectionData(HMAP hMap, int number,
                                                  MAPREGISTEREX* mapregister);

  // Запросить параметры эллипсоида растра
  // hMap   - идентификатор открытой основной векторной карты
  // number - номер файла растра в цепочке
  // ellipsoidparam - адрес структуры, в которой будут размещены
  // параметры эллипсоида
  // Структурa ELLIPSOIDPARAM описанa в mapcreat.h
  // При ошибке возвращает ноль

_MAPIMP long int _MAPAPI mapGetRstEllipsoidParam(HMAP hMap, long int number,  // 14/07/10
                                                 ELLIPSOIDPARAM * ellipsoidparam);

  // Установить параметры эллипсоида растра
  // hMap    - идентификатор открытой основной векторной карты
  // number  - номер файла растра в цепочке.
  // ellipsoidparam - адрес структуры, содержащей параметры эллипсоида
  // Структурa ELLIPSOIDPARAM описанa в mapcreat.h
  // При ошибке возвращает ноль

_MAPIMP long int _MAPAPI mapSetRstEllipsoidParam(HMAP hMap, long int number,  // 14/07/10
                                                 const ELLIPSOIDPARAM * ellipsoidparam);

  // Запросить коэффициенты трансформирования геодезических координат растра
  // hMap   - идентификатор открытой основной векторной карты
  // number - номер файла растра в цепочке
  // datumparam - адрес структуры, в которой будут размещены
  // коэффициенты трансформирования геодезических координат
  // Структурa DATUMPARAM описанa в mapcreat.h
  // При ошибке возвращает ноль

_MAPIMP long int _MAPAPI mapGetRstDatumParam(HMAP hMap, long int number,  // 14/07/10
                                             DATUMPARAM * datumparam);

  // Установить коэффициенты трансформирования геодезических координат растра
  // hMap    - идентификатор открытой основной векторной карты
  // number  - номер файла растра в цепочке.
  // datumparam - адрес структуры, содержащей коэффициенты трансформирования
  // геодезических координат
  // Структурa DATUMPARAM описанa в mapcreat.h
  // При ошибке возвращает ноль

_MAPIMP long int _MAPAPI mapSetRstDatumParam(HMAP hMap, long int number,  // 14/07/10
                                             const DATUMPARAM * datumparam);

  // Запросить габариты растра в метрах в районе работ
  // hMap       - идентификатор открытой векторной карты
  // number     - номер файла в цепочке
  // frame      - возвращаемые габариты растра
  // При ошибке возвращает ноль

_MAPIMP  long int _MAPAPI mapGetRstFrameMeters(HMAP hMap,DFRAME *frame, long int number);


  // Запросить фактические габариты отображаемого растра в метрах в районе работ   // 14/05/03
  // При отображение растра по рамке возвращаются габариты рамки
  // hMap       - идентификатор открытой векторной карты
  // number     - номер файла в цепочке
  // frame      - возвращаемые габариты растра
  // При ошибке возвращает ноль

_MAPIMP  long int _MAPAPI mapGetActualRstFrame(HMAP hMap,DFRAME *frame, long int number);


  // Установить привязку растра в районе работ(в метрах)
  // hMap       - идентификатор открытой векторной карты
  // number     - номер файла в цепочке
  // location   - координаты юго-западного угла растра(в метрах)
  // При ошибке возвращает 0

_MAPIMP  long int _MAPAPI mapSetRstLocation(HMAP hMap,long int number, DOUBLEPOINT* location);


  // Запросить привязку растра в районе работ(в метрах)
  // hMap       - идентификатор открытой векторной карты
  // number     - номер файла в цепочке
  // location   - координаты юго-западного угла растра(в метрах)
  // При ошибке возвращает 0

_MAPIMP  long int _MAPAPI mapGetRstLocation(HMAP hMap,long int number, DOUBLEPOINT *location);


  // Запросить флаг существования привязки растра
  // hMap       - идентификатор открытой векторной карты
  // number     - номер файла в цепочке
  // При ошибке возвращает 0

_MAPIMP  long int _MAPAPI mapCheckExistenceRstLocation(HMAP hMap,long int number);




  //**********************************************************************
  // Как подвинуть растр на отрезок (Dx,Dy)?
  //    Запросите привязку растра - mapGetRstLocation(...)
  //    Измените точку привязки на отрезок (Dx,Dy)
  //    Установите новую точку привязки - mapSetRstLocation(...)
  //    Перерисуйте окно.
  //**********************************************************************
  // Как подвинуть растр с изменением масштаба ?
  //    Запросите привязку растра - mapGetRstLocation(...)
  //    Запросите знаменатель масштаба растра - mapGetRstScale(...)
  //    Измените точку привязки и расчитайте знаменатель масштаба
  //    Установите новую точку привязки - mapSetRstLocation(...)
  //    Установите новый знаменатель масштаба - mapSetRstScale(...)
  //    Перерисуйте окно.
  //**********************************************************************

  // 05/05/10  Устаревшая функция
  // Запросить размер элемента растра в метрах на местности
  // hMap       - идентификатор открытой векторной карты
  // number     - номер файла в цепочке
  // metinelem  - размер элемента растра в метрах на местности
  // При ошибке возвращает ноль

_MAPIMP  long int _MAPAPI mapGetRstMeterInElement(HMAP hMap,long int number,double *metinelem);

  // Запросить размер элемента растра в метрах по оси X // 05/05/10
  // number    - номер файла в цепочке
  // metinelemX - размер элемента растра в метрах на местности по оси X
  // При ошибке возвращает ноль
_MAPIMP  long int _MAPAPI mapGetRstMeterInElementX(HMAP hMap,long int number, double *metinelemX);

  // Запросить размер элемента растра в метрах по оси Y // 05/05/10
  // number    - номер файла в цепочке
  // metinelemY - размер элемента растра в метрах на местности по оси Y
  // При ошибке возвращает ноль
_MAPIMP  long int _MAPAPI mapGetRstMeterInElementY(HMAP hMap,long int number, double *metinelemY);

  // 05/05/10  Устаревшая функция
  // Запросить размер точки экрана в элементах растра
  // hMap       - идентификатор открытой векторной карты
  // number     - номер файла в цепочке
  // eleminpix  - размер точки экрана в элементах растра
  // При ошибке возвращает ноль

_MAPIMP  long int _MAPAPI mapGetSizeRstElemInPix(HMAP hMap,long int number,double *eleminpix);

  // Запросить размер элемента растра в пикселах экрана по оси X  // 05/05/10
  // number - номер файла в цепочке
  // При ошибке возвращает ноль
_MAPIMP  long int _MAPAPI mapGetSizeRstElemXInPix(HMAP hMap,long int number,double *eleminpix);

  // Запросить размер элемента растра в пикселах экрана по оси Y  // 05/05/10
  // number - номер файла в цепочке
  // При ошибке возвращает ноль
_MAPIMP  long int _MAPAPI mapGetSizeRstElemYInPix(HMAP hMap,long int number,double *eleminpix);

  // Запросить ширину растра в элементах
  // hMap       - идентификатор открытой векторной карты
  // number     - номер файла в цепочке
  // При ошибке возвращает ноль

_MAPIMP  long int _MAPAPI mapGetRstWidth(HMAP hMap,long int number);


  // Запросить высоту растра в элементах
  // hMap       - идентификатор открытой векторной карты
  // number     - номер файла в цепочке
  // При ошибке возвращает ноль

_MAPIMP  long int _MAPAPI mapGetRstHeight(HMAP hMap,long int number);


  // Запросить объем растра в байтах        // 18/06/01
  // hMap       - идентификатор открытой векторной карты
  // number     - номер файла в цепочке
  // При ошибке возвращает ноль

_MAPIMP  unsigned long int _MAPAPI mapGetRstLength(HMAP hMap,long int number);


  // Запросить размер элемента растра в битах
  // hMap       - идентификатор открытой векторной карты
  // number     - номер файла в цепочке
  // При ошибке возвращает ноль

_MAPIMP  long int _MAPAPI mapGetRstElementSize(HMAP hMap,long int number);


  // Запросить флаг редактируемости растра
  // hMap       - идентификатор открытой векторной карты
  // number     - номер файла в цепочке
  // При ошибке возвращает ноль

_MAPIMP  long int _MAPAPI mapGetRstEdit(HMAP hMap,long int number);
_MAPIMP  long int _MAPAPI mapCheckRstEdit(HMAP hMap,long int number);


  // Запросить номер алгоритма сжатия растра (0 - растр не сжат)
  // hMap       - идентификатор открытой векторной карты
  // number     - номер файла в цепочке
  // При ошибке возвращает ноль

_MAPIMP  long int _MAPAPI mapCheckRstCompressNumber(HMAP hMap,long int number);


  // Чтение элемента по абсолютным индексам
  // hMap       - идентификатор открытой векторной карты
  // number     - номер файла в цепочке
  // string, column - строка и столбец элемента
  // value      - значение элемента
  // При ошибке возвращает ноль

_MAPIMP  long int _MAPAPI mapGetRstPoint(HMAP hMap, long int number,long int *value, long int string, long int column);


  // Запись элемента по абсолютным индексам
  // hMap       - идентификатор открытой векторной карты
  // number     - номер файла в цепочке
  // string, column - строка и столбец элемента
  // value      - значение элемента
  // При ошибке возвращает ноль

_MAPIMP  long int _MAPAPI mapPutRstPoint(HMAP hMap, long int number,long int value, long int string, long int column);


  // Чтение элемента  по его прямоугольным координатам
  // (в метрах) из буфера
  // hMap       - идентификатор открытой векторной карты
  // number     - номер файла в цепочке
  // x,y        - координаты элемента
  // value      - значение элемента
  // При ошибке возвращает ноль

_MAPIMP  long int _MAPAPI mapGetRstPlanePoint(HMAP hMap, long int number,long int *value, double x, double y);


  // Чтение элемента по его прямоугольным координатам по методу треугольников
  // hMap       - идентификатор открытой векторной карты
  // number     - номер файла в цепочке
  // x,y        - координаты элемента
  // value      - значение элемента
  // При ошибке возвращает ноль              // 12/11/02

_MAPIMP  long int _MAPAPI mapGetRstPlanePointTriangle(HMAP hMap, long int number,long int *value, double x, double y);


  // Определение цвета точки растра по прямоугольным координатам точки // 19/03/02
  // (в метрах)
  // hMap       - идентификатор открытой векторной карты
  // number     - номер файла в цепочке
  // x,y        - координаты элемента
  // color      - цвет элемента
  // При ошибке возвращает ноль

_MAPIMP long int _MAPAPI mapGetRstPlanePointColor(HMAP hMap, long int number,
                                                  COLORREF* color, double x, double y);

 // Билинейная интерполяция - определение цвета точки по 4 соседним пикселям растра //12/08/10
 // hMap       - идентификатор открытой векторной карты
 // number     - номер файла в цепочке
 // color      - заполняется вычисленным цветом
 // indexColor - заполняется индексом ближайшего цвета к вычисленному из палитры растра
 //              (для 1,4 и 8 бит на пиксель)
 // x, y       - прямоугольные координаты точки в системе координат растра в метрах на местности
 // При попадании в крайние пиксели растра возвращается цвет ближайшего пикселя
 // При ошибке возвращает ноль

_MAPIMP long int _MAPAPI mapGetRstBilinearInterpolationColor(HMAP hMap, long int number,
                                                             COLORREF* color, long int *indexcolor,
                                                             double x, double y);

 // Бикубическая интерполяция - определение цвета точки по 16 соседним пикселям растра //12/08/10
 // hMap       - идентификатор открытой векторной карты
 // number     - номер файла в цепочке
 // color      - заполняется вычисленным цветом
 // indexColor - заполняется индексом ближайшего цвета к вычисленному из палитры растра
 //              (для 1,4 и 8 бит на пиксель)
 // x, y       - прямоугольные координаты точки в системе координат растра в метрах на местности
 // При попадании в крайних 2 пикселя растра возвращается цвет ближайшего пикселя
 // При ошибке возвращает ноль

_MAPIMP long int _MAPAPI mapGetRstBicubicInterpolationColor(HMAP hMap, long int number,
                                                            COLORREF* color, long int *indexcolor,
                                                            double x, double y);

  // Запись элемента  по его прямоугольным координатам
  // (в метрах) в буфер
  // hMap       - идентификатор открытой векторной карты
  // number     - номер файла в цепочке
  // x,y        - координаты элемента
  // value      - значение элемента
  // При ошибке возвращает ноль

_MAPIMP  long int _MAPAPI mapPutRstPlanePoint(HMAP hMap, long int number,long int value, double x, double y);


  // Запись отрезка в изображение основного растра по прямоугольным координатам (в метрах)  // 16/04/04
  // hMap       - идентификатор открытой векторной карты
  // number     - номер файла в цепочке
  // color - цвет отрезка типа COLORREF для растров с 16,24,32 точек на пиксель;
  //         индекс цвета в палитре для растров с 1,4,8 точек на пиксель.
  //  point1 - координаты начальной точки отрезка
  //  point2 - координаты конечной точки отрезка
  // При ошибке возвращает ноль

_MAPIMP  long int _MAPAPI mapPutRstPlaneLine(HMAP hMap, long int number, long color,
                                             DOUBLEPOINT *point1, DOUBLEPOINT *point2);


  // Запросить количество блоков растра
  // hMap       - идентификатор открытой векторной карты
  // number     - номер файла в цепочке
  // При ошибке возвращает ноль

_MAPIMP  long int _MAPAPI mapGetRstBlockCount(HMAP hMap,long int number);


  // Запросить число строк блоков растра
  // hMap       - идентификатор открытой векторной карты
  // number     - номер файла в цепочке
  // При ошибке возвращает ноль

_MAPIMP  long int _MAPAPI mapGetRstBlockRow(HMAP hMap,long int number);


  // Запросить число столбцов блоков растра
  // hMap       - идентификатор открытой векторной карты
  // number     - номер файла в цепочке
  // При ошибке возвращает ноль

_MAPIMP  long int _MAPAPI mapGetRstBlockColumn(HMAP hMap,long int number);


  // Запросить размер неусеченного блока растра в байтах
  // hMap       - идентификатор открытой векторной карты
  // number     - номер файла в цепочке
  // При ошибке возвращает ноль

_MAPIMP  long int _MAPAPI mapGetRstBlockSize(HMAP hMap,long int number);


  // Запросить размер текущего блока {string,column} растра в байтах
  // (с учетом усеченных блоков)
  // hMap       - идентификатор открытой векторной карты
  // number     - номер файла в цепочке
  // string, column - координаты блока
  // При ошибке возвращает ноль

_MAPIMP  long int _MAPAPI mapGetRstCurrentBlockSize(HMAP hMap,long int number,
                                             long int string,long int column);


  // Запросить ширину неусеченного блока растра в элементах
  // hMap       - идентификатор открытой векторной карты
  // number     - номер файла в цепочке
  // При ошибке возвращает ноль

_MAPIMP  long int _MAPAPI mapGetRstBlockWidth(HMAP hMap,long int number);


  // Запросить высоту неусеченного блока растра в элементах
  // hMap       - идентификатор открытой векторной карты
  // number     - номер файла в цепочке
  // При ошибке возвращает ноль

_MAPIMP  long int _MAPAPI mapGetRstBlockHeight(HMAP hMap,long int number);


  // Запросить ширину текущего блока {string,column} растра в элементах
  // (с учетом усеченных блоков)
  // hMap       - идентификатор открытой векторной карты
  // number     - номер файла в цепочке
  // column     - столбец блока
  // При ошибке возвращает ноль

_MAPIMP  long int _MAPAPI mapGetRstCurrentBlockWidth(HMAP hMap,long int number,
                                              long int column);


  // Запросить высоту текущего блока {string,column} растра в элементах
  // (с учетом усеченных блоков)
  // hMap       - идентификатор открытой векторной карты
  // number     - номер файла в цепочке
  // string     - строка блока
  // При ошибке возвращает ноль

_MAPIMP  long int _MAPAPI mapGetRstCurrentBlockHeight(HMAP hMap,long int number,
                                               long int string);


  // Запросить адрес блока растра по номеру строки и столбца
  // Блоки последнего ряда могут иметь усеченный размер
  // hMap       - идентификатор открытой векторной карты
  // number     - номер файла в цепочке
  // string     - строка блока
  // column     - столбец блока
  // При запросе следующего блока может вернуть прежний адрес
  // При ошибке возвращает ноль, иначе - адрес считанного блока

_MAPIMP  char *  _MAPAPI mapGetRstBlock(HMAP hMap,long int number,
                                 long int string,
                                 long int column);


  // Запросить адрес блока растра по номеру строки и столбца
  // При отсутствии в файле - создается
  // При запросе следующего блока может вернуть прежний адрес
  // hMap       - идентификатор открытой векторной карты
  // number     - номер файла в цепочке
  // string     - строка блока
  // column     - столбец блока
  // При ошибке возвращает ноль
_MAPIMP  char *  _MAPAPI mapGetRstBlockAndCreate(HMAP hMap,long int number,
                                 long int string,
                                 long int column);


  // Запросить наличие блока растра в файле
  // hMap       - идентификатор открытой векторной карты
  // number     - номер файла в цепочке
  // i          - порядковый номер блока
  // При ошибке возвращает ноль

_MAPIMP  long int _MAPAPI mapCheckRstBlockExistence(HMAP hMap,long int number,long int i);


  // Возврат флага отображения блока
  // (0 - не отображается, 1- отображается, 2 - разделен рамкой )
  // hMap       - идентификатор открытой векторной карты
  // number     - номер файла в цепочке
  // i          - порядковый номер блока
  // При ошибке возвращает ноль

_MAPIMP  long int _MAPAPI mapCheckRstBlockVisible(HMAP hMap,long int number,long int i);  // 09/04/01


  // Запись блока {string,column} в файл растрового изображения  из памяти bits.
  // hMap       - идентификатор открытой векторной карты
  // number     - номер файла в цепочке
  // string     - строка блока
  // column     - столбец блока
  // bits       - указатель на начало изображения битовой области
  // sizebits   - размер области bits в байтах
  // Возвращает количество записанных байт.
  // При ошибке возвращает ноль.

_MAPIMP  long int _MAPAPI mapWriteRstBlock(HMAP hMap,long int number,
                                long int string, long int column,
                                char * bits, long int sizebits);


  // Запись блока {string,column} размером "size" по DIB-маске "mask"
  // индексом "value"
  // hMap       - идентификатор открытой векторной карты
  // number     - номер файла в цепочке
  // string     - строка блока
  // column     - столбец блока
  // mask       - указатель на начало маски
  // size       - размер области mask в байтах
  // При ошибке возвращает ноль

_MAPIMP  long int _MAPAPI mapPutRstBlockByMask(HMAP hMap,long int number,
                                long int string, long int column,
                                char* mask, long int size,
                                long int width,long int height,
                                long value);


  // Записать изменения растра в файл
  // hMap       - идентификатор открытой векторной карты
  // number     - номер файла в цепочке
  // При ошибке возвращает ноль

_MAPIMP  long int _MAPAPI mapSaveRst(HMAP hMap,long int number);


  // Запись прямоугольного участка растра
  //  hMap    - идентификатор открытой векторной карты
  //  number  - номер файла в цепочке
  //  bits    - указатель на начало изображения битовой области
  //  left    - смещение слева в элементах (выравнено на границу байта)
  //  top     - смещение сверху в элементах
  //  width   - ширина в элементах (выравнено на границу байта)
  //  height  - высота в элементах
  //  begining  - начало изображения:
  //    ==  1  - (bits - указатель на первую строку битовой области)
  //    == -1  - (bits - указатель на послелнюю строку битовой области,
  //                           в BMP изображение хранится снизу - вверх)
  //  widthinbyte    - ширину прямоугольного участка растра в байтах
  // Принцип выравнивания:
  //  при ElementSize() == 1 (бит) - left,width кратны 8,
  //                    == 4 (бит) - left,width кратны 2
  // При ошибке возвращает 0

_MAPIMP  long int _MAPAPI mapPutRstFrame(HMAP hMap, long int number, char* bits,
                                  long int left, long int top,
                                  long int width, long int height,
                                  long int begining/* = 1*/,
                                  long int widthinbyte /*= 0*/);  // 27/04/01

  // Чтение прямоугольного участка растра
  //  hMap       - идентификатор открытой векторной карты
  //  number     - номер файла в цепочке
  //  bits    - указатель на начало изображения битовой области
  //  left    - смещение слева в элементах (выравнено на границу байта)
  //  top     - смещение сверху в элементах
  //  width   - ширина в элементах (выравнено на границу байта)
  //  height  - высота в элементах
  //  widthinbyte    - ширину прямоугольного участка растра в байтах
  // Принцип выравнивания:
  //  при ElementSize() == 1 (бит) - left,width кратны 8,
  //                    == 4 (бит) - left,width кратны 2
  // При ошибке возвращает 0

_MAPIMP  long int _MAPAPI mapGetRstFrame(HMAP hMap, long int number, char* bits,
                                  long int left, long int top,
                                  long int width, long int height,
                                  long int widthinbyte = 0);

  // Чтение цветовых плоскостей прямоугольного участка растра
  //  hMap       - идентификатор открытой векторной карты
  //  number     - номер файла в цепочке
  //  bitsR,bitsG - указатели на начало изображения байтовых областей
  //  bitsB         красной, зеленой и синей плоскости
  //  left    - смещение слева в элементах
  //  top     - смещение сверху в элементах
  //  width   - ширина в элементах
  //  height  - высота в элементах
  //  Поддерживает только 8-битные растры (пока)
  // При ошибке возвращает 0

_MAPIMP  long int _MAPAPI mapGetRstFrameRGB(HMAP hMap, long int number,
                          char* bitsR, char* bitsG, char* bitsB,
                          long int left, long int top,
                          long int width, long int height);


  // Отображение прямоугольного участка исходного растра    22/05/03
  // в результирующем растре, расположенном в области памяти.
  //   hMap   - идентификатор открытой векторной карты
  //   number - номер файла в цепочке
  //   bits   - указатель на начало области памяти;
  //   width  - ширина области памяти в элементах COLORREF
  //            (количество столбцов результирующего растра);
  //   height - высота области памяти в элементах
  //            (количество строк результирующего растра);
  //   StrL,ColL,StrR,ColR - координаты левого и правого элементов
  //                         исходного растра, которые определяют
  //                         верхний граничный отрезок прямоугольного
  //                         участка.
  // При ошибке возвращает ноль.

_MAPIMP  long int _MAPAPI mapGetRstFrameTurn(HMAP hMap,        // 22/05/03
                      long int number, COLORREF* bits,
                      long int width, long int height,
                      double StrL, double ColL,
                      double StrR, double ColR);


  // Пересчитать элементы растра в пикселы 
  // для текущего масштаба отображения
  // hMap       - идентификатор открытой векторной карты
  // number     - номер файла в цепочке
  // element    - элементы растра
  // pixel      - результат в пикселах
  // При ошибке возвращает ноль

_MAPIMP  long int _MAPAPI mapRstElementToPixel(HMAP hMap, long int number,
                                        double element,double *pixel);


  // Пересчитать пикселы в элементы растра
  // для текущего масштаба отображения
  // hMap       - идентификатор открытой векторной карты
  // number     - номер файла в цепочке
  // element    - результат в элементах растра
  // pixel      - пикселы
  // При ошибке возвращает ноль

_MAPIMP  long int _MAPAPI mapPixelToRstElement(HMAP hMap, long int number,
                                        double pixel, double *element);


  // Формирование битовой маски текущего блока {string,column} // 26/06/01
  // с учетом рамки растра
  // hMap       - идентификатор открытой векторной карты
  // number     - номер файла в цепочке
  // string     - строка блока
  // column     - столбец блока
  // bits       - область битовой маски
  // size       - размер области битовой маски в байтах
  // При ошибке возвращает ноль

_MAPIMP  long int _MAPAPI mapBuildRstBlockMask(HMAP hMap, long int number,
                                        char * bits, long int size,
                                        long int string, long int column);

  // Установить маску изображения растра по метрике объекта    // 09/11/04
  // hMap       - идентификатор открытой векторной карты
  // number     - номер файла в цепочке
  // info       - объект карты с подобъектами
  // После выполнения функции отображение растра ограничится заданной областью
  // При ошибке возвращает 0

_MAPIMP  long int _MAPAPI mapSetRstMask(HMAP hMap,long int number,HOBJ info);

  // Заливка цветом части растра, ограниченной рамкой.  // 12/07/05
  // hMap       - идентификатор открытой векторной карты
  // number     - номер файла в цепочке
  // При ошибке возвращает 0

_MAPIMP  long int _MAPAPI mapFillRstVisiblePart (HMAP hMap, long int number, long int color);

  // Обновить уменьшенную копию   // 26/11/04
  // Если уменьшенные копии не существуют, создаются ДВЕ копии   
  // hMap   - идентификатор открытой векторной карты
  // number - номер файла в цепочке

_MAPIMP  long int _MAPAPI mapUpdateRstDuplicates (HMAP hMap, long int number);

  // Обновить уменьшенную копию блока (string,column) растра       // 04/10/09
  // При ошибке возвращает ноль

_MAPIMP  long int _MAPAPI mapUpdateRstDuplicateOfBlock(HMAP hMap, long int number,
                                          int string, int column);

  // Запросить пользовательский идентификатор растра
  // number    - номер файла в цепочке
  // При ошибке возвращает ноль

_MAPIMP  long int _MAPAPI mapGetRstUserLabel(HMAP hMap, long int number);   // 27/05/08

  // Установить пользовательский идентификатор растра
  // number    - номер файла в цепочке
  // userLabel - идентификатор модели
  // При ошибке возвращает ноль

_MAPIMP  long int _MAPAPI mapSetRstUserLabel(HMAP hMap, long int number,
                                             long int userLabel);           // 27/05/08

  // Запросить координаты Юго-Западного угла растра в метрах
  // hMap    - идентификатор открытой основной векторной карты
  // number  - номер файла в цепочке
  // По адресу x,y записываются координаты найденной точки в метрах
  // При ошибке возвращает 0

_MAPIMP long int _MAPAPI mapWhereSouthWestRstPlane(HMAP hMap,long int number,
                                                   double * x, double * y);  // 24/06/09

  // Удалить файл RSW
  // Функция предназначена для удаления растра и его составных частей
  // Растровая карта размером более 4Gb состоит из 2-х файлов: *.rsw и *.rsw.01
  // Анолог функции DeleteTheFile()
_MAPIMP  long int _MAPAPI mapDeleteRstFile(const char * name);       // 26/11/08

  // Переименовать имя файла RSW
  // Функция предназначена для переименовывания растра и его составных частей
  // Растровая карта размером более 4Gb состоит из 2-х файлов: *.rsw и *.rsw.01
  // Анолог функции MoveTheFile()

_MAPIMP  long int _MAPAPI mapMoveRstFile(const char * oldname,const char * newname); // 26/11/08

  // Скопировать файл RSW
  // Функция предназначена для копирования растра и его составных частей
  // Растровая карта размером более 4Gb состоит из 2-х файлов: *.rsw и *.rsw.01
  // Анолог функции CopyTheFile()

_MAPIMP  long int _MAPAPI mapCopyRstFile(const char * oldname, const char * newname, int exist = 0); // 26/11/08

  // Установить систему координат отрисовки TIFF-растров  // 23/06/11

_MAPIMP  long int _MAPAPI mapSetRstPaintCoordSys(HMAP hMap, MAPREGISTEREX* mapreg,
                                                 DATUMPARAM * datum, ELLIPSOIDPARAM * ellipsoid);

  // Запросить тип растра   // 31/08/11
  // hMap   - идентификатор открытой векторной карты
  // number - номер файла в цепочке
  // Возвращает: 0 - обычный растр
  //             1 - растр-пустышка с прямым доступом к файлу TIFF

_MAPIMP  long int _MAPAPI mapRstIsAccessTiff(HMAP hMap, long int number);

  // Запросить имя TIFF-файла для растра с номером  number                      
  // hMap   - идентификатор открытой векторной карты
  // number - номер файла в цепочке

_MAPIMP  long int _MAPAPI mapGetRstFileName_Tiff(HMAP hMap, long int number, char * name);

  // Запросить количество каналов TIFF-растра с номером  number                      
  // hMap   - идентификатор открытой векторной карты
  // number - номер файла в цепочке

_MAPIMP  long int _MAPAPI mapGetRstBandCount_Tiff(HMAP hMap, long int number);

  // Запросить номер канала TIFF-растра с номером  number, отображаемого красным  
  // hMap   - идентификатор открытой векторной карты
  // number - номер файла в цепочке

_MAPIMP  long int _MAPAPI mapGetRstRedBand_Tiff(HMAP hMap, long int number);

  // Запросить номер канала TIFF-растра с номером  number, отображаемого зеленым  
  // hMap   - идентификатор открытой векторной карты
  // number - номер файла в цепочке

_MAPIMP  long int _MAPAPI mapGetRstGreenBand_Tiff(HMAP hMap, long int number);

  // Запросить номер канала TIFF-растра с номером  number, отображаемого синим  
  // hMap   - идентификатор открытой векторной карты
  // number - номер файла в цепочке

_MAPIMP  long int _MAPAPI mapGetRstBlueBand_Tiff(HMAP hMap, long int number);

  // Установить номер канала TIFF-растра с номером  number, отображаемого красным  
  // (если установить -1, то такой канал не используется)
  // hMap   - идентификатор открытой векторной карты
  // number - номер файла в цепочке

_MAPIMP  long int _MAPAPI mapSetRstRedBand_Tiff(HMAP hMap, long int number, int redband);

  // Установить номер канала TIFF-растра с номером  number, отображаемого зеленым  
  // (если установить -1, то такой канал не используется)
  // hMap   - идентификатор открытой векторной карты
  // number - номер файла в цепочке

_MAPIMP  long int _MAPAPI mapSetRstGreenBand_Tiff(HMAP hMap, long int number, int greenband);

  // Установить номер канала TIFF-растра с номером  number, отображаемого синим  
  // (если установить -1, то такой канал не используется)
  // hMap   - идентификатор открытой векторной карты
  // number - номер файла в цепочке

_MAPIMP  long int _MAPAPI mapSetRstBlueBand_Tiff(HMAP hMap, long int number, int blueband);

  // Установить отображение мультиспектрального растра по вегетационному индексу  
  // Перед вызовом необходимо убедиться при помощи функции mapRstIsAccessTiff, что
  // для растра с номером number осуществляется прямой доступ к файлу TIFF
  // Функция справедлива для мультиспектральных изображений (mapGetRstBandCount_Tiff() >= 3)

_MAPIMP long int _MAPAPI mapSetRstVegIndex_Tiff(HMAP hMap, long int number, VEGINDEX *vegindex);

  // Возвращает параметры отображения вегетационного индекса  
  // Если отображение по вегетационному индексу не установлено возвращает 0
  // Перед вызовом необходимо убедиться при помощи функции mapRstIsAccessTiff, что
  // для растра с номером number осуществляется прямой доступ к файлу TIFF
  // Функция справедлива для мультиспектральных изображений (mapGetRstBandCount_Tiff() >= 3)

_MAPIMP long int _MAPAPI mapGetRstVegIndex_Tiff(HMAP hMap, long int number, VEGINDEX *vegindex);

  // Возвращает яркость пиксела изображения на канал bandnum 
  // x, y  - координаты пикселя в системе координат растра (в пикселях)
  // color - возвращаемое значение реально записанное в растре (может быть 1,4,8,16 бит)
  // bandnum - номер канала (от 0 до mapGetRstBandCount_Tiff - 1)
  // При ошибке возвращает 0

_MAPIMP long int _MAPAPI mapGetRstBandPixel_Tiff(HMAP hMap, long int number, 
                                                 long int x, long int y,
                                                 long int bandnum, long int *color);

  // Устанавливает радиус клетки в узлах которой пересчет координат выполняется
  // по строгим формулам при отрисовке растра в системе координат, отличной от
  // системы координат растра.
  // Между узлами пересчет координат выполняется линейной интерполяцией. Коэффициенты
  // линейного пересчета внутри клетки вычисляются по двум верхним узлам клетки.
  // При увеличении радиуса увеличивается скорость отрисовки, но ухудшается качество
  // изображения при значительной деформации системы координат отрисовки относительно
  // системы координат растра (изображение сегментируется по размеру клетки).
  // Этот параметр является глобальным, т.е. с момента установки все растры
  // отрисовываются с использовнаием этого параметра
  // radius - устанавливаемый радиус клетки в пикселях (не может быть меньше 0).
  //          Если равен 0, то все пикселы вычисляются по строгим формулам.
  //          Значение по умолчанию 3.
  // При ошибке возвращает 0

_MAPIMP long int _MAPAPI mapSetRstPaintCellRadius_Tiff(long int radius);

  // Возвращает радиус клетки в узлах которой пересчет координат выполняется
  // по строгим формулам при отрисовке растра в системе координат, отличной от
  // системы координат растра.

_MAPIMP long int _MAPAPI mapGetRstPaintCellRadius_Tiff();

  // Возвращает глубину цвета на канал (1, 4, 8, 16) // 31/01/12
  // hMap   - идентификатор открытой векторной карты
  // number - номер файла в цепочке
  // При ошибке возвращает 0

_MAPIMP long int _MAPAPI mapGetRstBitInBand_Tiff(HMAP hMap, long int number);

  // Возвращает гистограмму              // 31/01/12
  // Гистограмма - поканальный массив количества пикселей, присутствующих в растре
  // hMap   - идентификатор открытой векторной карты
  // number - номер файла в цепочке
  // count     - количество элементов в массиве histogram
  //             количество элементов вычисляется по формуле
  //             count = BandCount * (1 << BitInBand)
  //             Для палитровых растров BandCount = 1
  //             для 1 битных растров (палитровых) count = 2
  //             для 4 битных растров (палитровых) count = 16
  //             для 8 битных растров (палитровых) count = 256
  //             для RGB                           count = 3 * 256 = 768
  //             для 8  битных мультиспектральных  count = BandCount * 256
  //             для 16 битных мультиспектральных  count = BandCount * 65536
  // histogram - возвращаемая гистограмма
  // При ошибке возвращает 0

_MAPIMP long int _MAPAPI mapGetRstHistogram_Tiff(HMAP hMap, long int number, 
                                                 int count, int *histogram);



}  // extern "C"


#endif  // RSTAPI_H