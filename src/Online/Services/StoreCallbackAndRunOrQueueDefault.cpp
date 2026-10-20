#include <globaldefs.h>
ARM
extern "C" void System_AwaitAndDispatchDeferredCallback(void);
extern "C" void System_RegisterCallbackWithGlobalValue(void*);
// Original data: arm9/ov031 @ 0x224e5c0; symbol: data_ov031_0224e5c0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned int DownloadServiceReportStatus_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x02212BCC; symbol: StoreCallbackAndRunOrQueueDefault; size: 0x4C.
// Stores the callback on the global object; directly runs the default routine when object +0x48 is null, otherwise queues it.
extern "C" int StoreCallbackAndRunOrQueueDefault(void* callback) {
    if (!*(void**)&DownloadServiceReportStatus_UnknownRoleZeroInitializedStorage) return 0;
    *(void**)(*(char**)&DownloadServiceReportStatus_UnknownRoleZeroInitializedStorage + 4) = callback;
    if (!*(void**)(*(char**)&DownloadServiceReportStatus_UnknownRoleZeroInitializedStorage + 0x48)) System_AwaitAndDispatchDeferredCallback();
    else System_RegisterCallbackWithGlobalValue((void*)System_AwaitAndDispatchDeferredCallback);
    return 1;
}
