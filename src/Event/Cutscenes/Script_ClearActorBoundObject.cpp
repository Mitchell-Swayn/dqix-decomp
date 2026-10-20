#include <globaldefs.h>
ARM
// Original data: arm9/ov001 @ 0x2165880; symbol: data_ov001_02165880.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" void* EventGetObjectSession_UnknownRoleZeroInitializedStorage;
extern "C" int Script_ReadParameterAsInteger(void*);
extern "C" void* ActorPool_GetGlobalInstance(void);
extern "C" unsigned* ActorPool_GetActiveSlot(unsigned**, unsigned);
// Original: arm9/ov001 @ 0x0215D0F4; symbol: func_ov001_0215d0f4; size: 0x40.
extern "C" int Script_ClearActorBoundObject(void* parameter) {
    int index = Script_ReadParameterAsInteger(parameter);
    unsigned** container = (unsigned**)ActorPool_GetGlobalInstance();
    unsigned* entries = *(unsigned**)((char*)&EventGetObjectSession_UnknownRoleZeroInitializedStorage + 4);
    unsigned key = *(unsigned*)((char*)entries + index * 16 + 4);
    unsigned* slot = ActorPool_GetActiveSlot(container, key);
    if (!slot)
        return 0;
    slot[4] = 0;
    return 1;
}
