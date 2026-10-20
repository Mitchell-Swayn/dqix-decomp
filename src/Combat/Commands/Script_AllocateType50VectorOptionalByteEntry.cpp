#include <globaldefs.h>
ARM
// Original data: arm9/ov000 @ 0x2184264; symbol: data_ov000_02184264.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov000.md.
extern "C" unsigned char CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage[];
extern "C" char* _ZN13SafeAllocator8AllocateEj(void*, unsigned);
extern "C" const void* _ZN6Script9Parameter9ToVec3fixEP8Vector3i(const void*, void*);
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void*);
extern "C" void Overlay_EnqueueLinkedNode(void*);

// Original: arm9/ov000 @ 0x0216B328; symbol: Script_AllocateType50VectorOptionalByteEntry; size: 0x6c.
// Allocates and queues a type-0x32 node containing a fixed-point vector and an optional byte.
extern "C" int Script_AllocateType50VectorOptionalByteEntry(const void* parameter, int count) {
    char* entry = _ZN13SafeAllocator8AllocateEj(*(void**)(CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage + 8), 0x18);
    *(unsigned*)entry = 0;
    *(unsigned*)(entry + 4) = 0;
    *(unsigned*)entry = 0x32;
    const void* nextParameter = _ZN6Script9Parameter9ToVec3fixEP8Vector3i(parameter, entry + 8);
    unsigned char optionalValue = 0;
    if (count >= 4) optionalValue = (unsigned char)_ZNK6Script9Parameter5ToIntEv(nextParameter);
    entry[0x14] = optionalValue;
    Overlay_EnqueueLinkedNode(entry);
    return 1;
}
