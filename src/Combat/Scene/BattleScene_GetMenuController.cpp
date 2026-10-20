#include <globaldefs.h>

#pragma force_active on
// Original: arm9/ov000 @ 0x02160F08; symbol: func_ov000_02160f08; size: 0xC.
// Describes observed operations; underlying field roles remain uncertain.
extern "C" void* BattleScene_GetMenuController(unsigned char* self)
{
    return self+0x3760;
}
