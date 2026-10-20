#include <globaldefs.h>
ARM
struct Vector {int x,y,z;};
struct Descriptor {char pad[0x64];Vector vector;};
// Original: arm9/ov023 @ 0x021FD028; symbol: func_ov023_021fd028; size: 0x14.
// Returns the descriptor's three-word vector at offset 0x64.
extern "C" Vector MenuModel_GetPosition(const Descriptor* self){return self->vector;}
