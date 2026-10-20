#include <globaldefs.h>
ARM
extern "C" void Wireless_ClearDownloadSessionPacketBuffers(void);
extern "C" void WirelessHost_SetChildConnectionFilter(unsigned);
extern "C" void Wireless_AssociateMultibootChildWithConnection(void);
// Original data: arm9/ov031 @ 0x2290d20; symbol: data_ov031_02290d20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned *Ov031AdvanceContextFromFive_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x0223ADF0; symbol: System_InitializeModeEightCallback; size: 0x2C.
// Runs setup, registers callback 0x0223b040, then stores mode 8 in the shared state byte at +0xa90.
extern "C" void System_InitializeModeEightCallback(void) {
    Wireless_ClearDownloadSessionPacketBuffers();
    WirelessHost_SetChildConnectionFilter((unsigned)Wireless_AssociateMultibootChildWithConnection);
    *((unsigned char *)Ov031AdvanceContextFromFive_UnknownRoleZeroInitializedStorage + 0xa90) = 8;
}
