#ifndef CELLULAR_COMMON_H
#define CELLULAR_COMMON_H

#include <QtCore>
#include <QPoint>
#include <QHash>
#include <QSharedPointer>
#include <QVariant>
#include <QVector>

#include "cellular_ipc.h"
#include "cellular_exception.h"

namespace cellular{

class IModule;
class Engine;

struct Item
{
    qint64 id;
    QString key;
    QString value;
    QVariant exetend;
};

/**
 * @brief The ICursor class 数据源游标。
 * 从该类继续，实现：
 * virtual Item &next()=0;
 * 返回下一个Item，前计算hasNext。
 */
class ICursor
{
private:
    bool _hasNext;
    Item &nextOne();
    QVector< Item > nextMulti(int count=-1);
    
protected:
    virtual Item &next()=0;
public:
    ICursor(){}
    virtual ~ICursor(){}
    bool hasNext();
    
};

/**
 * @brief Cursor 智能指针，由source查找创建并返回，不用手工delete。
 */
typedef QSharedPointer< ICursor > Cursor;

struct Session
{
    qint64 clientId;
    qint32 key;
    bool shift;
    bool ctrl;
    bool menu;
    bool meta;
    bool keyPress;
    QPoint caretPosition;
    QString commit;
    QString edit;
    bool isComposing;
    bool keyEaten;
    
    void getRequestInfo(const cellular::Request &request);
    
    void setResponseInfo(cellular::Response &response);
};

// key -> {moduleId}/{key}
struct Environment
{
    QHash< QString, QString > configs;
    QHash< QString, IModule* > modules;
    QHash< QString, Engine* > engines;
    
    /**
     * @brief add 查找设置
     * @param moduleId
     * @param key
     * @param value
     * @return 如果重复设置，则返回false，原设置的值并不会改变。
     */
    bool addConfig(const QString &moduleId, const QString &key, const QString &value);
    
    /**
     * @brief getConfig 查找设置
     * @param moduleId
     * @param key
     * @return 如果没有找到，返回空QString。
     */
    QString getConfig(const QString &moduleId, const QString &key);
    
    /**
     * @brief isModuleExsit 判断模块是否存在。
     * @param moduleId
     * @return
     */
    bool isModuleExist(const QString &moduleId);
    
    /**
     * @brief addModule 添加模块。
     * 如果相同Id的存在，则会删除已有的模块。
     * @param pmodule 
     */
    void addModule(IModule *pModule);
    
    /**
     * @brief getModule 查找模块。
     * @param moduleId
     * @return 如果不存在，返回0。
     */
    IModule *getModule(const QString &moduleId);
    
    /**
     * @brief isEngineExist 判断引擎是否存在
     * @param engineId
     */
    bool isEngineExist(const QString &engineId);
    
    /**
     * @brief addEngine 添加引擎
     * @param pEngine
     */
    void addEngine(Engine *pEngine);
    
    /**
     * @brief getEngine
     * @param engineId
     */
    void getEngine(const QString &engineId);
};

struct Context
{
    
};

}

#endif // CELLULAR_COMMON_H
