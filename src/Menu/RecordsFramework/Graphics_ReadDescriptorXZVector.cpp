#include <globaldefs.h>
ARM
extern "C" void* __clear(void*,unsigned);
struct Vector {int x,y,z;};
struct Descriptor {char pad[0x28];int x,z;};
// Original: arm9/ov023 @ 0x021FB1DC; symbol: func_ov023_021fb1dc; size: 0x40.
// Returns descriptor words 0x28 and 0x2c as X/Z with zero Y.
extern "C" Vector Graphics_ReadDescriptorXZVector(const Descriptor* self){
 Vector result;__clear(&result,12);result.x=self->x;result.z=self->z;return result;
}
