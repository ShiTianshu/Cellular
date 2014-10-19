#include "cellular_common.h"
#include "cellular_module.h"
#include "cellular_engine.h"

namespace cellular {

bool Environment::addConfig(const QString &moduleId, const QString &key, const QString &value)
{
    QString k = QString("%1/%2").arg(moduleId).arg(key);
    if (!configs.contains(k))
    {
        configs[QString("%1/%2").arg(moduleId).arg(key)] = value;
        return true;
    }
    return false;
}

QString Environment::getConfig(const QString &moduleId, const QString &key)
{
    QString k = QString("%1/%2").arg(moduleId).arg(key);
    QHash< QString, QString >::iterator it = configs.find(k);
    if (it != configs.end())
        return it.value();
    return QString("");
}

bool Environment::isModuleExist(const QString &moduleId)
{
    return modules.contains(moduleId);
}

void Environment::addModule(IModule *pModule)
{
    if (isModuleExist(pModule->id()))
    {
        delete modules.find(pModule->id()).value();
        modules.remove(pModule->id());
    }
    modules[pModule->id()] = pModule;
}

IModule *Environment::getModule(const QString &moduleId)
{
    QHash< QString, IModule* >::iterator it = modules.find(moduleId);
    if (it == modules.end())
        return 0;
    return it.value();
}

bool Environment::isEngineExist(const QString &engineId)
{
    return engines.contains(engineId);
}

void Environment::addEngine(Engine *pEngine)
{
    if (isEngineExist(pEngine->id()))
    {
        delete engines.find(pEngine->id()).value();
        engines.remove(pEngine->id());
    }
    engines[pEngine->id()] = pEngine;
}

void Environment::getEngine(const QString &engineId)
{
    QHash< QString, Engine* >::iterator it = engines.find(engineId);
    if (it == engines.end())
        return 0;
    return it.value();
}

Item &ICursor::nextOne()
{
    return next();
}

QVector<Item> ICursor::nextMulti(int count)
{
    QVector< Item >vector;
    if (count == -1)
    {
        while(hasNext())
        {
            vector.append(next());
        }
    }
    else
    {
        for (int i = 0; i < count && hasNext(); i ++)
        {
            vector.append(next());
        }
    }
    return vector;
}

bool ICursor::hasNext()
{
    return _hasNext;
}

void Session::getRequestInfo(const Request &request)
{
    clientId = request.clientId;
    key = request.key;
    cellular::ParseKeyFlags(request.keyFlags, shift, ctrl, menu, meta);
    keyPress = request.keyPress;
    caretPosition = QPoint(request.x, request.y);
}

void Session::setResponseInfo(Response &response)
{
    if (commit.size() > 255)
    {
        qDebug() << "commit string len > 255";
        commit = commit.left(255);
    }
    if (edit.size() > 255)
    {
        qDebug() << "edit string len > 255";
        edit = edit.left(255);
    }
    commit.toWCharArray(response.commit);
    edit.toWCharArray(response.edit);
    response.isComposing = isComposing;
    response.keyEaten = keyEaten;
}


}
