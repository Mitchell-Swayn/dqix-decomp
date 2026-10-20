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
struct Argument { unsigned kind; void* pointer; };
struct Arguments { Argument entries[4]; };
struct Item { const void* vtable; char storage[200]; };
// Original data: arm9/ov023 @ 0x21ff6b8; symbol: data_ov023_021ff6b8.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 38ce1f02e8cf1f0208d01f0284691f0288691f02186a1f0228ce1f020cd01f0228d01f0258741f0250741f024c741f0244741f0240741f0238741f029c7d1f02 ...; full span in module reference.
// Observed span: 252 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov023.md.
extern "C" const unsigned SharedData_UnknownRoleProcedureReferenceRecords_Variant16[];
extern "C" int Object3D_InitializeParameterizedRecord(Item*,void*,unsigned,unsigned,unsigned,void*);
// Original: arm9/ov011 @ 0x02187B30; symbol: func_ov011_02187b30; size: 0xDC.
extern "C" unsigned Menu_CreateParameterizedObject3DDescriptor(Arguments* self) {
 unsigned id=Menu_ReadScriptArgumentAsInteger(self);
 unsigned kind=Menu_ReadScriptArgumentAsInteger(self->entries+1);
 unsigned value=Menu_ReadScriptArgumentAsInteger(self->entries+2);
 void* pointer=self->entries[3].kind==2 ? self->entries[3].pointer : 0;
 if(!pointer) return 0;
 void* owner=Resource_GetSharedLoadState();
 void* arena=Menu_FindSessionArenaById(owner,kind);
 if(!arena) return 0;

 _ZNK13SafeAllocator30GetSizeWithLargestBlockRemovedEv((char*)arena+4);
 Item* item=(Item*)_ZN13SafeAllocator8AllocateEj((char*)arena+4,sizeof(Item));
 if(!item) return 0;
 Item initial; initial.vtable=SharedData_UnknownRoleProcedureReferenceRecords_Variant16;
 memcpy(item,&initial,sizeof(Item));
 if(!Object3D_InitializeParameterizedRecord(item,owner,id,kind,value,pointer)) return 0;
 MenuRecordList_AppendKeyedRecord(Menu_GetDisplayRecordRegistry(owner),item);
 return 1;
}
