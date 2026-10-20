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
// Original: arm9/ov000 @ 0x0216CEC0; symbol: CreateScriptOpcode80Entry; size: 0x44.
// Allocates a 0xC-byte entry, sets type 0x80, stores the script integer as a halfword at +8, initializes the entry, and returns success.
extern "C" int CreateScriptOpcode80Entry(const void* parameter) {
    char* allocator = *(char**)((char*)&CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage + 8);
    char* entry = _ZN13SafeAllocator8AllocateEj((unsigned int)allocator, 0xc);
    *(unsigned int*)entry = 0x80;
    *(unsigned short*)(entry + 8) = (unsigned short)_ZNK6Script9Parameter5ToIntEv(parameter);
    Overlay_EnqueueLinkedNode(entry);
    return 1;
}
