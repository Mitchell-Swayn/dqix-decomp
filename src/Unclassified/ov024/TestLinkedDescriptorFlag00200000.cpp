#include <globaldefs.h>
struct DescriptorFlagView { unsigned char pad[0x14]; unsigned flags; };
struct LinkedDescriptorView { unsigned char pad[0x138]; DescriptorFlagView* descriptor; };
// Original: arm9/ov024 @ 0x021EDC38; symbol: func_ov024_021edc38; size: 0x18.
extern "C" ARM int TestLinkedDescriptorFlag00200000(LinkedDescriptorView* self) { return (self->descriptor->flags & 0x00200000) != 0; }
