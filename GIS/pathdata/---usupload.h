#ifndef USUPLOAD_H
#define USUPLOAD_H

#include "../Library/mapapi.h"

/*целевая нагрузка*/


class QSettings;

typedef enum ESUPLOADTYPE_
{
    SPT_VIDEO = 1, // видеокамера
    SPT_FOTO = 2, // фотокамера
    SPT_IRC = 3,// ИК-камера
    SPT_ERR = -1
}ESUPLOADTYPE;

typedef enum ESUPLOADMODE_
{
    SPM_NULL = 0, //нет режима работы
    SPM_NAV = 1, // наведение
    SPM_STAB = 2, // стабилизация
    SPM_SLEZ = 3,// слежение
    SPM_SKAN = 4,// сканирование
    SPM_ERR = -1
}ESUPLOADMODE;


//структура целевой нагрузки
struct SPURPOSELOAD
{
public:
    SPURPOSELOAD();
    SPURPOSELOAD(const SPURPOSELOAD& src_)
    {
        this->setState(src_.isOn());
        this->setAngleK(src_.getAngleK());
        this->setAngleR(src_.getAngleR());
        this->setAngleT(src_.getAngleT());
        this->changeStatus(src_.isChangedStatus());
        this->setMode(src_.getMode());
        this->setObjCoord(src_.getObjCoord());
        this->setObjH(src_.getObjH());
        this->setPhotoSpeed(src_.getPhotoSpeed());
        this->setPhotoState(src_.isPhoto());
        this->setType(src_.getType());
        this->setZoom(src_.getZoom());
    }

    SPURPOSELOAD& operator=(const SPURPOSELOAD& src_)
    {
        this->setState(src_.isOn());
        this->setAngleK(src_.getAngleK());
        this->setAngleR(src_.getAngleR());
        this->setAngleT(src_.getAngleT());
        this->changeStatus(src_.isChangedStatus());
        this->setMode(src_.getMode());
        this->setObjCoord(src_.getObjCoord());
        this->setObjH(src_.getObjH());
        this->setPhotoSpeed(src_.getPhotoSpeed());
        this->setPhotoState(src_.isPhoto());
        this->setType(src_.getType());
        this->setZoom(src_.getZoom());
        return *this;
    }

    void setState(bool); // вкл/выкл целевой нагрузки
    bool isOn() const;

    void setType(const ESUPLOADTYPE);
    ESUPLOADTYPE getType() const;

    void setMode(const ESUPLOADMODE);
    ESUPLOADMODE getMode() const;

    void setPhotoState(bool);
    bool isPhoto() const;

    void setPhotoSpeed(const int);
    int getPhotoSpeed()const;

    void setZoom(const int);
    int getZoom() const;

    void setAngleK(const double);
    double getAngleK() const;

    void setAngleT(const double);
    double getAngleT() const;

    void setAngleR(const double);
    double getAngleR() const;

    void setObjCoord(const DOUBLEPOINT);
    void setObjCoord(const double, const double);
    void setObjCoordB(const double);
    void setObjCoordL(const double);
    DOUBLEPOINT getObjCoord() const;
    double getObjCoordB() const;
    double getObjCooordL() const;

    void setObjH(const unsigned int);
    unsigned int getObjH()const;

    void changeStatus(bool);
    bool isChangedStatus() const;

    int save(QSettings*);
    int load(QSettings*);

private:
    bool on; //признак включения
    ESUPLOADTYPE type; // тип целевой нагрузки
    ESUPLOADMODE mode; //режим работы
    bool onfoto; //признак включения режима фотосъемки
    int speedfoto; //темп фотосъемки
    int zoom; //значение зума
    double angleK; //заданный угол крена
    double angleT;//заданный угол тангажа
    double angleR; // заданный угол рыскания
    DOUBLEPOINT objcoord; //координаты объекта наблюдения в рад
    unsigned int objh; //высота объекта наблюдения

    bool statusChange;

};

#endif // USUPLOAD_H
