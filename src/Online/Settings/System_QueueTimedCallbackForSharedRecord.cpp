#include <globaldefs.h>
ARM

extern "C" void *WfcUtility_CreateTaskWithBorrowedContext(unsigned, void (*)(void), void *, unsigned);
extern "C" void WfcUtility_AdvanceScreenTransitionDelay(void);
// Original data: arm9/ov031 @ 0x2290d34; symbol: data_ov031_02290d34.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char *WfcUtilityIsScreenTransitionBusy_UnknownRoleZeroInitializedStorage;

// Original: arm9/ov031 @ 0x0223C278; symbol: func_ov031_0223c278; size: 0x58.
extern "C" int System_QueueTimedCallbackForSharedRecord(unsigned short value) {
    unsigned char *record = WfcUtilityIsScreenTransitionBusy_UnknownRoleZeroInitializedStorage;
    if (record[9] != 0) {
        return 0;
    }
    *(void **)record = WfcUtility_CreateTaskWithBorrowedContext(1, WfcUtility_AdvanceScreenTransitionDelay, record, 0xC8);
    *(unsigned short *)(record + 4) = 0;
    *(unsigned short *)(record + 6) = value;
    record[9] = 1;
    return 1;
}
