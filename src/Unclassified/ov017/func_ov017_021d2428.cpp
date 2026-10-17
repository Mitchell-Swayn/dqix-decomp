#include <globaldefs.h>
ARM
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" void Object_WriteByteAtOffset5729(int, unsigned char);
// Original: arm9/ov017 @ 0x021D2428; symbol: func_ov017_021d2428; size: 0x14.
extern "C" void func_ov017_021d2428(void) {
    Object_WriteByteAtOffset5729((int)_ZN9GameState11GetInstanceEv(), 1);
}
