#include <QDebug>

#include "exceptions.h"

#include <typeinfo>

Exception::Exception()
{
}

Exception::Exception(const QString &message)
{
    _message = message;
    _traceback = message;
}

Exception::Exception(const QString &message, const Exception &exception)
{
    _message = message;
    _traceback = QString("%1\n%2").arg(message).arg(exception.traceback());
}

Exception::~Exception()
{
    
}

QString Exception::message() const
{
    return _message;
}

void Exception::setMessage(const QString &message)
{
    _message = message;
}

QString Exception::traceback() const
{
    return _traceback;
}

void Exception::setTraceback(const QString &traceback)
{
    _traceback = traceback;
}

void Exception::printTraceback()
{
    qDebug() << typeid(this).name() << _traceback;
}

SourceNotFoundException::SourceNotFoundException()
{
    
}

SourceNotFoundException::SourceNotFoundException(const QString &message):
    Exception(message)
{
    
}

SourceNotFoundException::SourceNotFoundException(const QString &message, const Exception &exception):
    Exception(message, exception)
{
    
}
