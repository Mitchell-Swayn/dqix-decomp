#include <globaldefs.h>
ARM
#pragma always_inline on
struct Record {short key;char pad[20];unsigned char flags;char last;};
struct Owner {char pad[8];Record* table;char gap[8];unsigned short count;};
static inline Record* FindRecord(Owner* self,int key){
 Record* table=self->table;if(!table)return 0;
 unsigned count=self->count;if(!count)return 0;
 for(unsigned short i=0;i<count;i++){Record* entry=table+i;if(entry->key==key)return entry;}
 return 0;
}
// Original: arm9/ov023 @ 0x021E3D3C; symbol: func_ov023_021e3d3c; size: 0x74.
// Clears the requested flag bits on the signed-key-matched 24-byte record, if present.
extern "C" void Menu_ClearLayoutGroupFlags(Owner* self,int key,unsigned mask){
 Record* record=FindRecord(self,key);
 if(record)record->flags&=~mask;
}
