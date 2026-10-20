#include <globaldefs.h>
ARM
extern "C" double Runtime_ComputeDoublePower(double, double);
struct State;
extern "C" void Menu_QueueScriptEntry(State* self, unsigned value);
// Original data: arm9/ov004 @ 0x21707d8; symbol: data_ov004_021707d8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" volatile unsigned MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov004 @ 0x0215ADF8; symbol: func_ov004_0215adf8; size: 0xB0.
extern "C" int Menu_CommitListingPriceDigits(State *self) {
    *(int *)(((char *)MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage[2]) + 0x78) = 0;
    for (int i = 0; i < 7; ++i) {
        int place = (int)Runtime_ComputeDoublePower(10.0, (double)i);
        char *record = ((char *)MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage[2]);
        *(int *)(record + 0x78) += place * *(signed char *)(record + i + 0x3f);
    }
    *(unsigned char *)(((char *)MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage[2]) + 0x6e) = 1;
    if (*(unsigned char *)(((char *)MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage[2]) + 0x6f) == 1) Menu_QueueScriptEntry(self, 0x39c);
    else Menu_QueueScriptEntry(self, 0x6d);
    return 0;
}
