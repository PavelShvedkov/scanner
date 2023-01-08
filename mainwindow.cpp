#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui -> setupUi(this);

    setPlot();
    setPlotGrid();
    setCurveParameters();

    setPlotBright();
    setPlotBrightGrid();
    setCurveBrightParameters();

    enableMagnifier();
    enableMovingOnPlot();
    enablePicker();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setPlot()
{
    ui -> qwtPlot -> setTitle( "Scanner" );
    ui -> qwtPlot -> setCanvasBackground( Qt::white );

    // Axis params
    ui -> qwtPlot -> setAxisTitle(QwtPlot::yLeft, "Z");
    ui -> qwtPlot -> setAxisTitle(QwtPlot::xBottom, "X");
    ui -> qwtPlot -> insertLegend( new QwtLegend() );
}

void MainWindow::setPlotBright()
{
    ui -> qwtPlotBright -> setTitle( "Brightness" );
    ui -> qwtPlotBright -> setCanvasBackground( Qt::white );

    //Axis params
    ui -> qwtPlotBright -> setAxisTitle(QwtPlot::yLeft, "Brightness");
    ui -> qwtPlotBright -> setAxisTitle(QwtPlot::xBottom, "X");
    ui -> qwtPlotBright -> insertLegend( new QwtLegend() );
}

void MainWindow::setPlotGrid()
{
    QwtPlotGrid *grid = new QwtPlotGrid();
    grid -> setMajorPen(QPen( Qt::gray, 2 )); // color and width of grid
    grid -> attach( ui->qwtPlot);
}

void MainWindow::setPlotBrightGrid()
{
    QwtPlotGrid *grid = new QwtPlotGrid();
    grid -> setMajorPen(QPen( Qt::gray, 2 )); // color and width of grid
    grid -> attach( ui->qwtPlotBright);
}

void MainWindow::setCurveParameters()
{
    //#include <qwt_plot_curve.h>
    curve = new QwtPlotCurve();
    curve->setPen( Qt::blue, 2 ); // color and width
    curve->setRenderHint
        ( QwtPlotItem::RenderAntialiased, true ); // smoothing

    // marks
    // #include <qwt_symbol.h>
    QwtSymbol *symbol = new QwtSymbol( QwtSymbol::Ellipse,
        QBrush( Qt::yellow ), QPen( Qt::red, 2 ), QSize( 3, 3 ) );
    curve->setSymbol( symbol );
}

void MainWindow::setCurveBrightParameters()
{
    brightCurve = new QwtPlotCurve();
    brightCurve->setPen( Qt::blue, 2 ); // color and width
    brightCurve->setRenderHint
        ( QwtPlotItem::RenderAntialiased, true ); // smoothing

    // marks
    // #include <qwt_symbol.h>
    QwtSymbol *symbol = new QwtSymbol( QwtSymbol::Ellipse,
        QBrush( Qt::yellow ), QPen( Qt::red, 2 ), QSize( 3, 3 ) );
    brightCurve->setSymbol( symbol );
}

void MainWindow::enableMagnifier()
{
    // #include <qwt_plot_magnifier.h>
    QwtPlotMagnifier *magnifierPlot =
            new QwtPlotMagnifier(ui -> qwtPlot -> canvas());
    QwtPlotMagnifier *magnifierPlotBr =
            new QwtPlotMagnifier(ui -> qwtPlotBright -> canvas());
    // zoom button
    magnifierPlot -> setMouseButton(Qt::MidButton);
    magnifierPlotBr -> setMouseButton(Qt::MidButton);
}

void MainWindow::enableMovingOnPlot()
{
    // #include <qwt_plot_panner.h>
    QwtPlotPanner *d_panner_plot = new QwtPlotPanner( ui->qwtPlot->canvas() );
    QwtPlotPanner *d_panner_plot_br = new QwtPlotPanner( ui->qwtPlotBright->canvas() );
    // клавиша, активирующая перемещение
    // клавиша, активирующая перемещение
    d_panner_plot -> setMouseButton( Qt::RightButton );
    d_panner_plot_br -> setMouseButton( Qt::RightButton );
}

void MainWindow::enablePicker()
{
    // #include <qwt_plot_picker.h>
    // настройка функций
    QwtPlotPicker *d_picker_plot =
            new QwtPlotPicker(
                QwtPlot::xBottom, QwtPlot::yLeft, // ассоциация с осями
    QwtPlotPicker::CrossRubberBand, // стиль перпендикулярных линий
    QwtPicker::AlwaysOn, // всегда включен
    ui->qwtPlot->canvas() ); // ассоциация с полем

    QwtPlotPicker *d_picker_plot_br =
            new QwtPlotPicker(
                QwtPlot::xBottom, QwtPlot::yLeft, // ассоциация с осями
    QwtPlotPicker::CrossRubberBand, // стиль перпендикулярных линий
    QwtPicker::AlwaysOn, // всегда включен
    ui -> qwtPlotBright -> canvas() ); // ассоциация с полем

    d_picker_plot -> setRubberBandPen( QColor( Qt::red ) );
    d_picker_plot -> setTrackerPen( QColor( Qt::black ) );
    d_picker_plot -> setStateMachine( new QwtPickerDragPointMachine() );

    d_picker_plot_br -> setRubberBandPen( QColor( Qt::red ) );
    d_picker_plot_br -> setTrackerPen( QColor( Qt::black ) );
    d_picker_plot_br -> setStateMachine( new QwtPickerDragPointMachine() );
}

void MainWindow::on_plotButton_clicked(bool checked)
{
    // Добавить точки на ранее созданную кривую
    // Значения точек записываются в массив, затем считываются
    // из этого массива

    points.clear();
    brightPoints.clear();

    int counts = (ui -> countsBox -> text()).toInt();
    float step = (ui -> stepBox -> text()).toFloat();
    float ws = (ui -> whStrBox -> text()).toFloat();
    float bs = (ui -> blStrBox -> text()).toFloat();
    float zMax =  (ui -> zMaxBox -> text()).toFloat();

    float maxBr = (ui -> maxBrBox -> text()).toFloat();
    float minBr = (ui -> minBrBox -> text()).toFloat();

    float X0 = 0;
    float Z0 =0;

    ui -> qwtPlot -> setAxisScale(QwtPlot::yLeft, 0, zMax);
    ui -> qwtPlotBright -> setAxisScale(QwtPlot::yLeft, minBr, maxBr);

    (this -> profile).set(counts, step, ws, bs, X0, Z0, minBr, maxBr);
    (this -> initProfile).set(counts, step, ws, bs, X0, Z0, minBr, maxBr);

    std::vector<float> x = (this -> profile).getX();
    std::vector<float> z = (this -> profile).getZ();
    std::vector<float> bright = (this -> profile).getBrightness();

    for (int i = 0; i < counts; i++)
    {
        points << QPointF(x[i], z[i]);
        brightPoints << QPointF(x[i], bright[i]);
    }

    curve -> setSamples( points ); // ассоциировать набор точек с кривой
    brightCurve -> setSamples (brightPoints);

    curve -> attach(ui -> qwtPlot);
    brightCurve -> attach(ui -> qwtPlotBright);

    ui -> qwtPlot -> replot();
    ui -> qwtPlotBright -> replot();
}

void MainWindow::on_startButton_clicked()
{
    this -> timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,
            SLOT(plotFrame()));

    timer -> start(FRAME_FREQUENCY);
}

void MainWindow::plotFrame()
{
    float zMax =  (ui -> zMaxBox -> text()).toFloat();

    points.clear();
    brightPoints.clear();

    (this -> profile).move(0, FRAME_STEP);

    if((this -> profile).getZ()[0] > zMax)
    {
        (this -> profile) = this -> initProfile;
    }

    float minBr = (this -> profile).getMinBrightness();//(ui -> minBrBox -> text()).toFloat();
    float maxBr = (this -> profile).getMaxBrightness();//(ui -> maxBrBox -> text()).toFloat();
    float initStep = (this -> initProfile).getStep();


    std::vector<float> z = (this -> profile).getZ();
    std::vector<float> x = (this -> profile).getX();
    std::vector<float> bright = (this -> profile).getBrightness();

    if(maxBr <= minBr)
    {
        maxBr = minBr;
    }
    else
    {
        maxBr *= BRIGHTNESS_DECAY;
    }

    (this -> profile).setBrightnessWithNoise(minBr, maxBr);
    (this -> profile).setStep((z[0] + DISTANCE_TO_TARGET) * initStep/DISTANCE_TO_TARGET);

    for(int i = 0; i < (this -> profile).getCounts(); i++)
    {
        points << QPointF(x[i], z[i]);
        brightPoints << QPointF(x[i], bright[i]);
    }


    curve -> setSamples( points ); // ассоциировать набор точек с кривой
    brightCurve -> setSamples (brightPoints);

    curve -> attach(ui -> qwtPlot);
    brightCurve -> attach(ui -> qwtPlotBright);

    ui -> qwtPlot -> replot();
    ui -> qwtPlotBright -> replot();
}

void MainWindow::on_stopButton_clicked()
{
    timer -> stop();
}


