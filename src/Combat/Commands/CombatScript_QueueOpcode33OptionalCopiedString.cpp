#include <globaldefs.h>
ARM
// Original data: arm9/ov000 @ 0x2184264; symbol: data_ov000_02184264.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov000.md.
extern "C" void* CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage[3];
extern "C" char* _ZN13SafeAllocator8AllocateEj(void*, unsigned);
extern "C" const char* _ZNK6Script9Parameter8ToStringEv(const void*);
extern "C" unsigned strlen(const char*);
extern "C" char* strcpy(char*, const char*);
extern "C" void Overlay_EnqueueLinkedNode(void*);
// Original: arm9/ov000 @ 0x0216B394; symbol: func_ov000_0216b394; size: 0x74.
extern "C" int CombatScript_QueueOpcode33OptionalCopiedString(const void* parameter) {
    char* record = _ZN13SafeAllocator8AllocateEj(CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage[2], 12);
    *(unsigned*)record = 0;
    *(unsigned*)(record + 4) = 0;
    *(unsigned*)record = 0x33;
    const char* value = _ZNK6Script9Parameter8ToStringEv(parameter);
    if (value) {
        unsigned length = strlen(value) + 1;
        char* copy = _ZN13SafeAllocator8AllocateEj(CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage[2], length);
        *(char**)(record + 8) = copy;
        strcpy(copy, value);
    }
    Overlay_EnqueueLinkedNode(record);
    return 1;
}
