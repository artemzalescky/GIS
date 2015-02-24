#ifndef DISTANCECALCULATORWIDGET_H
#define DISTANCECALCULATORWIDGET_H

#include <QDialog>
#include "../gisdata/GISPainter.h"

class QPushButton;
class QRadioButton;
class QLineEdit;

/*!
 \brief Виджет калькулятор расстояний (расстояния только отображаются!!! , вычисления в другом модуле)
*/
class DistanceCalculatorWidget : public QDialog {

    Q_OBJECT

public:
    DistanceCalculatorWidget(QWidget *parent_ = 0);

private:

    QLineEdit *editValue;  /* Окно отображения результата вычислений */

    QRadioButton *radioLine,   /* переключатель - тип Отрезок  */
                 *radioPath,   /* переключатель - тип Ломаная*/
                 *radioRadial; /* переключатель - тип Луч*/

    QPushButton *buttonClose,
                *buttonClear;

private:
    int typeCalc; /* param 0 - line(отрезок)  1  - radial(луч) 2- path(ломанная) */

public slots:
    void slotClear();    
    void slotSetDistance(double);

private slots:
    void slotSetLineType();   //Установка типа линии ОТРЕЗОК
    void slotSetPathType();   // Установка типа линии ЛОМАНАЯ
    void slotSetRadialType(); //Установка типа линии ЛУЧ

signals:
    /*
     \brief Оповедение об установке нового типа вычислений
     \param int type_ - код установленного типа вычислений
    **/
    void signalNewLineType(int type_);

private:

    virtual void showEvent(QShowEvent *event_);
    virtual void closeEvent(QCloseEvent *event_);

};


#endif // DISTANCECALCULATORWIDGET_H
