#ifndef ABSTRACTCONTROLPANEL_H
#define ABSTRACTCONTROLPANEL_H

#include <QToolBar>
/*Абстактный класс в котором реализовано создание иконок для панели*/

class QToolButton;

class AbstractControlPanel : public QToolBar
{
    Q_OBJECT
public:
    explicit AbstractControlPanel(const QString &title, QWidget *parent = 0);
    
protected:
    virtual void initializeItems() = 0;
    QToolButton* createToolButton(const QString &name, const QString &iconPath);

};

#endif // ABSTRACTCONTROLPANEL_H
