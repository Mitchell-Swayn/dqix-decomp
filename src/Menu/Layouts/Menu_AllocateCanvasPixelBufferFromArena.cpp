#include <globaldefs.h>
struct Tree { unsigned id; char allocator[0x14]; Tree* child; Tree* sibling; };
struct Item { unsigned short id, flags; char pad[0x70]; unsigned parent; Item* next; };
typedef unsigned (*Callback)(void*);
struct State { Tree root; Item first; void* allocated; unsigned allocationSize,allocationId; char padA8[8]; void* temporary; unsigned temporarySize; char padB8[0xfc]; Callback* callbacks; unsigned count; unsigned short active,fallback; };
extern "C" void _ZN13SafeAllocator21ResetAllocatorPointerEv(void*);
extern "C" void _ZN13SafeAllocator11CreateTypeBEPvji(void*,void*,unsigned,int);
extern "C" void* _ZN13SafeAllocator8AllocateEj(void*,unsigned);
extern "C" void _ZN13SafeAllocator7DestroyEv(void*);
extern "C" void RemoveDescriptorsMatchingHalfwordKey(void*,unsigned);
extern "C" void TextureVRAM_SnapshotAllocationBounds(void*);
extern "C" void TextureVRAM_CloneSavedAllocationBounds(void*,void*);
extern "C" void Menu_ResetVramSnapshotRecordHeader(Item*);
extern "C" void Menu_InitializeArenaNode(Tree*);
extern "C" Tree* Menu_FindArenaNodeById(Tree*,unsigned);
extern "C" void Menu_AppendArenaToForwardChain(Tree*,Tree*);
extern "C" void Menu_DestroyArenaTreeAndOwnedDisplayRecords(State*,Tree*);
// Original: arm9/ov011 @ 0x021844A4; symbol: func_ov011_021844a4; size: 0x48.
extern "C" unsigned Menu_AllocateCanvasPixelBufferFromArena(State* self, unsigned id, unsigned size) { Tree* node=Menu_FindArenaNodeById(&self->root,id); if(!node) return 1; self->allocated=_ZN13SafeAllocator8AllocateEj(node->allocator,size); if(!self->allocated) return 1; self->allocationId=id; self->allocationSize=size; return 0; }
