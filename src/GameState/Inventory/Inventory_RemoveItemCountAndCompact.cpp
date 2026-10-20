#include <globaldefs.h>
ARM
struct Items {short* ids; signed char* flags; short count;};
extern "C" int Inventory_FindItemSlot(unsigned char*,int);
extern "C" void Inventory_CompactOccupiedSlotsFromIndex(Items*,int);
// Original: arm9/main @ 0x020A0A08; symbol: Inventory_RemoveItemCountAndCompact; size: 0x58.
// Subtracts a keyed signed-byte count and removes exhausted entries.
extern "C" int Inventory_RemoveItemCountAndCompact(Items* self,int key,int amount) {
 short* ids=self->ids; signed char* counts=self->flags;
 int index=Inventory_FindItemSlot((unsigned char*)self,key);
 int result=0;
 if(index>=0) {
 counts[index]-=amount;
 if(counts[index]<=0){ids[index]=result-1;counts[index]=result;Inventory_CompactOccupiedSlotsFromIndex(self,index);}
 result=1;
 }
 return result;
}
