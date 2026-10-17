#include <globaldefs.h>
ARM
struct Entry { unsigned int flags,value; };
struct Object { int pad[2]; Entry* entries; unsigned char count; };
// Original: arm9/ov031 @ 0x0223BAB4; symbol: func_ov031_0223bab4; size: 0xA4.
extern "C" void Object_SetIndexedOrAllEntryModeFlags(Object* object,int index,unsigned int mode,unsigned int value) {
Entry* entries=object->entries;
if(index>=0){
if(mode!=0x100 && mode!=0x300){unsigned int f=entries[index].flags;f&=0xc1fffcff;f|=mode;entries[index].flags=f;}
else {unsigned int f=entries[index].flags;f&=0xc1fffcff;f|=mode;f|=value<<25;entries[index].flags=f;}
}else{
index=0;
int count=object->count;
if(count>0)do {
unsigned int flags;
if(mode!=0x100 && mode!=0x300){flags=entries[index].flags;flags&=0xc1fffcff;flags|=mode;}
else {flags=entries[index].flags;flags&=0xc1fffcff;flags|=mode;flags|=value<<25;}
entries[index].flags=flags;
count=object->count;
++index;
}while(index<count);
}
}
