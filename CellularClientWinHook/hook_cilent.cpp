#include <QLocalSocket>
#include <QDebug>
#include <QTime>

#include "hook_client.h"
#include "../CellularBase/cellular_ipc.h"

#include <windows.h>
#include <winable.h>

HHOOK hHook;
QLocalSocket *psocket = 0;
qint64 clientId;

void SendUnicode(wchar_t data)
{
  INPUT input[2];
  memset(input, 0, 2 * sizeof(INPUT));
 
  input[0].type = INPUT_KEYBOARD;
  input[0].ki.wVk = 0;
  input[0].ki.wScan = data;
  input[0].ki.dwFlags = 0x4;//KEYEVENTF_UNICODE;
 
  input[1].type = INPUT_KEYBOARD;
  input[1].ki.wVk = 0;
  input[1].ki.wScan = data;
  input[1].ki.dwFlags = KEYEVENTF_KEYUP | 0x4;//KEYEVENTF_UNICODE;
 
  SendInput(2, input, sizeof(INPUT));
}

void SendString(wchar_t string[])
{
    for (unsigned int i = 0; i < wcslen(string); ++i)
        SendUnicode(string[i]);
}

POINT CaretPos()
{
    POINT point;
    GUITHREADINFO pg;
    
    pg.cbSize = 48;
    GetGUIThreadInfo(0, &pg);
    if (pg.hwndCaret)
    {
        point.x = pg.rcCaret.right;
        point.y = pg.rcCaret.bottom;
        ClientToScreen(pg.hwndCaret, &point);
    }
    else
    {
        point.x = -1;
        point.y = -1;
    }
    return point;
}

extern "C"
CALLBACK LRESULT KeyBoardProc(int nCode, WPARAM wParam,LPARAM lParam)
{
    cellular::Request request;
    cellular::Response response;
    KBDLLHOOKSTRUCT* pStruct = (KBDLLHOOKSTRUCT*)lParam;
    // vk_packet pass
    if (pStruct->vkCode == VK_PACKET)
        return CallNextHookEx(hHook, nCode, wParam, lParam);
    
    request.clientId = clientId;
    request.key = pStruct->vkCode;
    if (pStruct->flags & LLKHF_UP)
        request.keyPress = false;
    else
        request.keyPress = true;
    request.keyFlags = cellular::GenerateKeyFlags(
                GetKeyState(VK_SHIFT) < 0,
                GetKeyState(VK_CONTROL) < 0,
                pStruct->flags & LLKHF_ALTDOWN,
                GetKeyState(VK_LWIN) < 0 && GetKeyState(VK_RWIN) < 0
                );
    POINT point = CaretPos();
    request.x = point.x;
    request.y = point.y;
    request.onFocus = true;
    
    psocket->write((char*)&request, sizeof(request));
    psocket->flush();
    if (psocket->waitForReadyRead(-1))
    {
        psocket->read((char*) &response, sizeof(cellular::Response));
    }
    SendString(response.commit);
    if (response.keyEaten)
        return 1;
    return CallNextHookEx(hHook, nCode, wParam, lParam);
}

bool HookKeyboard()
{
    bool succeed = false;
    hHook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyBoardProc, GetModuleHandle(NULL), 0);
    if (hHook)
    {
        qDebug() << "hook keyboard succeed!";
        succeed = true; 
    }
    else
    {
        qDebug() << "hook keyboard failed!";
    }
    return succeed;
}

bool ConnectToServer()
{
    bool succeed = false;
    
    clientId = (qint64)QTime::currentTime().msecsSinceStartOfDay();
    if (!psocket)
        psocket = new QLocalSocket;
    
    psocket->connectToServer(CELLULAR_SERVER_NAME);
    
    if (psocket->waitForConnected())
    {
        qDebug() << "connect succeed!";
        succeed = true;
    }
    else
    {
        qDebug() << "connect failed!";
    }
    return succeed;
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
