#include <globaldefs.h>
ARM
struct Vector {int x,y,z;};
struct Descriptor {char pad[0x24];Vector vector;};
// Original: arm9/ov023 @ 0x021F8CC0; symbol: func_ov023_021f8cc0; size: 0x14.
// Returns the descriptor's three-word vector at offset 0x24.
extern "C" Vector MenuTextLabel_GetCursorOffset(const Descriptor* self){return self->vector;}
