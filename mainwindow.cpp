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

    ui -> qwtPlot -> setAxisTitle(QwtPlot::yLeft, "Z");
    ui -> qwtPlot -> setAxisTitle(QwtPlot::xBottom, "X");
    ui -> qwtPlot -> insertLegend( new QwtLegend() );
}

void MainWindow::setPlotBright()
{
    ui -> qwtPlotBright -> setTitle( "Brightness" );
    ui -> qwtPlotBright -> setCanvasBackground( Qt::white );

    ui -> qwtPlotBright -> setAxisTitle(QwtPlot::yLeft, "Brightness");
    ui -> qwtPlotBright -> setAxisTitle(QwtPlot::xBottom, "X");
    ui -> qwtPlotBright -> insertLegend( new QwtLegend() );
}

void MainWindow::setPlotGrid()
{
    QwtPlotGrid *grid = new QwtPlotGrid();
    grid -> setMajorPen(QPen( Qt::gray, 2 ));
    grid -> attach( ui->qwtPlot);
}

void MainWindow::setPlotBrightGrid()
{
    QwtPlotGrid *grid = new QwtPlotGrid();
    grid -> setMajorPen(QPen( Qt::gray, 2 ));
    grid -> attach( ui->qwtPlotBright);
}

void MainWindow::setCurveParameters()
{
    curve = new QwtPlotCurve();
    curve->setPen( Qt::blue, 2 );
    curve->setRenderHint
        ( QwtPlotItem::RenderAntialiased, true ); 

    QwtSymbol *symbol = new QwtSymbol( QwtSymbol::Ellipse,
        QBrush( Qt::yellow ), QPen( Qt::red, 2 ), QSize( 3, 3 ) );
    curve->setSymbol( symbol );
}

void MainWindow::setCurveBrightParameters()
{
    brightCurve = new QwtPlotCurve();
    brightCurve->setPen( Qt::blue, 2 );
    brightCurve->setRenderHint
        ( QwtPlotItem::RenderAntialiased, true );

    QwtSymbol *symbol = new QwtSymbol( QwtSymbol::Ellipse,
        QBrush( Qt::yellow ), QPen( Qt::red, 2 ), QSize( 3, 3 ) );
    brightCurve->setSymbol( symbol );
}

void MainWindow::enableMagnifier()
{
    QwtPlotMagnifier *magnifierPlot =
            new QwtPlotMagnifier(ui -> qwtPlot -> canvas());
    QwtPlotMagnifier *magnifierPlotBr =
            new QwtPlotMagnifier(ui -> qwtPlotBright -> canvas());

    magnifierPlot -> setMouseButton(Qt::MiddleButton);
    magnifierPlotBr -> setMouseButton(Qt::MiddleButton);
}

void MainWindow::enableMovingOnPlot()
{
    QwtPlotPanner *d_panner_plot = new QwtPlotPanner( ui->qwtPlot->canvas() );
    QwtPlotPanner *d_panner_plot_br = new QwtPlotPanner( ui->qwtPlotBright->canvas() );

    d_panner_plot -> setMouseButton( Qt::RightButton );
    d_panner_plot_br -> setMouseButton( Qt::RightButton );
}

void MainWindow::enablePicker()
{
    QwtPlotPicker *d_picker_plot =
            new QwtPlotPicker(
                QwtPlot::xBottom, QwtPlot::yLeft,
    QwtPlotPicker::CrossRubberBand,
    QwtPicker::AlwaysOn,
    ui->qwtPlot->canvas() ); 

    QwtPlotPicker *d_picker_plot_br =
            new QwtPlotPicker(
                QwtPlot::xBottom, QwtPlot::yLeft,
    QwtPlotPicker::CrossRubberBand,
    QwtPicker::AlwaysOn,
    ui -> qwtPlotBright -> canvas() );

    d_picker_plot -> setRubberBandPen( QColor( Qt::red ) );
    d_picker_plot -> setTrackerPen( QColor( Qt::black ) );
    d_picker_plot -> setStateMachine( new QwtPickerDragPointMachine() );

    d_picker_plot_br -> setRubberBandPen( QColor( Qt::red ) );
    d_picker_plot_br -> setTrackerPen( QColor( Qt::black ) );
    d_picker_plot_br -> setStateMachine( new QwtPickerDragPointMachine() );
}

void MainWindow::on_plotButton_clicked(bool checked)
{
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

    curve -> setSamples( points );
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
    
    ui->startButton->setDisabled(true);
}

void MainWindow::plotFrame()
{
    float zMax =  (ui -> zMaxBox -> text()).toFloat();

    points.clear();
    brightPoints.clear();

    (this -> profile).move(0, FRAME_STEP);

    if((this -> profile).getZ()[0] > zMax)
    {
        (this -> profile) = (this -> initProfile);
    }

    float minBr = (this -> profile).getMinBrightness();
    float maxBr = (this -> profile).getMaxBrightness();
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

    curve -> setSamples( points );
    brightCurve -> setSamples (brightPoints);

    curve -> attach(ui -> qwtPlot);
    brightCurve -> attach(ui -> qwtPlotBright);

    ui -> qwtPlot -> replot();
    ui -> qwtPlotBright -> replot();
}

void MainWindow::on_stopButton_clicked()
{
    timer -> stop();
    ui->startButton->setEnabled(true);
}

void MainWindow::on_defaultButton_clicked()
{
    points.clear();
    brightPoints.clear();

    int counts = 300;
    float step = 0.05;
    float ws = 2;
    float bs = 3;
    float zMax = 5;

    float maxBr = 5;
    float minBr = 1;

    float X0 = 0;
    float Z0 = 0;

    this->setUiBoxes(counts, step, ws, bs, zMax, maxBr, minBr);

    ui->qwtPlot->setAxisScale(QwtPlot::yLeft, 0, zMax);
    ui->qwtPlotBright->setAxisScale(QwtPlot::yLeft, minBr, maxBr);

    (this->profile).set(counts, step, ws, bs, X0, Z0, minBr, maxBr);
    (this->initProfile).set(counts, step, ws, bs, X0, Z0, minBr, maxBr);

    std::vector<float> x = (this->profile).getX();
    std::vector<float> z = (this->profile).getZ();
    std::vector<float> bright = (this->profile).getBrightness();

    for (int i = 0; i < counts; i++)
    {
        points << QPointF(x[i], z[i]);
        brightPoints << QPointF(x[i], bright[i]);
    }

    curve->setSamples(points);
    brightCurve->setSamples(brightPoints);

    curve->attach(ui->qwtPlot);
    brightCurve->attach(ui->qwtPlotBright);

    ui->qwtPlot->replot();
    ui->qwtPlotBright->replot();
}

void MainWindow::setUiBoxes(int counts, float step, float wStrWidth, float blStrWidth, float zMax, float maxBr, float minBr)
{
    ui->countsBox->setText(QString::number(counts));
    ui->stepBox->setText(QString::number(step));
    ui->whStrBox->setText(QString::number(wStrWidth));
    ui->blStrBox->setText(QString::number(blStrWidth));
    ui->zMaxBox->setText(QString::number(zMax));
    ui->maxBrBox->setText(QString::number(maxBr));
    ui->minBrBox->setText(QString::number(minBr));
}

void MainWindow::slotForNoiseParams(float mean, float stdDev)
{
    (this->profile).setNoiseParams(mean, stdDev);
    
    (this->noiseDialog)->close();
    ui->noiseSetButton->setEnabled(true);
}

void MainWindow::on_noiseSetButton_clicked()
{
    noiseDialog = new NoiseParamsDialog(this);
    noiseDialog -> show();
    ui -> noiseSetButton -> setDisabled(true);

    connect(this, &MainWindow::sendCurrNoiseParamsSignal, this->noiseDialog, &NoiseParamsDialog::setBoxesSlot); //параметры шума в окно
    connect(noiseDialog, &NoiseParamsDialog::sendParamsSignal, this, &MainWindow::slotForNoiseParams);//параметры шума из окна

    emit sendCurrNoiseParamsSignal((this->profile).getMean(), (this->profile).getStdDev());
}



