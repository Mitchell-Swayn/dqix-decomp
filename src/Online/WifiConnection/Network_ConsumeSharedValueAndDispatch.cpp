#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x224e53c; symbol: data_ov031_0224e53c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned int NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage;
extern "C" void Network_NotifyWirelessEvent(int, int, int, int, int);
// Original: arm9/ov031 @ 0x0220D984; symbol: Network_ConsumeSharedValueAndDispatch; size: 0x44.
// Consumes and clears the signed halfword at shared pointer+0x2280, then forwards it with four arguments.
extern "C" void Network_ConsumeSharedValueAndDispatch(int a, int b, int c, int d) {
    signed short *selected = (signed short *)((unsigned char *)*(void **)&NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage + 0x2280);
    int value = *selected;
    *selected = 0;
    Network_NotifyWirelessEvent(value, a, b, c, d);
}
