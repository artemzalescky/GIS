#include "mapControlPanel.h"

#include <QToolButton>
#include <QTextCodec>


MapControlPanel::MapControlPanel(QWidget *parent) :
    AbstractControlPanel(tr("Map Control Panel"), parent)
{
    initializeItems();
}

//-----------------------------------------------
void MapControlPanel::initializeItems()
{
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8")); //установил формат


    mapOpenButton = createToolButton(tr("Загрузить карту"), ":/Resurses/24/open_map.png");
    connect(mapOpenButton, SIGNAL(clicked()), this, SLOT(slotPressOpenMap()));

    mapCloseButton = createToolButton(tr("Закрыть карту"), ":/Resurses/24/close_map.png");
    connect(mapCloseButton, SIGNAL(clicked()), this, SLOT(slotPressCloseMap()));

    zoomPlusButton = createToolButton(tr("Увеличить изображение"), ":/Resurses/24/map_zoom_plus.png");
    connect(zoomPlusButton, SIGNAL(clicked()), this, SLOT(slotPressZoomPlus()));

    zoomMinusButton = createToolButton(tr("Уменьшить изображение"), ":/Resurses/24/map_zoom_minus.png");
    connect(zoomMinusButton, SIGNAL(clicked()), this, SLOT(slotPressZoomMinus()));

    addWidget(mapOpenButton);
    addWidget(mapCloseButton);
    addSeparator();
    addWidget(zoomPlusButton);
    addWidget(zoomMinusButton);  
    addSeparator();
}

void MapControlPanel::slotPressZoomPlus()
{
    emit signalZoomPlus();
}
void MapControlPanel::slotPressZoomMinus()
{
    emit signalZoomMinus();
}
void MapControlPanel::slotPressOpenMap()
{
    emit signalOpenMap();
}
void MapControlPanel::slotPressCloseMap()
{
    emit signalCloseMap();
}
