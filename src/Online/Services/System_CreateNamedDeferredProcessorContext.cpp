#include <globaldefs.h>
ARM
extern "C" int OnlineError_IsSet(void *, void *, void *);
extern "C" int System_TryInitializeNamedRecord(const char *, void *);
extern "C" void *DownloadService_Allocate(unsigned, unsigned);
extern "C" void DownloadService_Free(int);
extern "C" void VectorizedMemset(void *, int, unsigned);
extern "C" char *strncpy(char *, const char *, unsigned);
extern "C" int System_TryInitializeNamedRecord(const char *, void *);
extern "C" void _Z24PopulateProcessorContextP16ProcessorContextjjjjj(void *, unsigned, unsigned, unsigned, unsigned, unsigned);
extern "C" void _Z25MarkContextReadyAndSwitchP16ProcessorContext(void *);
// Original data: arm9/ov031 @ 0x224e5c0; symbol: data_ov031_0224e5c0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char *DownloadServiceReportStatus_UnknownRoleZeroInitializedStorage;
extern "C" char System_CreateNamedDeferredProcessorContext_Text9000[];
extern "C" void DownloadService_InitializeAfterLookup(void);
// Original: arm9/ov031 @ 0x02212AB4; symbol: System_CreateNamedDeferredProcessorContext; size: 0x118.
extern "C" int System_CreateNamedDeferredProcessorContext(void *owner, const char *firstName, const char *secondName) {
    if (OnlineError_IsSet(owner, (void *)firstName, (void *)secondName)) return 0;
    DownloadServiceReportStatus_UnknownRoleZeroInitializedStorage = (unsigned char *)DownloadService_Allocate(0xa80, 0x20);
    *(int *)(DownloadServiceReportStatus_UnknownRoleZeroInitializedStorage + 0x48) = 0;
    VectorizedMemset(DownloadServiceReportStatus_UnknownRoleZeroInitializedStorage, 0, 0xa80);
    *(void **)DownloadServiceReportStatus_UnknownRoleZeroInitializedStorage = owner;
    strncpy((char *)DownloadServiceReportStatus_UnknownRoleZeroInitializedStorage + 8, (const char *)firstName, 0x1f);
    strncpy((char *)DownloadServiceReportStatus_UnknownRoleZeroInitializedStorage + 0x28, (const char *)secondName, 0x1f);
    if (System_TryInitializeNamedRecord(System_CreateNamedDeferredProcessorContext_Text9000, DownloadServiceReportStatus_UnknownRoleZeroInitializedStorage + 0x4c) == 0) {
        DownloadService_Free((int)DownloadServiceReportStatus_UnknownRoleZeroInitializedStorage);
        DownloadServiceReportStatus_UnknownRoleZeroInitializedStorage = 0;
        return 0;
    }
    _Z24PopulateProcessorContextP16ProcessorContextjjjjj(DownloadServiceReportStatus_UnknownRoleZeroInitializedStorage + 0x9c0, (unsigned)DownloadService_InitializeAfterLookup, 0, (unsigned)(DownloadServiceReportStatus_UnknownRoleZeroInitializedStorage + 0x9c0), 0x800, 0x10);
    _Z25MarkContextReadyAndSwitchP16ProcessorContext(DownloadServiceReportStatus_UnknownRoleZeroInitializedStorage + 0x9c0);
    return 1;
}
