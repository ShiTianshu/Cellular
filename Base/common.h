#ifndef COMMON_H
#define COMMON_H

#include <QtCore>
#include <QMap>

class InputMethod;

struct Context
{
    QString composition;
};

struct Session
{
    qint32 key;
    bool ctrl;
    bool menu;
    bool shift;
    bool meta;
    QString commit;
    QString edit;
    bool keyEaten;
    bool isComposing;
    QPoint caretPosition;
};

struct Environment
{
    QMap< QString, InputMethod* > inputMethods;
    QMap< QString, QString > configs;
    InputMethod* pCurrentInputMethod;
};

#endif // COMMON_H
