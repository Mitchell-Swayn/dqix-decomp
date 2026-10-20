#include <globaldefs.h>
ARM
struct Vector {int x,y,z;};
struct Descriptor {char pad[0x3c];Vector vector;};
// Original: arm9/ov023 @ 0x021F7174; symbol: func_ov023_021f7174; size: 0x14.
// Returns the descriptor's three-word vector at offset 0x3c.
extern "C" Vector MenuZoneRenderRecord_GetPosition(const Descriptor* self){return self->vector;}
