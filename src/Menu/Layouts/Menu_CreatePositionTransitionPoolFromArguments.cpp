#include <globaldefs.h>
extern "C" unsigned Menu_ReadScriptArgumentAsInteger(void*);
extern "C" void* Resource_GetSharedLoadState();
extern "C" void* Menu_GetDisplayRecordRegistry(void*);
extern "C" void* Menu_FindSessionArenaById(void*,unsigned);
extern "C" unsigned _ZNK13SafeAllocator30GetSizeWithLargestBlockRemovedEv(void*);
extern "C" void* _ZN13SafeAllocator8AllocateEj(void*,unsigned);
extern "C" void* memcpy(void*,const void*,unsigned);
extern "C" void MenuRecordList_AppendKeyedRecord(void*,void*);
extern "C" void* MenuRecordList_LocateByKey(void*,unsigned);
struct Item { const void* vtable; char storage[0x24]; };
// Original data: arm9/ov023 @ 0x21fe910; symbol: data_ov023_021fe910.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 789f1f02b8691f02e8691f0284691f0288691f02186a1f0238a01f02189b1f021c8c1f0258741f0250741f024c741f0244741f0240741f0238741f029c7d1f02 ...; full span in module reference.
// Observed span: 252 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov023.md.
extern "C" const unsigned SharedData_UnknownRoleProcedureReferenceRecords_Variant3[];
extern "C" int Menu_InitializeMotionQueue(Item*,void*,unsigned,unsigned,unsigned);
// Original: arm9/ov011 @ 0x02185B10; symbol: func_ov011_02185b10; size: 0xD8.
extern "C" unsigned Menu_CreatePositionTransitionPoolFromArguments(void* self) {
 void* owner=Resource_GetSharedLoadState();
 void* list=Menu_GetDisplayRecordRegistry(owner);
 if(MenuRecordList_LocateByKey(list,0xffff)) return 0;
 unsigned kind=Menu_ReadScriptArgumentAsInteger(self);
 unsigned value=Menu_ReadScriptArgumentAsInteger((char*)self+8);
 void* arena=Menu_FindSessionArenaById(owner,kind);
 if(!arena) return 0;
 _ZNK13SafeAllocator30GetSizeWithLargestBlockRemovedEv((char*)arena+4);
 Item* item=(Item*)_ZN13SafeAllocator8AllocateEj((char*)arena+4,sizeof(Item));
 if(!item) return 0;
 Item initial; initial.vtable=SharedData_UnknownRoleProcedureReferenceRecords_Variant3;
 memcpy(item,&initial,sizeof(Item));
 if(!Menu_InitializeMotionQueue(item,owner,0xffff,kind,value)) return 0;
 MenuRecordList_AppendKeyedRecord(list,item);
 return 1;
}
