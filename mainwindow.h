#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "signalstopwatch.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    int s,ms;
    bool flag=true;

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    SignalStopwatch *sigWatch;

public slots:
    void TimerSlot(void);
    void TimerSlotStartStop(void);
    void TimerSlotClear(void);

};
#endif // MAINWINDOW_H
