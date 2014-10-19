#include "cellular_engine.h"

namespace cellular{
QString Engine::id() const
{
    return _id;
}

void Engine::setId(const QString &id)
{
    _id = id;
}

void Engine::addProcessor(IProcessor *p)
{
    this->processers.append(p);
}


Engine::Engine()
{
    
}

Engine::~Engine()
{
    
}

void Engine::process(cellular::Session *pSession, cellular::Context *pContext, cellular::Environment *pEnvironment)
{
    foreach(IProcessor *p, processers)
    {
        p->process(pSession, pContext, pEnvironment);
    }
}

}
