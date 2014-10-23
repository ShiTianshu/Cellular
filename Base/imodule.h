#ifndef IMODULE_H
#define IMODULE_H

#include <QObject>
#include <QStringList>

struct Context;
struct Environment;
struct Session;

class IModule : public QObject
{
    Q_OBJECT
public:
    IModule();
    virtual ~IModule();
    
    QString name() const;
    void setName(const QString &name);
    
    QString id() const;
    void setId(const QString &id);
    
    QString description() const;
    void setDescription(const QString &description);
    
    QStringList necessaryParameters() const;
    void setNecessaryParameters(const QStringList &necessaryParameters);
    
    QStringList optionalParameters() const;
    void setOptionalParameters(const QStringList &optionalParameters);
    
    QString idAndName() const;
    
    virtual bool initialize(Environment *pE, Context *pC, Session *pS)=0;
private:
    QString _name;
    QString _id;
    QString _description;
    QStringList _necessaryParameters;
    QStringList _optionalParameters;
};

#endif // IMODULE_H
