#include <globaldefs.h>
ARM
extern "C" void Network_UnlinkNodeAndReleaseRecords(void*);
// Original data: arm9/ov031 @ 0x2250bf0; symbol: data_ov031_02250bf0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" void** OverlayClearFourSharedObjects_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x022238CC; symbol: func_ov031_022238cc; size: 0x40.
extern "C" void Overlay_ClearFourSharedObjects(void) {
    int i = 0;
    do {
        void* object = OverlayClearFourSharedObjects_UnknownRoleZeroInitializedStorage[i];
        if (object != 0) {
            Network_UnlinkNodeAndReleaseRecords(object);
            OverlayClearFourSharedObjects_UnknownRoleZeroInitializedStorage[i] = 0;
        }
        ++i;
    } while (i < 4);
}
