#include <globaldefs.h>
ARM
struct Vector {int x,y,z;};
struct Descriptor {char pad[0x50];short x,y;};
// Original: arm9/ov023 @ 0x021F7D48; symbol: func_ov023_021f7d48; size: 0x40.
// Returns the descriptor's signed halfword coordinates as a fixed-point vector with zero Z.
extern "C" Vector Graphics_ReadFixedPointDescriptorCoordinates(const Descriptor* self){
 Vector result;result.x=self->x<<12;result.y=self->y<<12;result.z=0;
 return result;
}
