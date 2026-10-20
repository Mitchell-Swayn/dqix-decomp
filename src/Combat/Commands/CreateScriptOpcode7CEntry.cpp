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
// Original: arm9/ov000 @ 0x0216CD90; symbol: CreateScriptOpcode7CEntry; size: 0x5C.
// Allocates a 0xC-byte entry tagged 0x7C, stores zero or the script integer low halfword at +8, initializes it, and returns success.
extern "C" int CreateScriptOpcode7CEntry(const void* parameter, int count) {
    char* allocator = *(char**)((char*)&CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage + 8);
    char* entry = _ZN13SafeAllocator8AllocateEj((unsigned int)allocator, 0xc);
    *(unsigned int*)entry = 0x7c;
    unsigned int value = 0;
    if (count > 0) value = (unsigned short)_ZNK6Script9Parameter5ToIntEv(parameter);
    *(unsigned short*)(entry + 8) = (unsigned short)value;
    Overlay_EnqueueLinkedNode(entry);
    return 1;
}
