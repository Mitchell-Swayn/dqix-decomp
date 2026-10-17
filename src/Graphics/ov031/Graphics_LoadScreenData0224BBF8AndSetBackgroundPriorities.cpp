#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov031_0224bbf8[];
extern "C" void LoadToMainBG2ScreenData();
extern "C" void System_LoadResourceAndInvokeCallback(void*,void(*)());
struct BG { unsigned short priority:2; unsigned short other:14; };
// Original: arm9/ov031 @ 0x022319C4; symbol: func_ov031_022319c4; size: 0x80.
extern "C" void Graphics_LoadScreenData0224BBF8AndSetBackgroundPriorities() {
 System_LoadResourceAndInvokeCallback(data_ov031_0224bbf8,LoadToMainBG2ScreenData);
 ((volatile BG*)0x04001008)->priority=3;
 ((volatile BG*)0x0400100a)->priority=3;
 ((volatile BG*)0x04000008)->priority=3;
 ((volatile BG*)0x0400000a)->priority=3;
 ((volatile BG*)0x0400000c)->priority=3;
}
