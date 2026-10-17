#include <globaldefs.h>
ARM
struct Record { unsigned char pad[0x18]; short x,y; unsigned short value,previous; };
struct Object { unsigned char pad[0x6e4d];unsigned char count;unsigned char align[2];Record entries[5]; };
extern "C" void func_ov025_021dcd28(void*,const void*);
// Original: arm9/ov025 @ 0x021DCC70; symbol: func_ov025_021dcc70; size: 0xB8.
extern "C" void Object_AppendRecordWithPreviousValue(Object* object,Record* source) {
if(object->count>=5)return;
func_ov025_021dcd28(&object->entries[object->count],source);
object->entries[object->count].x=source->x;
object->entries[object->count].y=source->y;
object->entries[object->count].value=0;
object->entries[object->count].previous=0;
if(object->count)object->entries[object->count].previous=object->entries[object->count-1].value;
++object->count;
}
