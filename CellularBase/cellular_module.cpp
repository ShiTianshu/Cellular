#include "cellular_module.h"
#include "cellular_common.h"

namespace cellular{

IModule::IModule()
{
    _name = "IModule";    
}

IModule::~IModule()
{
    
}

QString IModule::id() const
{
    return _id;
}

void IModule::setId(const QString &id)
{
    _id = id;
}

QString IModule::name() const
{
    return _name;
}
QString IModule::description() const
{
    return _description;
}

void IModule::setDescription(const QString &description)
{
    _description = description;
}

Cursor IModule::sourceFind(const QString &moduleId, const QString &key)
{
    ICursor **ppCursor = 0;
    emit sourceFindSignal(moduleId, key, ppCursor);
    if (!ppCursor)
        throw Exception("sourceFind got ppCursor = 0");
    return Cursor(*ppCursor);
}

bool IModule::sourceInsert(const QString &moduleId, const QString &key, const QString &value)
{
    bool isCreated = false;
    emit sourceInsertSignal(moduleId, key, value, isCreated);
    return isCreated;
}

bool IModule::sourceRemove(const QString &moduleId, qint64 itemId)
{
    bool isRemoved = false;
    emit sourceRemoveSignal(moduleId, itemId, isRemoved);
    return isRemoved;
}

IProcessor::IProcessor()
{
    _name = "IProcessor";
}

IProcessor::~IProcessor()
{
    
}

IGui::IGui()
{
    _name = "IGui";
}

IGui::~IGui()
{
    
}

ISource::ISource()
{
    _name = "ISource";
}

ISource::~ISource()
{
    
}


}
