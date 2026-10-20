#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290d14; symbol: data_ov031_02290d14.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char MultibootGetParentState_UnknownRoleZeroInitializedStorage[];
extern "C" void MB_End(void);
// Original: arm9/ov031 @ 0x02238DB4; symbol: func_ov031_02238db4; size: 0x30.
extern "C" void System_ProcessMatchingGlobalRecord(void) {
    unsigned short *record = *(unsigned short **)MultibootGetParentState_UnknownRoleZeroInitializedStorage;
    if (record[0] == 4 && record[1] == record[6])
        MB_End();
}
