#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QLabel;

class MapScroll;
class MapControlPanel;
class BaseProfileWidget;
class CCreateMTWWidget;
class DistanceCalculatorWidget;

class CPaintControlPanel;

//------------------------------
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent_ = 0, Qt::WFlags flags_ = 0);
    ~MainWindow();
    
private:
    Ui::MainWindow *ui;


    MapScroll *mapScroll;
    bool m_first;

    MapControlPanel *mapControlPanel;           //объект инициализации панели со значками


    QLabel  *labelSB_CS;
    QLabel  *labelSB_Coord;
    QLabel	*labelSB_Scale;

    bool mVisibleProfile;

public:
    void setVisibleProfile(bool);
    bool isVisibleProfile();

private slots:
    void slotOpenMapFile();
    void slotCloseMapData();

    void slotZoomPlus();
    void slotZoomMinus();
    void slotShowCoord(QString);

    void slotShowMapControlPanel(bool);

private:
    void connectToolActions();
    void initToolBar();
    void createStatusBar();
    void createGISParamDialog();


protected:
    virtual void showEvent(QShowEvent *);
    virtual void closeEvent(QCloseEvent *);

};

#endif // MAINWINDOW_H
