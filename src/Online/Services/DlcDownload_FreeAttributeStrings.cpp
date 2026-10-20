#include <globaldefs.h>
ARM

// Original data: arm9/ov031 @ 0x2290dc8; symbol: data_ov031_02290dc8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" void *DlcDownloadFreeAttributeStrings_UnknownRoleZeroInitializedStorage[3];
// Original data: arm9/ov031 @ 0x2290dc0; symbol: data_ov031_02290dc0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" void (*DlcDownloadRequestFileList_UnknownRoleZeroInitializedStorage_Variant3)(void *);

// Original: arm9/ov031 @ 0x0223E348; symbol: func_ov031_0223e348; size: 0x44.
extern "C" void DlcDownload_FreeAttributeStrings(void) {
    int i = 0;
    do {
        void *pending = DlcDownloadFreeAttributeStrings_UnknownRoleZeroInitializedStorage[i];
        if (pending != 0) {
            DlcDownloadRequestFileList_UnknownRoleZeroInitializedStorage_Variant3(pending);
            DlcDownloadFreeAttributeStrings_UnknownRoleZeroInitializedStorage[i] = 0;
        }
    } while (++i < 3);
}
