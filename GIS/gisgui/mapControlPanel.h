#ifndef MAPCONTROLPANEL_H
#define MAPCONTROLPANEL_H

#include "./abstractСontrolPanel.h"
class QToolButton;

/*класс в котором реализовано добавление иконок на widget*/

class MapControlPanel : public AbstractControlPanel
{
    Q_OBJECT
public:
    explicit MapControlPanel(QWidget *parent = 0);
    
signals:
    void signalOpenMap();
    void signalCloseMap();
    void signalZoomPlus();
    void signalZoomMinus();
    void signalProfileShow();
    void signalShowDistCalc();
    void signalSetCenter(bool);  //Установить как центр отображения карты(?????? не работает!!! проверка!!!!)

private slots:
    void slotPressZoomPlus();
    void slotPressZoomMinus();
    void slotPressOpenMap();
    void slotPressCloseMap();
    void slotPressProfile();
    void slotPressDistCalc();   //калькулятор расстояний
    void slotPressSetCenter();  //Установить как центр отображения карты(?????? не работает!!! проверка!!!!)

private:
    void initializeItems();

private:
    QToolButton *mapOpenButton,
                *mapCloseButton,
                *zoomPlusButton,
                *zoomMinusButton,
                *profileButton,
                *distCalcButton,
                *setCenterButton;
    
};

#endif // MAPCONTROLPANEL_H
