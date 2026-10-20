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
struct Arguments { Argument entries[4]; };
struct Item { char storage[0xac]; };
extern "C" Item* Menu_InitializeContainerRenderRecord(Item*);
extern "C" void Menu_ResetContainerRenderRecordParts(Item*);
extern "C" int MenuZoneRenderRecord_Initialize(Item*,void*,unsigned,unsigned,unsigned,void*);
// Original: arm9/ov011 @ 0x02185020; symbol: func_ov011_02185020; size: 0xF0.
extern "C" unsigned Menu_CreateContainerRenderFromArguments(Arguments* self) {
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
 Item initial; Menu_InitializeContainerRenderRecord(&initial);
 memcpy(item,&initial,sizeof(Item));
 if(!MenuZoneRenderRecord_Initialize(item,owner,id,kind,value,pointer)) {
  Menu_ResetContainerRenderRecordParts(&initial); return 0;
 }
 MenuRecordList_AppendKeyedRecord(Menu_GetDisplayRecordRegistry(owner),item);
 Menu_ResetContainerRenderRecordParts(&initial);
 return 1;
}
