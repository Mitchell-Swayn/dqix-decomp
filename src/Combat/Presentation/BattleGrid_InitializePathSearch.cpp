#include <globaldefs.h>
ARM
// Original: arm9/ov025 @ 0x021E20D8; symbol: func_ov025_021e20d8; size: 0x14.
extern "C" void BattleGrid_InitializePathSearch(void *p) {
    *(unsigned int *)p = 0;
    *(unsigned int *)((unsigned char *)p + 4) = 0;
    *((unsigned char *)p + 0x14) = 0;
}
