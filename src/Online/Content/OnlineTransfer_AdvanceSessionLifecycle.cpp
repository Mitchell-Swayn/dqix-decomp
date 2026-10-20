#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x224c8a8; symbol: data_ov031_0224c8a8.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex c0362402e03624020837240214372402000000006400000008302402650000001030240267000000483324020000000000000000.
// Observed span: 52 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern unsigned int OnlineTransferAdvanceSessionLifecycle_UnknownRoleProcedureReferenceRecords[];
// Original: arm9/ov031 @ 0x02243690; symbol: func_ov031_02243690; size: 0x30.
extern "C" int OnlineTransfer_AdvanceSessionLifecycle(unsigned char *object) {
    int index = (signed char)object[0x2c];
    if (index >= 0) {
        int (*callback)(unsigned char *) = (int (*)(unsigned char *))OnlineTransferAdvanceSessionLifecycle_UnknownRoleProcedureReferenceRecords[index];
        object[0x2c] = (unsigned char)callback(object);
    }
    return 1;
}
