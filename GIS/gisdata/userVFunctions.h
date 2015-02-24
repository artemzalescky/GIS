#ifndef USERVFUNCTIONS_H
#define USERVFUNCTIONS_H

#include <QString>
#include <QSettings>
#include "GISTypes.h"

//#include <mapapi.h>

#include "../Library/mapapi.h"

namespace servfunc
{
    QString createMtwFileName(QString mapfilename_);
    QString createMtqFileName(QString mapfilename_, int num_);
    QString createImhFileName(QString imhdir_, int num_);

    //установка и считывание настроек по умолчанию (GISTYPES.h)
    void readMapShowOptions(QSettings*, MAPSHOWOPTIONS&);
    void writeMapShowOptions(QSettings*, const MAPSHOWOPTIONS&);

    void readAppGisOptions(QSettings*, APPGISOPTIONS&);
    void writeAppGisOptions(QSettings*, const APPGISOPTIONS&);

    void readPathShowOptions(QSettings*, APPPATHSHOWOPTIONS&);
    void writePathShowOptions(QSettings*, const APPPATHSHOWOPTIONS&);

    void writeLastMapName(QSettings*, const QString);
    QString readLastMapName(QSettings*);

    DOUBLEPOINT convertRadToDegree(const DOUBLEPOINT&);
    DOUBLEPOINT convertDegreeToRad(const DOUBLEPOINT&);
}

#endif // USERVFUNCTIONS_H
