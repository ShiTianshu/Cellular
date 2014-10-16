#ifndef CELLULAR_IPC_H
#define CELLULAR_IPC_H

#define CELLULAR_SERVER_NAME "cellular_server_v0.01"

#include <QtCore>
#include <QByteArray>

namespace cellular{

class Request
{
public:
    qint64 clientId;
    qint32 key;
    qint8 keyFlags;
    bool keyPress;
    bool onFocus;
    qint32 x;
    qint32 y;
    Request();
};

class Response
{
public:
    wchar_t commit[256];
    wchar_t edit[256];
    bool keyEaten;
    bool isComposing;
    Response();
};

Request::Request()
{
    clientId = -1;
    key = -1;
    keyFlags = -1;
    x = -1;
    y = -1;
}

Response::Response()
{
    wmemset(commit, 0, 256);
    wmemset(edit, 0, 256);
}

}


#endif // CELLULAR_IPC_H
