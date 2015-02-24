/******* QDMLAYR.H ************** Dishlenko S.G.  ****** 22/03/12 **
*                                                                  *
*              Copyright (c) PANORAMA Group 1991-2012              *
*                      All Rights Reserved                         *
*                                                                  *
********************************************************************
*                                                                  *
*                      FOR Qt3-DESIGNER                            *
*                                                                  *
********************************************************************
*                                                                  *
*                 КЛАССЫ ДОСТУПА К СЛОЯМ КАРТЫ                     *
*                                                                  *
*******************************************************************/

#ifndef QDMLAYR_H
#define QDMLAYR_H

#include "maptype.h"

class QDMapViewAcces;
class QDMapView;
class QDMapObjAcces;
class QDMapSite;

//++++++++++++++++++++++++++++++++++++++++
//+++  КЛАСС ДОСТУПА К СЛОЯМ КАРТЫ     +++
//++++++++++++++++++++++++++++++++++++++++

class QDMapLayer
{

public :
    QDMapLayer(QDMapViewAcces *mapview, QDMapSite *mapsite);
    ~QDMapLayer();

    HRSC  GetRscHandle();
     // Указатель на компонент карты
    QDMapView  *GetMapView();
     // Указатель на компонент пользовательской карты
    QDMapSite  *GetMapSite();
     // Наименование слоя
    char  *GetLayerName();
    // Уникальное наименование слоя - ключ
    char  *GetLayerKey();
    // Количество объектов описанных в классификаторе
    int    GetObjCount();
    // Условное название объектов
    char   *GetObjName(int number);
    // Внешний код объекта
    int    GetObjExCode(int number);
    // Внутренний код объекта
    int    GetObjInCode(int number);
    // Характер локализации оьъекта
    int    GetObjLocal(int number);
    // Уникальное название оьъекта (ключ)
    char   *GetObjKey(int number);

public :
    // Пользователю только на чтение
    QDMapViewAcces *VarMapView;
    QDMapSite      *VarMapSite;      // Site с которым работаем  имеет высший приоритет по сравнениб с VarRsc
    HRSC           VarHRsc;          // RSC с которым работаем (если FMapSite<>nil то rsc вычисляется по Site)
    int            VarNumber;        // т╫е╫к╫у╫щ╫и╫й╫ н╫о╫м╫е╫р╫ с╫л╫о╫я╫               // 22/03/12
};

//+++++++++++++++++++++++++++++++++++++++++++++++++++
//+++  КЛАСС ДОСТУПА К СЛОЯМ КАРТЫ - КОНТЕЙНЕР    +++
//+++++++++++++++++++++++++++++++++++++++++++++++++++

class QDMapLayers
{

public :
    QDMapLayers(QDMapViewAcces *mapview, QDMapSite *mapsite);
    QDMapLayers(HRSC rsc);
    ~QDMapLayers();

    // Количество слоев
    int        GetLayerCount();
    // Слой по порядковому номеру
    QDMapLayer *GetMapLayers(int number);
    // Слой по оьъекту карты
    QDMapLayer *GetObjLayers(QDMapObjAcces *mapobj);
    // Слой по уникальному названию - ключу
    QDMapLayer *GetKeyLayers(char *keyname);
    void       SetRscHandle(HRSC rsc);

public :
   // Для внутреннего использования
   QDMapLayer *VarMapLayer;
};

#endif  // QDMLAYR_H
