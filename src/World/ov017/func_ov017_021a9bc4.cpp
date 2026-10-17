#include <globaldefs.h>
ARM
extern "C" void InitializeFourWordsWithInvalidIndex(signed char *p);
extern "C" void* _ZN9GameState11GetInstanceEv();
// Original: arm9/ov017 @ 0x021A9BC4; symbol: func_ov017_021a9bc4; size: 0x34.
extern "C" void func_ov017_021a9bc4(signed char *p, unsigned char value) {
    InitializeFourWordsWithInvalidIndex(p);
    p[0] = 0x3b;
    p[8] = 0;
    p[0x26c] = 0;
    ((unsigned char *)_ZN9GameState11GetInstanceEv())[0x64de] = value;
}
