#ifndef CELLULARIPC_H
#define CELLULARIPC_H

#include <QtCore>
#include <QString>

/**
 * 通信的接口定义
 *
 *
 * ShiTianshu
 * 2014/10/13
 */

#define CELLULAR_SERVER_NAME "cellular_server_v0.01"

namespace cellular{

///
/// 客户端和服务器通信，初步决定使用QLocalSocket
/// 客户端为和系统相关的部分，服务器为和系统无关核心逻辑。
/// 服务器实现本身与输入法的具体逻辑无关，
/// 输入法具体逻辑由"CellularService"决定。
///

/**
 * @brief The REQUEST struct
 * 输入法请求，由客户端发送
 * clientId 通过当前的时间生成。
 * keyFlags可以通过GenerateKeyFlags生成，通过ParseKeyFlags分解。
 */
struct REQUEST
{
    int clientId;  // 客户端的id
    int keyCode;  // 键值，无效时为-1其余有效，当键值有效时，keyFlags, isKeyPress有效。
    int keyFlags;  // 键标志位
    bool isKeyPress;  // 按键抬起
    bool isFocus;  // 当前是焦点，用于确认输入法是否展示。如果是false时，输入法的候选将不展示。
    int x;  // 候选x坐标，位置坐标可以用请求单独发送，也可以和其它的请求一起发送。
    int y;  // 候选y坐标
    REQUEST (void)
    {
        clientId = -1;
        keyCode = -1;
        keyFlags = -1;
        isKeyPress = false;
        isFocus = false;
        x = -1;
        y = -1;
    }
};

/**
 * @brief The RESPONSE struct
 * 输入法响应，由服务器发送
 * 
 */
struct RESPONSE
{
    QString commitText;  // 上屏字符串，非空时字符串将上屏。
    QString editText;  // 编辑字符串，用于嵌入编码的展示。
    bool isComposing;  // 当前正在输入编码，客户端无法得知是否在输入编码。
    bool isKeyEaten;  // 按键是否被处理了
    RESPONSE (void)
    {
        isComposing = false;
        isKeyEaten = false;
    }
};

// 生成标志位
inline int GenerateKeyFlags (bool isShiftPress, bool isCtrlPress,
                             bool isMenuPress, bool isMetaPress)
{
    int keyFlags = 0;
    if (isShiftPress)
        keyFlags += 1;
    if (isCtrlPress)
        keyFlags += 2;
    if (isMenuPress)
        keyFlags += 4;
    if (isMetaPress)
        keyFlags += 8;
    return keyFlags;
}

// 转换标志位
inline void ParseKeyFlags (const int &keyFlags, bool &isShiftPress,
                           bool &isCtrlPress, bool &isMenuPress,
                           bool &isMetaPress)
{
    if (keyFlags & 1)
        isShiftPress = true;
    else
        isShiftPress = false;
    if (keyFlags & 2)
        isCtrlPress = true;
    else
        isCtrlPress = false;
    if (keyFlags & 4)
        isMenuPress = true;
    else
        isMenuPress = false;
    if (keyFlags & 8)
        isMetaPress = true;
    else
        isMetaPress = false;
}

}

#endif // CELLULARIPC_H
