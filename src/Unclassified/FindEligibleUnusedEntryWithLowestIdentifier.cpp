#include <globaldefs.h>
struct Entry {unsigned char id,status;char pad[42];};struct State {Entry* entries;unsigned short unknown,count;};extern "C" char* ReadGlobalValueAt02108844();extern "C" int ReadNonnegativeIndexedBit(void*,void*,unsigned);
// Original: arm9/main @ 0x020A8458; symbol: func_020a8458; size: 0x88.
extern "C" Entry* FindEligibleUnusedEntryWithLowestIdentifier(State* self) {char* owner=ReadGlobalValueAt02108844();unsigned lowest;unsigned selected=0;lowest=255;for(int i=0;i<self->count;++i){Entry* entry=self->entries+i;if(entry->status==255 && entry->id<lowest && ReadNonnegativeIndexedBit(owner,owner+0x8c,entry->id+0x200)){lowest=entry->id;selected=i&255;}}Entry* result;if(lowest!=255)result=self->entries+selected;else result=0;return result;}
