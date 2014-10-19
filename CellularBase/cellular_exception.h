#ifndef CELLULAR_EXCEPTION_H
#define CELLULAR_EXCEPTION_H

#include <QString>
#include <QDebug>

namespace cellular{

class Exception
{
public:
    Exception(QString message);
    Exception(QString message, Exception exception);
    
    QString message() const;
    void setMessage(const QString &message);
    
    inline friend QDebug &operator <<(QDebug &debug, const Exception &exception)
    {
        debug << exception.message();
        return debug;
    }
private:
    QString _message;
    
};


Exception::Exception(QString message)
{
    setMessage(message);    
}

Exception::Exception(QString message, Exception exception)
{
    setMessage(QString("%1\ncause by:%2").arg(message).arg(exception.message()));
}

QString Exception::message() const
{
    return _message;
}

void Exception::setMessage(const QString &message)
{
    _message = message;
}
}

#endif // CELLULAR_EXCEPTION_H
