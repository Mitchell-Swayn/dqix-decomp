#include <globaldefs.h>
extern "C" unsigned Menu_ReadScriptArgumentAsInteger(void*);
extern "C" void* Resource_GetSharedLoadState();
extern "C" void* Menu_GetDisplayRecordRegistry(void*);
extern "C" void* Menu_FindSessionArenaById(void*,unsigned);
extern "C" unsigned _ZNK13SafeAllocator30GetSizeWithLargestBlockRemovedEv(void*);
extern "C" void* _ZN13SafeAllocator8AllocateEj(void*,unsigned);
extern "C" void* memcpy(void*,const void*,unsigned);
extern "C" void MenuRecordList_AppendKeyedRecord(void*,void*);
extern "C" float Menu_ReadScriptArgumentAsFloat(void*);
struct Item { const void* vtable; char storage[76]; };
// Original data: arm9/ov023 @ 0x21fe708; symbol: data_ov023_021fe708.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex f08c1f02b8691f02e8691f0284691f0288691f02186a1f02e88a1f02ec8a1f02308b1f0258741f0250741f024c741f0244741f0240741f0238741f02688c1f02 ...; full span in module reference.
// Observed span: 260 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov023.md.
extern "C" const unsigned SharedData_UnknownRoleProcedureReferenceRecords[];
extern "C" int MenuTextLabel_InitializeSelectableTextRecord(Item*,void*,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned);
// Original: arm9/ov011 @ 0x0218598C; symbol: func_ov011_0218598c; size: 0x134.
extern "C" unsigned Menu_CreateMotionFromArguments(void* self) {
 unsigned id=Menu_ReadScriptArgumentAsInteger(self);
 unsigned kind=Menu_ReadScriptArgumentAsInteger((char*)self+8);
 unsigned a=Menu_ReadScriptArgumentAsInteger((char*)self+16);
 unsigned b=Menu_ReadScriptArgumentAsInteger((char*)self+24);
 unsigned c=Menu_ReadScriptArgumentAsInteger((char*)self+32);
 int d=(int)Menu_ReadScriptArgumentAsFloat((char*)self+40);
 int e=(int)Menu_ReadScriptArgumentAsFloat((char*)self+48);
 int f=(int)Menu_ReadScriptArgumentAsFloat((char*)self+56);
 int g=(int)Menu_ReadScriptArgumentAsFloat((char*)self+64);
 void* owner=Resource_GetSharedLoadState();
 void* arena=Menu_FindSessionArenaById(owner,kind);
 if(!arena) return 0;
 _ZNK13SafeAllocator30GetSizeWithLargestBlockRemovedEv((char*)arena+4);
 Item* item=(Item*)_ZN13SafeAllocator8AllocateEj((char*)arena+4,sizeof(Item));
 if(!item) return 0;
 Item initial; initial.vtable=SharedData_UnknownRoleProcedureReferenceRecords;
 memcpy(item,&initial,sizeof(Item));
 if(!MenuTextLabel_InitializeSelectableTextRecord(item,owner,id,kind,a,b,c,d,e,f,g)) return 0;
 MenuRecordList_AppendKeyedRecord(Menu_GetDisplayRecordRegistry(owner),item);
 return 1;
}
