#include <globaldefs.h>
struct DescriptorFlagView { unsigned char pad[0x14]; unsigned flags; };
struct LinkedDescriptorView { unsigned char pad[0x138]; DescriptorFlagView* descriptor; };
// Original: arm9/ov024 @ 0x021EDC08; symbol: func_ov024_021edc08; size: 0x18.
extern "C" ARM int Combatant_TestPrimaryStatusFlagBit26(LinkedDescriptorView* self) { return (self->descriptor->flags & 0x04000000) != 0; }
