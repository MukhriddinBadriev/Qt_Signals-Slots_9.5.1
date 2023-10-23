#include "signalstopwatch.h"

SignalStopwatch::SignalStopwatch(QObject *parent)
    : QObject{parent}
{
    tPtr = new QTimer(this);
    QObject::connect(tPtr, &QTimer::timeout, this, &SignalStopwatch::recieveTimeout);
    setInterval(100);
}

SignalStopwatch::~SignalStopwatch()
{
    delete tPtr;
}

void SignalStopwatch::setInterval(int &&interval)
{
    this->interval = interval;
}

void SignalStopwatch::startTimer()
{
    tPtr->start(interval);
    start = true;
}

void SignalStopwatch::stopTimer()
{
    tPtr->stop();
    start = false;
}

void SignalStopwatch::updateTime()
{
    time += static_cast<double>(interval)/1000;
}

QString SignalStopwatch::getTime() const
{
    return QString("%1").arg(time);
}

bool SignalStopwatch::isStarted() const
{
    return start;
}

QString SignalStopwatch::getLoop()
{
    ++loop;
    return QString("%1").arg(loop);
}

QString SignalStopwatch::getLoopTime()
{
    double res = time - loopTime;
    loopTime = time;
    return QString("%1").arg(res);
}

void SignalStopwatch::clear()
{
    time = 0.0;
    loopTime = 0.0;
    loop = 0;
}

void SignalStopwatch::recieveTimeout()
{
    SignalStopwatch::updateTime();
    emit timeoutSignal();
}
