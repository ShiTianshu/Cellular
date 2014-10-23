#include "inputmethod.h"
#include "isource.h"

InputMethod::InputMethod()
{
}
QString InputMethod::name() const
{
    return _name;
}

void InputMethod::setName(const QString &name)
{
    _name = name;
}
Engine InputMethod::engine() const
{
    return _engine;
}

void InputMethod::setEngine(const Engine &engine)
{
    _engine = engine;
}

void InputMethod::addSource(ISource *pSource)
{
    _sources[pSource->name()] = pSource;
}

ISource *InputMethod::getSource(const QString &sourceId) const
{
    ISource *pSource = 0;
    QMap< QString, ISource* >::const_iterator it = _sources.find(sourceId);
    if (it != _sources.end())
        pSource = it.value();
    return pSource;
}


