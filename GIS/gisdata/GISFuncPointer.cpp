#include <memory>
#include <QDebug>

#include "GISFuncPointer.h"

#define LIBMAPACCESNAME "libqdmapacces.so"
#define LIBMAPVECEXNAME "libqdmapvecex.so"


//---------------------------------------------------------------------------
/**
 * @brief SharedGISLibrary::GISFuncPointer::Set ������������� ����� ����� �������� ���������� � �������� ������
 * @param libHandle_ - ��� ����������
 * @param funName_ - ��� �������
 */
void SharedGISLibrary::GISFuncPointer::Set(HINSTANCE libHandle_, const char *funName_ )
{

 pFun = reinterpret_cast<PFUNC>(dlsym(reinterpret_cast<void *>(libHandle_), funName_));
    if(!pFun)
    {
        qDebug() << "Error loading " << funName_;
    }

    assert(pFun);         //?????????????????????????
}

//---------------------------------------------------------------------------
SharedGISLibrary::SharedGISLibrary()
    : libAccesHandle(0)
    , libVecexHandle(0)
{
    loadLibrary();
    setPointers();
}

SharedGISLibrary::~SharedGISLibrary()
{
    freeLibrary();
}

/**
 * @brief SharedGISLibrary::loadLibrary ��������� libqdmapacces.so"  "libqdmapvecex.so"
 */
void SharedGISLibrary::loadLibrary()
{
    assert(libAccesHandle == 0);
    assert(libVecexHandle == 0);


        libAccesHandle = (HINSTANCE)dlopen(LIBMAPACCESNAME, RTLD_LAZY);
        libVecexHandle = (HINSTANCE)dlopen(LIBMAPVECEXNAME, RTLD_LAZY);

        if(libAccesHandle == 0)
        {
            qDebug()<<"error MAPAPI lib Acces loading" << LIBMAPACCESNAME;
            assert(libAccesHandle != 0);
        }

        if(libVecexHandle == 0)
        {
            qDebug()<<"error MAPAPI lib Vecex loading" << LIBMAPVECEXNAME;
            assert(libVecexHandle != 0);
        }
}

/**
 * @brief SharedGISLibrary::freeLibrary ������� libAccesHandle � libVecexHandle
 */
void SharedGISLibrary::freeLibrary()
{
        dlclose((void *)libAccesHandle);
        dlclose((void *)libVecexHandle);
}

//---------------------------------------------------------------------------
void SharedGISLibrary::setPointers()
{
    funLoadMap.Set(libAccesHandle, "mapOpenData");
    funLoadMtrForMap.Set(libAccesHandle, "mapOpenMtrForMap");
    funcOpenMtqForMap.Set(libAccesHandle, "mapOpenMtqForMap");
    funLoadSXFToMap.Set(libVecexHandle, "LoadSxfToMap");
    funLoadMapByDIR.Set(libVecexHandle, "LoadDirToMap");

    funCloseMap.Set(libAccesHandle, "mapCloseData");
    funCloseMtr.Set(libAccesHandle, "mapCloseMtrForMap");
    funcCloseMtqForMap.Set(libAccesHandle, "mapCloseMtqForMap");

    funGetHeightValue.Set(libAccesHandle, "mapGetHeightValue");
    funGetArrHeight.Set(libAccesHandle, "mapGetHeightArray");

    funGetMtqValue.Set(libAccesHandle, "mapGetMtqValue");
    funcPutMtqValue.Set(libAccesHandle, "mapPutMtqValue");

    funGetDistance.Set(libAccesHandle, "mapDistance");

    funGetPictureHeight.Set(libAccesHandle, "mapGetPictureHeight");
    funGetPictureWidth.Set(libAccesHandle, "mapGetPictureWidth");

// ������� ����������� ����� � XImage (������)  ������ ������� ����������� ��� XWindow !
// �������� ��������� XIMAGEDESC � maptype.h
    funPaintMapImage.Set(libAccesHandle, "mapPaintToXImage");


    funGetShowScale.Set(libAccesHandle, "mapGetShowScale");

     // �������� ������� ����������� ������������ ��������
    funChangeShowScale.Set(libAccesHandle, "mapChangeViewScale");

    // ���������� ������� ����������� (����������� ��������)
    funSetShowScale.Set(libAccesHandle, "mapSetViewScale");

    funGetBaseScale.Set(libAccesHandle, "mapGetMapScale"); // ��������� ������� ������� �����


    // ��������� ������������� ���������� ��������� �������� ��������� �����
    // � ������ (������� ��������� PLANE)
    funGetMapX1.Set(libAccesHandle, "mapGetMapX1");
    funGetMapY1.Set(libAccesHandle, "mapGetMapY1");
    funGetMapX2.Set(libAccesHandle, "mapGetMapX2");
    funGetMapY2.Set(libAccesHandle, "mapGetMapY2");




    funSupportGeoConvert.Set(libAccesHandle, "mapIsGeoSupported");


    // �������������� �� �������� � ����������� � ���������� �� ��������� � ������
    funScrToMM.Set(libAccesHandle, "mapPictureToPlane");
    // �������������� �� ������ �� ��������� � ������� �� �����������
    funMMToScr.Set(libAccesHandle, "mapPlaneToPicture");


// �������������� �� ������ �� ��������� � ������������� ���������� � �������� � ������������ � ��������� �����
    fumMMtoGeo.Set(libAccesHandle, "mapPlaneToGeo");
// �������������� �� ������������� ��������� � �������� � ����� �� ��������� � ������������ � ��������� �����
    funGeotoMM.Set(libAccesHandle, "mapGeoToPlane");
// �������������� �� ������������� ��������� � �������� ( ��-42) ����� �� ��������� � �������� �����
    funSC42toMM.Set(libAccesHandle, "mapGeo42ToPlane3D");
// �������������� �� ������ �� ��������� � ������������� ���������� � �������� (��-42)
    funMMtoGeo42.Set(libAccesHandle, "mapPlaneToGeo42");
// �������������� �� ������ �� ��������� (�������� �����) � ������������� ���������� � �������� (WGS84)
    funMMtoGeo84.Set(libAccesHandle, "mapPlaneToGeoWGS84");
// �������������� �� ������������� ��������� � ������� (WGS84)� ����� �� ��������� � ������� 1942�
    funWGS84toGC42.Set(libAccesHandle, "mapGeoWGS84ToPlane42");
    funWGS84toSC42.Set(libAccesHandle, "mapGeoWGS84ToGeo42");
    funSC42toWGS84.Set(libAccesHandle, "mapGeo42ToGeoWGS84");
    funPZ90ToSc42.Set(libAccesHandle, "mapGeoEP90ToGeo42");
    funSC42toPZ90.Set(libAccesHandle, "mapGeo42ToGeoEP90");

// �������������� ��������� � ������ �� ��������� �� �������� ���� � ������������� ���������� � ������� 42�.
// zone - ����� �������� ���� ������� 1942�
    funGK42toSC42byZone.Set(libAccesHandle, "mapPlane42ToGeo42ByZone");

// �������������� ������������� ��������� � �������� �� ������� 1942 �
// (��������� �����������) � ������������� � ������ � ������� NAHRWAN �
// �������� UTM (��������� ������ 1880�.) - NAD27
    funSC42toUTM.Set(libAccesHandle, "mapGeo42ToPlaneUTM");

    funSetMtrViewType.Set(libAccesHandle, "mapSetMtrView");
    funSetMapViewType.Set(libAccesHandle, "mapSetViewType");
    funSetMapViewBright.Set(libAccesHandle, "mapSetBright");
    funSetMapViewContrast.Set(libAccesHandle, "mapSetContrast");
    funSetMapViewBackColor.Set(libAccesHandle, "mapSetBackColor");

    funcBuildMTW.Set(libAccesHandle, "mapBuildMtw");

    funGetMapInfoEx.Set(libAccesHandle, "mapGetMapInfoEx"); // ��������� ���������� ������ ��������� �����
    funGetMapType.Set(libAccesHandle, "mapGetMapType");     // �������� ��� �����


    funcGetCountLayers.Set(libAccesHandle, "mapGetLayerCount");
    funcGetNameLayer.Set(libAccesHandle, "mapGetLayerName");
    funcReadCheckLayer.Set(libAccesHandle, "mapCheckLayer");

    funcGetCountObjInLayer.Set(libAccesHandle, "mapRscObjectCountInLayer");
    funcGetNameObjInLayer.Set(libAccesHandle, "mapRscObjectNameInLayer");
    funcGetCodeObjInLayer.Set(libAccesHandle, "mapRscObjectCodeInLayer");
    funcReadObjChecked.Set(libAccesHandle, "mapCheckObject");

    funcSelectLayer.Set(libAccesHandle, "mapSelectLayer");
    funcSelectObj.Set(libAccesHandle, "mapSelectObject");

    funCreateSelCont.Set(libAccesHandle, "mapCreateMapSelectContext");
    funDeleteSelCont.Set(libAccesHandle, "mapDeleteSelectContext");
    funcSetViewSelect.Set(libAccesHandle, "mapSetViewSelect");
    funcGetViewSelect.Set(libAccesHandle, "mapGetViewSelect");

}


/**
 * @brief SharedGISLibrary::loadMap ������� ������ � �������������� ������������ �� ����
 * (���������,���������,���������...)
 * @param mapName_ ��� ������������ ����� (MAP, SIT, MTW, RSW, MPT)
 * @param mode_ ����� ������/������ (GENERIC_READ, GENERIC_WRITE ��� 0)
 * @return ��� ������ ���������� ����
 */
HMAP SharedGISLibrary::loadMap(const char* mapName_, int mode_)
{
    typedef HMAP (WINAPI * functype)(const char*, int);

    functype func = reinterpret_cast<functype>(funLoadMap.Get());
    return func(mapName_, mode_);
}


long int SharedGISLibrary::loadMtwForMap( HMAP handle_, const char *name_ , int mode_ )
{
    typedef long int (WINAPI * funtype)(HMAP, const char*, int);
    funtype fun = reinterpret_cast<funtype>(funLoadMtrForMap.Get());
    return fun(handle_, name_, mode_);
}

//----------------------------------------------------------------------------------
long int SharedGISLibrary::loadSxf2Map(const char* sxfname_, const char* rscname_, const char* mapname_, HWND hwnd_)
{
    typedef long int (WINAPI * funtype)(char*, char*, char*, HWND);
    funtype fun = reinterpret_cast<funtype>(funLoadSXFToMap.Get());
    return fun(const_cast<char*>(sxfname_), const_cast<char*>(mapname_), const_cast<char*>(rscname_), hwnd_);
}

long int SharedGISLibrary::loadMapByDIR(const char* nameDIR_, // ������������ dir-�����
                                         const char* nameMap_, // ������������ ������������ ����� �����
                                         HWND messageHandle_)
{
    typedef long int (WINAPI* funtype)(const char*, const char*, HWND);
    funtype func = reinterpret_cast<funtype>(funLoadMapByDIR.Get());
    return func(nameDIR_, nameMap_, messageHandle_);
}



//---------------------------------------------------------------------------
int SharedGISLibrary::closeData(HMAP handle_)
{
    typedef long int (WINAPI * funtype)(HMAP);
    funtype func = reinterpret_cast<funtype>(funCloseMap.Get());
    return func(handle_);
}

//---------------------------------------------------------------------------
void SharedGISLibrary::closeMtr(HMAP handle_, long int nu)
{
    typedef long int (WINAPI * funtype)(HMAP, long int);
    funtype fun = reinterpret_cast<funtype>(funCloseMtr.Get());
    fun(handle_, nu);
}

//---------------------------------------------------------------------------
long int SharedGISLibrary::getMapPictureWidth(HMAP handle_)
{
    typedef int (WINAPI * functype)(HMAP);
    functype fun = reinterpret_cast<functype>(funGetPictureWidth.Get());
    return fun(handle_);
}

//---------------------------------------------------------------------------
long int SharedGISLibrary::getMapPictureHeight(HMAP handle_)
{
    typedef int (WINAPI * functype)(HMAP);
    functype fun = reinterpret_cast<functype>(funGetPictureHeight.Get());
    return fun(handle_);
}

//----------------------------------------------------------------------------
// ������� ����������� ����� � XImage (������)
// ������ ������� ����������� ��� XWindow !
// �������� ��������� XIMAGEDESC � maptype.h
// hmap - ������������� �������� ������
// x,y - ���������� ������ �������� ���� ������
// ������� ������� XImage ��� ���������� �����������
// rect - ��������� �������� �����
// ��� ������ � ���������� ���������� ����
int SharedGISLibrary::paintMapToXImage(HMAP hmap_, XIMAGEDESC* adr_, int a_, int b_, RECT* paintrec_)
{
    typedef int (WINAPI * functype)(HMAP, XIMAGEDESC*, long int, long int,  RECT*);
    functype fun = reinterpret_cast<functype>(funPaintMapImage.Get());
    return fun(hmap_, adr_, a_, b_, paintrec_);
}


//----------------------------------------------------------------------------
long int SharedGISLibrary::PaintMapToDib(HMAP handle_, BITMAPINFOHEADER* info_, char* data_, RECT* rect_)
{
    typedef long int (WINAPI * FunPaintMap)(HMAP, BITMAPINFOHEADER*, char*, RECT*);
    FunPaintMap fun = reinterpret_cast<FunPaintMap>(funPaintToDib.Get());
    return fun(handle_, info_, data_, rect_);
}

//----------------------------------------------------------------------------
// ��������� ����������� ������� ����������� �����
 // hmap - ������������� �������� ������
 // ���������� �������� ����������� ��������
int SharedGISLibrary::getShowScale(HMAP hmap_)
{
    typedef int (WINAPI * functype)(HMAP);
    functype fun = reinterpret_cast<functype>(funGetShowScale.Get());
    return fun(hmap_);
}

//----------------------------------------------------------------------------
// �������� ������� ����������� ������������ ��������
//  ���������:
//          hmap - ������������� �������� ������
//          x, y - ���������� ��������������� "������ �����������"
//                 (����� ����� ��������) � ���� � ������� ��������
//        change - ����������� ��������� �������� �������� �����������
//                 0 < change < 1 , ��� ������
//                 1 < change < N , ��� ����������
//  ����������:   0 - ������� �� ���������,  1 - ������� ���������
//          x, y - ���������� ��������������� "������ �����������"
//                 � ���� ������������ ���� ��������
//                 � ����� �������� �����������
int SharedGISLibrary::changeShowScale(HMAP handle_, long int* centrX_, long int* centerY_, float k_)
{
    typedef long int (WINAPI* TypeFun)(HMAP, long int*, long int*, float);
    TypeFun fun = reinterpret_cast<TypeFun>(funChangeShowScale.Get());
    return fun(handle_, centrX_, centerY_, k_);
}


//----------------------------------------------------------------------------
// ���������� ������� ����������� (����������� ��������)
//  ���������:
//          hmap - ������������� �������� ������
//          x, y - ���������� ��������������� "������ �����������"
//                 (����� ����� ��������) � ���� � ������� ��������
//         scale - �������� ������� �����������, ������� ������ ��������
//  ����������:   0 - ������� �� ���������,  1 - ������� ���������
//          x, y - ���������� ��������������� "������ �����������"
//                 � ���� ������������ ���� ��������
//                 � ����� �������� �����������

int SharedGISLibrary::setShowScale(HMAP handle_, long int* centrX_, long int* centerY_, float k_)
{
    typedef long int (WINAPI* TypeFun)(HMAP, long int*, long int*, float);
    TypeFun fun = reinterpret_cast<TypeFun>(funSetShowScale.Get());
    return fun(handle_, centrX_, centerY_, k_);
}

//---------------------------------------------------------------------------
// �������������� �� �������� � ����������� � ���������� �� ��������� � ������
// ���������� :
//  // xmet = xdis; ymet = ydis;
// mapPictureToPlane(xmet,ymet);
// hmap - ������������� �������� ������
// x,y  - ������������� ����������
DOUBLEPOINT SharedGISLibrary::translatePictureToMM(HMAP handle_, DOUBLEPOINT point_)
{
    typedef int (WINAPI * TypeFun)(HMAP, double*, double*);
    TypeFun fun = reinterpret_cast<TypeFun>(funScrToMM.Get());
    fun(handle_, &(point_.x), &(point_.y));
    return point_;
}

//---------------------------------------------------------------------------
// �������������� �� ������ �� ��������� � ������� �������������
// hmap - ������������� �������� ������
// x,y  - ������������� ����������

DOUBLEPOINT SharedGISLibrary::translateMMToPicture(HMAP handle_, DOUBLEPOINT point_)
{
    typedef int (WINAPI * TypeFun)(HMAP, double*, double*);
    TypeFun fun = reinterpret_cast<TypeFun>(funMMToScr.Get());
    fun(handle_, &(point_.x), &(point_.y));
    return point_;
}

//---------------------------------------------------------------------------
// ������ - �������������� �� �������� � ������������� ����������� �� ������� ������������� � �������
 // hmap - ������������� �������� ������
 // ���� ��� - ���������� ����
bool SharedGISLibrary::isConvertSupported(HMAP handle_)
{
    typedef int (WINAPI * TypeFun)(HMAP);
    TypeFun fun = reinterpret_cast<TypeFun>(funSupportGeoConvert.Get());
    return bool(fun(handle_));
}

//---------------------------------------------------------------------------
// �������������� �� ������ �� ��������� � ������������� ���������� � �������� � ������������ � ��������� �����
// (������������� �� ��� ���� ���� !)
 // ���������� :
 // if (mapIsGeoSupported())   |  ��� :
 //   {                        |  if (mapIsGeoSupported())
 //     B = Xmet; L = Ymet;    |    {
 //     mapPlan2Geo(B,L);      |      mapPlan2Geo(B=Xmet,L=Ymet);
 //   }                        |    }
 // hmap - ������������� �������� ������
 // Bx,Ly  - ������������� ����������
 // �� ����� �����, �� ������ - �������
 // ��� ������ ���������� 0
DOUBLEPOINT SharedGISLibrary::translateMMToGeo(HMAP hmap_, DOUBLEPOINT srcpoint_)
{
    typedef long int (WINAPI* TypeFunc)(HMAP,double*, double*);
    TypeFunc func = reinterpret_cast<TypeFunc>(fumMMtoGeo.Get());
    func(hmap_, &srcpoint_.x, &srcpoint_.y);
    return srcpoint_;
}

//---------------------------------------------------------------------------
// �������������� �� ������������� ��������� � �������� � ����� �� ��������� � ������������ � ��������� �����
// (�������������� �� ��� ���� ���� !)
// hmap - ������������� �������� ������
// Bx,Ly  - ������������� ����������
// �� ����� �������, �� ������ - �����
// ��� ������ ���������� 0
DOUBLEPOINT SharedGISLibrary::translateGeoToMM(HMAP hmap_, DOUBLEPOINT srcpoint_)
{
    typedef long int (WINAPI* TypeFunc)(HMAP,double*, double*);
    TypeFunc func = reinterpret_cast<TypeFunc>(funGeotoMM.Get());
    func(hmap_, &srcpoint_.x, &srcpoint_.y);
    return srcpoint_;
}

//---------------------------------------------------------------------------
//  �������������� �� ������������� ��������� � �������� (��������� �����������, ��-42)
//  � ����� �� ��������� � �������� �����
// (�������������� �� ��� ���� ���� !)
// hmap - ������������� �������� ������
// Bx,Ly,H  - ������������� ����������
// �� ����� �������, �� ������ - �����
// ��� ������ ���������� ����
DOUBLEPOINT SharedGISLibrary::translateGeo42ToMM(HMAP hmap_, DOUBLEPOINT srcpoint_, double hpoint_)
{
    typedef long int (WINAPI* TypeFunc)(HMAP, double*, double*, double*);
    TypeFunc func = reinterpret_cast<TypeFunc>(funSC42toMM.Get());
    func(hmap_, &srcpoint_.x, &srcpoint_.y, &hpoint_);
    return srcpoint_;
}

/**
 * @brief SharedGISLibrary::translateMMToGeo42  �������������� �� ������ �� ��������� (�������� �����)
 * � ������������� ���������� � �������� (��������� �����������, ��-42) (�������������� �� ��� ���� ���� !)
 * hmap  - ������������� �������� ������
 * Bx,Ly - ������������� ����������
 * �� ����� �����, �� ������ - �������
 * H     - ������ � ����� (�����)
 * ��� ������ ���������� ����
 */
bool SharedGISLibrary::translateMMToGeo42(HMAP hmap_, DOUBLEPOINT mmPoint_, DOUBLEPOINT &geo42Point_)
{
    if(SharedGISLibrary::isConvertSupported(hmap_))
    {
        typedef long int (WINAPI* TypeFunc)(HMAP, double*, double*);
        TypeFunc func = reinterpret_cast<TypeFunc>(funMMtoGeo42.Get());
        if(func(hmap_, &(mmPoint_.x), &(mmPoint_.y)))
        {
            geo42Point_ = mmPoint_;
            return true;
        }
    }
    return false;
}

//---------------------------------------------------------------------------
bool SharedGISLibrary::translateMMToGeo84(HMAP hmap_, DOUBLEPOINT mmPoint_, DOUBLEPOINT &geo84Point_)
{
    if(SharedGISLibrary::isConvertSupported(hmap_))
        {
            typedef long int (WINAPI* TypeFunc)(HMAP, double*, double*);
            TypeFunc func = reinterpret_cast<TypeFunc>(funMMtoGeo84.Get());
            if(func(hmap_, &(mmPoint_.x), &(mmPoint_.y)))
            {
                geo84Point_ = mmPoint_;
                return true;
            }
        }
        return false;
}

//---------------------------------------------------------------------------
bool SharedGISLibrary::translateWGS84ToGK42(HMAP hmap_, DOUBLEPOINT geo84Point_, DOUBLEPOINT &gk42Point_)
{
    if(SharedGISLibrary::isConvertSupported(hmap_))
        {
            typedef long int (WINAPI* TypeFunc)(HMAP, double*, double*);
            TypeFunc func = reinterpret_cast<TypeFunc>(funWGS84toGC42.Get());
            if(func(hmap_, &(geo84Point_.x), &(geo84Point_.y)))
            {
                gk42Point_ = geo84Point_;
                return true;
            }
        }
        return false;
}

//---------------------------------------------------------------------------
bool SharedGISLibrary::translateWGS84ToSC42(HMAP hmap_, DOUBLEPOINT geo84Point_, DOUBLEPOINT &geo42Point_)
{
    if(SharedGISLibrary::isConvertSupported(hmap_))
        {
            typedef long int (WINAPI* TypeFunc)(HMAP, double*, double*);
            TypeFunc func = reinterpret_cast<TypeFunc>(funWGS84toSC42.Get());
            if(func(hmap_, &(geo84Point_.x), &(geo84Point_.y)))
            {
                geo42Point_ = geo84Point_;
                return true;
            }
        }
        return false;
}

//---------------------------------------------------------------------------
bool SharedGISLibrary::translateSC42ToWGS84(HMAP hmap_, DOUBLEPOINT geo42Point_, DOUBLEPOINT &geo84Point_)
{
    if(SharedGISLibrary::isConvertSupported(hmap_))
        {
            typedef long int (WINAPI* TypeFunc)(HMAP, double*, double*);
            TypeFunc func = reinterpret_cast<TypeFunc>(funSC42toWGS84.Get());
            if(func(hmap_, &(geo42Point_.x), &(geo42Point_.y)))
            {
                geo84Point_ = geo42Point_;
                return true;
            }
        }
        return false;
}

//---------------------------------------------------------------------------
bool SharedGISLibrary::translatePZ90ToSC42(HMAP hmap_, DOUBLEPOINT geo90Point_, DOUBLEPOINT &geo42Point_)
{
    if(SharedGISLibrary::isConvertSupported(hmap_))
    {
        typedef long int (WINAPI* TypeFunc)(HMAP, double*, double*);
        TypeFunc func = reinterpret_cast<TypeFunc>(funPZ90ToSc42.Get());
        if(func(hmap_, &(geo90Point_.x), &(geo90Point_.y)))
        {
            geo42Point_ = geo90Point_;
            return true;
        }
    }
    return false;
}

//---------------------------------------------------------------------------
bool SharedGISLibrary::translateSC42ToPZ90(HMAP hmap_, DOUBLEPOINT geo42Point_, DOUBLEPOINT &geo90Point_)
{
    if(SharedGISLibrary::isConvertSupported(hmap_))
    {
        typedef long int (WINAPI* TypeFunc)(HMAP, double*, double*);
        TypeFunc func = reinterpret_cast<TypeFunc>(funSC42toPZ90.Get());
        if(func(hmap_, &(geo42Point_.x), &(geo42Point_.y)))
        {
            geo90Point_ = geo42Point_;
            return true;
        }
    }
    return false;
}

//---------------------------------------------------------------------------
// �������������� ��������� � ������ �� ��������� �� �������� ����
 // � ������������� ���������� � ������� 42�.
 // zone - ����� �������� ���� ������� 1942�
 // x,y  - ������������� ����������
 // �� ����� ����� � ����� ���� 42�.,�� ������ - �������.
 // ��� ������ ���������� 0
bool SharedGISLibrary::translateGK42ToSC42ByZone(long int zone_, DOUBLEPOINT srcpoint_, DOUBLEPOINT& point_)
{
    typedef long int (WINAPI* TypeFunc)(long int, double*, double*);
    TypeFunc func = reinterpret_cast<TypeFunc>(funGK42toSC42byZone.Get());
    if(func(zone_, &(srcpoint_.x), &(srcpoint_.y)))
    {
        point_ = srcpoint_;
        return true;
    }
    return false;
}


 bool SharedGISLibrary::translateSC42ToUTM(HMAP hmap_, DOUBLEPOINT geo42Point_, DOUBLEPOINT &utmPoint_)
 {
     if(SharedGISLibrary::isConvertSupported(hmap_))
     {
         typedef long int (WINAPI* TypeFunc)(HMAP, double*, double*);
         TypeFunc func = reinterpret_cast<TypeFunc>(funSC42toUTM.Get());
         if(func(hmap_, &(geo42Point_.x), &(geo42Point_.y)))
         {
             utmPoint_ = geo42Point_;
             return true;
         }
     }
     return false;
 }


//---------------------------------------------------------------------------
double SharedGISLibrary::getHPointByCoordMM(HMAP& hmap_, DOUBLEPOINT testpoint_)
{
    return getHeightValue(hmap_, testpoint_.x, testpoint_.y);
}

//---------------------------------------------------------------------------
double SharedGISLibrary::getHeightValue(HMAP handle_, double x_, double y_)
{
    typedef double (WINAPI * TypeFunc)(HMAP, double, double);
    TypeFunc fun = reinterpret_cast<TypeFunc>(funGetHeightValue.Get());
    return fun(handle_, x_, y_);
}

//---------------------------------------------------------------------------
std::vector<double> SharedGISLibrary::getHeightArrayByStep(HMAP hmap_,
                                                            double step_,
                                                            DOUBLEPOINT* fstpoint_,
                                                            DOUBLEPOINT* secpoint_)
{
    size_t countofpoint(getDistance(fstpoint_, secpoint_) / step_ + 1);
    std::vector<double> dst(countofpoint);
    if (getHeightArraByCount(hmap_, &(dst.front()), countofpoint, fstpoint_, secpoint_) == 0)
    {
        dst.clear();
    }
    return dst;
}

//---------------------------------------------------------------------------
long int SharedGISLibrary::getHeightArraByCount(HMAP handle_,
                                                 double* data_,
                                                 long int count_,
                                                 DOUBLEPOINT* pntA_,
                                                 DOUBLEPOINT* pntB_)
{
    typedef long int (WINAPI * TypeFunc)(HMAP, double*, long int, const DOUBLEPOINT*, const DOUBLEPOINT*);
    TypeFunc fun = reinterpret_cast<TypeFunc>(funGetArrHeight.Get());
    return fun(handle_, data_, count_, pntA_, pntB_);
}

//---------------------------------------------------------------------------
double SharedGISLibrary::getDistance(DOUBLEPOINT* pntA_, DOUBLEPOINT* pntB_)
{
    typedef double (WINAPI * TypeFunc)(DOUBLEPOINT*, DOUBLEPOINT*);
    TypeFunc fun = reinterpret_cast<TypeFunc>(funGetDistance.Get());
    return fun(pntA_, pntB_);
}

//-----------------------------------------------------------------
long int SharedGISLibrary::openMtqForMap(HMAP hMap,
                                          const char * mtqname,
                                          long int mode)
{
    typedef long int (WINAPI* typeFunc)(HMAP, const char*, long int);
    typeFunc func = reinterpret_cast<typeFunc>(funcOpenMtqForMap.Get());
    return func(hMap, mtqname, mode);
}

//-----------------------------------------------------------------
long int SharedGISLibrary::closeMtqForMap(HMAP hMap,
                                           long int number)
{
    typedef long int (WINAPI* typeFunc)(HMAP, long int);
    typeFunc func = reinterpret_cast<typeFunc>(funcCloseMtqForMap.Get());
    return func(hMap, number);
}



//---------------------------------------------------------------------------
double SharedGISLibrary::getMtqValue(HMAP handle_, long int nu, double x_, double y_)
{
    typedef double (WINAPI * typeFunc)(HMAP, long int, double, double);
    typeFunc fun = reinterpret_cast<typeFunc>(funGetMtqValue.Get());
    return fun(handle_, nu, x_, y_);
}

//---------------------------------------------------------------------------
long int SharedGISLibrary::putMtqValue(HMAP handle_, long int nu, double x_, double y_, double value_)
{
    typedef long int (WINAPI * typeFunc)(HMAP, long int, double, double, double);
    typeFunc fun = reinterpret_cast<typeFunc>(funcPutMtqValue.Get());
    return fun(handle_, nu, x_, y_, value_);
    //
}

//---------------------------------------------------------------------------
double SharedGISLibrary::getMTQValueByCoordMM(HMAP& hmap_, DOUBLEPOINT testpoint_, int numMtq_)
{
    return getMtqValue(hmap_, numMtq_, testpoint_.x, testpoint_.y);
}

//---------------------------------------------------------------------------
long int SharedGISLibrary::putMtqValueByCoordMM(HMAP& hmap_, DOUBLEPOINT testpoint_, double value_, int numMtq_)
{
    return putMtqValue(hmap_, numMtq_, testpoint_.x, testpoint_.y, value_);
}


//-------------------------------------------------------------------------------
void SharedGISLibrary::SetMapViewType(HMAP hmap_, int type_)
{
    typedef long int (WINAPI* TypeFunc)(HMAP, long int);
    TypeFunc func = reinterpret_cast<TypeFunc>(funSetMapViewType.Get());
    func(hmap_, type_);
}
//-------------------------------------------------------------------------------
void SharedGISLibrary::SetMtrViewType(HMAP hmap_, int mtrNu, int type_)
{
    typedef long int (WINAPI* TypeFunc)(HMAP, long int, long int);
    TypeFunc func = reinterpret_cast<TypeFunc>(funSetMtrViewType.Get());
    func(hmap_, mtrNu, type_);
}
//-------------------------------------------------------------------------------
void SharedGISLibrary::SetMapViewBright(HMAP hmap_, int type_)
{
    typedef long int (WINAPI* TypeFunc)(HMAP, long int);
    TypeFunc func = reinterpret_cast<TypeFunc>(funSetMapViewBright.Get());
    func(hmap_, type_);
}
//-------------------------------------------------------------------------------
void SharedGISLibrary::SetMapViewContrast(HMAP hmap_, int type_)
{
    typedef long int (WINAPI* TypeFunc)(HMAP, long int);
    TypeFunc func = reinterpret_cast<TypeFunc>(funSetMapViewContrast.Get());
    func(hmap_, type_);
}
//-------------------------------------------------------------------------------
void SharedGISLibrary::SetMapViewBackColor(HMAP hmap_, int color_)
{
    typedef COLORREF (WINAPI* TypeFunc)(HMAP, COLORREF);
    TypeFunc func = reinterpret_cast<TypeFunc>(funSetMapViewBackColor.Get());
    func(hmap_, static_cast<COLORREF>(color_));
}


//---------------------------------------------------------------------------
// ��������� ������� ������� �����
// hmap - ������������� �������� ������
// ��� ������ ���������� ����
int SharedGISLibrary::getBaseMapScale(HMAP handle_)
{
    typedef long int (WINAPI * TypeFunc)(HMAP);
    TypeFunc fun = reinterpret_cast<TypeFunc>(funGetBaseScale.Get());
    return fun(handle_);
}


//-------------------------------------------------------------------------------
// ��������� ������������� ���������� ��������� �������� ��������� �����
  // � ������ (������� ��������� PLANE)
  // X - ����� �����, Y - ����� �������
  // �.1 - ������ ����� ����,
  // �.2 - ������� ������
  // hmap - ������������� �������� ������
  // ��� ������ ���������� ���� (��������, ���� ������ ������ �����)
double SharedGISLibrary::getX1(HMAP hMap_)
{
    typedef double (WINAPI* TypeFunc)(HMAP);
    TypeFunc func = reinterpret_cast<TypeFunc>(funGetMapX1.Get());
    return func(hMap_);
}

double SharedGISLibrary::getY1(HMAP hMap_)
{
    typedef double (WINAPI* TypeFunc)(HMAP);
    TypeFunc func = reinterpret_cast<TypeFunc>(funGetMapY1.Get());
    return func(hMap_);
}

double SharedGISLibrary::getX2(HMAP hMap_)
{
    typedef double (WINAPI* TypeFunc)(HMAP);
    TypeFunc func = reinterpret_cast<TypeFunc>(funGetMapX2.Get());
    return func(hMap_);
}

double SharedGISLibrary::getY2(HMAP hMap_)
{
    typedef double (WINAPI* TypeFunc)(HMAP);
    TypeFunc func = reinterpret_cast<TypeFunc>(funGetMapY2.Get());
    return func(hMap_);
}
//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------

double SharedGISLibrary::getMapWidth(HMAP hMap_)
{
    return getY2(hMap_) - getY1(hMap_);
}
//-------------------------------------------------------------------------------
double SharedGISLibrary::getMapHeight(HMAP hMap_)
{
    return getX2(hMap_) - getX1(hMap_);
}

//-------------------------------------------------------------------------------
int SharedGISLibrary::buildMTW(HMAP hMap_,
                                const char* mtrname_,
                                const char* filtername_,
                                BUILDMTW* mtrpar,
                                HWND handle_)
{
    typedef long int (WINAPI* TypeFunc)(HMAP, const char*, const char*, BUILDMTW*, HWND);
    TypeFunc func = reinterpret_cast<TypeFunc>(funcBuildMTW.Get());
    return func(hMap_, mtrname_, filtername_, mtrpar, handle_);
}

//---------------------------------------------------------------------------
// ��������� ���������� ������ ��������� �����
// ��������� MAPREGISTER � LISTREGISTER ������� � mapcreat.h
// hmap - ������������� �������� ������
// sheetnumber - ����� ����� ����� ���
// �������� ������������� ���������� ������
// ��� ������ ���������� ����
long int SharedGISLibrary::getMapInfoEx(HMAP handle_, long int nu, MAPREGISTEREX* mapreg_, LISTREGISTER* sheet_)
{
    typedef long int (WINAPI * TypeFunc)(HMAP, long int, MAPREGISTEREX*, LISTREGISTER*);
    TypeFunc fun = reinterpret_cast<TypeFunc>(funGetMapInfoEx.Get());
    return fun(handle_, nu, mapreg_, sheet_);
}

//-----------------------------------------------------------------
// ��������� ��� �����
// hmap - ������������� �������� ������
// ���� ���� - ��. mapcreat.h, MAPTYPE
// ��� ������ ���������� ����
long int SharedGISLibrary::getMapType(HMAP hMap)
{
    typedef long int (WINAPI* typeFunc)(HMAP);
    typeFunc func = reinterpret_cast<typeFunc>(funGetMapType.Get());
    return func(hMap);
}


//------------------------------------------------------------------
// ��������� ����� ����� �� �����
// hmap - ������������� �������� ������
// ��� ������ ���������� ����
long int SharedGISLibrary::getCountLayers(HMAP hmap_)
{
    typedef long int (WINAPI* TypeFunc)(HMAP);
    TypeFunc func = reinterpret_cast<TypeFunc>(funcGetCountLayers.Get());
    return func(hmap_);
}

//------------------------------------------------------------------
// ��������� �������� ���� �� ��� ������ (number)
// hmap - ������������� �������� ������
// name - ����� ������ ��� ���������� �������
// size - ������ ������
// ����� ������� ���� 0
// ��� ������ ���������� ����

const char* SharedGISLibrary::getLayerName(HMAP hmap_,long int nu)
{
    typedef const char* (WINAPI* TypeFunc)(HMAP, long int);
    TypeFunc func = reinterpret_cast<TypeFunc>(funcGetNameLayer.Get());
    return func(hmap_, nu);
}


//------------------------------------------------------------------
long int SharedGISLibrary::isLayerChecked(HSELECT hsel_, long int nu)
{
    typedef long int (WINAPI* TypeFunc)(HSELECT, long int);
    TypeFunc func = reinterpret_cast<TypeFunc>(funcReadCheckLayer.Get());
    return func(hsel_, nu);
//mapCheckLayer
}

//-------------------?????????????????????????--------------------
long int SharedGISLibrary::getCountObjInLayer(HMAP hmap_, long int nu)
{
    typedef long int (WINAPI* TypeFunc)(HMAP, long int);
    TypeFunc func = reinterpret_cast<TypeFunc>(funcGetCountObjInLayer.Get());
    return func(hmap_, nu);
//mapRscObjectCountInLayer
}

//--------------------???????????????????????---------------------
std::string SharedGISLibrary::getNameObjInLayer(HMAP hmap_, long int layernu, long int objnu)
{
    typedef const char* (WINAPI* TypeFunc)(HMAP, long int, long int);
    TypeFunc func = reinterpret_cast<TypeFunc>(funcGetNameObjInLayer.Get());
    return std::string(func(hmap_, layernu, objnu));
// mapRscObjectNameInLayer
}

//-------------------------?????????????????---------------------------
long int SharedGISLibrary::getCodeObjInLayer(HMAP hmap_, long int layernu, long int objnu)
{
    typedef long int (WINAPI* TypeFunc)(HMAP, long int, long int);
    TypeFunc func = reinterpret_cast<TypeFunc>(funcGetCodeObjInLayer.Get());
    return func(hmap_, layernu, objnu);
//	mapRscObjectCodeInLayer
}

//-----------------------------------------------------------------
long int SharedGISLibrary::isObjChecked(HSELECT hsel_, long int code_)
{
    typedef long int (WINAPI* TypeFunc)(HSELECT, long int);
    TypeFunc func = reinterpret_cast<TypeFunc>(funcReadObjChecked.Get());
    return func(hsel_, code_);
    //mapCheckObject
}

//-----------------------------------------------------------------
void SharedGISLibrary::selectLayer(HSELECT hsel_, int nu, int access_)
{
    typedef void (WINAPI* TypeFunc)(HSELECT, long int, long int);
    TypeFunc func = reinterpret_cast<TypeFunc>(funcSelectLayer.Get());
    func(hsel_, nu, access_);
}

//-----------------------------------------------------------------
void SharedGISLibrary::selectObj(HSELECT hsel_, long int code_, bool check_)
{
    typedef void (WINAPI* TypeFunc)(HSELECT, long int, long int);
    TypeFunc func = reinterpret_cast<TypeFunc>(funcSelectObj.Get());
    func(hsel_, code_, static_cast<long int>(check_));
}


//-------------------------------------------------------------------------------
HSELECT SharedGISLibrary::createSelectContecxt(HMAP hmap_)
{
    typedef HSELECT (WINAPI* TypeFunc)(HMAP);
    TypeFunc func = reinterpret_cast<TypeFunc>(funCreateSelCont.Get());
    return func(hmap_);
}

//-------------------------------------------------------------------------------
void SharedGISLibrary::deleteSelectContext(HSELECT hsel_)
{
    typedef void (WINAPI* TypeFunc)(HSELECT);
    TypeFunc func = reinterpret_cast<TypeFunc>(funDeleteSelCont.Get());
    func(hsel_);
}


//-----------------------------------------------------------------
long int SharedGISLibrary::getViewSelect(HMAP hmap_, HSELECT hsel_)
{
    typedef long int (WINAPI* TypeFunc)(HMAP, HSELECT);
    TypeFunc func = reinterpret_cast<TypeFunc>(funcGetViewSelect.Get());
    return func(hmap_, hsel_);
    //mapGetViewSelect
}

//-----------------------------------------------------------------
// ���������� ������ ������������ ��������
// hmap - ������������� �������� ������
// select - ������������� ���������������� ��������� ������/�����������

void SharedGISLibrary::setViewSelect(HMAP hmap_, HSELECT hsel_)
{
    typedef void (WINAPI* TypeFunc)(HMAP, HSELECT);
    TypeFunc func = reinterpret_cast<TypeFunc>(funcSetViewSelect.Get());
    func(hmap_, hsel_);

}
