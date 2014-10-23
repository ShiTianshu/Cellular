#ifndef ENGINE_H
#define ENGINE_H

#include <QList>

class IProcessor;
struct Context;
struct Environment;
struct Session;

class Engine
{
public:
    Engine();
    ~Engine();
    void process(Environment *pE, Context *pC, Session *pS);
    void addProcessor(IProcessor *p);
private:
    QList< IProcessor* > _callbacks;
};

#endif // ENGINE_H
