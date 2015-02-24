/******* QDMGSRV.H    ************* Dishlenko S.G. ***** 18/12/09 **
*                                                                  *
*              Copyright (c) PANORAMA Group 1991-2009              *
*                      All Rights Reserved                         *
*                                                                  *
********************************************************************
*                                                                  *
*                      FOR Qt3-DESIGNER                            *
*                                                                  *
********************************************************************
*                                                                  *
*         ОПИСАНИЕ КОМПОНЕНТА "ДОСТУП К ДАННЫМ ГИС СЕРВЕРА"        *
*                                                                  *
*******************************************************************/

#ifndef QDMGSRV_H
#define QDMGSRV_H

#include "qdmcmp.h"

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++ КЛАСС "КОМПОНЕНТ ДОСТУПА К ДАННЫМ ГИС СЕРВЕРА"              ++
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class QDMapGisServer : public QDMapComponent
{
    Q_OBJECT

//    Q_PROPERTY(QDMapView MapView READ GetMapView WRITE SetMapView FROMSTRL def TOSTRL def ORDER 1)  // 24/07/03
//    Q_PROPERTY(QDMapObj  MapObj  READ GetMapObj  WRITE SetMapObj  FROMSTRL def TOSTRL def ORDER 2)  // 24/07/03

public  :
    QDMapGisServer(QWidget * parent = 0, const char * name = 0);
    ~QDMapGisServer();

    virtual void SetMapView(QDMapView *value);
    QDMapView    *GetMapView() const;
    bool         IsGISServerActive(const char *aUsername);
    // Вызвать диалог настройки параметров подсоединения к ГИС Серверу
    int          DoDlgConnectParam();
    // Вызвать диалог ввода параметров пользователя
    int          DoDlgUserParam();
    // Вызвать диалог открытия данных
    int          DoDlgOpenData();
    // Запросить имя текущего зарегистрированного пользователя
    const char   *GetCurrentUserName();
    // Вызвать диалог добавления данных
    int          DoDlgAppendData(HMAP aMap);
    // Преобразовать строку в хэш по алгоритму MD5
    int          StringToHash(char *aSource, char* aTarget, int aSize);
    // Служебная часть
    //--------------------------------------------
    // Заполнить структуру для вызова задачи
    void         InitTaskParmEx(TASKPARMEX *taskparm);

public:
    QTextCodec   *MainCodec;
    HINSTANCE    FhDllDlgs;
    long int     (WINAPI *svGetConnectParameters)(TASKPARMEX *);
    long int     (WINAPI *svGetUserData)(TASKPARMEX *);
    long int     (WINAPI *svOpenData)(TASKPARMEX *);
    long int     (WINAPI *svAppendData)(HMAP, TASKPARMEX *);
    long int     (WINAPI *svStringToHash)(const char * source,
                                          char * target, long int size);
};

#endif // QDMGSRV_H
