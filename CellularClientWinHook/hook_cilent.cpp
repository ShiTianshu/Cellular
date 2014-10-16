#include <QLocalSocket>
#include <QDebug>

#include "hook_client.h"
#include "../CellularBase/cellular_ipc.h"

#include <windows.h>

HHOOK hHook;
QLocalSocket *psocket = 0;

extern "C"
CALLBACK LRESULT KeyBoardProc(int nCode, WPARAM wParam,LPARAM lParam)
{
    cellular::Request request;
    cellular::Response response;
    KBDLLHOOKSTRUCT* pStruct = (KBDLLHOOKSTRUCT*)lParam;
    request.clientId = 1230;
    request.key = pStruct->vkCode;
    request.keyPress = !((bool)pStruct->flags & LLKHF_UP);
    
    psocket->write((char*)&request, sizeof(request));
    psocket->flush();
    if (psocket->waitForReadyRead())
    {
        psocket->read((char*) &response, sizeof(cellular::Response));
    }
    qDebug() << QString::fromWCharArray(response.commit) 
             <<QString::fromWCharArray(response.edit) << response.isComposing;
    return CallNextHookEx(hHook, nCode, wParam, lParam);
}

bool HookKeyboard()
{
    hHook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyBoardProc, GetModuleHandle(NULL), 0);
    if (hHook)
    {
        qDebug() << "hook keyboard succeed!";
        return true;
    }
    else
    {
        qDebug() << "hook keyboard failed!";
        return false;
    }
}

void ConnectToServer()
{
    if (!psocket)
        psocket = new QLocalSocket;
    
    psocket->connectToServer(CELLULAR_SERVER_NAME);
    
    if (psocket->waitForConnected())
        qDebug() << "connect succeed!";
    else
        qDebug() << "connect failed!";
                  
}

int MainLoop()
{
    MSG Msg;
    while(GetMessage(&Msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }
    return 0;
}
