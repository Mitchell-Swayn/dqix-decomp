#include <globaldefs.h>
ARM
struct SourceEntry { short key; unsigned short flag0:1; unsigned short flag1:1; unsigned short rest:14; };
struct DestEntry { char pad[0x10]; unsigned int low:22; unsigned int flag:1; unsigned int high:9; };
extern "C" unsigned char* Object_FindHalfwordKeyInThirtyTwoByteEntries(unsigned char* p,int key);
// Original: arm9/ov006 @ 0x02153744; symbol: func_ov006_02153744; size: 0x84.
extern "C" void Object_UpdateKeyedEntryFlags(void* unused,unsigned char* object,SourceEntry* source,int count) {
for(int i=0;i<count;++i,++source){
DestEntry* entry=(DestEntry*)Object_FindHalfwordKeyInThirtyTwoByteEntries(object,source->key);
if(entry)entry->flag=source->flag0 || source->flag1;
}
}
