#include <globaldefs.h>
ARM
#pragma optimize_for_size off
extern "C" int Aoss_ValidateAndRunSetup(unsigned char*);
// Original data: arm9/ov031 @ 0x2250c04; symbol: data_ov031_02250c04.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WfcUtilityInitializeNetworkRequest_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x02226F68; symbol: func_ov031_02226f68; size: 0x60.
// Marks successful processing and returns 1; otherwise maps request states 1 and 3..5 to 0, and all other states to 2.
extern "C" int WfcUtility_ProcessNetworkRequestAndClassifyResult() {
    if (Aoss_ValidateAndRunSetup(*(unsigned char**)(WfcUtilityInitializeNetworkRequest_UnknownRoleZeroInitializedStorage+4))==0) {
        WfcUtilityInitializeNetworkRequest_UnknownRoleZeroInitializedStorage[0]=1;
        return 1;
    }
    unsigned char status=(*(unsigned char**)(WfcUtilityInitializeNetworkRequest_UnknownRoleZeroInitializedStorage+4))[0x116];
    if (status==1 || (unsigned char)(status+253)<=2) return 0;
    return 2;
}
