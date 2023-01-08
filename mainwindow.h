#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolButton>
#include <QToolBar>
#include <QVBoxLayout>

#include <qwt_plot.h>
#include <qwt_plot_grid.h>

#include <qwt_legend.h>

#include <qwt_plot_curve.h>
#include <qwt_symbol.h>

#include <qwt_plot_magnifier.h>

#include <qwt_plot_panner.h>

#include <qwt_plot_picker.h>
#include <qwt_picker_machine.h>

#include <qwt_counter.h>

#include <QMainWindow>

#include <QTimer>

#include "profile.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setPlot();
    void setPlotBright();

    void setPlotGrid();
    void setPlotBrightGrid();

    void setCurveParameters();
    void setCurveBrightParameters();

    void addPointsToCurveAndShow(float x0, float y0);

    void enableMagnifier();
    void enableMovingOnPlot();
    void enablePicker();

    QwtPlotCurve *curve;
    QwtPlotCurve *brightCurve;
    QPolygonF points;
    QPolygonF brightPoints;
    Profile profile; //состояние на данные момент
    Profile initProfile; //состояние при инициализации

private slots:
    void on_plotButton_clicked(bool checked);
    void on_startButton_clicked();
    void on_stopButton_clicked();

    void plotFrame();
private:
    Ui::MainWindow *ui;
    QTimer *timer;

    const float FRAME_STEP = 0.001;
    const int FRAME_FREQUENCY = 30;
    const float BRIGHTNESS_DECAY = 0.999;
    const float DISTANCE_TO_TARGET = 1;
};
#endif // MAINWINDOW_H
