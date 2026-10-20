#include <globaldefs.h>
ARM
extern "C" void Menu_QueueScriptEntry(void* self, unsigned value);
// Original data: arm9/ov004 @ 0x21707d8; symbol: data_ov004_021707d8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" char MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov004 @ 0x0215AFF0; symbol: func_ov004_0215aff0; size: 0x3C.
extern "C" int GameState_ApplyModeSpecificState(void* self) {
    if (*((unsigned char*)(*(char**)(&MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage + 8)) + 0x6e) == 1)
        Menu_QueueScriptEntry(self, 0x39c);
    else
        Menu_QueueScriptEntry(self, 0x39b);
    return 0;
}
