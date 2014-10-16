#include <QDebug>

#include "cellularserver.h"
#include "../CellularBase/cellular_ipc.h"

CellularServer::CellularServer()
{
    this->_pserver = 0;
}

bool CellularServer::initialize()
{
    if (!this->_pserver)
        this->_pserver = new QLocalServer();
    return true;
}

void CellularServer::start()
{
    if (this->_pserver)
        this->_pserver->listen(CELLULAR_SERVER_NAME);
    connect(this->_pserver, SIGNAL(newConnection()),
            this, SLOT(newConnection()));
    qDebug() << "server started!";
}

void CellularServer::newConnection()
{
    QLocalSocket *psocket = _pserver->nextPendingConnection();
    connect(psocket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    qDebug() << "client connected!";
}
#include <windows.h>
void CellularServer::readyRead()
{
    cellular::Request request;
    cellular::Response response;
    
    QLocalSocket *psocket = qobject_cast< QLocalSocket* >(sender());
    

    psocket->read((char*)&request, sizeof(request));
    qDebug() << request.clientId << request.key << request.keyPress;
    wcscpy(response.commit, L"你好啊");
    wcscpy(response.edit, L"这个世界");
    response.isComposing = true;
    psocket->write((char*)&response, sizeof(response));
    psocket->flush();
}




