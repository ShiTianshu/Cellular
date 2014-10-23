#ifndef IPROCESSOR_H
#define IPROCESSOR_H

#include <QObject>

#include "imodule.h"

class IProcessor : public IModule
{
public:
    IProcessor();
    
    virtual void process(Environment *pE, Context *pC, Session *pS)=0;
};

#endif // IPROCESSOR_H
