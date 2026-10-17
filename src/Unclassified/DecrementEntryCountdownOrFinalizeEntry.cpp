#include <globaldefs.h>
extern "C" void ClearFortyByteRecordIndirect(void*); extern "C" void Object_InitializeEmbeddedRecordAndInvalidSlot(void*);
struct Entry { char pad[56]; int remaining; }; struct Table { unsigned count,pad; Entry* entries; };
// Original: arm9/main @ 0x0204039C; symbol: func_0204039c; size: 0x68.
extern "C" void DecrementEntryCountdownOrFinalizeEntry(Table* table,int index) { Entry* entries=table->entries; if(!entries)return; if(index<0)return; if(table->count<=(unsigned)index)return; int offset=index*60; int* remaining=(int*)((char*)entries+56+offset); if(*remaining<0)return; if(*remaining>0) { --*remaining; return; } ClearFortyByteRecordIndirect((char*)entries+offset+16); Object_InitializeEmbeddedRecordAndInvalidSlot((char*)table->entries+offset); }
