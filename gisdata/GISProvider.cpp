#include "GISProvider.h"

//------------------------------------------
bool GISProvider::LoadMapData(const char* mapfile_,
                               const char* mtrfile_,
                               bool MtrExsist_)
{
    if(hmap != 0)
    {
        GISLibrary.closeData(hmap);
        hmap = 0;
    }

    hmap = GISLibrary.loadMap(mapfile_, 0);

    if(!hmap)
    {
        return 0;
    }

    fileName = mapfile_;
    if(MtrExsist_)
    {
        addMtrToMap(mtrfile_);
    }

    hselect = GISLibrary.createSelectContecxt(hmap);

    return IsLoaded();
}


//------------------------------------------------------------------------
int GISProvider::addMtrToMap(const char* mtrfilename_)        //????????????????????????????????
{
    m_nummtr = GISLibrary.loadMtwForMap(hmap, mtrfilename_, 0);
    if(!m_nummtr)
    {
        GISLibrary.closeMtr(hmap, 0);
        return 0;
    }
    mtrName = mtrfilename_;
    return m_nummtr;
}


//------------------------------------------------------------------------
int GISProvider::addMtqToMap(const char* mtqfilename_)        //?????????????????????????????????
{
    return GISLibrary.openMtqForMap(hmap, mtqfilename_, 0);
}


//-------------------------------------------------------------------------
bool GISProvider::createMapFromSXF(const char* sxfname_,
                                    const char* rscname_,
                                    const char* mapname_,
                                    HWND hwnd_)
{
    // вызывается метод LoadSxfToMap
    return bool(GISLibrary.loadSxf2Map(sxfname_, rscname_, mapname_, hwnd_));
}


bool GISProvider::CloseData()
{
    if(hselect)
    {
        GISLibrary.deleteSelectContext(hselect);
        hselect = 0;
    }
    if (hmap)
    {
        GISLibrary.closeData(hmap);
        hmap = 0;
    }

    fileName = "";
    mtrName = "";

        return true;

}

//------------------------------------------
bool GISProvider::IsLoaded() const
{
    return bool(hmap != 0);
}


//--------------------------------------------------------------------------
bool GISProvider::MMCoord_to_SC42(DOUBLEPOINT mmpoint_, DOUBLEPOINT &sc42GeoPoint_ ) //const
{
    if(hmap)
    {
        return GISLibrary.translateMMToGeo42(hmap, mmpoint_, sc42GeoPoint_);
    }
    return false;
}

//--------------------------------------------------------------------------
bool GISProvider::WGS84_to_GK42(DOUBLEPOINT geo84point_, DOUBLEPOINT &gk42point_) //const
{
    if(hmap)
    {
        return  GISLibrary.translateWGS84ToGK42(hmap, geo84point_, gk42point_);
    }
    return false;
}

//--------------------------------------------------------------------------
bool GISProvider::PE90_to_SC42(DOUBLEPOINT srcpoint_, DOUBLEPOINT &dstpoint_) //const
{
    if(hmap)
    {
        return  GISLibrary.translatePZ90ToSC42(hmap, srcpoint_, dstpoint_);
    }
    return false;
}

//--------------------------------------------------------------------------
bool GISProvider::SC42_to_PE90(DOUBLEPOINT srcpoint_, DOUBLEPOINT &dstpoint_) //const
{
    if(hmap)
    {
        return GISLibrary.translateSC42ToPZ90(hmap, srcpoint_, dstpoint_);
    }
    return false;
}

//--------------------------------------------------------------------------
bool GISProvider::SC42_to_WGS84(DOUBLEPOINT srcpoint_, DOUBLEPOINT &dstpoint_) //const
{
    if(hmap)
    {
        return  GISLibrary.translateSC42ToWGS84(hmap, srcpoint_, dstpoint_);
    }
    return false;
}
//--------------------------------------------------------------------------
bool GISProvider::SC42_to_UTM(DOUBLEPOINT sc42point_, DOUBLEPOINT &utmpoint_)// const;
{
    if(hmap)
    {
        return  GISLibrary.translateSC42ToUTM(hmap, sc42point_, utmpoint_);
    }
    return false;
}

//--------------------------------------------------------------------------
bool GISProvider::WGS84_to_SC42(DOUBLEPOINT srcpoint_, DOUBLEPOINT &dstpoint_) //const
{
    if(hmap)
    {
        return GISLibrary.translateWGS84ToSC42(hmap, srcpoint_, dstpoint_);
    }
    return false;
}

//--------------------------------------------------------------------------
bool GISProvider::GK42_to_SC42(DOUBLEPOINT srcpoint_, DOUBLEPOINT& dstpoint_) //const
{
    div_t zone = div(srcpoint_.y, 1000000);
    return GISLibrary.translateGK42ToSC42ByZone(zone.quot, srcpoint_, dstpoint_);
}

//-------------------------------------------------------------------------
bool GISProvider::WGS84_to_MM(DOUBLEPOINT srcpoint_, DOUBLEPOINT& dstpoint_)
{
    DOUBLEPOINT tmppoint;
    if(WGS84_to_SC42(srcpoint_, tmppoint))
    {
        return SC42_to_MM(tmppoint, dstpoint_);
    }
    else
    {
        return false;
    }
}


//---------------------------------------------------------------------------
bool GISProvider::SC42_to_MM(const DOUBLEPOINT &srcpoint_, DOUBLEPOINT& dstpoint_) //const
{
    if(hmap && GISLibrary.isConvertSupported(hmap))
    {
        double HPoint = 0;
        dstpoint_ = GISLibrary.translateGeo42ToMM(hmap, srcpoint_, HPoint);
    }
    return true;
}

//--------------------------------------------------------------------------
DOUBLEPOINT GISProvider::MM_to_Geo(DOUBLEPOINT pointMM_) //const
{
    return GISLibrary.translateMMToGeo(hmap, pointMM_);
}

//--------------------------------------------------------------------------
DOUBLEPOINT GISProvider::Geo_to_MM(DOUBLEPOINT pointGeo_) //const
{
    return GISLibrary.translateGeoToMM(hmap, pointGeo_);
}

//--------------------------------------------------------------------------
double GISProvider::getDistance(DOUBLEPOINT pntA_, DOUBLEPOINT pntB_)
{
    return GISLibrary.getDistance(&pntA_, &pntB_);
}

//--------------------------------------------------------------------------
std::vector<double> GISProvider::getHeightArray(const double& step_,
                                                 const DOUBLEPOINT& pntA_,
                                                 const DOUBLEPOINT& pntB_)
{
    DOUBLEPOINT pntA(pntA_), pntB(pntB_);
    return GISLibrary.getHeightArrayByStep(hmap, step_, &pntA, &pntB);
}

//--------------------------------------------------------------------------
double GISProvider::getMtqValueByMM(const DOUBLEPOINT& pnt_, long int numMtq_)
{
    return GISLibrary.getMTQValueByCoordMM(hmap, pnt_, numMtq_);
}

//--------------------------------------------------------------------------
long int GISProvider::getBaseScale()
{
    return GISLibrary.getBaseMapScale(hmap);
}

//--------------------------------------------------------------------------
double GISProvider::getMapX1()
{
    return GISLibrary.getX1(hmap);
}

//--------------------------------------------------------------------------
double GISProvider::getMapY1()
{
    return GISLibrary.getY1(hmap);
}

//--------------------------------------------------------------------------
double GISProvider::getMapX2()
{
    return GISLibrary.getX2(hmap);
}

//--------------------------------------------------------------------------
double GISProvider::getMapY2()
{
    return GISLibrary.getY2(hmap);
}

//--------------------------------------------------------------------------
double GISProvider::getMapWidth()
{
    return GISLibrary.getMapWidth(hmap);
}

//--------------------------------------------------------------------------
double GISProvider::getMapHeight()
{
    return GISLibrary.getMapHeight(hmap);
}


//--------------------------------------------------------
int GISProvider::getCountLayers()
{
    return GISLibrary.getCountLayers(hmap);
}

//--------------------------------------------------------
const char* GISProvider::getNameLayerByNum(int num_) // начиная с 1
{
    return GISLibrary.getLayerName(hmap, num_);
}

//-------------------------------------------------------
bool GISProvider::isLayerChecked(int num_) // начиная с 1
{
    return bool(GISLibrary.isLayerChecked(hselect, num_));
}

//-------------------------------------------------------
bool GISProvider::isLayerChecked(int num_, HSELECT hsel_) // начиная с 1
{
    return bool(GISLibrary.isLayerChecked(hsel_, num_));
}

//-------------------------------------------------------
int GISProvider::getCountObjInLayer(int num_)
{
    return GISLibrary.getCountObjInLayer(hmap, num_);
}

//-------------------------------------------------------
std::string GISProvider::getNameObjInLayer(int layernum_, int objnum_)
{
    return GISLibrary.getNameObjInLayer(hmap, layernum_, objnum_);
}

//-------------------------------------------------------
int GISProvider::getCodeObjInLayer(int layernum_, int objnum_)
{
    return GISLibrary.getCodeObjInLayer(hmap, layernum_, objnum_);
}

//-------------------------------------------------------
bool GISProvider::isCheckedObjInLayer(int layernum_, int objnum_)
{
    return bool(GISLibrary.isObjChecked(hselect, getCodeObjInLayer(layernum_, objnum_)));
}

//-------------------------------------------------------
bool GISProvider::isCheckedObjInLayer(int layernum_, int objnum_, HSELECT hsel_)
{
    long int code = getCodeObjInLayer(layernum_, objnum_);
    return bool(GISLibrary.isObjChecked(hsel_, code));
}

//-------------------------------------------------------
void GISProvider::setCheckedLayerByNum(int num_, bool check_, HSELECT hsel_)
{
    GISLibrary.selectLayer(hsel_, num_, static_cast<long int>(check_));
}

//-------------------------------------------------------
void GISProvider::setCheckedLayerByNum(int num_, bool check_)
{
    GISLibrary.selectLayer(hselect, num_, static_cast<long int>(check_));
}

//-------------------------------------------------------
void GISProvider::setCheckedObjByCode(int code_, bool check_, HSELECT hsel_)
{
    GISLibrary.selectObj(hsel_, code_, check_);
}

//-------------------------------------------------------
void GISProvider::setCheckedObjByCode(int code_, bool check_)
{
    GISLibrary.selectObj(hselect, code_, check_);
}

//--------------------------------------------------------
void GISProvider::setSelViewContext(const HSELECT& hsel_)
{
    GISLibrary.setViewSelect(hmap, hsel_);
}

//--------------------------------------------------------
int GISProvider::getViewSelContext(HSELECT& hsel_)
{
    return GISLibrary.getViewSelect(hmap, hsel_);
}

//--------------------------------------------------------
void GISProvider::reloadSelViewContext()
{
    setSelViewContext(hselect);
    getViewSelContext(hselect);
}


