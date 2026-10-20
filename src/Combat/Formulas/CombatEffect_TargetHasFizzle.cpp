#include <globaldefs.h>

#pragma force_active on
// Original: arm9/ov024 @ 0x021DD010; symbol: func_ov024_021dd010; size: 0x18.
// Describes observed operations; underlying field roles remain uncertain.
extern "C" int CombatEffect_TargetHasFizzle(unsigned char* self)
{
    return ((*(unsigned**)(self+0x138))[5] & 0x100) != 0;
}
