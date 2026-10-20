#include <globaldefs.h>
#pragma optimize_for_size off

// Original data: arm9/main @ 0x2112140; symbol: data_02112140.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned int CardReadManagerReadGlobalStatus_UnknownRoleZeroInitializedStorage[];
extern "C" void DisableInterruptsAndHaltForever(void);
extern "C" void ResetDMAAndProcessSharedHardwareStatus(void);

// Original: arm9/main @ 0x020D1144; symbol: func_020d1144; size: 0x54.
extern "C" void IPC_HandleCommandSeventeenOnceAndInvokeCallback(unsigned int, unsigned int command, unsigned int)
{
    if ((command & 0x3f) == 0x11) {
    if (CardReadManagerReadGlobalStatus_UnknownRoleZeroInitializedStorage[0] != 0) return;
    CardReadManagerReadGlobalStatus_UnknownRoleZeroInitializedStorage[0] = 1;
    int result = 1;
    if (CardReadManagerReadGlobalStatus_UnknownRoleZeroInitializedStorage[1] != 0) {
        result = ((int (*)())CardReadManagerReadGlobalStatus_UnknownRoleZeroInitializedStorage[1])();
    }
    if (result != 0) ResetDMAAndProcessSharedHardwareStatus();
    } else {
        DisableInterruptsAndHaltForever();
    }
}
