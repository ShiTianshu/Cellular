#ifndef ISOURCE_H
#define ISOURCE_H

#include <QSharedPointer>
#include <QVariant>

#include "imodule.h"

struct Item
{
    quint64 id;
    QString key;
    QString value;
    QVariant extend;
};

class ICursor
{
public:
    ICursor();
    virtual ~ICursor();
    bool hasNext() const;
    virtual Item *next()=0;
protected:
    void setHasNext(bool hasNext);
private:
    bool _hasNext;
};

typedef QSharedPointer< ICursor > PCursor; 

class ISource : public IModule
{
public:
    ISource();
    virtual ~ISource();
    virtual ICursor *query(const QString &key)=0;
    virtual bool insert(const QString &key, const QString &value, const QVariant &extend)=0;
    virtual bool remove(quint64 id)=0;
};

#endif // ISOURCE_H
