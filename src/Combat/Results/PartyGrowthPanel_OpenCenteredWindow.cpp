#include <globaldefs.h>
extern "C" void Window_PushTextCanvas(void *, void *, int, int, int, int, int, int);
// Original: arm9/ov023 @ 0x021D921C; symbol: func_ov023_021d921c; size: 0x74.
extern "C" void PartyGrowthPanel_OpenCenteredWindow(void *panel, void *callback, int width, int height) {
    unsigned char *p = (unsigned char *)panel;
    *(unsigned short *)(p + 0xc0) = (unsigned short)width;
    *(unsigned short *)(p + 0xc2) = (unsigned short)height;
    *(unsigned short *)(p + 0xc4) = (unsigned short)((0x20 - width) >> 1);
    *(unsigned short *)(p + 0xc6) = (unsigned short)((0x18 - height) >> 1);
    *(unsigned short *)(p + 0xc8) = 0;
    *(unsigned short *)(p + 0xca) = 5;
    *(unsigned short *)(p + 0xcc) = 10;
    *(unsigned short *)(p + 0xce) = 10;
    p[0xd1] = 0;
    p[0xd5] = 0;
    Window_PushTextCanvas(p + 0x20, callback, 0, 0, 0, 1, 0, 0);
}
