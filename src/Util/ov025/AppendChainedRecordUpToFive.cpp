#include <globaldefs.h>
ARM
extern "C" void func_ov025_021dcd28(void*,const void*);
struct Entry { char pad[0x18];unsigned short value,previous; };
struct Object { char pad[0x6f00];unsigned char count;char pad2[7];Entry entries[5]; };
// Original: arm9/ov025 @ 0x021DCDE8; symbol: func_ov025_021dcde8; size: 0x94.
extern "C" void AppendChainedRecordUpToFive(Object* p,const void* source){
if(p->count>=5)return;
func_ov025_021dcd28(&p->entries[p->count],source);
p->entries[p->count].value=0;
p->entries[p->count].previous=0;
if(p->count!=0)p->entries[p->count].previous=p->entries[p->count-1].value;
p->count++;
}
