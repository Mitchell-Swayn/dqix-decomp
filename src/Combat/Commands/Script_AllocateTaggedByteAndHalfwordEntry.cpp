#include <globaldefs.h>
ARM
extern "C" char* _ZN13SafeAllocator8AllocateEj(void* allocator, unsigned size);
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void* parameter);
extern "C" void Overlay_EnqueueLinkedNode(void* entry);
// Original data: arm9/ov000 @ 0x2184264; symbol: data_ov000_02184264.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov000.md.
extern "C" char CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov000 @ 0x0216C624; symbol: func_ov000_0216c624; size: 0x5C.
extern "C" int Script_AllocateTaggedByteAndHalfwordEntry(void* parameter) {
    void* allocator = *(void**)(CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage + 8);
    volatile unsigned* entry = (volatile unsigned*)_ZN13SafeAllocator8AllocateEj(allocator, 0xc);
    entry[0] = 0;
    entry[1] = 0;
    entry[0] = 0x6c;
    *(volatile unsigned char*)((char*)entry + 8) = (unsigned char)_ZNK6Script9Parameter5ToIntEv(parameter);
    *(volatile unsigned short*)((char*)entry + 0xa) = (unsigned short)_ZNK6Script9Parameter5ToIntEv((char*)parameter + 8);
    Overlay_EnqueueLinkedNode((void*)entry);
    return 1;
}
