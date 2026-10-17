#include <globaldefs.h>
ARM
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" int GameState_TestByteFlagsAtOffset63DC(void *, unsigned);
// Original: arm9/ov004 @ 0x021688BC; symbol: func_ov004_021688bc; size: 0x18.
extern "C" unsigned func_ov004_021688bc(void) {
    GameState_TestByteFlagsAtOffset63DC(_ZN9GameState11GetInstanceEv(), 2);
    return 0;
}
