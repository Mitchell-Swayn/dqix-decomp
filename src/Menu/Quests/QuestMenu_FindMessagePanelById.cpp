#include <globaldefs.h>
// Opaque owner-local type from Menu_GetDisplayRecordRegistry; this wrapper does not access its layout.
struct State;
extern "C" void* Menu_GetDisplayRecordRegistry(State*);
extern "C" void* MenuRecordList_LocateByKey(void**,unsigned short);
extern "C" unsigned MenuRecord_GetType(void*);
// Original: arm9/ov004 @ 0x02165E70; symbol: func_ov004_02165e70; size: 0x34.
extern "C" ARM void* QuestMenu_FindMessagePanelById(void* owner,unsigned short key){
 void* record=MenuRecordList_LocateByKey((void**)Menu_GetDisplayRecordRegistry((State*)owner),key);
 if(!record)return 0;
 if(MenuRecord_GetType(record)!=21)record=0;
 return record;
}
