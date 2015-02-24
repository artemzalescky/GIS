
#include "mapScroll.h"

#include <QtGui>
#include <QFileInfo>
#include <QFile>
#include <QPainter>
#include <QTextCodec>
#include <math.h>


MapScroll::MapScroll(QWidget * parent_)
    : QScrollArea(parent_),
      widget(0),
      centerMode(false)
{
    this->setMouseTracking(true);

    startObj = false;
    tmpCoordMode = false;

    tmpCoord.x = -11111;
    tmpCoord.y = -11111;
}

//-------------------------------------------------------------
MapScroll::~MapScroll()
{}

//-------------------------------------------------------------
void MapScroll::setTmpCoordMode(bool mode_)
{
    tmpCoordMode = mode_;
    if(!getTmpCoordMode())
    {
        tmpCoord.x = -11111;
        tmpCoord.y = -11111;
    }
}

bool MapScroll::getTmpCoordMode()
{
    return tmpCoordMode;
}

void MapScroll::setTmpMMCoord(DOUBLEPOINT mmcoord_)
{
    tmpCoord = mmcoord_;
}

QPoint MapScroll::getTmpScrCoord()
{
    return gisData.getScrCoordByMM(tmpCoord);
}

// Показ карты
bool MapScroll::eventFilter (QObject * watched, QEvent * event)
{
    if (event->type() == QEvent::Paint && widget != 0 & widget == watched)
    {
        QPainter p;
        p.begin(widget);
        if(gisData.IsLoaded())
            {
                RECT paintrect;
                paintrect.left = ((QPaintEvent *)event)->rect().left();
                paintrect.top = ((QPaintEvent *)event)->rect().top();
                paintrect.bottom = ((QPaintEvent *)event)->rect().bottom() + 1;
                paintrect.right = ((QPaintEvent *)event)->rect().right() + 1;

                gisData.paintMapImage(&p, &paintrect);
            }

        p.end();
        return true;
    }
    else
    {
        return QScrollArea::eventFilter(watched, event);
    }
}

//загрузка
int  MapScroll::loadMapFile(QString nameMapFile_)
{
    if(!QFile::exists(nameMapFile_))
    {
        return 0;
    }

    QFileInfo loadingFileInfo(nameMapFile_);

    if(loadingFileInfo.completeSuffix() == "sxf" || loadingFileInfo.completeSuffix() == "SXF")
    {
        nameMapFile_ = converSXF2Map(nameMapFile_, &loadingFileInfo);
    }

    if(loadingFileInfo.completeSuffix() == "map" || loadingFileInfo.completeSuffix() == "MAP")
    {
        QString mtrName(servfunc::createMtwFileName(nameMapFile_));
        QFile file(mtrName);
        if(!gisData.LoadMapData(nameMapFile_.toLocal8Bit(),
                                mtrName.toLocal8Bit(),
                                file.exists()))
        {
            return 0;
        }
    }

    if (gisData.IsLoaded())
    {
        long int mapW(gisData.getPictureWidth()),
                mapH(gisData.getPictureHeigth());

        if (widget == 0)
        {
            widget = new QWidget(viewport());
            widget->setAttribute(Qt::WA_NoBackground);
            widget->setMouseTracking(true);
            setWidget(widget);
        }
        else
        {
            widget->show();
        }
        widget->setGeometry(0, 0, mapW, mapH);
        setFocus();
        readMapSettings();
        qDebug() << getIniName();
        repaint();
        return 1;
    }
    return 0;
}


//-------------------------------------------------------------------
QString MapScroll::converSXF2Map(QString filename_, QFileInfo* info_)
{
    QString rscName = QFileDialog::getOpenFileName(this,
                                                   tr("Файл классификатора карты"),
                                                   info_->absolutePath(),
                                                   tr("RSC files (*.rsc)\n"
                                                      "All files (*.*)"));
    if(!rscName.isEmpty())
    {
        QString outFileName(filename_);
        outFileName.replace(outFileName.length() - 3, 3, "map");
        if(gisData.createMapFromSXF(filename_.toStdString().c_str(),
                                    rscName.toStdString().c_str(),
                                    outFileName.toStdString().c_str(),
                                    NULL))
        {
            filename_ = outFileName;
            info_->setFile(filename_);
        }
        else
        {
            filename_.clear();
        }
    }
    else
    {
        filename_.clear();
    }
    return filename_;
}

//---------------------------------------------
void MapScroll::closeMapData()
{

    if(gisData.IsLoaded())
    {
        QSettings *mapSettings = new QSettings(getIniName(),
                                               QSettings::IniFormat,
                                               this);
        qDebug() << getIniName();
        writeMapComposition(mapSettings);
        gisData.CloseData();
        widget->repaint();
    }
}

//--------------------------------------------------------------------
void MapScroll::setGISViewParam(MAPSHOWOPTIONS data_)
{
    if(gisData.IsLoaded())
    {
        gisData.setMapViewType(data_.typeMapShow);
        gisData.setMtrViewType(data_.typeMtrShow);
        gisData.setBrightMapPicture(data_.valueBrigth);
        gisData.setContrastMapPicture(data_.valueContrast);
        gisData.setBackColorMapPicture(Qt::white);
    }
}

//--------------------------------------------------------------------
void MapScroll::readMapSettings(void)
{
    if(!gisData.IsLoaded())
    {
        return;
    }
    QSettings *mapSettings = new QSettings(getIniName(),
                                           QSettings::IniFormat,
                                           this);
    if(!QFile::exists(getIniName()))
    {
        writeMapComposition(mapSettings);
        return;
    }

    MAPSHOWOPTIONS viewoptions;
    servfunc::readMapShowOptions(mapSettings, viewoptions);
    setGISViewParam(viewoptions);

    if(readMapComposition(mapSettings) < 1)
    {
        writeMapComposition(mapSettings);
    }

    QSettings appSettings;
    servfunc::readAppGisOptions(&appSettings, appGisOptions);
    servfunc::readPathShowOptions(&appSettings, appPathShowOptions);


}

//--------------------------------------------------------------------
void MapScroll::writeMapComposition(QSettings* settings_)
{

    QTextCodec *codec = QTextCodec::codecForName("KOI8-R");
    char strtext[256];

    settings_->beginGroup("Map_Composition");
    int CountLayer(gisData.getCountLayers());
    qDebug()<<"Layer map Composition";
    settings_->setValue("Layers_Count", CountLayer);
    for (int i(1); i < CountLayer; i++)
    {
        settings_->setValue(QString("Layer_%1").arg(i), gisData.isLayerChecked(i));
        sprintf(strtext, gisData.getNameLayerByNum(i));
#ifndef WINAPI32
        QString layername = QString::fromLocal8Bit(strtext);
#else
        QString layername = codec ? codec->toUnicode(strtext) : QString::fromLocal8Bit(strtext);
#endif
        settings_->setValue(QString("Layer_%1_name").arg(i), layername);
        int countObj(gisData.getCountObjInLayer(i));
        settings_->setValue(QString("Layers_Obj_Count_%1").arg(i), countObj);
        for (int j(1); j < countObj + 1; j++)
        {
            settings_->setValue(QString("Object_%1_%2").arg(i).arg(j), gisData.isCheckedObjInLayer(i, j));
            sprintf(strtext, gisData.getNameObjInLayer(i, j).c_str());
#ifndef WINAPI32
            QString objname = QString::fromLocal8Bit(strtext);
#else
            QString objname = codec ? codec->toUnicode(strtext) : QString::fromLocal8Bit(strtext);
#endif
            settings_->setValue(QString("Object_%1_%2_name").arg(i).arg(j), objname);
        }
    }
    settings_->endGroup();
}

//--------------------------------------------------------------------
int MapScroll::readMapComposition(QSettings* settings_)
{
    settings_->beginGroup("Map_Composition");
    int mapCountLayer(gisData.getCountLayers());
    int dataCountLayer = settings_->value("Layers_Count", 0).toInt();
    if(mapCountLayer != dataCountLayer)
    {
        settings_->endGroup();
        return -1;
    }
    for (int i(1); i < dataCountLayer; i++)
    {
        // TODO: fix selection layers and objects by data from inifile GVD
        gisData.setCheckedLayerByNum(i, settings_->value(QString("Layer_%1").arg(i), 1).toBool());
        int mapCountObj(gisData.getCountObjInLayer(i));
        int dataCountObj = settings_->value(QString("Layers_Obj_Count_%1").arg(i), 0).toInt();
        if(mapCountObj != dataCountObj)
        {
            continue;
        }
        for (int j(1); j < dataCountObj + 1; j++)
        {
            long int codeObj = gisData.getCodeObjInLayer(i, j);
            gisData.setCheckedObjByCode(codeObj, settings_->value(QString("Object_%1_%2").arg(i).arg(j), 1).toBool());
        }
    }
    gisData.reloadSelViewContext();
    settings_->endGroup();
    return mapCountLayer;
}

//--------------------------------------------------------------------
QString MapScroll::getIniName()
{
    QString iniFileName = gisData.getNameMapFile();
    iniFileName.replace(iniFileName.length() - 3, 3, "set");
    return iniFileName;
}

//-------------------------------------------------------------------
GISPainter *MapScroll::getGISDataP()
{
    return &gisData;
}

//--------------------------------------------------------------------
void MapScroll::setCenterViewByMM(DOUBLEPOINT mmpoint_)
{
    setCenterViewByScr(gisData.getScrCoordByMM(mmpoint_));
}

//-------------------------------------------------------------------
void MapScroll::setCenterViewByScr(const QPoint centerPoint_)
{
    horizontalScrollBar()->minimum();
    horizontalScrollBar()->value();
    horizontalScrollBar()->maximum();
    verticalScrollBar()->minimum();
    verticalScrollBar()->value();
    verticalScrollBar()->maximum();

    widget->hide();
    horizontalScrollBar()->setValue(centerPoint_.x() - viewport()->width() / 2);
    verticalScrollBar()->setValue(centerPoint_.y() - viewport()->height() / 2);
    widget->show();
}

//------------------------------------------------------------
void MapScroll::changeScale(float kChange_)
{
    if (!gisData.IsLoaded())
    {
        return;
    }

    QPoint centerView;

    centerView.setX(horizontalScrollBar()->value() + viewport()->width() / 2);
    centerView.setY(verticalScrollBar()->value() + viewport()->height() / 2);

    widget->hide();
    centerView = gisData.changeShowScale(centerView, kChange_);

    widget->resize(gisData.getPictureWidth(), gisData.getPictureHeigth());

    horizontalScrollBar()->setValue(centerView.x() - viewport()->width() / 2);
    verticalScrollBar()->setValue(centerView.y() - viewport()->height() / 2);

    widget->show();
}

//-----------------------------------------------------------
void MapScroll::slotSetShowTypeSC(GISTYPESC data_)
{
    appGisOptions.typeSC = data_;
}

//-----------------------------------------------------------
void MapScroll::slotSetShowTypeValue(GISVALUETYPE data_)
{
    appGisOptions.typeValue = data_;
}


//----------------------------------------------------------
void MapScroll::mousePressEvent(QMouseEvent *event)
{
//  objSecPoint = event->pos();
//    DOUBLEPOINT mmPoint = getMMCoordByScreen(event->pos()); //получить координаты точки (x,y)

}
//----------------------------------------------------------
void MapScroll::mouseMoveEvent(QMouseEvent *event_)
{

    if(!gisData.IsLoaded())
    {
        return;
    }
    emit signalMapPointByMouseMove(getMapPointByMM(getMMCoordByScreen(event_->pos())));
    QString coordasstr = getMapPointByMMAsStr(getMMCoordByScreen(event_->pos()));
    emit signalMapPointStrByMouseMove(coordasstr);



}

//----------------------------------------------------------
void MapScroll::mouseReleaseEvent(QMouseEvent *event_)
{
    if(!gisData.IsLoaded())
    {
        return;
    }
    DOUBLEPOINT mmpoint = getMMCoordByScreen(event_->pos());
    emit signalMapPointByMouseRelese(getMapPointByMM(mmpoint));
    emit signalMMPointByMouseRelese(mmpoint);
    emit signalWGS84DegreePoint(getWGS84DgrPointByMM(mmpoint));
    emit signalMapPointStrByMouseRelese(getMapPointByMMAsStr(mmpoint));


    if(centerMode)
    {
        setCenterViewByMM(mmpoint);
        centerMode = false;
        //TODO: emit signal for up buton
    }

    if(getTmpCoordMode())
    {
        setTmpMMCoord(mmpoint);
        widget->repaint();
    }
}

//------------------------------------------------------------
QPoint MapScroll::getScreenCoordByMM(DOUBLEPOINT mmCoord_)
{
    return gisData.getScrCoordByMM(mmCoord_);
}

//------------------------------------------------------------
DOUBLEPOINT MapScroll::getMMCoordByScreen(QPoint scrpoint_)
{
    DOUBLEPOINT tmpMMPoint;
    tmpMMPoint.x = scrpoint_.x() + horizontalScrollBar()->sliderPosition();
    tmpMMPoint.y = scrpoint_.y() + verticalScrollBar()->sliderPosition();
    return gisData.getMMCoordByScr(tmpMMPoint);
}

//------------------------------------------------------------
DOUBLEPOINT MapScroll::getMapPointByMM(DOUBLEPOINT mmpoint_)
{
    DOUBLEPOINT respoint;
    switch(appGisOptions.typeSC)
    {
    case GTCS_ERR:
        {
            respoint.x = -1111111;
            respoint.y = -1111111;
            break;
        }
    case GTCS_MM:
        {
            respoint = mmpoint_;
            break;
        }
    case GTCS_GK42:
        {
            gisData.MMCoord_to_SC42(mmpoint_, respoint);
            gisData.SC42_to_WGS84(respoint, respoint);
            gisData.WGS84_to_GK42(respoint, respoint);
            break;
        }
    case GTCS_SC42:
        {
            gisData.MMCoord_to_SC42(mmpoint_, respoint);
            break;
        }
    case GTCS_WGS84:
        {
            gisData.MMCoord_to_SC42(mmpoint_, respoint);
            gisData.SC42_to_WGS84(respoint, respoint);
            break;
        }
    case GTCS_PZ90:
        {
            gisData.MMCoord_to_SC42(mmpoint_, respoint);
            gisData.SC42_to_PE90(respoint, respoint);
            break;
        }
    case GTCS_UTM:
        {
            gisData.MMCoord_to_SC42(mmpoint_, respoint);
            gisData.SC42_to_UTM(respoint, respoint);
            break;
        }
    }
    if(appGisOptions.typeValue == GVT_DEG)
    {
        respoint = servfunc::convertRadToDegree(respoint);
    }
    return respoint;
}

DOUBLEPOINT MapScroll::getWGS84DgrPointByMM(DOUBLEPOINT mmpoint_)
{
    DOUBLEPOINT respoint;
    gisData.MMCoord_to_SC42(mmpoint_, respoint);
    gisData.SC42_to_WGS84(respoint, respoint);
    return servfunc::convertRadToDegree(respoint);
}

//------------------------------------------------------------
QString MapScroll::getMapPointByMMAsStr(DOUBLEPOINT mmpoint_)
{
    DOUBLEPOINT respoint = getMapPointByMM(mmpoint_);
    QString str;
    if(appGisOptions.typeSC == GTCS_MM || appGisOptions.typeSC == GTCS_GK42 || appGisOptions.typeSC == GTCS_UTM)
    {
        str = tr("X = %1 м  Y = %2 м").
              arg(QString::number(respoint.x, 'g', 7)).
              arg(QString::number(respoint.y, 'g', 7));
    }
    else
    {
        if(appGisOptions.typeValue == GVT_RAD)
        {
            str = tr("B = %1 rad  L = %2 rad").arg(respoint.x).arg(respoint.y);
        }
        else
        {
            str = tr("B = %1°  L = %2°").arg(respoint.x).arg(respoint.y);
        }
    }
    return str;
}

//-------------------------------------------------------------------
QString MapScroll::getMapFileName()
{
    return gisData.getNameMapFile();
}

//-------------------------------------------------------------------
bool MapScroll::isLoaded()
{
    return gisData.IsLoaded();
}

//-------------------------------------------------------------------
void MapScroll::slotUpdateViewOptions()
{
    if(!gisData.IsLoaded() || !QFile::exists(getIniName()))
    {
        return;
    }

    readMapSettings();

    QSettings appSettings;
    servfunc::readAppGisOptions(&appSettings, appGisOptions);
    servfunc::readPathShowOptions(&appSettings, appPathShowOptions);

    repaint();
}

//-------------------------------------------------------------
void MapScroll::slotSetCenterMode(bool set_)
{
    centerMode = set_;
}

DOUBLEPOINT MapScroll::invertWGSfromPhoto(DOUBLEPOINT wgspoint_)
{
    double tmpX = wgspoint_.x;
    wgspoint_.x = wgspoint_.y;
    wgspoint_.y = tmpX;
    return wgspoint_;
}


//--------------------------------------------------------------
void MapScroll::setPathFromFile(bool data_)
{
    pathFromFile = data_;
}

//--------------------------------------------------------------
QString MapScroll::getPathName()
{
    return fileNameCurPath;
}

//--------------------------------------------------------------
bool MapScroll::isLoadPath()
{
    return pathFromFile;
}

void MapScroll::slotSetTmpCoordMode(bool mode_)
{
    setTmpCoordMode(mode_);
    if(!getTmpCoordMode())
    {
        tmpCoord.x = -11111;
        tmpCoord.y = -11111;
        widget->repaint();
    }

}
