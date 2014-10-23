#ifndef INPUTMETHOD_H
#define INPUTMETHOD_H

#include <QtCore>

#include "engine.h"

class ISource;
class Engine;

class InputMethod
{
public:
    InputMethod();
    ~InputMethod();
        
    QString name() const;
    void setName(const QString &name);
    
    Engine engine() const;
    void setEngine(const Engine &engine);
    
    void addSource(ISource* pSource);
    ISource *getSource(const QString &sourceId) const;
private:
    QString _name;
    Engine _engine;
    QMap< QString, ISource* > _sources;
};

#endif // INPUTMETHOD_H
