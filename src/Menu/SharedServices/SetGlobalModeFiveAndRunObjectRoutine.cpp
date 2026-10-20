#include <globaldefs.h>
ARM
// Original data: arm9/ov004 @ 0x21707d8; symbol: data_ov004_021707d8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" unsigned char MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage[];
extern "C" void Menu_PositionDecimalDigitSelectionMarkers(void *object);
// Original: arm9/ov004 @ 0x0215CD64; symbol: func_ov004_0215cd64; size: 0x24.
extern "C" int SetGlobalModeFiveAndRunObjectRoutine(void *object) {
    unsigned char *global = *(unsigned char **)(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage + 8);
    global[0x3e] = 5;
    Menu_PositionDecimalDigitSelectionMarkers(object);
    return 0;
}
