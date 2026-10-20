#include <globaldefs.h>
extern "C" unsigned Menu_ReadScriptArgumentAsInteger(void*);
extern "C" void* Resource_GetSharedLoadState();
extern "C" void* Menu_GetDisplayRecordRegistry(void*);
extern "C" void* Menu_FindSessionArenaById(void*,unsigned);
extern "C" unsigned _ZNK13SafeAllocator30GetSizeWithLargestBlockRemovedEv(void*);
extern "C" void* _ZN13SafeAllocator8AllocateEj(void*,unsigned);
extern "C" void* memcpy(void*,const void*,unsigned);
extern "C" void MenuRecordList_AppendKeyedRecord(void*,void*);
struct Item { const void* vtable; char header[0x1c]; char allocator[0x14]; char prefix34[4]; char member38[0x5c]; char member94[0x84]; };
// Original data: arm9/ov004 @ 0x21705f8; symbol: data_ov004_021705f8.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex d878160234e4150230e415022ce4150228e4150224e41502bc781602783715027c37150220e4150218e4150214e415020ce4150208e4150200e41502dc371502 ...; full span in module reference.
// Observed span: 252 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" const unsigned MenuCreateQuestMessagePanelDescriptor_UnknownRoleProcedureReferenceRecords[];
extern "C" void _ZN13SafeAllocator21ResetAllocatorPointerEv(void*);
extern "C" void ResourceStringLoader_Initialize(void*);
extern "C" void Graphics_InitializeSpriteResourceBuffers(void*);
extern "C" void Graphics_FinalizeSpriteResourceBuffers(void*);
extern "C" int QuestMessagePanelRecord_Initialize(Item*,void*,unsigned,unsigned);
// Original: arm9/ov011 @ 0x02187E20; symbol: func_ov011_02187e20; size: 0xE4.
extern "C" unsigned Menu_CreateQuestMessagePanelDescriptor(void* self) {
 unsigned id=Menu_ReadScriptArgumentAsInteger(self);
 unsigned kind=Menu_ReadScriptArgumentAsInteger((char*)self+8);
 void* owner=Resource_GetSharedLoadState();
 void* arena=Menu_FindSessionArenaById(owner,kind);
 if(!arena) return 0;
 _ZNK13SafeAllocator30GetSizeWithLargestBlockRemovedEv((char*)arena+4);
 Item* item=(Item*)_ZN13SafeAllocator8AllocateEj((char*)arena+4,sizeof(Item));
 if(!item) return 0;
 Item initial; initial.vtable=MenuCreateQuestMessagePanelDescriptor_UnknownRoleProcedureReferenceRecords;
 _ZN13SafeAllocator21ResetAllocatorPointerEv(initial.allocator);
 char* members=initial.prefix34;
 ResourceStringLoader_Initialize(members+4);
 Graphics_InitializeSpriteResourceBuffers(members+0x60);
 memcpy(item,&initial,sizeof(Item));
 if(!QuestMessagePanelRecord_Initialize(item,owner,id,kind)) {
  Graphics_FinalizeSpriteResourceBuffers(initial.member94); return 0;
 }
 MenuRecordList_AppendKeyedRecord(Menu_GetDisplayRecordRegistry(owner),item);
 Graphics_FinalizeSpriteResourceBuffers(initial.member94);
 return 1;
}
