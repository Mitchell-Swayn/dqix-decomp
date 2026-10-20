#include <globaldefs.h>
ARM
// Original data: arm9/ov004 @ 0x21707d8; symbol: data_ov004_021707d8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" unsigned char MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage[];
extern "C" void Menu_PositionDecimalDigitSelectionMarkers(void *);
// Original: arm9/ov004 @ 0x0215CC84; symbol: func_ov004_0215cc84; size: 0x2C.
extern "C" int Menu_SelectPreviousListingPriceDigit(void *argument) {
    unsigned char *object = *(unsigned char **)(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage + 8);
    if (object[0x3E] != 0)
        --object[0x3E];
    Menu_PositionDecimalDigitSelectionMarkers(argument);
    return 0;
}
