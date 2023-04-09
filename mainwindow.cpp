#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer=new QTimer(this);
    sigWatch=new SignalStopwatch(this);

    ui->label->setText("0");
    ui->label_2->setText("0");
    ui->label_3->setText(":");
    ui->pushButton->setText("Start/Stop");
    ui->pushButton_2->setText("Clear");
    ui->pushButton_3->setText("Circle");
    ui->pushButton_3->setEnabled(false);


    connect(ui->pushButton,&QPushButton::clicked,this,&MainWindow::TimerSlotStartStop);
    connect(ui->pushButton_2,&QPushButton::clicked,this,&MainWindow::TimerSlotClear);
    connect(ui->pushButton_3,&QPushButton::clicked,this,&MainWindow::TimerSlotCircle);
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
    ui->label->setText(QString("%1").arg(s));
    ui->label_2->setText(QString("%1").arg(ms));
}

void MainWindow::TimerSlotStartStop()
{
    ui->pushButton_3->setEnabled(true);
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
    ui->label->setText("0");
    ui->label_2->setText("0");
    flag=1;
    ui->pushButton->setText("Start");
    ui->textBrowser->clear();
    ui->pushButton_3->setEnabled(false);
}

void MainWindow::TimerSlotCircle()
{
    i++;
    ui->textBrowser->clear();
    int32_t printS=ui->label->text().toInt();
    int32_t printMS=ui->label_2->text().toInt();
    if(i==1){
        ui->textBrowser->append(QString("Circle №%1, time %2 : %3").arg(i)
                            .arg(ui->label->text().toInt())
                            .arg(ui->label_2->text().toInt()));
        l1=ui->label->text().toInt();
        l2=ui->label_2->text().toInt();
    }
    else{
        if(l2>printMS){
            ui->textBrowser->append(QString("Circle №%1, time %2 : %3").arg(i)
                                .arg(printS-l1-1)
                                .arg(10+printMS-l2));
        }else{
            ui->textBrowser->append(QString("Circle №%1, time %2 : %3").arg(i)
                                .arg(printS-l1)
                                .arg(printMS-l2));
        }
        l1=printS;
        l2=printMS;
    }
}

