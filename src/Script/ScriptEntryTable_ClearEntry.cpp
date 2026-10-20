#include <globaldefs.h>
ARM
extern "C" {
// Original: arm9/main @ 0x020A1380; symbol: func_020a1380; size: 0x44.
void ScriptEntryTable_ClearEntry(unsigned int *p) {
    p[0] &= ~0x1ffU;
    p[0] &= 0xfffc01ffU;
    p[0] &= 0xf803ffffU;
    p[0] &= ~0x38000000U;
    p[0] &= ~0xc0000000U;
    p[1] = 0; p[2] = 0;
}
}
