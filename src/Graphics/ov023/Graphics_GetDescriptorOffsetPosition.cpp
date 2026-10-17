#include <globaldefs.h>
ARM
struct State;struct Vector {int x,y,z;};
extern "C" void __clear(void*,unsigned);
extern "C" void* func_ov011_021849c8(State*);
extern "C" void* func_ov023_021f6880(void**,unsigned short);
// Original: arm9/ov023 @ 0x021F8B78; symbol: func_ov023_021f8b78; size: 0xA4.
extern "C" Vector Graphics_GetDescriptorOffsetPosition(const char* descriptor,State* state) {
Vector offset;
__clear(&offset,12);
offset.x=*(const unsigned short*)(descriptor+0x3a)<<12;
offset.y=*(const unsigned short*)(descriptor+0x3c)<<12;
void** list=(void**)func_ov011_021849c8(state);
void* object=func_ov023_021f6880(list,*(const unsigned short*)(descriptor+0x34));
if(object) {
Vector position=(*(Vector(***)(void*))object)[8](object);
offset.x+=position.x;
offset.y+=position.y;
}
return offset;
}
