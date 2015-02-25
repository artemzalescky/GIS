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

private slots:
    void slotPressOpenMap();
    void slotPressCloseMap();
    void slotPressZoomPlus();
    void slotPressZoomMinus();

private:
    void initializeItems();

private:
    QToolButton *mapOpenButton,
                *mapCloseButton,
                *zoomPlusButton,
                *zoomMinusButton;
    
};

#endif // MAPCONTROLPANEL_H
