#ifndef SIGNALSLOT_H
#define SIGNALSLOT_H

#include <QWidget>

class SignalSlot : public QWidget
{
    Q_OBJECT
public:
    explicit SignalSlot(QWidget *parent = 0);
    ~SignalSlot();

signals:

public slots:
};

#endif // SIGNALSLOT_H
