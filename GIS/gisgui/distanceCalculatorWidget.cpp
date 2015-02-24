#include "distanceCalculatorWidget.h"

#include <QPushButton>
#include <QGridLayout>
#include <QLineEdit>
#include <QRadioButton>
#include <QString>
#include <QDebug>

#include "mapScroll.h"
#include <QLabel>

DistanceCalculatorWidget::DistanceCalculatorWidget(QWidget *parent_)
    : QDialog(parent_)
{
    editValue = new QLineEdit(this);
    editValue->setFixedSize(100, 24);
    QLabel *labelValue = new QLabel(tr("Расстояние:"));
    labelValue->setBuddy(editValue);
    QLabel *labelMeter = new QLabel(tr("м"));

    buttonClose = new QPushButton(tr("Закрыть"));
    buttonClose->setDefault(true);

    buttonClear = new QPushButton(tr("Очистить"));

    radioLine = new QRadioButton(tr("Отрезок"));
    radioLine->setChecked(true);
    radioPath = new QRadioButton(tr("Ломаная"));
    radioPath->setChecked(false);
    radioRadial = new QRadioButton(tr("Луч"));
    radioRadial->setChecked(false);

    QGridLayout *topLayout = new QGridLayout;

    topLayout->addWidget(labelValue, 0, 0, 1, 2);
    topLayout->addWidget(editValue, 0, 2, 1, 4);
    topLayout->addWidget(labelMeter, 0, 6, 1, 1, Qt::AlignLeft);

    topLayout->addWidget(buttonClear, 0, 8, 1, 2);

    topLayout->addWidget(radioLine, 1, 0, 1, 2);
    topLayout->addWidget(radioRadial, 1, 2, 1, 2);
    topLayout->addWidget(radioPath, 1, 5, 1, 2);

    topLayout->addWidget(buttonClose, 1, 8, 1, 2);

    setLayout(topLayout);
    setWindowTitle(tr("Калькулятор растояний"));

    connect(buttonClose, SIGNAL(clicked()), this, SLOT(close()));
    connect(buttonClear, SIGNAL(clicked()), this, SLOT(slotClear()));
    connect(radioLine, SIGNAL(clicked()), this, SLOT(slotSetLineType()));
    connect(radioPath, SIGNAL(clicked()), this, SLOT(slotSetPathType()));
    connect(radioRadial, SIGNAL(clicked()), this, SLOT(slotSetRadialType()));


    typeCalc = 0; // по умолчанию отрезок
}

//----------------------------------------------------------------------------------
void DistanceCalculatorWidget::slotClear()
{
    editValue->clear();
    emit signalNewLineType(typeCalc + 1);
}

//----------------------------------------------------------------------------------
void DistanceCalculatorWidget::slotSetDistance(double dist_)
{
    if(dist_ < 0)
    {
        editValue->clear();
    }
    else
    {
        editValue->setText(QString::number(dist_, 'f', 0));
    }
}

//----------------------------------------------------------------------------------
void DistanceCalculatorWidget::slotSetLineType()
{
    if(typeCalc == 0)
    {
        return;
    }
    radioPath->setChecked(false);
    radioRadial->setChecked(false);
    typeCalc = 0;
    slotClear();
}

//----------------------------------------------------------------------------------
void DistanceCalculatorWidget::slotSetPathType()
{
    if(typeCalc == 2)
    {
        return;
    }
    radioLine->setChecked(false);
    radioRadial->setChecked(false);
    typeCalc = 2;
    slotClear();
}

//---------------------------------------------------------------------------------
void DistanceCalculatorWidget::slotSetRadialType()
{
    if(typeCalc == 1)
    {
        return;
    }
    radioLine->setChecked(false);
    radioPath->setChecked(false);
    typeCalc = 1;
    slotClear();

}

//-----------------------------------------------------------------------------------
void DistanceCalculatorWidget::showEvent(QShowEvent *event_)
{
    event_;
    slotSetLineType();
}

//-----------------------------------------------------------------------------------
void DistanceCalculatorWidget::closeEvent(QCloseEvent *event_)
{
    event_;
    emit signalNewLineType(-1);
}
