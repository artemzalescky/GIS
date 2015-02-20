/****** S57API.CPP   *********** Dishlenko S.G.  ****** 19/01/10 ***
*                                                                  *
*              Copyright (c) PANORAMA Group 1991-2010              *
*                      All Rights Reserved                         *
*                                                                  *
********************************************************************
*                                                                  *
*                            FOR  LINUX                            *
*                                                                  *
********************************************************************
*                                                                  *
*          ОПИСАНИЕ API-ИНТЕРФЕЙСА ОБРАБОТКИ СТАНДАРТА S57.ED3     *
*                                                                  *
*******************************************************************/


#ifndef S57API_H
#define S57API_H

#ifndef MAPTYPE_H
  #include "maptype.h"   // Описание структур интерфейса MAPAPI
#endif

extern "C"
{
  // Загрузить S57-файл в карту (вызов из приложения)
  // s57name - название файла S57
  // mapname - название файла паспорта карты
  // parm    - параметры (поля структуры должы быть инициализированы в 0)
  // при ошибке возвращает 0
  long int WINAPI _export LoadS57ToMap(const char* s57name, char* mapname, TASKPARM* parm);

  // Загрузить карту в S57-файл
  // hmap    - идентификатор карты
  // s57name - название файла S57
  // parm    - параметры (поля структуры должы быть инициализированы в 0)
  // при ошибке возвращает 0
  long int WINAPI _export LoadMapToS57(HMAP hmap, char* s57name, TASKPARM* parm);

  // Вызов диалога "НАСТРОЙКА ПАРАМЕТРОВ МОРСКИХ КАРТ ФОРМАТА S57"   // 19/01/10
  // hmap    - идентификатор карты
  // parm    - параметры (поля структуры должы быть инициализированы в 0)
  // при ошибке возвращает 0  
  long int WINAPI _export CallS57SetupDialog(long int hmap,TASKPARM * parm);
}

#endif  // S57API_H
