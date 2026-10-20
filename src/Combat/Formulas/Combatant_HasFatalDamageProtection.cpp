#include <globaldefs.h>

#pragma force_active on
// Original: arm9/ov024 @ 0x021E47DC; symbol: func_ov024_021e47dc; size: 0x18.
// Describes observed operations; underlying field roles remain uncertain.
extern "C" int Combatant_HasFatalDamageProtection(unsigned char* self)
{
    return ((*(unsigned**)(self+0x138))[5] & 0x400000) != 0;
}
