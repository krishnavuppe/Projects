#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <unistd.h>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Start_clicked()
{
    QVector<double> xaxis(2), yaxis(2);
    int i=0;
    // create graph and assign data to it:
    ui->customPlot->addGraph();
    // give the axes some labels:
    ui->customPlot->xAxis->setLabel("x");
    ui->customPlot->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
    ui->customPlot->xAxis->setRange(0, 12);
    ui->customPlot->yAxis->setRange(-1, 2);
    while(1)
    { xaxis[0] = i*1.0;
      if(yaxis[0]==0.0){yaxis[0] = 1.0;}
      else{yaxis[0] = 0.0;}
      //  ui-> customPlot->graph(0)->setData(x, y);
      // add data to lines:
      ui->customPlot->graph(0)->addData(xaxis[0], yaxis[0]);
      // make key axis range scroll with the data (at a constant range size of 8):
      if(xaxis[0] >= 12){
      ui->customPlot->xAxis->setRange(xaxis[0], 10, Qt::AlignRight);}
      ui->customPlot->replot();
      i++;
      usleep(500000);
    }
}
