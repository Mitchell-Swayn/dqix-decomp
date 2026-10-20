#include <globaldefs.h>
ARM
struct GlobalObjectRef { unsigned char pad[8]; void *object; };
// Original data: arm9/ov004 @ 0x21707d8; symbol: data_ov004_021707d8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" GlobalObjectRef MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage;
extern "C" void Menu_PositionDecimalDigitSelectionMarkers(void *argument);
// Original: arm9/ov004 @ 0x0215CCF8; symbol: func_ov004_0215ccf8; size: 0x24.
extern "C" int Menu_SelectHundredsDigit(void *argument) {
    *((unsigned char *)MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage.object + 0x3e) = 2;
    Menu_PositionDecimalDigitSelectionMarkers(argument);
    return 0;
}
