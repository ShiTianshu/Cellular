#ifndef CELLULARSERVER_H
#define CELLULARSERVER_H

#include <QLocalSocket>
#include <QLocalServer>

class CellularServer :
        public QObject
{
    Q_OBJECT
public:
    CellularServer();
    bool initialize();
    void start();
public slots:
    void newConnection();
    void readyRead();
private:
    QLocalServer *_pserver;
};

#endif // CELLULARSERVER_H
