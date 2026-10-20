#include <globaldefs.h>
ARM

extern "C" void DlcDownload_FreeAttributeStrings(void);
extern "C" void DlcDownload_FinalizeRequestHandleMutex(void);
extern "C" void NasAuth_FinalizeRequestSynchronization(void);
// Original data: arm9/ov031 @ 0x2290da0; symbol: data_ov031_02290da0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char DlcDownloadShutdownClient_UnknownRoleZeroInitializedStorage[];

// Original: arm9/ov031 @ 0x0223E868; symbol: func_ov031_0223e868; size: 0x44.
extern "C" void DlcDownload_ShutdownClient(void) {
    DlcDownload_FreeAttributeStrings();
    DlcDownload_FinalizeRequestHandleMutex();
    NasAuth_FinalizeRequestSynchronization();
    ((void (*)(void *))(*(void **)(DlcDownloadShutdownClient_UnknownRoleZeroInitializedStorage + 0x20)))(*(void **)(DlcDownloadShutdownClient_UnknownRoleZeroInitializedStorage + 8));
    ((void (*)(void *))(*(void **)(DlcDownloadShutdownClient_UnknownRoleZeroInitializedStorage + 0x20)))(*(void **)(DlcDownloadShutdownClient_UnknownRoleZeroInitializedStorage + 0x10));
    ((void (*)(void))(*(void **)DlcDownloadShutdownClient_UnknownRoleZeroInitializedStorage))();
}
