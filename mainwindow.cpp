#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->pushButton_3->setEnabled(false);

    sWatch = new SignalStopwatch(this);
    connect(sWatch, &SignalStopwatch::timeoutSignal, this, [&]{
        ui->label->setText(sWatch->getTime());
    });
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::getStartStop);
    connect(ui->pushButton_3, &QPushButton::clicked, this, [&]{
        ui->textBrowser->append("Круг " + sWatch->getLoop() + ", время: " + sWatch->getLoopTime() + " сек");
    });
    connect(ui->pushButton_2, &QPushButton::clicked, this, [&]{
        sWatch->clear();
        ui->label->setText("0.0");
        ui->textBrowser->clear();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::getStartStop()
{
    if(!sWatch->isStarted())
    {
        sWatch->startTimer();
        ui->pushButton->setText("Стоп");
        ui->pushButton_3->setEnabled(true);
    }
    else
    {
        sWatch->stopTimer();
        ui->pushButton->setText("Старт");
        ui->pushButton_3->setEnabled(false);
    }
}
