#include <globaldefs.h>
ARM
extern "C" void Http_DestroyRequestAndResponse(void *);
extern "C" void NasAuth_ReleaseRequestProcessingGuard(void);
// Original data: arm9/ov031 @ 0x2290dc0; symbol: data_ov031_02290dc0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char DlcDownloadRequestFileList_UnknownRoleZeroInitializedStorage_Variant3[];
// Original: arm9/ov031 @ 0x0223EDB4; symbol: func_ov031_0223edb4; size: 0x2C.
extern "C" void DlcDownload_DestroyUnsubmittedRequest(void *state, void *object) {
    Http_DestroyRequestAndResponse(object);
    NasAuth_ReleaseRequestProcessingGuard();
    ((void (*)(void *))(*(void **)DlcDownloadRequestFileList_UnknownRoleZeroInitializedStorage_Variant3))(state);
}
