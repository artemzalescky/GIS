/******** QDMACTPT.H   *********** Dishlenko S.G.  ***** 22/03/12 **
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
*  Компонент      : QDGetMapPoint -  компонент интерактивного      *
*                   выбора точки карты                             * 
*                                                                  *
*******************************************************************/

#ifndef QDMACTPT_H
#define QDMACTPT_H

#include "qdmact.h"
#include "mapapi.h"

class QDMapObj;


//++++++++++++++++++++++++++++++++++++++++++++++++++
//+++ QDGetMapPoint -  КОМПОНЕНТ ИНТЕРАКТИВНОГО    +
//+++                  ВЫБОРА ТОЧКИ КАРТЫ          + 
//++++++++++++++++++++++++++++++++++++++++++++++++++
class QDGetMapPoint : public QDGtkAction
 {
  Q_OBJECT

public:

    QDGetMapPoint(QWidget * parent = 0, const char * name = 0);
    ~QDGetMapPoint();
    // Рабочие функции
    //---------------------------------------------------
    virtual void MapBeforePaint(QObject *sender, HWND canvas, RECT mappaintrect);
    virtual void MouseMove(int x, int y, int modkeys);
    virtual void MouseUp(int x, int y, int modkeys);

private :
    void PaintDot();
    void CalcCoordsForObjAndMouse(int aMouseX, int aMouseY);
    // нарисовать/стереть линию
    void LinePaint();

public:                                           // 11/11/05

    // Для пользователя
    //---------------------------------------------------
    // подсоединить обработчик к компоненту отображения карты
    virtual void StartAction();     
    // отсоединить
    virtual void StopAction();      
    // Объект для которого выбирается точка
    QDMapObj     *GetMapObj();
    void         SetMapObj(QDMapObj *mapobj);
    
    typedef enum TSELECTIONMODE
    {
      GETEXISTPOINT    = 1,      // существующая точка объекта
      GETVIRTUALPOINT  = 2       // ближайшая точка объекта
    };
    // Тип точки(TSELECTIONMODE) // 14/11/05
    int          GetTypePoint();          
    void         SetTypePoint(int type);

signals :
    // Сигнал о выборе точки
    // x, y       - координаты точки объекта в метрах
    // numpoint   - номер точки
    // numsubobj  - номер подобъекта
    void SignalSelectPoint(double x, double y, int numpoint, int numsubobj);

    // Рабочие переменные
    //---------------------------------------------------
private :
    
    QDMapObj    *FMapObj;        // О©╫О©╫О©╫О©╫О©╫О©╫ О©╫О©╫О©╫ О©╫О©╫О©╫О©╫О©╫О©╫О©╫О©╫ О©╫О©╫О©╫О©╫О©╫О©╫О©╫О©╫О©╫О©╫ О©╫О©╫О©╫О©╫О©╫              // 22/03/12
    DOUBLEPOINT FPointMouse;     // О©╫О©╫О©╫О©╫О©╫О©╫О©╫О©╫О©╫О©╫ О©╫О©╫О©╫О©╫О©╫ О©╫О©╫О©╫О©╫ О©╫ О©╫О©╫О©╫О©╫О©╫О©╫ О©╫О©╫О©╫ О©╫О©╫О©╫О©╫О©╫О©╫
    DOUBLEPOINT FPointObj;       // О©╫О©╫О©╫О©╫О©╫О©╫О©╫О©╫О©╫О©╫ О©╫О©╫О©╫О©╫О©╫ О©╫О©╫О©╫О©╫О©╫О©╫О©╫ О©╫О©╫О©╫ О©╫О©╫О©╫О©╫О©╫О©╫
    DOUBLEPOINT FPlacePoints[2]; // к▐о▐о▐р▐д▐и▐н▐О©╫т▐ы▐ м▐е▐т▐р▐и▐к▐и▐
    PAINTPARM   FImageParm;      // п▐О©╫р▐О©╫м▐е▐т▐р▐ы▐ о▐т▐р▐и▐с▐о▐ к▐и▐
    IMGDOT      FImageObj;
    PLACEDATA   FPlaceData;      // м▐е▐т▐р▐и▐к▐О©╫ р▐е▐з▐и▐н▐к▐и▐
    int         FNumPoint;       // номер точки на объекте
    int         FNumSubj;        // номер подъобъекта для которого точка
    int    FColorDot;       // цвет резинки                  // 21/03/12
    int         FLineWidth;      // толщина резинки
    int         FDashLenght;     // длина штриха резинки
    int         FBlankLenght;    // длина пробела резинки
    int    FPlaceCount;     // количество метрики            // 21/03/12
    int         FTypeGetPoint;   // тип точки
    bool        FIsLine;         // О©╫О©╫О©╫О©╫О©╫О©╫О©╫О©╫О©╫О©╫ О©╫О©╫ О©╫О©╫О©╫О©╫О©╫
};

#endif // QDMACTPT_H
