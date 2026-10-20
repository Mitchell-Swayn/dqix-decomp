#include <globaldefs.h>
extern "C" unsigned Network_GetWirelessWorkspace();
extern "C" int Network_AcquireItcmTokenReference(void *);
extern "C" int WM_SetDCFData(int, const void *, void *, unsigned);
extern "C" void Ov031_DecrementBlockedContextCount(char *);
// Original data: arm9/ov031 @ 0x224e54c; symbol: data_ov031_0224e54c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char NetworkSendEmptyDcfFrame_UnknownRoleZeroInitializedStorage[];
extern "C" void Network_ReleaseDcfTransmitToken();
// Original: arm9/ov031 @ 0x0220EFD0; symbol: func_ov031_0220efd0; size: 0x70.
extern "C" void Network_SendEmptyDcfFrame(void) {
    unsigned char *shared = (unsigned char *)Network_GetWirelessWorkspace();
    if (!shared) return;
    if (*(unsigned *)(shared + 0x2260) != 9) return;
    if (shared[0x226b] == 1) return;
    if (!Network_AcquireItcmTokenReference(NetworkSendEmptyDcfFrame_UnknownRoleZeroInitializedStorage)) return;
    int status = WM_SetDCFData((int)Network_ReleaseDcfTransmitToken, shared + 0x2144, shared + 0xf00, 0);
    if (status != 2) Ov031_DecrementBlockedContextCount((char *)NetworkSendEmptyDcfFrame_UnknownRoleZeroInitializedStorage);
}
