#include <globaldefs.h>
ARM
extern "C" void* Menu_GetDisplayRecordRegistry(void*); extern "C" void* MenuRecordList_LocateByKey(void**,unsigned short); extern "C" unsigned MenuRecord_GetType(void*); extern "C" void* Menu_GetRecordMessageTable(void*);
// Original: arm9/ov004 @ 0x02157018; symbol: Filesystem_FindTypeFourEmbeddedValue; size: 0x3c.
// Finds a keyed node and returns its embedded field only when its type is four.
extern "C" void* Filesystem_FindTypeFourEmbeddedValue(void* state,unsigned short key) {void* head=Menu_GetDisplayRecordRegistry(state); void* entry=MenuRecordList_LocateByKey((void**)head,key); if(entry && MenuRecord_GetType(entry)==4) return Menu_GetRecordMessageTable(entry); return (void*)0;}
