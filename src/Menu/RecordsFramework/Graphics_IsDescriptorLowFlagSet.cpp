#include <globaldefs.h>
ARM
struct Descriptor {char pad[0x45];unsigned char flag:1,other:7;};
// Original: arm9/ov023 @ 0x021F8CA8; symbol: func_ov023_021f8ca8; size: 0x18.
// Returns whether bit zero of descriptor byte 0x45 is set.
extern "C" bool Graphics_IsDescriptorLowFlagSet(const Descriptor* self){return self->flag!=0;}
