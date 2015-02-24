#ifndef MAPSCROLL_H
#define MAPSCROLL_H

#include <QScrollArea>
#include <QString>
#include <QPixmap>

#include "../gisdata/GISPainter.h"
#include "../gisdata/GISTypes.h"
#include "../gisdata/userVFunctions.h"

class QWidget;
class QPainter;
class QFileInfo;

class MapScroll : public QScrollArea
{
    Q_OBJECT
public:
    MapScroll(QWidget * parent = 0);
    ~MapScroll();

private: //Data
    GISPainter gisData;

    RECT	rectDraw;
    QWidget	*widget;

    APPGISOPTIONS appGisOptions;           //настройки по умолчанию карты
    APPPATHSHOWOPTIONS appPathShowOptions; //настройка по умолчанию параметров  (PATH)

    bool centerMode;
    bool tmpCoordMode;
    bool pathFromFile;
    bool startObj;

    DOUBLEPOINT tmpCoord;    
    QPoint objSecPoint;


public:
     QString fileNameCurPath;

private:
    void setPathFromFile(bool data_);

    void setTmpCoordMode(bool);
    bool getTmpCoordMode();

    void setTmpMMCoord(DOUBLEPOINT);
    QPoint getTmpScrCoord();

    void readMapSettings();

    //Запись/чтение состава отображения карты
    void writeMapComposition(QSettings*);
    int readMapComposition(QSettings*);

    DOUBLEPOINT getMapPointByMM(DOUBLEPOINT);
    DOUBLEPOINT getWGS84DgrPointByMM(DOUBLEPOINT);
    QString getMapPointByMMAsStr(DOUBLEPOINT);

    void setGISViewParam(MAPSHOWOPTIONS);

//=== uobjpainter.cpp
    void paintCurrentPath(QPainter* painter_);
    void paintPLMode(QPainter* painter_, QPoint);
    void paintPatrolMode(QPainter* painter_, QPoint center_);

    void paintObjByMove(QPainter*, QPoint);
    void paintCurrentCritSheme(QPainter* painter_);


//===
public:
    QString getIniName();
    GISPainter* getGISDataP();
    QString getPathName();
    bool isLoadPath();
    bool isPathValid();

    bool getPhotoMod();
    void setPhotoMod(bool);

public:
    int loadMapFile(QString);
    QString converSXF2Map(QString, QFileInfo*);
    void closeMapData();
    QString getMapFileName();
    bool isLoaded();

    void changeScale(float);

    void setCenterViewByMM(DOUBLEPOINT);
    void setCenterViewByScr(const QPoint);

    QPoint getScreenCoordByMM(DOUBLEPOINT);
    DOUBLEPOINT getMMCoordByScreen(QPoint);

    DOUBLEPOINT invertWGSfromPhoto(DOUBLEPOINT);

protected:
    bool eventFilter (QObject * watched, QEvent * event);

private:
    virtual void mousePressEvent(QMouseEvent *event_);
    virtual void mouseMoveEvent(QMouseEvent *event_);
    virtual void mouseReleaseEvent(QMouseEvent *event_);

public slots:
    void slotSetShowTypeSC(GISTYPESC);
    void slotSetShowTypeValue(GISVALUETYPE);
    void slotUpdateViewOptions();


    void slotSetCenterMode(bool);

    void slotSetTmpCoordMode(bool);

signals:
    void signalGetShowTypeSC(GISTYPESC);
    void signalGetShowTypeValue(GISVALUETYPE);
    void signalMapPointByMouseRelese(DOUBLEPOINT);
    void signalMMPointByMouseRelese(DOUBLEPOINT);
    void signalWGS84DegreePoint(DOUBLEPOINT);

    void signalMapPointByMouseMove(DOUBLEPOINT);
    void signalMapPointStrByMouseRelese(QString);
    void signalMapPointStrByMouseMove(QString);

    void signalSetDistance(double);

    void signalGetMapName(QString);

};


#endif // MAPSCROLL_H
