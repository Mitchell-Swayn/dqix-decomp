#include <globaldefs.h>
ARM
// Original: arm9/ov004:0215cc58; Increments the global record byte at +0x3e up to six, invokes a helper with the original argument, and returns zero.
// Original data: arm9/ov004 @ 0x21707d8; symbol: data_ov004_021707d8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" unsigned char MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage;
extern "C" void Menu_PositionDecimalDigitSelectionMarkers(void *);
extern "C" int Menu_SelectNextListingPriceDigit(void *arg) {
    unsigned char *record = *(unsigned char **)((unsigned char *)&MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage + 8);
    if (record[0x3e] < 6) ++record[0x3e];
    Menu_PositionDecimalDigitSelectionMarkers(arg);
    return 0;
}
