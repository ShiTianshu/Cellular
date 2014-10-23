#include "imodule.h"

IModule::IModule()
{
}
QString IModule::name() const
{
    return _name;
}

void IModule::setName(const QString &name)
{
    _name = name;
}
QString IModule::id() const
{
    return _id;
}

void IModule::setId(const QString &id)
{
    _id = id;
}
QString IModule::description() const
{
    return _description;
}

void IModule::setDescription(const QString &description)
{
    _description = description;
}
QStringList IModule::necessaryParameters() const
{
    return _necessaryParameters;
}

void IModule::setNecessaryParameters(const QStringList &necessaryParameters)
{
    _necessaryParameters = necessaryParameters;
}
QStringList IModule::optionalParameters() const
{
    return _optionalParameters;
}

void IModule::setOptionalParameters(const QStringList &optionalParameters)
{
    _optionalParameters = optionalParameters;
}

QString IModule::idAndName() const
{
    return QString("%1@%2").arg(_name).arg(_id);
}





