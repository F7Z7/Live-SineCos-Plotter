#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "qcustomplot.h"
#include <QTimer>
#include <QtMath>
#include <QPen>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    ,t(0.0)
{
    ui->setupUi(this);
    timer= new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updatePlot);
    ui->graphPlotter->addGraph();
    //sine wave
    ui->graphPlotter->graph(0)->setPen(QPen(Qt::blue));
     ui->graphPlotter->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20)));
    ui->graphPlotter->graph(0)->setName("Sine Wave");
    //cos wave
     ui->graphPlotter->addGraph();
     ui->graphPlotter->graph(1)->setPen(QPen(Qt::red));
     ui->graphPlotter->graph(1)->setBrush(QBrush(QColor(0,255,0,0)));
     ui->graphPlotter->graph(1)->setName("Cos Wave");
     ui->graphPlotter->legend->setVisible(true);



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startButton_clicked()
{
    timer->start(50);
}


void MainWindow::on_stopButton_clicked()
{
    timer->stop();
}
void MainWindow::updatePlot()
{
    const double dt=0.05;
    t+=dt ;//new time=old time+change in time
    x.append(t);
    sineData.append(qSin(2*M_PI*t));
    cosData.append(qCos(2*M_PI*t));

    if (x.size() > 200) {
        x.remove(0);
        sineData.remove(0);
        cosData.remove(0);
    }
    ui->graphPlotter->graph(0)->setData(x,sineData);
    ui->graphPlotter->xAxis->setRange(t-10,t);
    ui->graphPlotter->yAxis->setRange(-1,1);

    ui->graphPlotter->graph(1)->setData(x,cosData);
    ui->graphPlotter->xAxis->setRange(t-10,t);
    ui->graphPlotter->yAxis->setRange(-1,1);
    ui->graphPlotter->replot();



}

void MainWindow::on_resetButton_clicked()
{
    timer->stop();
    t = 0;
    x.clear();
    sineData.clear();
    cosData.clear();

    ui->graphPlotter->clearGraphs();


    ui->graphPlotter->addGraph();
    ui->graphPlotter->graph(0)->setPen(QPen(Qt::blue));
    ui->graphPlotter->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20)));
    ui->graphPlotter->graph(0)->setName("Sine Wave");


    ui->graphPlotter->addGraph();
    ui->graphPlotter->graph(1)->setPen(QPen(Qt::red));
    ui->graphPlotter->graph(1)->setBrush(QBrush(QColor(255, 0, 0, 20)));
    ui->graphPlotter->graph(1)->setName("Cos Wave");

    ui->graphPlotter->legend->setVisible(true);
    ui->graphPlotter->replot();
}

