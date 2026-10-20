#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290d0c; symbol: data_ov031_02290d0c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" void *WirelessInitializeUsbAccessPointScan_UnknownRoleZeroInitializedStorage;
extern "C" int Network_StartExtendedScan(void *, void *);
extern "C" int Wireless_HandleUsbAccessPointScanEvent(void);
// Original: arm9/ov031 @ 0x022375CC; symbol: func_ov031_022375cc; size: 0x34.
extern "C" int CheckCurrentContextStatus(void) {
    return Network_StartExtendedScan((void *)Wireless_HandleUsbAccessPointScanEvent,
                         (unsigned char *)WirelessInitializeUsbAccessPointScan_UnknownRoleZeroInitializedStorage + 0x1374) == 2;
}
