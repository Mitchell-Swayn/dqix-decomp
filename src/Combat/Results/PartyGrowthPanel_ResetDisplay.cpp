#include <globaldefs.h>
extern "C" unsigned Window_GetCanvasStackDepth(char *);
extern "C" void Window_PopCanvasesAndResetSelection(void *, int);
extern "C" void Graphics_ApplySubBackgroundSnapshotAndClearPending(void *);
extern "C" void Selection_InitializeDisplayController(void *);
// Original: arm9/ov023 @ 0x021D8AF8; symbol: func_ov023_021d8af8; size: 0x74.
extern "C" void PartyGrowthPanel_ResetDisplay(void *owner) {
    unsigned char *p = (unsigned char *)owner;
    if (Window_GetCanvasStackDepth((char *)owner + 0x20))
        Window_PopCanvasesAndResetSelection((char *)owner + 0x20, 1);
    *(unsigned *)p = 0;
    volatile unsigned *reg = (volatile unsigned *)0x04001000;
    *reg = (*reg & ~0x1f00u) | (*(unsigned *)(p + 0x1c) << 8);
    Graphics_ApplySubBackgroundSnapshotAndClearPending(p + 8);
    Selection_InitializeDisplayController(p + 0x20);
    p[0x11a] = 0;
    p[0x11b] = 0;
    p[0x11c] = 0;
    *(unsigned *)p = 0;
    *(unsigned *)(p + 4) = 0;
}
