#ifndef CELLULAR_ENGINE_H
#define CELLULAR_ENGINE_H

#include <QString>
#include <QVector>

#include "cellular_module.h"

namespace cellular{

/**
 * @brief The Engine class 引擎
 * 有一组处理器的调用链。
 */
class Engine
{
public:
    Engine();
    ~Engine();
    
    void process(Session *pSession, Context *pContext, Environment *pEnvironment);
    QString id() const;
    void setId(const QString &id);
    
    void addProcessor(IProcessor *p);
    
private:
    QString _id;
    QVector< IProcessor* > processers;
};


}

#endif // CELLULAR_ENGINE_H
