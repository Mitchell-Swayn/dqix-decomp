#include <globaldefs.h>
ARM
// Original data: arm9/ov004 @ 0x21707d8; symbol: data_ov004_021707d8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern unsigned char MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage[];
struct State;
extern "C" void Menu_QueueScriptEntry(State *self, unsigned value);
// Original: arm9/ov004 @ 0x0215D6F8; symbol: func_ov004_0215d6f8; size: 0x40.
extern "C" int Menu_ShowPurchaseQuantityPrompt(State *self) {
    void *object = *(void **)(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage + 8);
    if (*((unsigned char *)object + 0x11) == 1) {
        Menu_QueueScriptEntry(self, 0x236A);
    } else {
        Menu_QueueScriptEntry(self, 0x38A);
    }
    return 0;
}
