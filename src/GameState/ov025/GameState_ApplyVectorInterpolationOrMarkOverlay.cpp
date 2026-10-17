#include <globaldefs.h>
ARM
extern "C" void *ReadOverlayControlSecondWord(void);
extern "C" unsigned char func_ov025_021dcc64(unsigned char *);
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" void *GameState_ReadUnknownB0(void *);
extern "C" void SetVectorInterpolationAndClearFlagBitOne(char *, const void *, const void *, int, int);
// Original: arm9/ov025 @ 0x021E7248; symbol: func_ov025_021e7248; size: 0x60.
extern "C" int GameState_ApplyVectorInterpolationOrMarkOverlay(void *arg) {
    void *control = ReadOverlayControlSecondWord();
    if (control != 0) {
        *((unsigned char *)control + 0x6FD5) = 1;
        if (func_ov025_021dcc64((unsigned char *)control) != 0) return 1;
    }
    void *state = _ZN9GameState11GetInstanceEv();
    void *target = GameState_ReadUnknownB0(state);
    SetVectorInterpolationAndClearFlagBitOne((char *)target, (const void *)((char *)arg + 8), *(const void **)((char *)arg + 0x14), *(int *)((char *)arg + 0x18), *(int *)((char *)arg + 0x1C));
    return 1;
}
