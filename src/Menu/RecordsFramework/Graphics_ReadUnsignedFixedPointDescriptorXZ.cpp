#include <globaldefs.h>
ARM
extern "C" void* __clear(void*,unsigned);
struct Vector {int x,y,z;};
struct Descriptor {char pad[0x28];unsigned short x,z;};
// Original: arm9/ov023 @ 0x021FB4DC; symbol: func_ov023_021fb4dc; size: 0x48.
// Returns unsigned descriptor halfwords 0x28/0x2a as fixed-point X/Z with zero Y.
extern "C" Vector Graphics_ReadUnsignedFixedPointDescriptorXZ(const Descriptor* self){
 Vector result;__clear(&result,12);result.x=self->x<<12;result.z=self->z<<12;return result;
}
