#include <globaldefs.h>
struct DescriptorFlagView { unsigned char pad[0x14]; unsigned flags; };
struct LinkedDescriptorView { unsigned char pad[0x138]; DescriptorFlagView* descriptor; };
// Original: arm9/ov024 @ 0x021DA9B0; symbol: func_ov024_021da9b0; size: 0x18.
extern "C" ARM int CombatEffect_TargetHasParalysis(LinkedDescriptorView* self) { return (self->descriptor->flags & 0x8) != 0; }
