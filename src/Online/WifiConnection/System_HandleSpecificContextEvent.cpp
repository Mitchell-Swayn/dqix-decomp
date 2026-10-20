#include <globaldefs.h>
ARM

extern "C" void Network_SetWirelessStateAndConnectionAlarm(int);
extern "C" void StartSharedWirelessTransition(void);
// Original data: arm9/ov031 @ 0x224e53c; symbol: data_ov031_0224e53c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage[];

// Original: arm9/ov031 @ 0x0220DBC8; symbol: func_ov031_0220dbc8; size: 0x78.
extern "C" void System_HandleSpecificContextEvent(const unsigned short *message) {
    if (message[1] != 8 || message[2] != 0x16 || message[3] != 0x25) {
        return;
    }
    unsigned int state = *(unsigned int *)((char *)*(void **)NetworkHandleEndDcfResult_UnknownRoleZeroInitializedStorage + 0x2260);
    switch (state) {
    case 8:
        Network_SetWirelessStateAndConnectionAlarm(12);
        break;
    case 9:
    case 12:
        StartSharedWirelessTransition();
        break;
    case 10:
        Network_SetWirelessStateAndConnectionAlarm(12);
        break;
    default:
        break;
    }
}
