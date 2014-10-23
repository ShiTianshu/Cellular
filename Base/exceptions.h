#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <QtCore>

class Exception
{
public:
    Exception();
    Exception(const QString &message);
    Exception(const QString &message, const Exception &exception);
    ~Exception();
    
    QString message() const;
    void setMessage(const QString &message);
    
    QString traceback() const;
    void setTraceback(const QString &traceback);

    void printTraceback();    
private:
    QString _message;
    QString _traceback;
};

class SourceNotFoundException: public Exception
{
public:
    SourceNotFoundException();
    SourceNotFoundException(const QString &message);
    SourceNotFoundException(const QString &message, const Exception &exception);
};

#endif // EXCEPTIONS_H
