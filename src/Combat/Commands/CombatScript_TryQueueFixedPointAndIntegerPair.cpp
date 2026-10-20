#include <globaldefs.h>
ARM
// Original data: arm9/ov000 @ 0x2184264; symbol: data_ov000_02184264.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov000.md.
extern "C" unsigned char CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage;
extern "C" char* _ZN13SafeAllocator8AllocateEj(void*, unsigned);
extern "C" float _ZNK6Script9Parameter7ToFloatEv(void*);
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void*);
extern "C" void Overlay_EnqueueLinkedNode(void*);
struct Entry { unsigned int type; unsigned char pad[4]; short amount; short first; short second; };
// Original: arm9/ov000 @ 0x0216C8E4; symbol: Resource_QueueScriptFixedPointRecord74; size: 0x78.
// Allocates a 16-byte script record tagged 0x74, converts a float parameter to fixed point, stores two integer parameters as halfwords, and queues it.
extern "C" int CombatScript_TryQueueFixedPointAndIntegerPair(unsigned char* parameter) {
    void* allocator = *(void**)((char*)&CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage + 8);
    Entry* entry = (Entry*)_ZN13SafeAllocator8AllocateEj(allocator, 0x10);
    if (!entry) return 0;
    entry->type = 0x74;
    entry->amount = (short)(float)(_ZNK6Script9Parameter7ToFloatEv(parameter) * 4096.0f);
    entry->first = (short)_ZNK6Script9Parameter5ToIntEv(parameter + 8);
    entry->second = (short)_ZNK6Script9Parameter5ToIntEv(parameter + 16);
    Overlay_EnqueueLinkedNode(entry);
    return 1;
}
