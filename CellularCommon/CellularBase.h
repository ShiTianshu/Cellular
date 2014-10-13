#ifndef CELLULARBASE_H
#define CELLULARBASE_H

#include <QtCore>
#include <QString>

namespace cellular{

// 基础模块。
class IBase :
        public QObject
{
    Q_OBJECT
public:
    IBase () { }
    virtual ~IBase () = 0;
    
    virtual bool initialize (void) = 0;  // 初始化
    void setName (const QString &name);
    const QString &getName (void);
    void setId (const QString &id);
    const QString &getId (void);
    const QString getFullName (void);
protected:
    
signals:
    // 调用行为
    void toAction (QString actionId);
    // 查找数据源
    
    // 添加数据源
    
    
private:
    QString name;  // 模块名
    QString id;  // 模块id
    
public:
    
};

void IBase::setName (const QString &name)
{
    this->name = QString(name);
}

const QString &IBase::getName (void)
{
    return this->name;
}

void IBase::setId (const QString &id)
{
    this->id = QString(id);
}

const QString &IBase::getId (void)
{
    return this->id;
}

const QString IBase::getFullName (void)
{
    return QString("%1[%2]").arg(this->id).arg(this->name);
}

}
#endif // CELLULARBASE_H
