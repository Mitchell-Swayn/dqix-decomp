#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290ca0; symbol: data_ov031_02290ca0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned StartMode6ContextCallback_UnknownRoleZeroInitializedStorage;
extern "C" void WfcSettingsList_RedrawVisibleRows(void);
// Original: arm9/ov031 @ 0x02230CD8; symbol: func_ov031_02230cd8; size: 0x54.
extern "C" void WfcSettingsList_TickOptionFlashTimers(void*,void*) {
    int i = 0;
    do {
        unsigned char* count = *(unsigned char**)((char*)&StartMode6ContextCallback_UnknownRoleZeroInitializedStorage + 8) + i + 4;
        if (*count != 0) {
            *count = *count - 1;
            if (*(*(unsigned char**)((char*)&StartMode6ContextCallback_UnknownRoleZeroInitializedStorage + 8) + i + 4) == 0)
                WfcSettingsList_RedrawVisibleRows();
        }
        ++i;
    } while (i < 4);
}
