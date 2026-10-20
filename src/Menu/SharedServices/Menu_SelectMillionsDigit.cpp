#include <globaldefs.h>
ARM
// Original data: arm9/ov004 @ 0x21707d8; symbol: data_ov004_021707d8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" unsigned char MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage[];
extern "C" void Menu_PositionDecimalDigitSelectionMarkers(void *);
// Original: arm9/ov004 @ 0x0215CD88; symbol: func_ov004_0215cd88; size: 0x24.
extern "C" int Menu_SelectMillionsDigit(void *argument) {
    void *object = *(void **)(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage + 8);
    *(unsigned char *)((unsigned char *)object + 0x3E) = 6;
    Menu_PositionDecimalDigitSelectionMarkers(argument);
    return 0;
}
