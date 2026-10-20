#include <globaldefs.h>
ARM
// Original data: arm9/ov004 @ 0x2171010; symbol: data_ov004_02171010.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" unsigned *PopulateSelectedRecordTextPanel_UnknownRoleZeroInitializedStorage;
extern "C" void Menu_QueueScriptEntry(void *self, unsigned value);
// Original: arm9/ov004 @ 0x0216583C; symbol: Unclassified_SetGlobalFlagAndDispatchState65; size: 0x2C.
// Sets the global byte at +0x18FD to one, calls the state helper with value 0x65, then returns zero.
extern "C" unsigned TreasureMapMenu_ReturnToSelectionAndSuppressDetailRefresh(void *self) {
    *((unsigned char *)PopulateSelectedRecordTextPanel_UnknownRoleZeroInitializedStorage + 0x18fd) = 1;
    Menu_QueueScriptEntry(self, 0x65);
    return 0;
}
