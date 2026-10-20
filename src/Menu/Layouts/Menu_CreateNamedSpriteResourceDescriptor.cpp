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
struct Item { char header[0x24]; char member24[0x64]; };
extern "C" Item* Menu_ConstructSpriteResourceRecord(Item*);
extern "C" void Graphics_FinalizeSpriteResourceBuffers(void*);
extern "C" int Menu_InitializeSpriteResourceRecord(Item*,void*,unsigned,unsigned,void*,void*,unsigned);
// Original: arm9/ov011 @ 0x02188774; symbol: func_ov011_02188774; size: 0x110.
extern "C" unsigned Menu_CreateNamedSpriteResourceDescriptor(Arguments* self) {
 unsigned id=Menu_ReadScriptArgumentAsInteger(self);
 unsigned kind=Menu_ReadScriptArgumentAsInteger(self->entries+1);
 void* pointer=self->entries[2].kind==2 ? self->entries[2].pointer : 0;
 if(!pointer) return 0;
 void* second=self->entries[3].kind==2 ? self->entries[3].pointer : 0;
 if(!second) return 0;
 unsigned value=Menu_ReadScriptArgumentAsInteger(self->entries+4);
 void* owner=Resource_GetSharedLoadState();
 void* arena=Menu_FindSessionArenaById(owner,kind);
 if(!arena) return 0;
 _ZNK13SafeAllocator30GetSizeWithLargestBlockRemovedEv((char*)arena+4);
 Item* item=(Item*)_ZN13SafeAllocator8AllocateEj((char*)arena+4,sizeof(Item));
 if(!item) return 0;
 Item initial; Menu_ConstructSpriteResourceRecord(&initial);
 memcpy(item,&initial,sizeof(Item));
 if(!Menu_InitializeSpriteResourceRecord(item,owner,id,kind,pointer,second,value)) {
  Graphics_FinalizeSpriteResourceBuffers(initial.member24); return 0;
 }
 MenuRecordList_AppendKeyedRecord(Menu_GetDisplayRecordRegistry(owner),item);
 Graphics_FinalizeSpriteResourceBuffers(initial.member24);
 return 1;
}
