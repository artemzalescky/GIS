/******** QDMRECT.H ************* Dishlenko S.G.  ***** 22/03/12 ***
*                                                                  *
*              Copyright (c) PANORAMA Group 1991-2012              *
*                      All Rights Reserved                         *
*                                                                  *
********************************************************************
*                                                                  *
*                      FOR QT-DESIGNER                             *
*                                                                  *
********************************************************************
*                                                                  *
*  Компонент      : QDMapSelectRect - выбор участка открытой карты *
*                                                                  *
*******************************************************************/

#ifndef QDMRECT_H
#define QDMRECT_H

#include "qdmact.h"
#include "mapapi.h"             // 28/11/03

//++++++++++++++++++++++++++++++++++++++++++++++++++
//+++ QDMapSelectRect - КЛАСС ВЫБОРА УЧАСТКА КАРТЫ +
//++++++++++++++++++++++++++++++++++++++++++++++++++

 class QDMapSelectRect : public QDGtkAction
 {
  Q_OBJECT

  public:

    // Для пользователя
    //---------------------------------
    QDMapSelectRect(QWidget * parent = 0, const char * name = 0);
    ~QDMapSelectRect();

    // Для пользователя
    virtual void StartAction();     // подсоединить обработчик к компоненту отображения карты
    virtual void StopAction();      // отсоединить
    // Запрос/установка системы координат     // 01/11/05
    void SetPlaceRect(int pp);
    int  GetPlaceRect();

    // Служебные
    //---------------------------------
    virtual void MapAfterPaint(QObject *sender, HWND canvas, RECT mappaintrect);
    virtual void MapBeforePaint(QObject *sender, HWND canvas, RECT mappaintrect);
    virtual void MouseDown(int x, int y, int modkeys);
    virtual void MouseMove(int x, int y, int modkeys);
    virtual void MouseUp(int x, int y, int modkeys);

    //  Построить контур фрагмента по угловым точкам
    void BuildFrame();
    //  Нарисовать на карте рамку фрагмента
    void PaintFrame();
    DOUBLEPOINT GetMapPoint(int x, int y);
    int         GetSelRect(MAPDFRAME *dframe, int pp);           // 26/10/05

signals :
    // Для пользователя
    //---------------------------------
    // Сигнал об окончании построения рамки
    // параметры - координаты верхнего левого и
    // правого нижнего угла рамки
    void SignalAfterBuildRect(double left, double top,            // 1/11/05
                              double right, double bottom);

public :
  // Служебные
  //---------------------------------
  struct Border                                                   // 22/03/12
  {
    DOUBLEPOINT UpLeft;     // О©╫О©╫О©╫О©╫О©╫О©╫О©╫О©╫О©╫О©╫ О©╫О©╫О©╫О©╫О©╫О©╫ О©╫О©╫О©╫О©╫О©╫ (Map)
    DOUBLEPOINT UpRight;    // О©╫О©╫О©╫О©╫О©╫О©╫О©╫О©╫О©╫О©╫ О©╫О©╫О©╫О©╫О©╫О©╫ О©╫О©╫О©╫О©╫О©╫
    DOUBLEPOINT DownRight;  // О©╫о≥о≥р≥д≥и≥н≥О©╫т≥ы≥ т≥р≥е≥т≥ь≥е≥й≥ т≥о≥ч≥к≥и≥
    DOUBLEPOINT DownLeft;   // О©╫О©╫О©╫О©╫О©╫О©╫О©╫О©╫О©╫О©╫ О©╫О©╫О©╫О©╫О©╫О©╫О©╫О©╫О©╫ О©╫О©╫О©╫О©╫О©╫
    DOUBLEPOINT UpLeftLast; // О©╫о≥о≥р≥д≥и≥н≥О©╫т≥ы≥ п≥о≥с≥л≥е≥д≥н≥е≥й≥ т≥о≥ч≥к≥и≥ (Map)
  }
    Border;
  DOUBLEPOINT First;      // О©╫О©╫О©╫О©╫О©╫О©╫О©╫О©╫О©╫О©╫ О©╫О©╫О©╫О©╫О©╫О©╫О©╫ О©╫О©╫О©╫О©╫ (Map)
  DOUBLEPOINT Second;     // О©╫О©╫О©╫О©╫О©╫О©╫О©╫О©╫О©╫О©╫ О©╫О©╫О©╫О©╫О©╫О©╫О©╫ О©╫О©╫О©╫О©╫ (Map)
  DOUBLEPOINT PointMap;   // 12/11/07

  PAINTPARM Form;   // Вид контура фрагмента на экране
                    // (пунктирная линия 5/2 инверсная)
  PLACEDATA Frame;  // Описание фрагмента карты
  int PointCount;         // О©╫О©╫О©╫О©╫О©╫ О©╫О©╫О©╫О©╫О©╫, О©╫О©╫О©╫О©╫О©╫О©╫О©╫О©╫О©╫О©╫О©╫ О©╫О©╫О©╫О©╫О©╫О©╫О©╫О©╫       // 21/03/12
  int  SelectedPoints;     // О©╫О©╫О©╫О©╫О©╫О©╫О©╫ О©╫О©╫О©╫О©╫О©╫

  int FlagClear;          // О©╫О©╫О©╫О©╫О©╫О©╫О©╫ "О©╫О©╫О©╫О©╫О©╫О©╫ О©╫О©╫О©╫О©╫О©╫"
  int VarPlace;           // О©╫О©╫О©╫О©╫О©╫О©╫О©╫ О©╫О©╫О©╫О©╫О©╫О©╫О©╫ О©╫О©╫О©╫О©╫О©╫О©╫О©╫О©╫О©╫  // 08/11/05
  IMGDOT Image;     // Описание пунктирной линии (контур фрагмента)
};

#endif
