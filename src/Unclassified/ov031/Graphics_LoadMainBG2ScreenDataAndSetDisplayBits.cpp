#include <globaldefs.h>
ARM
extern "C" void System_LoadResourceAndInvokeCallback(const void *request, void (*callback)(const void *, unsigned, unsigned));
extern "C" void LoadToMainBG2ScreenData(const void *data, unsigned offset, unsigned length);
extern "C" unsigned char data_ov031_0224b94c[];
// Original: arm9/ov031 @ 0x0222A1A4; symbol: func_ov031_0222a1a4; size: 0x6C.
extern "C" void Graphics_LoadMainBG2ScreenDataAndSetDisplayBits(void) {
    System_LoadResourceAndInvokeCallback(data_ov031_0224b94c, LoadToMainBG2ScreenData);
    volatile unsigned short *display = (volatile unsigned short *)0x04001008;
    volatile unsigned short *display2 = (volatile unsigned short *)0x0400000a;
    display[0] = (display[0] & ~3u) | 3u;
    display[1] = (display[1] & ~3u) | 3u;
    *display2 = (*display2 & ~3u) | 3u;
    display2[1] = (display2[1] & ~3u) | 3u;
}
