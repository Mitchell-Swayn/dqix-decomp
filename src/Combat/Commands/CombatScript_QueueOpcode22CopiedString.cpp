#include <globaldefs.h>
// Original data: arm9/ov000 @ 0x2184264; symbol: data_ov000_02184264.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov000.md.
extern "C" unsigned CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage[];
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned, unsigned);
extern "C" const char* _ZNK6Script9Parameter8ToStringEv(const void*);
extern "C" unsigned strlen(const char*);
extern "C" char* strcpy(char*, const char*);
extern "C" void Overlay_EnqueueLinkedNode(void*);
// Original: arm9/ov000 @ 0x0216AD0C; symbol: func_ov000_0216ad0c; size: 0x70.
extern "C" int CombatScript_QueueOpcode22CopiedString(const void* parameter) {
    char* record = _ZN13SafeAllocator8AllocateEj(CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage[2], 0xc);
    *(unsigned*)record = 0;
    *(unsigned*)(record + 4) = 0;
    *(unsigned*)record = 0x22;
    const char* text = _ZNK6Script9Parameter8ToStringEv(parameter);
    char* copy = _ZN13SafeAllocator8AllocateEj(CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage[2], strlen(text) + 1);
    *(char**)(record + 8) = copy;
    strcpy(copy, text);
    Overlay_EnqueueLinkedNode(record);
    return 1;
}
