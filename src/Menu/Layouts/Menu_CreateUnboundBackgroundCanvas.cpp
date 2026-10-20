#include <globaldefs.h>
extern "C" unsigned Menu_ReadScriptArgumentAsInteger(void*);
extern "C" void* Resource_GetSharedLoadState();
extern "C" void* Menu_GetDisplayRecordRegistry(void*);
extern "C" void* Menu_FindSessionArenaById(void*,unsigned);
extern "C" unsigned _ZNK13SafeAllocator30GetSizeWithLargestBlockRemovedEv(void*);
extern "C" void* _ZN13SafeAllocator8AllocateEj(void*,unsigned);
extern "C" void* memcpy(void*,const void*,unsigned);
extern "C" void MenuRecordList_AppendKeyedRecord(void*,void*);
struct Item { const void* vtable; char storage[0x50]; };
// Original data: arm9/ov023 @ 0x21fe4f0; symbol: data_ov023_021fe4f0.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 50751f02b8691f02e8691f0264781f0284781f02a4781f0284791f02147d1f02487d1f0258741f0250741f024c741f0244741f0240741f0238741f029c7d1f02 ...; full span in module reference.
// Observed span: 252 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov023.md.
extern "C" const unsigned MenuCreateNamedBackgroundCanvas_UnknownRoleProcedureReferenceRecords[];
extern "C" int MenuLayerRecord_InitializeAndAllocateScreenBuffer(Item*,void*,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned);
// Original: arm9/ov011 @ 0x0218792C; symbol: func_ov011_0218792c; size: 0xE8.
extern "C" unsigned Menu_CreateUnboundBackgroundCanvas(void* self) {
 unsigned id=Menu_ReadScriptArgumentAsInteger(self);
 unsigned kind=Menu_ReadScriptArgumentAsInteger((char*)self+8);
 unsigned first=Menu_ReadScriptArgumentAsInteger((char*)self+16);
 unsigned second=Menu_ReadScriptArgumentAsInteger((char*)self+24);
 unsigned third=Menu_ReadScriptArgumentAsInteger((char*)self+32);
 void* owner=Resource_GetSharedLoadState();
 void* arena=Menu_FindSessionArenaById(owner,kind);
 if(!arena) return 0;
 _ZNK13SafeAllocator30GetSizeWithLargestBlockRemovedEv((char*)arena+4);
 Item* item=(Item*)_ZN13SafeAllocator8AllocateEj((char*)arena+4,sizeof(Item));
 if(!item) return 0;
 Item initial; initial.vtable=MenuCreateNamedBackgroundCanvas_UnknownRoleProcedureReferenceRecords;
 memcpy(item,&initial,sizeof(Item));
 if(!MenuLayerRecord_InitializeAndAllocateScreenBuffer(item,owner,id,kind,0,0,first,second,third)) return 0;
 MenuRecordList_AppendKeyedRecord(Menu_GetDisplayRecordRegistry(owner),item);
 return 1;
}
