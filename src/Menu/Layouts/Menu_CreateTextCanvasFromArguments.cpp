#include <globaldefs.h>
extern "C" unsigned Menu_ReadScriptArgumentAsInteger(void*);
extern "C" void* Resource_GetSharedLoadState();
extern "C" void* Menu_GetDisplayRecordRegistry(void*);
extern "C" void* Menu_FindSessionArenaById(void*,unsigned);
extern "C" unsigned _ZNK13SafeAllocator30GetSizeWithLargestBlockRemovedEv(void*);
extern "C" void* _ZN13SafeAllocator8AllocateEj(void*,unsigned);
extern "C" void* memcpy(void*,const void*,unsigned);
extern "C" void MenuRecordList_AppendKeyedRecord(void*,void*);
struct Item { const void* vtable; char storage[268]; };
// Original data: arm9/ov023 @ 0x21fe604; symbol: data_ov023_021fe604.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 40811f0290811f0294811f0284691f0288691f02186a1f0230811f0298811f02f4811f0258741f0250741f024c741f0244741f0240741f0238741f029c7d1f02 ...; full span in module reference.
// Observed span: 260 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov023.md.
extern "C" const unsigned MenuCreateTextCanvasFromArguments_UnknownRoleProcedureReferenceRecords[];
extern "C" int MenuTextCanvas_InitializeAndBindLayer(Item*,void*,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned);
// Original: arm9/ov011 @ 0x02185318; symbol: func_ov011_02185318; size: 0x100.
extern "C" unsigned Menu_CreateTextCanvasFromArguments(void* self) {
 unsigned id=Menu_ReadScriptArgumentAsInteger(self);
 unsigned kind=Menu_ReadScriptArgumentAsInteger((char*)self+8);
 unsigned a=Menu_ReadScriptArgumentAsInteger((char*)self+16);
 unsigned b=Menu_ReadScriptArgumentAsInteger((char*)self+24);
 unsigned c=Menu_ReadScriptArgumentAsInteger((char*)self+32);
 unsigned d=Menu_ReadScriptArgumentAsInteger((char*)self+40);
 unsigned e=Menu_ReadScriptArgumentAsInteger((char*)self+48);
 void* owner=Resource_GetSharedLoadState();
 void* arena=Menu_FindSessionArenaById(owner,kind);
 if(!arena) return 0;
 _ZNK13SafeAllocator30GetSizeWithLargestBlockRemovedEv((char*)arena+4);
 Item* item=(Item*)_ZN13SafeAllocator8AllocateEj((char*)arena+4,sizeof(Item));
 if(!item) return 0;
 Item initial; initial.vtable=MenuCreateTextCanvasFromArguments_UnknownRoleProcedureReferenceRecords;
 memcpy(item,&initial,sizeof(Item));
 if(!MenuTextCanvas_InitializeAndBindLayer(item,owner,id,kind,a,b,c,d,e)) return 0;
 MenuRecordList_AppendKeyedRecord(Menu_GetDisplayRecordRegistry(owner),item);
 return 1;
}
