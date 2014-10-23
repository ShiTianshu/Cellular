#ifndef SERVICE_H
#define SERVICE_H

#include <QObject>
#include <QMap>

#include "isource.h"

class InputMethod;
struct Environment;
struct Context;
struct Session;

class Service : public QObject
{
    Q_OBJECT
public:
    Service();
    
private:
    QMap< QString, InputMethod* > _inputMethods;
    QMap< qint64, Context* > _contexts;
    Environment *_pEnvironment;
    Session *_pSession;
    
public slots:
    void slotFind(const QString &sourceId, const QString &key, PCursor *ppCursor);
};

#endif // SERVICE_H
