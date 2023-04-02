#include "signalstopwatch.h"

SignalStopwatch::SignalStopwatch(QObject *parent)
    : QObject{parent}
{

}

void SignalStopwatch::callSignals()
{
    SIGNAL(QTimer::timeout(SignalStopwatch::sig_Start()));
}
