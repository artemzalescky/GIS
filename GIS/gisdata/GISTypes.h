#ifndef GISTYPES_H
#define GISTYPES_H
#include <QColor>

/**
  *@brief Типы систем координат
  */

typedef enum GISTYPESC_
{
     GTCS_MM = 0, //MM
     GTCS_GK42 = 1, //ГК-42
     GTCS_SC42 = 2, //SC-42
    GTCS_WGS84 = 3, //WGS-84
     GTCS_PZ90 = 4, //ПЗ-90
     GTCS_UTM = 5,
     GTCS_ERR = -1
}GISTYPESC;

/**
  *@brief Единицы измерений (для геодезических систем координат)
  */
typedef enum GISVALUETYPE_
{
    GVT_RAD = 0, //радианы
    GVT_DEG = 1, //Градуcы
    GVT_GMS = 2  //Градусы, минуты, секнды
}GISVALUETYPE;

/**
  *@brief
  */

typedef enum GISDATATYPES_        //???????????????????????
{
     GDT_ERR = 0,
     GDT_MAP = 1,
     GDT_MTQ = 2,
     GDT_MTR = 3
}GISDATATYPES;

/**
 *@brief режим отображения карты
 */

typedef enum TYPEMAPSHOW_ //режим отображения карты
{
    MAPSHOW_ERR = 0,
    MAPSHOW_NORMAL = 1,    //Нормальный
    MAPSHOW_SCREENLINE = 2, //Контурный
    MAPSHOW_PRINTER = 3,  //Принтерный
    MAPSHOW_PRINTERLINE = 4//Принтерный контурный
}TYPEMAPSHOW;

/**
  *@brief режим отображения матрицы высот
  */

typedef enum TYPEMTRSHOW_
{
    MTRSHOW_NONE = 0, //отсутствует
    MTRSHOW_FULL = 1, //насыщенный
    MTRSHOW_SAT = 2,  //?? ??????? ?
    MTRSHOW_HALF = 3, //?????????? ??? ?
    MTRSHOW_MIDLE = 4,//???????
    MTRSHOW_LITE = 5  //полупрозрачный
}TYPEMTRSHOW;


/*!
 *@brief Параметры отображения карты

*/
struct MAPSHOWOPTIONS
{
    MAPSHOWOPTIONS():
        typeMapShow(MAPSHOW_NORMAL),
        typeMtrShow(MTRSHOW_NONE),
        valueBrigth(0),
        valueContrast(0)
    {}

    TYPEMAPSHOW typeMapShow; /*!< TODO */
    TYPEMTRSHOW typeMtrShow; /*!< TODO */
    int valueBrigth; /*!< TODO */
    int valueContrast; /*!< TODO */
};

/**
 * @brief The SAPPGISOPTIONS настройка по умолчанию карты
 */
struct APPGISOPTIONS
{
    APPGISOPTIONS():
        typeSC(GTCS_SC42),
        typeValue(GVT_RAD),
        isVisibleCalcLine(true),
        colorCalcLine(Qt::red),
        widthCalcLine(2)
    {}

    GISTYPESC typeSC;
    GISVALUETYPE typeValue;

    bool isVisibleCalcLine;
    QColor colorCalcLine;
    int widthCalcLine;
    bool isVisibleObjSheme;
};

/**
 * @brief The SAPPPATHSHOWOPTIONS  настройка по умолчанию параметров  (PATH)
 */
struct APPPATHSHOWOPTIONS
{
    APPPATHSHOWOPTIONS():
        isVisibleCurPath(true),
        colorPathPoint(Qt::blue),
        colorActivePoint(Qt::yellow),
        colorPathLine(Qt::blue),
        widthPathLine(3),
        sizePathPoint(5),
        isVisibleObjSheme(true),
        colorModeSigns(Qt::black),
        colorPatrolBorder(Qt::red),
        colorPLObj(Qt::darkRed)
    {}

    bool isVisibleCurPath;
    QColor colorPathPoint;
    QColor colorActivePoint;
    QColor colorPathLine;
    int widthPathLine;
    int sizePathPoint;

    QColor colorModeSigns;
    QColor colorPatrolBorder;
    QColor colorPLObj;

    bool isVisibleObjSheme;
};

/*Далее код не АКТУАЛЕН !!!!!!!!!! в рамках данной задачи*/

struct SPHOTOPLANPARAM
{
    QString namePhotoFile;
    int widthPhoto;
    int heightPhoto;
    double coordWest;
    double coordEast;
    double coordNorth;
    double coordSouth;
};

struct SPHOTOTRANSDATA
{
    int photoXutm;
    int photoYutm;
    double photoWidthUTM;
    double photoHeightUTM;
    double transKw;
    double transKh;

    int widthPhoto;
    int heightPhoto;
};

struct SCRITSHEMESHOWOPTIONS
{
    SCRITSHEMESHOWOPTIONS():
        isVisible(true),
        color1_PointObj(Qt::yellow),
        color2_PointObj(Qt::black),
        colorPen(Qt::red),
        colorFill(Qt::blue),
        widthPen(3),
        styleFill(Qt::Dense5Pattern),
        stylePen(Qt::DashLine)
    {}

    bool isVisible;
    QColor color1_PointObj;
    QColor color2_PointObj;
    QColor colorPen;
    QColor colorFill;
    int widthPen;
    Qt::BrushStyle styleFill;
    Qt::PenStyle stylePen;

};

#endif // GISTYPES_H
