#include <globaldefs.h>
ARM
extern "C" void* __clear(void*,unsigned);
struct Vector {int x,y,z;};
struct Descriptor {char pad[0x3a];unsigned short x,y;};
// Original: arm9/ov023 @ 0x021F8B30; symbol: func_ov023_021f8b30; size: 0x48.
// Returns unsigned descriptor halfwords 0x3a/0x3c as fixed-point X/Y with zero Z.
extern "C" Vector Graphics_ReadUnsignedFixedPointDescriptorCoordinates(const Descriptor* self){
 Vector result;__clear(&result,12);result.x=self->x<<12;result.y=self->y<<12;return result;
}
