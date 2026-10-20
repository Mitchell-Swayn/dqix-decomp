#include <globaldefs.h>
ARM
struct State;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void GameState_WriteUnknownF70(void*,int);
extern "C" void* Menu_GetDisplayRecordRegistry(State*);
extern "C" void Menu_RequestSelectionRefresh(State*);
extern "C" void* MenuRecordList_LocateByKey(void**,unsigned short);
extern "C" unsigned int MenuRecord_GetType(void*);
// Original data: arm9/ov004 @ 0x2171034; symbol: data_ov004_02171034.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" unsigned char InitializeGlobalTreeEntry_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov004 @ 0x0216E8F0; symbol: func_ov004_0216e8f0; size: 0x94.
extern "C" int Graphics_RevealSelectedListEntries(State* self) {
void** head=(void**)Menu_GetDisplayRecordRegistry(self);
if(head){unsigned char* entry=(unsigned char*)MenuRecordList_LocateByKey(head,*(unsigned short*)(InitializeGlobalTreeEntry_UnknownRoleZeroInitializedStorage+10));if(entry)entry[12]&=~16;}
Menu_RequestSelectionRefresh(self);
void* state=_ZN9GameState11GetInstanceEv();
if(InitializeGlobalTreeEntry_UnknownRoleZeroInitializedStorage[3]!=6){
unsigned char* entry=(unsigned char*)MenuRecordList_LocateByKey(head,1);
if(entry && MenuRecord_GetType(entry)==11){entry[12]&=~8;GameState_WriteUnknownF70(state,1);}
}
return 0;
}
