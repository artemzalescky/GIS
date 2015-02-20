/*******  QDMCOMPA.H ************* Dishlenko S.G.  ****** 07/04/06 *
*                                                                  *
*              Copyright (c) PANORAMA Group 1991-2006              *
*                      All Rights Reserved                         *
*                                                                  *
********************************************************************
*                                                                  *
*                      FOR QT-DESIGNER                             *
*                                                                  *
********************************************************************
*                                                                  *
*     ОПИСАНИЕ БАЗОВОГО КЛАССА КОМПОНЕНТ ДОСТУПА К                 *
*                     ЭЛЕКТРОННОЙ КАРТЫ                            *
*                                                                  *
*******************************************************************/

#ifndef QDMCOMPA_H
#define QDMCOMPA_H

#include <Qt/qwidget.h>                           // 07/04/06
#include "qdmviewa.h"

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++ БАЗОВЫЙ КЛАСС КОМПОНЕНТ ДОСТУПА К ЭЛЕКТРОННОЙ КАРТЕ         ++
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
class  QDMapComponent : public QWidget
{
    Q_OBJECT

public :
    QDMapComponent(QWidget *parent = 0, const char *name = 0);
    ~QDMapComponent();
    void SetMapViewAcces(QDMapViewAcces *value);
    // Обработка событий изменения состава карт на уровне MapViewWindow
    virtual void    MapAction(int typeaction) {};
    // Для служебного пользования  !!!!!!!!!
    void SetMapWindowAcces(QDMapViewAcces *value); // установка VarMapWindow      // 21/11/03
    // Получить объект типа QDMapViewWindow в котором отбражается карта (QDMapView or QDMapWindow)
    QDMapViewAcces *GetMapViewWindow();                                           // 21/11/03
    virtual void    Notification(QObject *component, int operation);

public :
    //  Для пользователя только на чтение
    QDMapViewAcces *VarMapView;
    // Для служебного пользования  !!!!!!!!!
    // Объект типа TMapWindow к которому подключен данный компонент и в который идет отображение
    QDMapViewAcces *VarMapWindow;
};

#endif  // QDMCOMPA_H
