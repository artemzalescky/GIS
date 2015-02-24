#include "./userVFunctions.h"

#include <QFileInfo>
#include <QSettings>

QString servfunc::createMtwFileName(QString mapfilename_)
{
    mapfilename_.replace(mapfilename_.length() - 3, 3, "mtr");
    return mapfilename_;
}
QString servfunc::createMtqFileName(QString mapfilename_, int num_)
{
    QFileInfo mapFileInfo(mapfilename_);
    QString path = mapFileInfo.canonicalPath();
    QString name = mapFileInfo.completeBaseName();

    QString retName = QString("%1/%2_matr%3.mtq")
                             .arg(path)
                             .arg(name)
                             .arg(num_);
    return retName;
}
QString servfunc::createImhFileName(QString imhdir_, int num_)
{
    QString retName = QString("%1/exp_%2.imh")
                             .arg(imhdir_)
                             .arg(num_);
    return retName;
}


//Параметры отображения карты
void  servfunc::readMapShowOptions(QSettings* settings_, MAPSHOWOPTIONS& data_)
{

    settings_->beginGroup("/GISShowOptions");
        data_.typeMapShow = static_cast<TYPEMAPSHOW>(int(settings_->value("/TypeMapShow", 1).toInt()));
        data_.typeMtrShow = static_cast<TYPEMTRSHOW_>(settings_->value("/TypeMtrShow", 0).toInt());
        data_.valueBrigth = settings_->value("/ValueBr", 0).toInt();
        data_.valueContrast = settings_->value("/ValueContr", 0).toInt();
    settings_->endGroup();


}
//---------------------------------------------------------------
void  servfunc::writeMapShowOptions(QSettings* settings_, const MAPSHOWOPTIONS& data_)
{
    settings_->beginGroup("/GISShowOptions");
        settings_->setValue("/TypeMapShow", static_cast<int>(data_.typeMapShow));
        settings_->setValue("/TypeMtrShow", static_cast<int>(data_.typeMtrShow));
        settings_->setValue("/ValueBr", data_.valueBrigth);
        settings_->setValue("/ValueContr", data_.valueContrast);
    settings_->endGroup();
    settings_->sync();
}
//---------------------------------------------------------------
void  servfunc::readAppGisOptions(QSettings* settings_, APPGISOPTIONS& data_)
{
    settings_->beginGroup("/GISModOptions");
        settings_->beginGroup("/AppGISOptions");
            data_.typeSC = static_cast<GISTYPESC>(int(settings_->value("/TypeMapSC", 2).toInt()));
            data_.typeValue = static_cast<GISVALUETYPE>(settings_->value("/TypeValue", 0).toInt());
            data_.isVisibleCalcLine = settings_->value("/VisibleCalcLine", true).toBool();
            data_.widthCalcLine = settings_->value("/WidthCalcLine", 2).toInt();
            settings_->beginGroup("/ColorCalcLine");
                data_.colorCalcLine.setRed(settings_->value("/red", 1).toInt());
                data_.colorCalcLine.setGreen(settings_->value("/green", 1).toInt());
                data_.colorCalcLine.setBlue(settings_->value("/blue", 1).toInt());
            settings_->endGroup();
        settings_->endGroup();
    settings_->endGroup();
}
//---------------------------------------------------------------
void  servfunc::writeAppGisOptions(QSettings* settings_, const APPGISOPTIONS& data_)
{
    settings_->beginGroup("/GISModOptions");
        settings_->beginGroup("/AppGISOptions");
            settings_->setValue("/TypeMapSC", static_cast<int>(data_.typeSC));
            settings_->setValue("/TypeValue", static_cast<int>(data_.typeValue));
            settings_->setValue("/VisibleCalcLine", data_.isVisibleCalcLine);
            settings_->beginGroup("/ColorCalcLine");
                settings_->setValue("/red", data_.colorCalcLine.red());
                settings_->setValue("/green", data_.colorCalcLine.green());
                settings_->setValue("/blue", data_.colorCalcLine.blue());
            settings_->endGroup();
            settings_->setValue("/WidthCalcLine", data_.widthCalcLine);
        settings_->endGroup();
    settings_->endGroup();
    settings_->sync();
}


void servfunc::readPathShowOptions(QSettings* settings_, APPPATHSHOWOPTIONS& data_)
{
    settings_->beginGroup("/GISModOptions");
        settings_->beginGroup("/PathPaintData");
            data_.isVisibleCurPath = settings_->value("/PaintCurrentPath", true).toBool();
            data_.widthPathLine = settings_->value("/WidthPathLine", 3).toInt();
            data_.sizePathPoint = settings_->value("/SizePathPoint", 5).toInt();
            settings_->beginGroup("/ColorPathLine");
                data_.colorPathLine.setRed(settings_->value("/red", 1).toInt());
                data_.colorPathLine.setGreen(settings_->value("/green", 1).toInt());
                data_.colorPathLine.setBlue(settings_->value("/blue", 1).toInt());
            settings_->endGroup();
            settings_->beginGroup("/ColorActivePoint");
                data_.colorActivePoint.setRed(settings_->value("/red", 1).toInt());
                data_.colorActivePoint.setGreen(settings_->value("/green", 1).toInt());
                data_.colorActivePoint.setBlue(settings_->value("/blue", 1).toInt());
            settings_->endGroup();
            settings_->beginGroup("/ColorPathPoint");
                data_.colorPathPoint.setRed(settings_->value("/red", 1).toInt());
                data_.colorPathPoint.setGreen(settings_->value("/green", 1).toInt());
                data_.colorPathPoint.setBlue(settings_->value("/blue", 1).toInt());
            settings_->endGroup();
            settings_->beginGroup("/ColorModeSign");
                data_.colorModeSigns.setRed(settings_->value("/red", 1).toInt());
                data_.colorModeSigns.setGreen(settings_->value("/green", 1).toInt());
                data_.colorModeSigns.setBlue(settings_->value("/blue", 1).toInt());
            settings_->endGroup();
            settings_->beginGroup("/ColorPatrolBorder");
                data_.colorPatrolBorder.setRed(settings_->value("/red", 1).toInt());
                data_.colorPatrolBorder.setGreen(settings_->value("/green", 1).toInt());
                data_.colorPatrolBorder.setBlue(settings_->value("/blue", 1).toInt());
            settings_->endGroup();
            settings_->beginGroup("/ColorPLObj");
                data_.colorPLObj.setRed(settings_->value("/red", 1).toInt());
                data_.colorPLObj.setGreen(settings_->value("/green", 1).toInt());
                data_.colorPLObj.setBlue(settings_->value("/blue", 1).toInt());
            settings_->endGroup();

        settings_->endGroup();
    settings_->endGroup();
}

void servfunc::writePathShowOptions(QSettings* settings_, const APPPATHSHOWOPTIONS& data_)
{
    settings_->beginGroup("/GISModOptions");
        settings_->beginGroup("/PathPaintData");
            settings_->setValue("/PaintCurrentPath", data_.isVisibleCurPath);
            settings_->setValue("/WidthPathLine", data_.widthPathLine);
            settings_->setValue("/SizePathPoint", data_.sizePathPoint);
            settings_->beginGroup("/ColorPathLine");
                settings_->setValue("/red", data_.colorPathLine.red());
                settings_->setValue("/green", data_.colorPathLine.green());
                settings_->setValue("/blue", data_.colorPathLine.blue());
            settings_->endGroup();
            settings_->beginGroup("/ColorActivePoint");
                settings_->setValue("/red", data_.colorActivePoint.red());
                settings_->setValue("/green", data_.colorActivePoint.green());
                settings_->setValue("/blue", data_.colorActivePoint.blue());
            settings_->endGroup();
            settings_->beginGroup("/ColorPathPoint");
                settings_->setValue("/red", data_.colorPathPoint.red());
                settings_->setValue("/green", data_.colorPathPoint.green());
                settings_->setValue("/blue", data_.colorPathPoint.blue());
            settings_->endGroup();
            settings_->beginGroup("/ColorModeSign");
                settings_->setValue("/red", data_.colorModeSigns.red());
                settings_->setValue("/green", data_.colorModeSigns.green());
                settings_->setValue("/blue", data_.colorModeSigns.blue());
            settings_->endGroup();
            settings_->beginGroup("/ColorPatrolBorder");
                settings_->setValue("/red", data_.colorPatrolBorder.red());
                settings_->setValue("/green", data_.colorPatrolBorder.green());
                settings_->setValue("/blue", data_.colorPatrolBorder.blue());
            settings_->endGroup();
            settings_->beginGroup("/ColorPLObj");
                settings_->setValue("/red", data_.colorPLObj.red());
                settings_->setValue("/green", data_.colorPLObj.green());
                settings_->setValue("/blue", data_.colorPLObj.blue());
            settings_->endGroup();

        settings_->endGroup();
    settings_->endGroup();
    settings_->sync();
}

//---------------------------------------------------------------
void servfunc::writeLastMapName(QSettings* settings_, const QString str_)
{
    settings_->beginGroup("/DataFiles");
        settings_->setValue("/LastMapFile", str_);
    settings_->endGroup();
    settings_->sync();
}

//---------------------------------------------------------------
QString servfunc::readLastMapName(QSettings* settings_)
{
    settings_->beginGroup("/DataFiles");
        QString mapfilename = settings_->value("/LastMapFile", "").toString();
    settings_->endGroup();
    return mapfilename;
}

//------------------------------------------------------------
DOUBLEPOINT servfunc::convertRadToDegree(const DOUBLEPOINT& radpoint_)
{
    DOUBLEPOINT respoint;
    respoint.x = radpoint_.x * 180.0 / M_PI;
    respoint.y = radpoint_.y * 180.0 / M_PI;
    return respoint;
}

//------------------------------------------------------------
DOUBLEPOINT servfunc::convertDegreeToRad(const DOUBLEPOINT& degreepoint_)
{
    DOUBLEPOINT respoint;
    respoint.x = degreepoint_.x * M_PI / 180.0;
    respoint.y = degreepoint_.y * M_PI / 180.0;
    return respoint;
}
