/******* QDMVIEWA.H ************* Dishlenko S.G.  ****** 09/11/07 **
*                                                                  *
*              Copyright (c) PANORAMA Group 1991-2007              *
*                      All Rights Reserved                         *
*                                                                  *
********************************************************************
*                                                                  *
*                      FOR Qt-DESIGNER                             *
*                                                                  *
********************************************************************
*                                                                  *
*       ОПИСАНИЕ БАЗОВОГО КЛАССА ДОСТУПА К ОБ'ЕКТУ                 *
*                     "ЭЛЕКТРОННАЯ КАРТА"                          *
*                                                                  *
*******************************************************************/

#ifndef QDMVIEWA_H
#define QDMVIEWA_H

#include <QWidget>                                     // 09/11/07
#include <QTextCodec>                                  // 06/04/06
#include "qdmtype.h"                                   // 28/11/03

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++ БАЗОВЫЙ КЛАСС "ИНТЕРФЕЙС УПРАВЛЕНИЯ ЭЛЕКТРОННОЙ КАРТОЙ" ++++
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
class  QDMapViewAcces : public QWidget                 // 09/11/07
{
    Q_OBJECT

public :
    QDMapViewAcces(QWidget *parent = 0, const char *name = 0);

   // Получить идентификатор карты
   virtual HMAP GetMapHandle();

   // Получить объект доступа к карте
   virtual QDMapViewAcces *GetMapViewAcces();

   // Получить название класса                // 07/04/06
   const char * GetClassName();

   // Установить название класса              // 07/04/06
   void SetClassName(char *name);

public :
   // Для внутреннего использования
   HMAP VarMapHandle;         // Реальный идентификатор карты
   QTextCodec *MainCodec;     // 02/06/06
   char ClassName[260];       // 07/04/06
};

#endif  // QDMVIEWA

