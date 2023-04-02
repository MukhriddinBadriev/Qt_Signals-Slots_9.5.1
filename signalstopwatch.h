#ifndef SIGNALSTOPWATCH_H
#define SIGNALSTOPWATCH_H

#include <QObject>
#include <QTimer>

class SignalStopwatch : public QObject
{
    Q_OBJECT
public:
    explicit SignalStopwatch(QObject *parent = nullptr);
    void callSignals(void);


signals:
    void sig_Start(void);

};

#endif // SIGNALSTOPWATCH_H
