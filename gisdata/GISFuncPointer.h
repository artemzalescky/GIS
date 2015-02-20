#ifndef GISFUNCPOINTERS_H
#define GISFUNCPOINTERS_H


#include <cassert>
#include <vector>

#include "../Library/mapapi.h"

typedef void* (*FUNC)();
typedef FUNC* PFUNC;

/*Динамическая библиотека ГИС*/
class SharedGISLibrary
{

private:

    class GISFuncPointer
    {

    public:
        GISFuncPointer()
            : pFun(0)
        {
        }

        void Set( HINSTANCE libHandle_, const char *funName_);
        inline PFUNC Get() const { assert(pFun != 0); return pFun; }


    private:
        PFUNC pFun;   //????????????
    };

public:
    SharedGISLibrary();
    ~SharedGISLibrary();

private:
    HINSTANCE libAccesHandle;      // typedef long int HINSTANCE;
    HINSTANCE libVecexHandle;      // typedef long int HINSTANCE;


private:
    void loadLibrary();
    void freeLibrary();
    void setPointers();


private:
    GISFuncPointer funLoadMap;
    GISFuncPointer funLoadMtrForMap;
    GISFuncPointer funcOpenMtqForMap;
    GISFuncPointer funLoadSXFToMap;
    GISFuncPointer funLoadMapByDIR;

    GISFuncPointer funCloseMap;
    GISFuncPointer funCloseMtr;
    GISFuncPointer funcCloseMtqForMap;

    GISFuncPointer funGetHeightValue;
    GISFuncPointer funGetArrHeight;

    GISFuncPointer funGetMtqValue;
    GISFuncPointer funcPutMtqValue;

    GISFuncPointer funGetDistance;

    GISFuncPointer funGetPictureWidth;
    GISFuncPointer funGetPictureHeight;
    GISFuncPointer funGetShowScale;
    GISFuncPointer funChangeShowScale;
    GISFuncPointer funSetShowScale;  // Установить масштаб отображения (знаменатель масштаба)

    GISFuncPointer funGetBaseScale;

    GISFuncPointer funGetMapX1;
    GISFuncPointer funGetMapY1;
    GISFuncPointer funGetMapX2;
    GISFuncPointer funGetMapY2;


    GISFuncPointer funSupportGeoConvert;
    GISFuncPointer funMMToScr;
    GISFuncPointer funScrToMM;

    GISFuncPointer funSC42toMM;
    GISFuncPointer fumMMtoGeo;
    GISFuncPointer funGeotoMM;
    GISFuncPointer funMMtoGeo42;
    GISFuncPointer funMMtoGeo84;
    GISFuncPointer funWGS84toGC42;   // GS84 геграфические координаты google
    GISFuncPointer funWGS84toSC42;
    GISFuncPointer funSC42toWGS84;
    GISFuncPointer funPZ90ToSc42;
    GISFuncPointer funSC42toPZ90;
    GISFuncPointer funGK42toSC42byZone;

    GISFuncPointer funSC42toUTM;

    GISFuncPointer funPaintToDib;
    GISFuncPointer funPaintMapImage;

    GISFuncPointer funSetMtrViewType;
    GISFuncPointer funSetMapViewType;
    GISFuncPointer funSetMapViewBright;
    GISFuncPointer funSetMapViewContrast;
    GISFuncPointer funSetMapViewBackColor;

    GISFuncPointer funcBuildMTW;

    GISFuncPointer funGetMapInfoEx;
    GISFuncPointer funGetMapType;

    GISFuncPointer funcGetCountLayers;
    GISFuncPointer funcGetNameLayer;
    GISFuncPointer funcReadCheckLayer;

    GISFuncPointer funcGetCountObjInLayer; //????????
    GISFuncPointer funcGetNameObjInLayer;  //????????
    GISFuncPointer funcGetCodeObjInLayer;  //????????
    GISFuncPointer funcReadObjChecked;     //????????

    GISFuncPointer funcSelectLayer;
    GISFuncPointer funcSelectObj;


    GISFuncPointer funCreateSelCont;
    GISFuncPointer funDeleteSelCont;
    GISFuncPointer funcSetViewSelect;
    GISFuncPointer funcGetViewSelect;


public:
    HMAP loadMap(const char* mapName_, int mode_);
    long int loadMtwForMap(HMAP handle_, const char *name_ , int mode_);
    long int openMtqForMap(HMAP hMap,
                           const char* mtqname,
                           long int mode);
    long int loadSxf2Map(const char*, const char*, const char*, HWND);


    long int loadMapByDIR(const char* nameDIR_, // наименование dir-файла
                          const char* nameMap_, // наименование создаваемого файла карты
                          HWND messageHandle_);

    long int getMapInfoEx(HMAP, long int, MAPREGISTEREX*, LISTREGISTER*);
    long int getMapType(HMAP);

    int closeData(HMAP);
    void closeMtr(HMAP, long int num_ = 0);
    long int closeMtqForMap(HMAP hMap,
                            long int number);

    double getHeightValue(HMAP, double, double);
    double getHPointByCoordMM(HMAP&, DOUBLEPOINT);
    std::vector<double> getHeightArrayByStep(HMAP, double, DOUBLEPOINT*, DOUBLEPOINT*);
    long int getHeightArraByCount(HMAP, double*, long int, DOUBLEPOINT*, DOUBLEPOINT*);

    double getMtqValue(HMAP, long int, double, double);
    long int putMtqValue(HMAP, long int, double, double, double);
    double getMTQValueByCoordMM(HMAP&, DOUBLEPOINT, int numMtq_ = 1);
    long int putMtqValueByCoordMM(HMAP&, DOUBLEPOINT, double, int numMtq_ = 1);

    double getDistance(DOUBLEPOINT* pntA_, DOUBLEPOINT* pntB_);

    long int getMapPictureWidth(HMAP);
    long int getMapPictureHeight(HMAP);

    bool isConvertSupported(HMAP);
    // Преобразование из пикселов в изображении в координаты на местности в метрах
    DOUBLEPOINT translatePictureToMM(HMAP handle_, DOUBLEPOINT point_);
    DOUBLEPOINT translateMMToPicture(HMAP handle_, DOUBLEPOINT point_);

    DOUBLEPOINT translateGeo42ToMM(HMAP, DOUBLEPOINT, double);
    DOUBLEPOINT translateMMToGeo(HMAP, DOUBLEPOINT);
    DOUBLEPOINT translateGeoToMM(HMAP, DOUBLEPOINT);

    bool translateMMToGeo42(HMAP hmap_, DOUBLEPOINT mmPoint_, DOUBLEPOINT &geo42Point_);
    bool translateMMToGeo84(HMAP hmap_, DOUBLEPOINT mmPoint_, DOUBLEPOINT &geo42Point_);
    bool translateWGS84ToGK42(HMAP hmap_, DOUBLEPOINT geo84Point_, DOUBLEPOINT &gk42Point_);
    bool translateWGS84ToSC42(HMAP hmap_, DOUBLEPOINT geo84Point_, DOUBLEPOINT &geo42Point_);
    bool translateSC42ToWGS84(HMAP hmap_, DOUBLEPOINT geo42Point_, DOUBLEPOINT &geo84Point_);
    bool translatePZ90ToSC42(HMAP hmap_, DOUBLEPOINT geo90Point_, DOUBLEPOINT &geo42Point_);
    bool translateSC42ToPZ90(HMAP hmap_, DOUBLEPOINT geo42Point_, DOUBLEPOINT &geo90Point_);

    bool translateGK42ToSC42ByZone(long int zone, DOUBLEPOINT, DOUBLEPOINT&);
    bool translateSC42ToUTM(HMAP hmap_, DOUBLEPOINT geo42Point_, DOUBLEPOINT &utmPoint_);

    int paintMapToXImage(HMAP, XIMAGEDESC*, int, int, RECT*);
    long int PaintMapToDib(HMAP, BITMAPINFOHEADER*, char*, RECT*);


    void SetMapViewType(HMAP, int);
    void SetMapViewBright(HMAP, int);
    void SetMapViewContrast(HMAP, int);
    void SetMtrViewType(HMAP, int, int);
    void SetMapViewBackColor(HMAP, int);

    double getX1(HMAP);
    double getY1(HMAP);
    double getX2(HMAP);
    double getY2(HMAP);

    double getMapWidth(HMAP);
    double getMapHeight(HMAP);

    //работа с масштабом
    int getBaseMapScale(HMAP);
    int getShowScale(HMAP);
    int changeShowScale(HMAP, long int*, long int*, float);

    // Установить масштаб отображения (знаменатель масштаба)
    int setShowScale(HMAP, long int*, long int*, float);


    int buildMTW(HMAP hMap,
                 const char* mtrname,
                 const char* filtername,
                 BUILDMTW* mtrparm,
                 HWND handle);


    // получить количество слоёв
    long int getCountLayers(HMAP);

    const char* getLayerName(HMAP, long int);
    long int isLayerChecked(HSELECT, long int);

    long int getCountObjInLayer(HMAP, long int);
    std::string getNameObjInLayer(HMAP, long int, long int);
    long int getCodeObjInLayer(HMAP, long int, long int);
    long int isObjChecked(HSELECT, long int);

    void selectLayer(HSELECT, int, int);
    void selectObj(HSELECT, long int, bool);

    HSELECT createSelectContecxt(HMAP);
    void deleteSelectContext(HSELECT);
    long int getViewSelect(HMAP, HSELECT);
    void setViewSelect(HMAP, HSELECT);

};


#endif // GISFUNCPOINTERS_H
