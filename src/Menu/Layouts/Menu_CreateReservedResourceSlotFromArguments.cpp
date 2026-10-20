#include <globaldefs.h>
extern "C" unsigned Menu_ReadScriptArgumentAsInteger(void*);
extern "C" void* Resource_GetSharedLoadState();
extern "C" void* Menu_GetDisplayRecordRegistry(void*);
extern "C" void* Menu_FindSessionArenaById(void*,unsigned);
extern "C" unsigned _ZNK13SafeAllocator30GetSizeWithLargestBlockRemovedEv(void*);
extern "C" void* _ZN13SafeAllocator8AllocateEj(void*,unsigned);
extern "C" void* memcpy(void*,const void*,unsigned);
extern "C" void MenuRecordList_AppendKeyedRecord(void*,void*);
struct Item { const void* vtable; char storage[40]; };
// Original data: arm9/ov023 @ 0x21fed64; symbol: data_ov023_021fed64.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex c8b31f02b8691f02e8691f0284691f0288691f02186a1f0264b31f0298b41f02dcb41f0258741f0250741f024c741f0244741f0240741f0238741f0224b51f02 ...; full span in module reference.
// Observed span: 260 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov023.md.
extern "C" const unsigned SharedData_UnknownRoleProcedureReferenceRecords_Variant7[];
extern "C" int Menu_InitializeSpriteTrackRecord(Item*,void*,unsigned,unsigned,unsigned,unsigned);
// Original: arm9/ov011 @ 0x02185DD4; symbol: func_ov011_02185dd4; size: 0xD0.
extern "C" unsigned Menu_CreateReservedResourceSlotFromArguments(void* self) {
 unsigned id=Menu_ReadScriptArgumentAsInteger(self);
 unsigned kind=Menu_ReadScriptArgumentAsInteger((char*)self+8);
 unsigned first=Menu_ReadScriptArgumentAsInteger((char*)self+16);
 unsigned second=Menu_ReadScriptArgumentAsInteger((char*)self+24);
 void* owner=Resource_GetSharedLoadState();
 void* arena=Menu_FindSessionArenaById(owner,kind);
 if(!arena) return 0;
 _ZNK13SafeAllocator30GetSizeWithLargestBlockRemovedEv((char*)arena+4);
 Item* item=(Item*)_ZN13SafeAllocator8AllocateEj((char*)arena+4,sizeof(Item));
 if(!item) return 0;
 Item initial;
 initial.vtable=SharedData_UnknownRoleProcedureReferenceRecords_Variant7;
 memcpy(item,&initial,sizeof(Item));
 if(!Menu_InitializeSpriteTrackRecord(item,owner,id,kind,first,second)) return 0;
 MenuRecordList_AppendKeyedRecord(Menu_GetDisplayRecordRegistry(owner),item);
 return 1;
}
