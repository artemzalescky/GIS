#ifndef GISTYPES_H
#define GISTYPES_H
#include <QColor>

/**
  *@brief ���� ������ ���������
  */

typedef enum GISTYPESC_
{
     GTCS_MM = 0, //MM
     GTCS_GK42 = 1, //��-42
     GTCS_SC42 = 2, //SC-42
    GTCS_WGS84 = 3, //WGS-84
     GTCS_PZ90 = 4, //��-90
     GTCS_UTM = 5,
     GTCS_ERR = -1
}GISTYPESC;

/**
  *@brief ������� ��������� (��� ������������� ������ ���������)
  */
typedef enum GISVALUETYPE_
{
    GVT_RAD = 0, //�������
    GVT_DEG = 1, //�����c�
    GVT_GMS = 2  //�������, ������, ������
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
 *@brief ����� ����������� �����
 */

typedef enum TYPEMAPSHOW_ //����� ����������� �����
{
    MAPSHOW_ERR = 0,
    MAPSHOW_NORMAL = 1,    //����������
    MAPSHOW_SCREENLINE = 2, //���������
    MAPSHOW_PRINTER = 3,  //����������
    MAPSHOW_PRINTERLINE = 4//���������� ���������
}TYPEMAPSHOW;

/**
  *@brief ����� ����������� ������� �����
  */

typedef enum TYPEMTRSHOW_
{
    MTRSHOW_NONE = 0, //�����������
    MTRSHOW_FULL = 1, //����������
    MTRSHOW_SAT = 2,  //?? ??????? ?
    MTRSHOW_HALF = 3, //?????????? ??? ?
    MTRSHOW_MIDLE = 4,//???????
    MTRSHOW_LITE = 5  //��������������
}TYPEMTRSHOW;


/*!
 *@brief ��������� ����������� �����

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
 * @brief The SAPPGISOPTIONS ��������� �� ��������� �����
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
 * @brief The SAPPPATHSHOWOPTIONS  ��������� �� ��������� ����������  (PATH)
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

/*����� ��� �� �������� !!!!!!!!!! � ������ ������ ������*/

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
