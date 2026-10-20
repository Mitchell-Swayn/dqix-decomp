#include <globaldefs.h>
ARM
struct Entry {unsigned value:26,metadata:6;};
struct Table {unsigned count:12,other:20;Entry* entries;};
// Original: arm9/ov023 @ 0x021F5534; symbol: func_ov023_021f5534; size: 0x44.
// Scans packed entries until a zero value or a threshold at least as large as the signed key is found.
extern "C" Entry* FindPackedThresholdEntry(Table* self,int key){
 Entry* entry=self->entries;
 while(self->count){int value=entry->value;if(value==0 || key<=value)return entry;entry++;}
 return 0;
}
