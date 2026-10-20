#include <globaldefs.h>
ARM
struct Vector {int x,y,z;};
struct Descriptor {char pad[0x20];Vector vector;};
// Original: arm9/ov023 @ 0x021FBCC0; symbol: func_ov023_021fbcc0; size: 0x14.
// Returns the descriptor's three-word vector at offset 0x20.
extern "C" Vector MenuNumber_GetAuxiliaryVector(const Descriptor* self){return self->vector;}
