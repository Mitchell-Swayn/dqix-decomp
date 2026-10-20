#include <globaldefs.h>
ARM
extern "C" void Inn_RequestStayDialogClose(void *record);
// Original: arm9/ov003 @ 0x0216D7EC; symbol: func_ov003_0216d7ec; size: 0x2C.
extern "C" void GameState_MarkOverlayRecordReadyForType3(void *object) {
    unsigned char *flags = (unsigned char *)object + 0x1000 + 0x3ec;
    *flags |= 2;
    if (*(signed short *)((char *)object + 4) == 3)
        Inn_RequestStayDialogClose((char *)object + 0x14);
}
