#ifndef GISPROVIDER_H
#define GISPROVIDER_H

#include <QString>
#include "./GISFuncPointer.h"


class GISProvider
{

protected:
    HMAP hmap;             //идентификатор открытых данных
    HSELECT hselect;       //идентификатор контекста условий поиска и отображения
    long m_nummtr;
    QString m_FileName;
    QString m_MtrName;

    SharedGISLibrary GISLibrary;  //Функционал для работы с картой (реализованы методы mapapi.h)

public:
    GISProvider():
        hmap(NULL),
        hselect(NULL),
        m_FileName(""),
        m_MtrName(""){}

    ~GISProvider() { CloseData(); }

    bool LoadMapData(const char*,
                     const char*,
                     bool MtrExsist_ = true);

    bool createMapFromSXF(const char*,
                          const char*,
                          const char*,
                          HWND hwnd_ = NULL);

    int addMtrToMap(const char*);
    int addMtqToMap(const char*);

    bool CloseData();
    bool IsLoaded() const;
    QString getNameMapFile() const
    {
        return m_FileName;
    }

    long int getBaseScale();

    double getMapX1();
    double getMapY1();
    double getMapX2();
    double getMapY2();
    double getMapWidth();
    double getMapHeight();

//
    bool MMCoord_to_SC42(DOUBLEPOINT mmPoint_, DOUBLEPOINT &sc42GeoPoint_);// const;
    bool SC42_to_MM(const DOUBLEPOINT &srcpoint_, DOUBLEPOINT& dstpoint_);// const;

    bool WGS84_to_GK42(DOUBLEPOINT, DOUBLEPOINT&);// const;
    bool WGS84_to_SC42(DOUBLEPOINT, DOUBLEPOINT&);// const;
    bool PE90_to_SC42(DOUBLEPOINT, DOUBLEPOINT&);// const;
    bool SC42_to_PE90(DOUBLEPOINT, DOUBLEPOINT&);// const;
    bool SC42_to_WGS84(DOUBLEPOINT, DOUBLEPOINT&);// const;
    bool SC42_to_UTM(DOUBLEPOINT, DOUBLEPOINT&);// const;

    bool GK42_to_SC42(DOUBLEPOINT, DOUBLEPOINT&);// const;

    bool WGS84_to_MM(DOUBLEPOINT, DOUBLEPOINT&);



    DOUBLEPOINT MM_to_Geo(DOUBLEPOINT);// const;
    DOUBLEPOINT Geo_to_MM(DOUBLEPOINT);// const;


    double getDistance(DOUBLEPOINT, DOUBLEPOINT);
    std::vector<double> getHeightArray(const double&, const DOUBLEPOINT&, const DOUBLEPOINT&);
    double getHPointByMM(const DOUBLEPOINT&);
    double getMtqValueByMM(const DOUBLEPOINT&, long int nummtqnum_ = 1);


    int getCountLayers();
    const char* getNameLayerByNum(int);
    bool isLayerChecked(int);
    bool isLayerChecked(int, HSELECT hsel_);
    void setCheckedLayerByNum(int num_, bool check_, HSELECT hsel_);
    void setCheckedLayerByNum(int num_, bool check_);

    int getCountObjInLayer(int);
    std::string getNameObjInLayer(int, int);
    int getCodeObjInLayer(int, int);
    bool isCheckedObjInLayer(int, int);
    bool isCheckedObjInLayer(int, int, HSELECT);
    void setCheckedObjByCode(int code_, bool check_, HSELECT hsel_);
    void setCheckedObjByCode(int code_, bool check_);


    int getViewSelContext(HSELECT&);
    void setSelViewContext(const HSELECT&);
    void reloadSelViewContext();

};


#endif // GISPROVIDER_H
