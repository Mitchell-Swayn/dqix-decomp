#include <globaldefs.h>
struct Tree { unsigned id; char allocator[0x14]; Tree* child; Tree* sibling; };
struct Item { unsigned short id, flags; char pad[0x70]; unsigned parent; Item* next; };
typedef unsigned (*Callback)(void*);
struct State { Tree root; Item first; void* allocated; unsigned allocationSize,allocationId; char padA8[8]; void* temporary; unsigned temporarySize; char padB8[0xfc]; Callback* callbacks; unsigned count; unsigned short active,fallback; };
extern "C" void _ZN13SafeAllocator21ResetAllocatorPointerEv(void*);
extern "C" void _ZN13SafeAllocator11CreateTypeBEPvji(void*,void*,unsigned,int);
extern "C" void* _ZN13SafeAllocator8AllocateEj(void*,unsigned);
extern "C" void _ZN13SafeAllocator7DestroyEv(void*);
extern "C" void func_ov023_021f6844(void*,unsigned);
extern "C" void SnapshotBlockAndVolatileWordPair(void*);
extern "C" void CopyCurrentStateToCurrentAndPreviousFields(void*,void*);
extern "C" void func_ov011_02184374(Item*);
extern "C" void func_ov011_021842a0(Tree*);
extern "C" Tree* func_ov011_021842c8(Tree*,unsigned);
extern "C" void func_ov011_02184324(Tree*,Tree*);
extern "C" void func_ov011_02184604(State*,Tree*);
// Original: arm9/ov011 @ 0x02184354; symbol: func_ov011_02184354; size: 0x20.
extern "C" void func_ov011_02184354(Tree* self, Tree* child) { Tree* current=self->sibling; if(!current) self->sibling=child; else func_ov011_02184324(current,child); }
