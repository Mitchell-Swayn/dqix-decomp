#include <globaldefs.h>
ARM
struct Pair { int key; void *value; };
struct PairTable { Pair *entries; int count; };
// Original: arm9/ov001 @ 0x02153884; symbol: Script_FindTextTableEntry; size: 0x44.
// Returns the first matching key/value pair when its value is nonzero.
extern "C" Pair *Script_FindTextTableEntry(PairTable *table,int key) {
 for(int index=0;index<table->count;index++) {
 if(table->entries[index].key==key) {
 Pair *entry=table->entries+index;
 if(!entry->value)entry=0;
 return entry;
 }
 }
 return 0;
}
