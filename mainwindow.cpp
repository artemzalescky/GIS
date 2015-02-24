#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QSettings>
#include <QLabel>

#include "./gisgui/mapScroll.h"
#include "./gisgui/mapControlPanel.h"             //Класс, в котором реализовано создание значков для панели(ToolBar)
#include "./gisdata/userVFunctions.h"


MainWindow::MainWindow(QWidget *parent_, Qt::WFlags flags_) :
    QMainWindow(parent_, flags_),
    ui(new Ui::MainWindow),
    mapScroll(new MapScroll(this)) //скролинг карты
{
    ui->setupUi(this);
    setCentralWidget(mapScroll);
    initToolBar();                   //инициализируем панель со значками

    createStatusBar();
    connectToolActions();
    m_first = true;
}

//---------------------------------------------
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setVisibleProfile(bool state_)
{
    mVisibleProfile = state_;
}
bool MainWindow::isVisibleProfile()
{
    return mVisibleProfile;
}

//---------------------------------------------
/**
 * @brief MainWindow::initToolBar - инициализируем панель со значками
 */
void MainWindow::initToolBar()
{
    mapControlPanel = new MapControlPanel(this);
    addToolBar(Qt::TopToolBarArea, mapControlPanel);

    connect(mapControlPanel, SIGNAL(signalOpenMap()), SLOT(slotOpenMapFile()));
    connect(mapControlPanel, SIGNAL(signalCloseMap()), SLOT(slotCloseMapData()));
    connect(mapControlPanel, SIGNAL(signalZoomMinus()), this, SLOT(slotZoomMinus()));
    connect(mapControlPanel, SIGNAL(signalZoomPlus()), this, SLOT(slotZoomPlus()));
}


//--------------------------------------------
void MainWindow::slotShowMapControlPanel(bool show_)
{
    mapControlPanel->setVisible(show_);
}

//---------------QLabel-----------------
void MainWindow::createStatusBar()
{
    labelSB_CS = new QLabel(statusBar());
    statusBar()->addPermanentWidget(labelSB_CS, 1);
    labelSB_Coord = new QLabel(statusBar());
    statusBar()->addPermanentWidget(labelSB_Coord, 5);
    labelSB_Scale = new QLabel(statusBar());
    statusBar()->addPermanentWidget(labelSB_Scale, 2);

    connect(mapScroll, SIGNAL(signalMapPointStrByMouseRelese(QString)), this, SLOT(slotShowCoord(QString)));
    connect(mapScroll, SIGNAL(signalMapPointStrByMouseMove(QString)), this, SLOT(slotShowCoord(QString)));

}

//---------загружается предыдущаяа карта--------------

void MainWindow::showEvent(QShowEvent *event_)
{
    event_;
    if(m_first)
    {
        QSettings appset;
        QString fileName =  servfunc::readLastMapName(&appset);

        if(!fileName.isEmpty())
        {
            mapScroll->loadMapFile(fileName);
            QFileInfo mapFi(fileName);
            setWindowTitle(tr("Linux GIS Module (test version) - %1 ").arg(mapFi.fileName()));
            servfunc::writeLastMapName(&appset, fileName);
        }
        m_first = false;
    }
}

//---------------------------------------------
void MainWindow::closeEvent(QCloseEvent *event_)
{
    event_;
    slotCloseMapData();
}

//---------------------------------------------
void MainWindow::slotOpenMapFile()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Выбор файла карты"), "",
                                                    tr("MAP files (*.map)\n"
                                                       "SXF files (*.sxf)\n"
                                                       "All files (*.*)"));
    if(!fileName.isEmpty())
    {
        mapScroll->loadMapFile(fileName);
        QFileInfo mapFi(fileName);
        setWindowTitle(tr("Linux GIS Module (test version) - %1 ").arg(mapFi.fileName()));
        QSettings appset;
        servfunc::writeLastMapName(&appset, fileName);
    }
}

//---------------------------------------------
void MainWindow::slotCloseMapData()
{
    mapScroll->closeMapData();
}


//--------------------------------------------------
void MainWindow::slotZoomPlus()
{
    mapScroll->changeScale(1.5);
}

//--------------------------------------------------
void MainWindow::slotZoomMinus()
{
    mapScroll->changeScale(0.75);
}

//-----------------------------------------------
void MainWindow::connectToolActions()
{
    connect(ui->actionMapControlPanel, SIGNAL(toggled(bool)), this, SLOT(slotShowMapControlPanel(bool)));
    connect(mapControlPanel, SIGNAL(visibilityChanged(bool)), ui->actionMapControlPanel, SLOT(setChecked(bool)));

    connect(ui->actionOpenMap, SIGNAL(triggered()), this, SLOT(slotOpenMapFile()));
    connect(ui->actionCloseMap, SIGNAL(triggered()), this, SLOT(slotCloseMapData()));

 }

//-----------------------------------------------
void MainWindow::slotShowCoord(QString str_)
{
    labelSB_Coord->setText(str_);
}

