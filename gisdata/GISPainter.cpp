#include "GISPainter.h"
#include <QPainter>
#include "./userVFunctions.h"

long int GISPainter::getPictureWidth()
{
    return GISLibrary.getMapPictureWidth(hmap);
}
long int GISPainter::getPictureHeigth()
{
    return GISLibrary.getMapPictureHeight(hmap);
}

//--------------------------------------------------------
int GISPainter::paintMapImage(QPainter* dst_, RECT* rect_)
{
    int mapdepth = 32;
    XIMAGEDESC xImageDesc;
    int cw(rect_->right - rect_->left);      //ширина
    int ch(rect_->bottom - rect_->top);      //высота
    long allignwidth = cw * (mapdepth / 8 );
    long size = allignwidth * ch;
    char * bits = ::AllocateTheMemory(size);
    if (!bits)
    {
        return 0;
    }

    memset(bits, 0x0, size);  //заполн€ет блок пам€ти()

    xImageDesc.Point = bits; // јдрес начала области пикселов
    xImageDesc.Width = cw; // Ўирина строки в пикселах
    xImageDesc.Height = ch; // „исло строк
    xImageDesc.Depth = mapdepth; // размер элемента в битах (8,15,16,24,32)
    xImageDesc.CellSize = mapdepth / 8; // размер элемента(пиксела) в байтах
    xImageDesc.RowSize = cw * xImageDesc.CellSize;// Ўирина строки в байтах
    int ret = GISLibrary.paintMapToXImage(hmap, &xImageDesc, 0, 0, rect_);

    QImage image((uchar *)bits, cw, ch, QImage::Format_RGB32);
    dst_->drawImage(rect_->left, rect_->top, image, 0, 0, cw, ch);
    return ret;

}

//--------------------------------------------------------
int GISPainter::getShowScale()
{
    qDebug()<< "getShowScale";
    return GISLibrary.getShowScale(hmap);
}

//--------------------------------------------------------
QPoint GISPainter::changeShowScale(QPoint point_, float k_)
{
    int long pointX(point_.x()),
             pointY(point_.y());

    if (GISLibrary.changeShowScale(hmap, &pointX, &pointY, k_))
    {
        point_.setX(pointX);
        point_.setY(pointY);
    }

    qDebug()<< "changeShowScale";
    return point_;
}

//--------------------------------------------------------
/**
 * @brief GISPainter::getScrCoordByMM перевести координаты из пикселей в метры
 * @param mmpoint_
 * @return
 */
QPoint GISPainter::getScrCoordByMM(DOUBLEPOINT mmpoint_)
{
    QPoint resPoint(0, 0);
    DOUBLEPOINT tmpPoint = GISLibrary.translateMMToPicture(hmap, mmpoint_);
    resPoint.setX(tmpPoint.X);
    resPoint.setY(tmpPoint.Y);
    qDebug()<< "getScrCoordByMM";
    return resPoint;
}

//--------------------------------------------------------
/**
 * @brief GISPainter::getMMCoordByScr пересчЄт из (plane) метров в (picture) пиксели
 * @param scrpoint_
 * @return
 */
DOUBLEPOINT GISPainter::getMMCoordByScr(DOUBLEPOINT scrpoint_)
{
    qDebug()<< "getMMCoordByScr";
    return GISLibrary.translatePictureToMM(hmap, scrpoint_);
}

//--------------------------------------------------------------
/**
 * @brief GISPainter::getScrCoord получить picture() координаты в пиксел€х
  */
QPoint GISPainter::getScrCoord(DOUBLEPOINT coord_,
                                GISTYPESC typecs_,
                                GISVALUETYPE valuetype_)
{
    qDebug()<< "<<<<<<<<<<>>>>>>>>>>>";

    if(valuetype_ == GVT_DEG)
    {
        coord_ = servfunc::convertDegreeToRad(coord_);
    }
    DOUBLEPOINT radcoord;
    switch(typecs_)
    {
        case GTCS_GK42:
        {
            GK42_to_SC42(coord_, radcoord);
            break;
        }
        case GTCS_SC42:
        {
            radcoord = coord_;
            break;
        }
        case GTCS_WGS84:
        {
            WGS84_to_SC42(coord_, radcoord);
            break;
        }
        case GTCS_PZ90:
        {
            PE90_to_SC42(coord_, radcoord);
            break;
        }
        default:
        {
            return QPoint(-11111, -11111);
        }
    }
    DOUBLEPOINT mmcoord;
    SC42_to_MM(radcoord, mmcoord);
    return getScrCoordByMM(mmcoord);
}

//-----------------------------------------------------------------
QPoint GISPainter::getScrCoordByWGS84Dgr(DOUBLEPOINT coord_)
{
    coord_ = servfunc::convertDegreeToRad(coord_);
    DOUBLEPOINT radcoord;
    WGS84_to_SC42(coord_, radcoord);
    DOUBLEPOINT mmcoord;
    SC42_to_MM(radcoord, mmcoord);
    return getScrCoordByMM(mmcoord);
}

//-----------------------------------------------------------------

void GISPainter::setMapViewType(const TYPEMAPSHOW type_)
{
    if(IsLoaded())
    {
        GISLibrary.SetMapViewType(hmap, static_cast<long int>(type_));
    }
}

//-----------------------------------------------------------------
void GISPainter::setMtrViewType(const TYPEMTRSHOW type_)
{
    GISLibrary.SetMtrViewType(hmap, m_nummtr, static_cast<long int>(type_));
}

//-----------------------------------------------------------------
void GISPainter::setBrightMapPicture(const int value_)
{
    GISLibrary.SetMapViewBright(hmap, value_);
}

//-----------------------------------------------------------------
void GISPainter::setContrastMapPicture(const int value_)
{
    GISLibrary.SetMapViewContrast(hmap, value_);
}

//-----------------------------------------------------------------
void GISPainter::setBackColorMapPicture(QColor color_)
{
    color_;
    GISLibrary.SetMapViewBackColor(hmap, 16777215);
}
