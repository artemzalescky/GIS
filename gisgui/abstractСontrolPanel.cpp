#include "abstractСontrolPanel.h"

#include <QToolButton>

AbstractControlPanel::AbstractControlPanel(const QString &title, QWidget *parent) :
    QToolBar(title, parent)
{
}

/*создание иконок для панели*/
QToolButton *AbstractControlPanel::createToolButton(const QString &name, const QString &iconPath)
{
    QToolButton *button = new QToolButton();
    button->setMinimumSize(QSize(30, 30));
    button->setMaximumSize(QSize(30, 30));
    button->setIcon(QPixmap(iconPath));
    button->setStatusTip(name);
    button->setToolTip(name);
    return button;
}
