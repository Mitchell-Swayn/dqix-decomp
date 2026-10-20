#include <globaldefs.h>
extern "C" unsigned Menu_ReadScriptArgumentAsInteger(void*);
extern "C" void* Resource_GetSharedLoadState();
extern "C" void* Menu_GetDisplayRecordRegistry(void*);
extern "C" void* Menu_FindSessionArenaById(void*,unsigned);
extern "C" unsigned _ZNK13SafeAllocator30GetSizeWithLargestBlockRemovedEv(void*);
extern "C" void* _ZN13SafeAllocator8AllocateEj(void*,unsigned);
extern "C" void* memcpy(void*,const void*,unsigned);
extern "C" void MenuRecordList_AppendKeyedRecord(void*,void*);
struct Argument { unsigned kind; void* pointer; };
struct Arguments { Argument entries[5]; };
struct Item { const void* vtable; char storage[0x2c]; };
// Original data: arm9/ov023 @ 0x21fea34; symbol: data_ov023_021fea34.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex f4a21f02b8691f02e8691f0284691f0288691f02186a1f0288a51f02189b1f021c8c1f0258741f0250741f024c741f0244741f0240741f0238741f029c7d1f02 ...; full span in module reference.
// Observed span: 252 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov023.md.
extern "C" const unsigned SharedData_UnknownRoleProcedureReferenceRecords_Variant4[];
extern "C" int Menu_InitializeMessageTableResource(Item*,void*,unsigned,unsigned,void*,void*,unsigned);
// Original: arm9/ov011 @ 0x02188560; symbol: func_ov011_02188560; size: 0xF8.
extern "C" unsigned Menu_CreateNamedMessageTableDescriptor(Arguments* self) {
 unsigned id=Menu_ReadScriptArgumentAsInteger(self);
 unsigned kind=Menu_ReadScriptArgumentAsInteger(self->entries+1);
 void* first=self->entries[2].kind==2 ? self->entries[2].pointer : 0;
 if(!first) return 0;
 void* second=self->entries[3].kind==2 ? self->entries[3].pointer : 0;
 if(!second) return 0;
 void* owner=Resource_GetSharedLoadState();
 void* arena=Menu_FindSessionArenaById(owner,kind);
 if(!arena) return 0;
 unsigned value=Menu_ReadScriptArgumentAsInteger(self->entries+4);
 _ZNK13SafeAllocator30GetSizeWithLargestBlockRemovedEv((char*)arena+4);
 Item* item=(Item*)_ZN13SafeAllocator8AllocateEj((char*)arena+4,sizeof(Item));
 if(!item) return 0;
 Item initial; initial.vtable=SharedData_UnknownRoleProcedureReferenceRecords_Variant4;
 memcpy(item,&initial,sizeof(Item));
 if(!Menu_InitializeMessageTableResource(item,owner,id,kind,first,second,value)) return 0;
 MenuRecordList_AppendKeyedRecord(Menu_GetDisplayRecordRegistry(owner),item);
 return 1;
}
