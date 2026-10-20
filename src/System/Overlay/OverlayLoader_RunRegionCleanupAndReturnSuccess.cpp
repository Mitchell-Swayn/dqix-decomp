#include <globaldefs.h>
#include <Filesystem/OverlayFSManagement.h>

extern "C" void Runtime_RunCleanupCallbacksForMemoryRegion(const OverlayMetadata*);

// Original: arm9/main @ 0x020CD584; symbol: func_020cd584; size: 0x10.
extern "C" ARM int OverlayLoader_RunRegionCleanupAndReturnSuccess(const OverlayMetadata* overlay) {
    Runtime_RunCleanupCallbacksForMemoryRegion(overlay);
    return 1;
}
