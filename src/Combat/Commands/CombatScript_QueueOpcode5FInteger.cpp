#include <globaldefs.h>
ARM
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned int, unsigned int);
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void*);
extern "C" void Overlay_EnqueueLinkedNode(void*);
// Original data: arm9/ov000 @ 0x2184264; symbol: data_ov000_02184264.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov000.md.
extern "C" unsigned int CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov000 @ 0x0216C2C4; symbol: Resource_QueueScriptIntegerRecord5F; size: 0x50.
// Allocates a 12-byte entry, tags it 0x5F, stores the converted script integer at +8, submits it, and returns success.
extern "C" int CombatScript_QueueOpcode5FInteger(const void* parameter) {
    char* allocator = *(char**)((char*)&CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage + 8);
    char* entry = _ZN13SafeAllocator8AllocateEj((unsigned int)allocator, 0xc);
    *(unsigned int*)entry = 0;
    *(unsigned int*)(entry + 4) = 0;
    *(unsigned int*)entry = 0x5f;
    *(unsigned int*)(entry + 8) = (unsigned int)_ZNK6Script9Parameter5ToIntEv(parameter);
    Overlay_EnqueueLinkedNode(entry);
    return 1;
}
