#include <globaldefs.h>
ARM
extern "C" void _ZN13SafeAllocator11CreateTypeBEPvji(void*,void*,unsigned,int);
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);
extern "C" unsigned _ZNK13SafeAllocator24GetMaxPossibleAllocationEv(void*);
struct Object;
extern "C" void CopyCurrentStateToCurrentAndPreviousFields(const Object*,Object*);
struct Context { char pad[16]; void *allocators[4]; Object *states[4]; unsigned char level; };
// Original: arm9/ov025 @ 0x021E8A74; symbol: func_ov025_021e8a74; size: 0x84.
extern "C" void Memory_PushAllocatorState(Context *self) {
    if (self->level == 3) return;
    unsigned size = _ZNK13SafeAllocator24GetMaxPossibleAllocationEv(self->allocators[self->level]);
    void *block = _ZN13SafeAllocator8AllocateEj((unsigned)self->allocators[self->level], size);
    _ZN13SafeAllocator11CreateTypeBEPvji(self->allocators[self->level + 1], block, size, 4);
    CopyCurrentStateToCurrentAndPreviousFields(self->states[self->level], self->states[self->level + 1]);
    self->level++;
}
