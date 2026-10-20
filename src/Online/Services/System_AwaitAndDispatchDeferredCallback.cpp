#include <globaldefs.h>
ARM

struct ProcessorContext;
extern "C" void _Z22AwaitContextCompletionP16ProcessorContext(ProcessorContext *context);
extern "C" void DownloadService_Free();
// Original data: arm9/ov031 @ 0x224e5c0; symbol: data_ov031_0224e5c0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" ProcessorContext *DownloadServiceReportStatus_UnknownRoleZeroInitializedStorage;

// Original: arm9/ov031 @ 0x022128B8; symbol: func_ov031_022128b8; size: 0x44.
extern "C" void System_AwaitAndDispatchDeferredCallback(void) {
    ProcessorContext *context = DownloadServiceReportStatus_UnknownRoleZeroInitializedStorage;
    _Z22AwaitContextCompletionP16ProcessorContext((ProcessorContext *)((char *)context + 0x9c0));
    context = DownloadServiceReportStatus_UnknownRoleZeroInitializedStorage;
    void (*callback)(void) = *(void (**)(void))((char *)context + 4);
    DownloadService_Free();
    DownloadServiceReportStatus_UnknownRoleZeroInitializedStorage = 0;
    if (callback != 0) callback();
}
