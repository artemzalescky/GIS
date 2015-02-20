#include "ccriticalsheme.h"
#include <assert.h>
#include <QSettings>
/*
CCriticalSheme::CCriticalSheme()
{
}

bool CCriticalSheme::isEmpty() const
{
    return objects.isEmpty();
}

int CCriticalSheme::getCountObj() const
{
    return objects.size();
}

bool CCriticalSheme::clear()
{
    name.clear();
    objects.clear();
    return isEmpty();
}

bool CCriticalSheme::addObj(const CCriticalPathObj &newobj_)
{
    int oldcount(getCountObj());
    objects << newobj_;
    return bool(getCountObj() - oldcount == 1);
}

void CCriticalSheme::addPointByNum(DOUBLEPOINT coord_, int num_)
{
    CCriticalPathObj tmpdata = getObjByNum(num_);
    tmpdata.addPoint(coord_);
    setObjtByNum(tmpdata, num_);
}

QString CCriticalSheme::getName() const
{
    return name;
}

void CCriticalSheme::setName(QString str_)
{
    name = str_;
}

void CCriticalSheme::setCurObj(const int ind_)
{
    curID = ind_;
}

int CCriticalSheme::getCurInd() const
{
    return curID;
}

CCriticalPathObj CCriticalSheme::getCurObj() const
{
    assert(curID >= 0 && curID <objects.size());
    return getObjByNum(curID);
}

CCriticalPathObj CCriticalSheme::getObjByNum(const int num_) const
{
    return objects[num_];
}

bool CCriticalSheme::removeObjByNum(const int num_)
{
    if(isEmpty())
        return false;
    int oldcount(getCountObj());
    objects.remove(num_, 1);
    return bool(oldcount - getCountObj() == 1);
}

void CCriticalSheme::setObjtByNum(const CCriticalPathObj &newdata_, int num_)
{
    objects.replace(num_,newdata_);
}

void CCriticalSheme::setCurObjData(const CCriticalPathObj &newdata_)
{
    setObjtByNum(newdata_, getCurInd());
}


int CCriticalSheme::save(QSettings *settings_)
{
    settings_->beginGroup("Sheme_of_Critical_Objects");
        settings_->setValue("Sheme_Name", name);
        settings_->setValue("Count_of_Objects", getCountObj());
        int countsavedobj(0);
        for (int i(0); i < getCountObj(); i++)
        {
            settings_->beginGroup(QString("Object_%1").arg(i));
                objects[i].write(settings_);
            settings_->endGroup();
            countsavedobj++;
        }
    settings_->endGroup();
    return countsavedobj;
}

int CCriticalSheme::load(QSettings *settings_)
{
    clear();
    settings_->beginGroup("Sheme_of_Critical_Objects");
    name = settings_->value("Sheme_Name", "").toString();
    int countOfObj = settings_->value("Count_of_Objects", 0).toInt();
    for(int i(0); i < countOfObj; i++)
    {
        settings_->beginGroup(QString("Object_%1").arg(i));
            CCriticalPathObj tmpObj;
            tmpObj.read(settings_);
            addObj(tmpObj);
        settings_->endGroup();
    }
    settings_->endGroup();
    return getCountObj();
}

int CCriticalSheme::saveToFile(const QString &filename_)
{
    QSettings *file = new QSettings(filename_,
                                    QSettings::IniFormat,
                                    NULL);
    return save(file);
}

int CCriticalSheme::loadFromFile(const QString &filename_)
{
    QSettings *file = new QSettings(filename_,
                                    QSettings::IniFormat,
                                    NULL);
    return load(file);
}
*/
