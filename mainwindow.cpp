#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer=new QTimer(this);
    sigWatch=new SignalStopwatch(this);

    ui->label->setText("0 : 0");
    ui->pushButton->setText("Start/Stop");
    ui->pushButton_2->setText("Clear");
    ui->pushButton_3->setText("Circle");


    connect(ui->pushButton,&QPushButton::clicked,this,&MainWindow::TimerSlotStartStop);
    connect(ui->pushButton_2,&QPushButton::clicked,this,&MainWindow::TimerSlotClear);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::TimerSlot()
{

    ms++;
    if(ms==10) {ms=0; s++;}
    if(s==60) {s=0;}
    ui->label->setText(QString::number(s) + " : " + (QString::number(ms)));
}

void MainWindow::TimerSlotStartStop()
{
    flag= !flag;
    if(flag){
        ui->pushButton->setText("Start");
        timer->stop();
    }
    else {
        connect(timer,SIGNAL(timeout()),this,SLOT(TimerSlot()));
        timer->start(100);
        ui->pushButton->setText("Stop");
    }
}

void MainWindow::TimerSlotClear()
{
    ms=0;s=0;
    timer->stop();
    ui->label->setText("0 : 0");
    //ui->

}

