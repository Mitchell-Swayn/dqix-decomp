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
// Original: arm9/ov000 @ 0x0216C95C; symbol: Resource_QueueScriptByteRecord79; size: 0x50.
// Allocates a 12-byte entry, tags it 0x79, stores the converted script integer low byte at +8, submits it, and returns success.
extern "C" int CombatScript_QueueOpcode79Byte(const void* parameter) {
    char* allocator = *(char**)((char*)&CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage + 8);
    char* entry = _ZN13SafeAllocator8AllocateEj((unsigned int)allocator, 0xc);
    *(unsigned int*)entry = 0;
    *(unsigned int*)(entry + 4) = 0;
    *(unsigned int*)entry = 0x79;
    entry[8] = (unsigned char)_ZNK6Script9Parameter5ToIntEv(parameter);
    Overlay_EnqueueLinkedNode(entry);
    return 1;
}
