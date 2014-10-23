#include "engine.h"
#include "iprocessor.h"

Engine::Engine()
{
}

Engine::~Engine()
{
    
}

void Engine::process(Environment *pE, Context *pC, Session *pS)
{
    foreach (IProcessor *p, _callbacks)
    {
        p->process(pE, pC, pS);
    }
}

void Engine::addProcessor(IProcessor *p)
{
    _callbacks.append(p);
}
