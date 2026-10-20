#include <globaldefs.h>
ARM
extern "C" void* __clear(void*,unsigned);
struct Vector {int x,y,z;};
struct Descriptor {char pad[0xa8];int x,z;};
// Original: arm9/ov023 @ 0x021FB88C; symbol: func_ov023_021fb88c; size: 0x40.
// Returns descriptor words 0xa8 and 0xac as X/Z with zero Y.
extern "C" Vector Graphics_ReadExtendedDescriptorXZVector(const Descriptor* self){
 Vector result;__clear(&result,12);result.x=self->x;result.z=self->z;return result;
}
