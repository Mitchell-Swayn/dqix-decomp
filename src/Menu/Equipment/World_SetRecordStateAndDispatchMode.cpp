#include <globaldefs.h>
ARM
extern "C" void Graphics_SetBackgroundStateAndClearTilemap(void *, int);
extern "C" void Graphics_SelectBackgroundStateRecord(void *, int);
// Original: arm9/ov005 @ 0x021551FC; symbol: World_SetRecordStateAndDispatchMode; size: 0x5C.
// Stores the input byte, sets bit 7 in a state halfword, reads the signed selected-record value, and dispatches through the helper chosen by mode.
extern "C" void World_SetRecordStateAndDispatchMode(void *self, unsigned char value, int mode) {
    char *p = (char *)self;
    int index = *(signed char *)(p + 0x3dbb);
    int selected = *(short *)(p + 0x2d90 + index * 0x1c);
    *(unsigned char *)(p + 0x19be) = value;
    *(unsigned short *)(p + 0x19b8) |= 0x80;
    if (mode) Graphics_SetBackgroundStateAndClearTilemap(p + 0x1244, selected);
    else Graphics_SelectBackgroundStateRecord(p + 0x1244, selected);
}
