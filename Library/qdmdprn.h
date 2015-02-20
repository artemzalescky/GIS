/******** QDMDPRN.H  ************* Dishlenko S.G.  ****** 22/03/12 *
*                                                                  *
*              Copyright (c) PANORAMA Group 1991-2012              *
*                      All Rights Reserved                         *
*                                                                  *
********************************************************************
*                                                                  *
*                      FOR Qt-DESIGNER                             *
*                                                                  *
********************************************************************
*                                                                  *
*        КОМПОНЕНТ - ДИАЛОГ "ФОРМИРОВАНИЯ ФАЙЛА POSTSCRIPT"        *
*                                                                  *
*******************************************************************/

#ifndef QDMDPRN_H
#define QDMDPRN_H

#include "qdmcmp.h"

//++++++++++++++++++++++++++++++++++++++++++++++++++
//+++ КЛАСС ДИАЛОГА                                +
//+++ "ФОРМИРОВАНИЯ ФАЙЛА POSTSCRIPT"              +
//++++++++++++++++++++++++++++++++++++++++++++++++++

class QDMapBuildEps : public QDMapComponent
{
    Q_OBJECT

    // Установить\Запросить значение флага выбора области карты      // 23/05/06
    Q_PROPERTY(bool AllRectActive READ GetAllRectActive WRITE SetAllRectActive)

public :
    // Для пользователя
    //------------------------------
    QDMapBuildEps(QWidget *parent = 0, const char *name = 0);
    ~QDMapBuildEps() {};
    // Выполнить диалог
    void         Execute();
    // Указатель на карту
    virtual void SetMapView(QDMapView *value);
    QDMapView    *GetMapView() const;
    // Установить\Запросить значение флага выбора области карты
    // true  - вся карта(по умолчанию)
    // false - прямоугольная область, заданная функцией SetMapRect
    void  SetAllRectActive(bool value);
    bool  GetAllRectActive() const;
    // Установить размеры области карты в пикселах
    // Перед использованием данной фукции необходимо
    // установить флаг выбора области карты в 0
    // left, top     -  левый верхний угол
    // right, bottom -  правый нижний
    void SetMapRect(int left, int top, int right, int bottom);

public:
    // Служебные
    //------------------------------

    RECT  MapRect;                                                     // 22/03/12
    // Флаг выбора области карты
    // true  - вся карта (по умолчанию)
    // false - прямоугольная область, заданная функцией SetMapRect
    bool  AllRectActive;
};

#endif // QDMDPRN_H
