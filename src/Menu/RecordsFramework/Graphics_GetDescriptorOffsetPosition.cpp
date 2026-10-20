#include <globaldefs.h>
ARM
struct State;struct Vector {int x,y,z;};
extern "C" void __clear(void*,unsigned);
extern "C" void* Menu_GetDisplayRecordRegistry(State*);
extern "C" void* MenuRecordList_LocateByKey(void**,unsigned short);
// Original: arm9/ov023 @ 0x021F8B78; symbol: func_ov023_021f8b78; size: 0xA4.
extern "C" Vector Graphics_GetDescriptorOffsetPosition(const char* descriptor,State* state) {
Vector offset;
__clear(&offset,12);
offset.x=*(const unsigned short*)(descriptor+0x3a)<<12;
offset.y=*(const unsigned short*)(descriptor+0x3c)<<12;
void** list=(void**)Menu_GetDisplayRecordRegistry(state);
void* object=MenuRecordList_LocateByKey(list,*(const unsigned short*)(descriptor+0x34));
if(object) {
Vector position=(*(Vector(***)(void*))object)[8](object);
offset.x+=position.x;
offset.y+=position.y;
}
return offset;
}
