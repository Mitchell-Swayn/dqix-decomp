#include <globaldefs.h>
extern "C" unsigned Menu_ReadScriptArgumentAsInteger(void*);
extern "C" void* Resource_GetSharedLoadState();
extern "C" void* Menu_GetDisplayRecordRegistry(void*);
extern "C" void* Menu_FindSessionArenaById(void*,unsigned);
extern "C" unsigned _ZNK13SafeAllocator30GetSizeWithLargestBlockRemovedEv(void*);
extern "C" void* _ZN13SafeAllocator8AllocateEj(void*,unsigned);
extern "C" void* memcpy(void*,const void*,unsigned);
extern "C" void MenuRecordList_AppendKeyedRecord(void*,void*);
struct Item { char storage[0xac]; };
extern "C" void* MenuRecordList_LocateByKey(void*,unsigned);
extern "C" unsigned MenuRecord_GetType(void*);
extern "C" Item* Menu_InitializeContainerRenderRecord(Item*);
extern "C" void Menu_ResetContainerRenderRecordParts(Item*);
extern "C" int MenuZoneRenderRecord_Initialize(Item*,void*,unsigned,unsigned,unsigned,void*);
extern "C" void* MenuZoneRenderRecord_GetRenderPart(void*);
extern "C" void ZoneContainerRenderPart_ShareFrameAndAnimationResources(void*,void*);
extern "C" void MenuZoneRenderRecord_MarkLoadComplete(void*);
// Original: arm9/ov011 @ 0x02187A14; symbol: func_ov011_02187a14; size: 0x11C.
extern "C" unsigned Menu_CloneRenderContainerSharedResources(void* self) {
 unsigned id=Menu_ReadScriptArgumentAsInteger(self);
 unsigned kind=Menu_ReadScriptArgumentAsInteger((char*)self+8);
 unsigned from=Menu_ReadScriptArgumentAsInteger((char*)self+16);
 void* owner=Resource_GetSharedLoadState();
 void* list=Menu_GetDisplayRecordRegistry(owner);
 void* source=MenuRecordList_LocateByKey(list,from);
 MenuRecord_GetType(source);
 void* arena=Menu_FindSessionArenaById(owner,kind);
 if(!arena) return 0;
 _ZNK13SafeAllocator30GetSizeWithLargestBlockRemovedEv((char*)arena+4);
 Item* item=(Item*)_ZN13SafeAllocator8AllocateEj((char*)arena+4,sizeof(Item));
 if(!item) return 0;
 Item initial; Menu_InitializeContainerRenderRecord(&initial);
 memcpy(item,&initial,sizeof(Item));
 if(!MenuZoneRenderRecord_Initialize(item,owner,id,kind,0,0)) {
  Menu_ResetContainerRenderRecordParts(&initial); return 0;
 }
 void* fromEntries=MenuZoneRenderRecord_GetRenderPart(source);
 void* toEntries=MenuZoneRenderRecord_GetRenderPart(item);
 ZoneContainerRenderPart_ShareFrameAndAnimationResources(fromEntries,toEntries);
 MenuZoneRenderRecord_MarkLoadComplete(item);
 MenuRecordList_AppendKeyedRecord(list,item);
 Menu_ResetContainerRenderRecordParts(&initial);
 return 1;
}
