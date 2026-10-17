#include <globaldefs.h>
ARM
extern "C" void *_ZN9GameState11GetInstanceEv(void);
// Original: arm9/ov001 @ 0x0215B058; symbol: func_ov001_0215b058; size: 0x1C.
extern "C" int GameState_ClearField5CAC(void) {
    unsigned char *field = (unsigned char *)_ZN9GameState11GetInstanceEv() + 0x5cac;
    *field = 0;
    return 1;
}
