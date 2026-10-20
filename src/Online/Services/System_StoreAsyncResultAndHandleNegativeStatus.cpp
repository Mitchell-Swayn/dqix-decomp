#include <globaldefs.h>
extern "C" void System_LockSharedMutex();
extern "C" int Network_ActivateContextUnderMutex(unsigned);
extern "C" void NasAuth_UnlockRequestMutex();
extern "C" void DlcDownload_DestroyUnsubmittedRequest(void*, unsigned);
// Original data: arm9/ov031 @ 0x2290dc4; symbol: data_ov031_02290dc4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" int DlcDownloadHandleHttpCompletion_UnknownRoleZeroInitializedStorage;
// Original data: arm9/ov031 @ 0x2290dbc; symbol: data_ov031_02290dbc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" int DlcDownloadRequestFileList_UnknownRoleZeroInitializedStorage_Variant2;
// Original: arm9/ov031 @ 0x0223F188; symbol: func_ov031_0223f188; size: 0x60.
extern "C" int System_StoreAsyncResultAndHandleNegativeStatus(int* output, unsigned argument) {
    System_LockSharedMutex();
    int result = Network_ActivateContextUnderMutex(argument);
    *output = result;
    DlcDownloadHandleHttpCompletion_UnknownRoleZeroInitializedStorage = result;
    NasAuth_UnlockRequestMutex();
    if (*output >= 0) return 1;
    DlcDownload_DestroyUnsubmittedRequest(output, argument);
    DlcDownloadRequestFileList_UnknownRoleZeroInitializedStorage_Variant2 = 3;
    return 0;
}
