#include <globaldefs.h>
ARM
extern "C" void* __clear(void*,unsigned);
struct Vector {int x,y,z;};
struct Descriptor {char pad[0x100];unsigned short x,y;};
// Original: arm9/ov023 @ 0x021F81F4; symbol: func_ov023_021f81f4; size: 0x4C.
// Returns unsigned descriptor halfwords 0x100/0x102 as fixed-point X/Y with zero Z.
extern "C" Vector MenuTextCanvas_GetFixedPointFrameOrigin(const Descriptor* self){
 Vector result;__clear(&result,12);result.x=self->x<<12;result.y=self->y<<12;return result;
}
