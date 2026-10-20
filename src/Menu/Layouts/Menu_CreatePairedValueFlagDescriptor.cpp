#include <globaldefs.h>
extern "C" unsigned Menu_ReadScriptArgumentAsInteger(void*);
extern "C" void* Resource_GetSharedLoadState();
extern "C" void* Menu_GetDisplayRecordRegistry(void*);
extern "C" void* Menu_FindSessionArenaById(void*,unsigned);
extern "C" unsigned _ZNK13SafeAllocator30GetSizeWithLargestBlockRemovedEv(void*);
extern "C" void* _ZN13SafeAllocator8AllocateEj(void*,unsigned);
extern "C" void* memcpy(void*,const void*,unsigned);
extern "C" void MenuRecordList_AppendKeyedRecord(void*,void*);
struct Item { const void* vtable; char storage[0x28]; };
// Original data: arm9/ov023 @ 0x21ff7c4; symbol: data_ov023_021ff7c4.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 38d21f02b8691f02e8691f0284691f0288691f02186a1f0234d21f02189b1f021c8c1f0258741f0250741f024c741f0244741f0240741f0238741f029c7d1f02 ...; full span in module reference.
// Observed span: 260 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov023.md.
extern "C" const unsigned SharedData_UnknownRoleProcedureReferenceRecords_Variant17[];
extern "C" int MenuDisplayCommand_InitializeRecord(Item*,void*,unsigned,unsigned,unsigned*,bool*);
// Original: arm9/ov011 @ 0x02186548; symbol: func_ov011_02186548; size: 0x108.
extern "C" unsigned Menu_CreatePairedValueFlagDescriptor(void* self) {
 unsigned id=Menu_ReadScriptArgumentAsInteger(self);
 unsigned kind=Menu_ReadScriptArgumentAsInteger((char*)self+8);
 unsigned values[2]; bool flags[2];
 values[0]=Menu_ReadScriptArgumentAsInteger((char*)self+16);
 values[1]=Menu_ReadScriptArgumentAsInteger((char*)self+24);
 flags[0]=Menu_ReadScriptArgumentAsInteger((char*)self+32)!=0;
 flags[1]=Menu_ReadScriptArgumentAsInteger((char*)self+40)!=0;
 void* owner=Resource_GetSharedLoadState();
 void* arena=Menu_FindSessionArenaById(owner,kind);
 if(!arena) return 0;
 _ZNK13SafeAllocator30GetSizeWithLargestBlockRemovedEv((char*)arena+4);
 Item* item=(Item*)_ZN13SafeAllocator8AllocateEj((char*)arena+4,sizeof(Item));
 if(!item) return 0;
 Item initial; initial.vtable=SharedData_UnknownRoleProcedureReferenceRecords_Variant17;
 memcpy(item,&initial,sizeof(Item));
 if(!MenuDisplayCommand_InitializeRecord(item,owner,id,kind,values,flags)) return 0;
 MenuRecordList_AppendKeyedRecord(Menu_GetDisplayRecordRegistry(owner),item);
 return 1;
}
