#include <globaldefs.h>
ARM
struct Entry { unsigned a;unsigned short key,value;unsigned char type,active;char pad[2]; };
extern "C" Entry* FindFirstAvailableTwelveByteEntry(void*);
// Original: arm9/ov025 @ 0x021EB188; symbol: func_ov025_021eb188; size: 0x7C.
extern "C" int AddUniqueFourSlotRecord(char* owner,Entry* source){
Entry* entry=(Entry*)(owner+0x594);
for(unsigned char i=0;i<4;i++,entry++){if(entry->key==source->key)return 1;}
entry=FindFirstAvailableTwelveByteEntry(owner);
if(!entry||!source)return 0;
entry->key=source->key;entry->value=source->value;entry->type=source->type;entry->active=1;return 1;
}
