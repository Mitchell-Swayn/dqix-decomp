#include <globaldefs.h>
ARM

extern "C" {
struct State { unsigned char pad[28]; unsigned char first:4; unsigned char second:4; };
typedef int (*Callback)(void *, void *);
extern Callback data_020f01b8[4][4];
int Graphics_InvokeTwoIndexTransferCallback(State *p, void *a, void *b);
// Original: arm9/ov023 @ 0x021F7D14; symbol: func_ov023_021f7d14; size: 0x34.
void Graphics_SetTransferCallbackIndicesFromFixedPoint(void *p, int *coords) {
    *(short *)((char *)p + 0x50) = (short)(coords[0] >> 12);
    *(short *)((char *)p + 0x52) = (short)(coords[1] >> 12);
    Graphics_InvokeTwoIndexTransferCallback((State *)((char *)p + 0x28),
        (void *)(int)*(short *)((char *)p + 0x50),
        (void *)(int)*(short *)((char *)p + 0x52));
}
}
