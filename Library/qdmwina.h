/******* QDMWINA.H ************** Dishlenko S.G.  ****** 22/03/12 **
*                                                                  *
*              Copyright (c) PANORAMA Group 1991-2012              *
*                      All Rights Reserved                         *
*                                                                  *
********************************************************************
*                                                                  *
*                      FOR QT-DESIGNER                             *
*                                                                  *
********************************************************************
*                                                                  *
*        �������� ������ ������� � �������� �����������            *
*                     ����������� �����                            *
*                                                                  *
*******************************************************************/

#ifndef QDMWINA_H
#define QDMWINA_H

#include <QList>
#include <QTimerEvent>
#include <QMouseEvent>
#include <QKeyEvent>

#include "qdmviewa.h"
#include "qdmcompa.h"

class QDMapSelect;
class QPainter;
class QScrollBar;                // 12/11/07
class QDMapViewPort;
class TCallS57Setup;                    // 08/07/10

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++ ����� "��������� ����������� ����������� ������" +++
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class  QDMapViewWindow : public QDMapViewAcces
{
    Q_OBJECT

    // ���������/��������� ���������� �����
    Q_PROPERTY(bool MapVisible READ GetMapVisible WRITE SetMapVisible)

public :
    QDMapViewWindow(QWidget *parent = 0, const char *name = 0);
   ~QDMapViewWindow();

    bool         GetMapVisible() const;
    // ���������/���������� ������� ����� ������� ������ �����������
    void         GetMapLeftTop(int *left, int *top);
    void         SetMapLeftTop(int left, int top);
    // �������� ���������� mapcomponent � ������ ���������
    void AppendMapObject(QDMapComponent *mapcomponent);
    // �������� ���������� mapcomponent �� ������ ���������
    void DeleteMapObject(QDMapComponent *mapcomponent);
    // ���������/���������� ������� ������� �����������
    virtual int     GetViewScale();
    virtual int     SetViewScale(int value);
    // ������� ��������� �������� ������������ ������� �����
    //   ���������: value - �������� �������, ������� ������ ��������
    int             SetViewScaleInPoint(int value);                        // 25/11/03

    // ���������� �������� ����� ������ ���� � ��������
    virtual RECT    GetRegionRect();
    // ���������� �������� ����� ������ ���� � ��������� ������� ���������
    virtual MAPDFRAME GetRegionDFrame(int pointplace);
    // �������� ������� �����, ��������������� QDMapSelect
    void            DoViewSelect(QDMapSelect *select, COLORREF color);
    // ������� �����������
    void            SetViewSelect(QDMapSelect *value);
    // ���������� ��������� ���������� ��������� �������� ��� ViewSelect
    void            SetViewSelected(bool view);
    // ���������/��������� ����������� ����� � ����������� � ����������
    // ������� �����������
    void            SetSelecting(bool value);
    // �������������� ���������� �� dframein ������� ��������� placein
    // � ������� ��������� placeout
    virtual MAPDFRAME ConvertDFrame(MAPDFRAME dframein, int placein, int placeout);  // 03/02/03
    // �������������� ���������� ��  ������� ��������� placein
    // � ������� ��������� placeout
    virtual int ConvertMetric(double *x, double *y, int placein, int placeout);
    // ���������� ��������� ���������� ��������� ������� �� ��������� VarViewSelect
    void            SetObjSelected(QDMapSelect *objselect, COLORREF color,
                                   bool repaint);
    // ��������� ��������� �� ����� �������� ����������� ������
    // ���� �������� ������������� ���������� �� ���������� true
    bool UpdatePictureBorder();
    virtual void Repaint();
    // ���������� �����, ��� x � � ���������� ������ �������� ����
    // ����� � ��������       // 15/11/07
    void Repaint(int x, int y, int width, int height);
    // ���������/��������� ����������� �����
    void  SetRendering(bool value);
    bool  GetRendering();
    // ����������/����������� ������� ���������� ������� 
    // �� �������� ����������� ������
    bool SetCurrentAction(QWidget *gtkaction);                      // 21/11/03
    // actionquery - ���� �� ������� ��������� ���������� 
    // �� ������������
    bool DeleteAction(QWidget *gtkaction, bool actionquery);
    // ������ ��������� ���� ����������� �����  // 15/11/07
    int GetVisibleWidth();
    int GetVisibleHeight();

public slots:
    void SetMapVisible(bool visible);
    // ��������� �������             // 09/11/07
    void SlotHBarChanged(int x);
    void SlotVBarChanged(int y);
    // ����� ��������� �������
    
signals :
    // ������� �� ���� :
    // x, y - ������� ������� � ������� ��������� ���� ����������� ����� (�������)
    // modkeys - ��������� ������ ������������� � ������ ����
    void SignalMouseMove(int x, int y, int modkeys);
    void SignalMousePress(int x, int y, int modkeys);
    void SignalMouseRelease(int x, int y, int modkeys);
    void SignalMouseDoubleClick(int x, int y, int modkeys);
    // ������� �� ���������� :
    // key     - ��� �������,
    // count   - ���������� ������� �������,
    // modkeys - ���������������� �����, ������� ������������ ����� ���,
    // ��� ������ ��������� �������
    void SignalKeyPress(int key, int count, int state);
    void SignalKeyRelease(int key, int count, int state);
    // ������� �� ���� ���������������� :                
    void SignalAfterPaint(QPainter *p, int cx, int cy, int cw, int ch); // 20/09/07

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// ���� ������� ��� ����������� �������������
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

protected :
    //  ��������� ������� Qt :
    //  ������ �������
    void keyPressEvent(QKeyEvent *k );
    //  ��������� ������� Qt :
    //  ������� ��������
    void keyReleaseEvent(QKeyEvent *k );
    void SetTypePaint(int type);
    int  GetTypePaint();

public :

    virtual void drawContents(QPainter* p, int cx, int cy, int cw, int ch); // 19/06/07
    // �������������� ��� ������ QDGtkAction � ��������
    //  ��������� ������� Qt :
    //  ���������� ���������
    //  ����������� ����
    void viewportMouseMoveEvent(QMouseEvent * e);
    //  ��������� ������� Qt :
    //  ���������� ��������� ������� ������ ����
    void viewportMousePressEvent(QMouseEvent * e);
    //  ��������� ������� Qt :
    //  ���������� ������� ������ ����
    void viewportMouseReleaseEvent(QMouseEvent * e);
    //  ��������� ������� Qt :
    //  ���������� ������� ������� ������ ����
    void viewportMouseDoubleClickEvent ( QMouseEvent * e );
    // ��������� ������� ��������� ������� ���� � �� �����������
    // �� ������ MapViewWindow
    virtual void    AllMapRef(int typeaction);
    // ��������� ������� ��������� ������� ���� �� ������ MapViewWindow
    virtual void    MapAction(int typeaction);
    // ����������� ��������� ������� (Qt)        // 06/07/10
    virtual void timerEvent(QTimerEvent *e);
    virtual bool event(QEvent *e);               // 06/07/10
    // ���������� ������ Select ��� �����������
    void SetViewSelectNow(QDMapSelect *mapselect, bool alwaysnew);
    // ����������� ���� ���������� ����  mapacces
    void PaintOfMapAcces(QPainter *p);
    // ���������� ���������
    long int MessageHandler(long int context, long int code,
                            long int wp, long int lp, long int typemsg = 0);
    //  ���������� ��������� ���� �����
    int   DoMapWindowMsg(long int code, long int param);
    //  ����������� ����� � �������� �����
    int   MoveMap(long int wparam, long int lparam);
    // ���������� ���������� ������ �������� ���� �����
    void  SetPicturePoint(POINT& point);
    // ��������� ��������� ���� �����
    int   MapWindowPort(int command, int parm);
    // ���������� ����� ���������� �����        // 21/11/03
    void MapBeforePaint(QObject *sender, HWND canvas, RECT mappaintrect);
    // ���������� ����� ��������� �����
    void MapAfterPaint(QObject *sender, HWND canvas, RECT mappaintrect);

public :
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// ���� ���������� ��� ����������� �������������
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    QDMapSelect            *VarViewSelectLast;  // ����� ������ QDMapSelect ����������         // 22/03/12
                                                // ��������� ��� ����������� � ����
    QDMapSelect            *VarViewSelect;
    QDMapSelect            *VarObjSelect;       // ��������� ��������� ��������
    // ������� ���������� ������� �� ���� ����� ���� QDGtkAction // 21/11/03
    QWidget                *VarCurrentGtkAction;
    TCallS57Setup         *CallS57Setup;       // ��������� ���������� ������� ���� ������� S57 // 08/07/10

    QDMapViewPort          *MapViewPort;        // 12/11/07
    HIMAGE                 hScreen;             // 19/07/10
    QScrollBar             *HScrollBar;
    QScrollBar             *VScrollBar;
    HDC                    VarHDC;
    void                   *PointerVarXDC;
    QList<QDMapComponent*> VarMapObjects;
    QRect                  RectDraw;            // �^Î̎�ӎԎ؎ ώԎҎɎӎώ ˎɎ ˎ�ҎԎَ
    DFRAME                 VarMapFrame;
    int                    VarPlace;
    RECT                   VarMapRec;
    int                    VarHorzPos;
    int                    VarVertPos;
    int                    VarColorSelected;    // ���� ���������� ���������
    int                    VarPaintEnabled;     // ���� ��������� �����
    bool                   VarRendering;
    bool                   VarViewSelected;     // ������� ������������� ���������� ���������
                                                // ��������� ViewSelect
    bool                   VarMapVisible;
    // ������������ ������ �� ������
    bool                  VarSelecting;        // ���������/��������� ����������� ����� �
                                               // ������������ � ���������� ������� �����������
//!!!!!!!!!!!!!!!!!!!!
// ��������� �����
//!!!!!!!!!!!!!!!!!!!
};

#endif // QDMWINA_H
