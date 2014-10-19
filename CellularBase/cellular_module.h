#ifndef CELLULAR_MODULE_H
#define CELLULAR_MODULE_H

#include <QString>

#include "cellular_exception.h"
#include "cellular_common.h"

namespace cellular{

////////////////////////////////////////////////////////////////////////////////
/// Interfaces
////////////////////////////////////////////////////////////////////////////////

class IModule :
        public QObject
{
    Q_OBJECT
public:
    IModule();
    virtual ~IModule();
    
    QString id() const;
    void setId(const QString &id);
    
    QString name() const;
    
    QString description() const;
    void setDescription(const QString &description);

    /**
     * @brief initilize 初始化模块。
     * @return 
     * 初始化完全成功，返回true；初始化有警告，返回false；
     * 初始化失败，抛出cellular:Exception。
     */
    virtual bool initilize(Environment *pEnvironment)=0;
    
    Cursor sourceFind(const QString &moduleId, const QString &key);
    bool sourceInsert(const QString &moduleId, const QString &key, const QString &value);
    bool sourceRemove(const QString &moduleId, qint64 itemId);
    
signals:
    void sourceFindSignal(const QString &moduleId, const QString &key, ICursor **ppCursor);
    void sourceInsertSignal(const QString &moduleId, const QString &key, const QString &value, bool &isCreated);
    void sourceRemoveSignal(const QString &moduleId, qint64 itemId, bool &isRemoved);
protected:
    QString _name;
private:
    QString _id;
    QString _description;
};

/**
 * @brief The IProcessor class 处理器模块
 */
class IProcessor :
        public IModule
{
public:
    IProcessor();
    virtual ~IProcessor();
    virtual void process(Session *pSession, Context *pContext, Environment *pEnvironment)=0;
};

/**
 * @brief The IGui class GUI模块。
 */
class IGui :
        public IModule
{
public:
    IGui();
    virtual ~IGui();
    virtual void update(Session *pSession, Context *pContext, Environment *pEnvironment)=0;
};

/**
 * @brief The ISource class 数据源模块。
 */
class ISource :
        public IModule
{
    Q_OBJECT
public:
    ISource();
    virtual ~ISource();
    
    virtual ICursor *find(const QString &key)=0;
    virtual bool insert(const QString &key, const QString &value)=0;
    virtual bool remove(const qint64 &itemId)=0;
};

}
#endif // CELLULAR_MODULE_H
