#include "---usupload.h"

#include <QSettings>

SPURPOSELOAD::SPURPOSELOAD()
{
    on = false; //признак включения
    type = SPT_ERR; // тип целевой нагрузки
    mode = SPM_ERR; //режим работы
    onfoto = false; //признак включения режима фотосъемки
    speedfoto = 0; //темп фотосъемки
    zoom = 0; //значение зума
    angleK = angleT = angleR = 0.;
    objcoord.x = -1111111; //координаты объекта наблюдения в рад
    objcoord.y = -1111111;
    objh = 0; //высота объекта наблюдения
    statusChange = false;
}

void SPURPOSELOAD::setState(bool state_)
{
    on = state_;
}

bool SPURPOSELOAD::isOn() const
{
    return on;
}

void SPURPOSELOAD::setType(const ESUPLOADTYPE type_)
{
    type = type_;
}

ESUPLOADTYPE SPURPOSELOAD::getType() const
{
    return type;
}

void SPURPOSELOAD::setMode(const ESUPLOADMODE mode_)
{
    mode = mode_;
}

ESUPLOADMODE SPURPOSELOAD::getMode() const
{
    return mode;
}

void SPURPOSELOAD::setPhotoState(bool state_)
{
    onfoto = state_;
}

bool SPURPOSELOAD::isPhoto() const
{
    return onfoto;
}

void SPURPOSELOAD::setPhotoSpeed(const int speed_)
{
    speedfoto = speed_;
}

int SPURPOSELOAD::getPhotoSpeed() const
{
    return speedfoto;
}

void SPURPOSELOAD::setZoom(const int zoom_)
{
    zoom = zoom_;
}

int SPURPOSELOAD::getZoom() const
{
    return zoom;
}

void SPURPOSELOAD::setAngleK(const double angle_)
{
    angleK = angle_;
}

double SPURPOSELOAD::getAngleK() const
{
    return angleK;
}

void SPURPOSELOAD::setAngleT(const double angle_)
{
    angleT = angle_;
}

double SPURPOSELOAD::getAngleT() const
{
    return angleT;
}

void SPURPOSELOAD::setAngleR(const double angle_)
{
    angleR = angle_;
}

double SPURPOSELOAD::getAngleR() const
{
    return angleR;
}

void SPURPOSELOAD::setObjCoord(const DOUBLEPOINT coord_)
{
    objcoord = coord_;
}

void SPURPOSELOAD::setObjCoord(const double b_, const double l_)
{
    setObjCoordB(b_);
    setObjCoordL(l_);
}

void SPURPOSELOAD::setObjCoordB(const double b_)
{
    objcoord.X = b_;
}

void SPURPOSELOAD::setObjCoordL(const double l_)
{
    objcoord.y = l_;
}

DOUBLEPOINT SPURPOSELOAD::getObjCoord() const
{
    return objcoord;
}

double SPURPOSELOAD::getObjCoordB() const
{
    return objcoord.x;
}

double SPURPOSELOAD::getObjCooordL() const
{
    return objcoord.y;
}

void SPURPOSELOAD::setObjH(const unsigned int h_)
{
    objh = h_;
}

unsigned int SPURPOSELOAD::getObjH() const
{
    return objh;
}

void SPURPOSELOAD::changeStatus(bool mod_)
{
    statusChange = mod_;
}

bool SPURPOSELOAD::isChangedStatus() const
{
    return statusChange;
}

int SPURPOSELOAD::save(QSettings *settings_)
{
    settings_->beginGroup("PrpLData");
        settings_->setValue("State", isOn());
        settings_->setValue("Type", static_cast<int>(getType()));
        settings_->setValue("Mode", static_cast<int>(getMode()));
        settings_->setValue("Photo", isPhoto());
        settings_->setValue("PhotoSpeed", getPhotoSpeed());
        settings_->setValue("Zoom", getZoom());
        settings_->setValue("AngleK", getAngleK());
        settings_->setValue("AngleR", getAngleR());
        settings_->setValue("AngleT", getAngleT());
        settings_->setValue("ObjB", getObjCoordB());
        settings_->setValue("ObjL", getObjCooordL());
        settings_->setValue("ObjH", getObjH());
    settings_->endGroup();
}

int SPURPOSELOAD::load(QSettings *settings_)
{
    settings_->beginGroup("PrpLData");
        setState(settings_->value("State", false).toBool());
        setType(static_cast<ESUPLOADTYPE>(settings_->value("Type", -1).toInt()));
        setMode(static_cast<ESUPLOADMODE>(settings_->value("Mode", -1).toInt()));
        setPhotoState(settings_->value("Photo", false).toBool());
        setPhotoSpeed(settings_->value("PhotoSpeed", 0).toInt());
        setZoom(settings_->value("Zoom", 0).toInt());
        setAngleK(settings_->value("AngleK", 0).toDouble());
        setAngleT(settings_->value("AngleT", 0).toDouble());
        setAngleR(settings_->value("AngleR", 0).toDouble());
        setObjCoordB(settings_->value("ObjB", -11111).toDouble());
        setObjCoordL(settings_->value("ObjL", -11111).toDouble());
        setObjH(settings_->value("ObjH", 0).toInt());
    settings_->endGroup();
}

