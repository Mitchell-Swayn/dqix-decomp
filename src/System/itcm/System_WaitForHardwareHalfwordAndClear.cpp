#include <globaldefs.h>
ARM

// Original data: arm9/main @ 0x2111668; symbol: data_02111668.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" volatile unsigned short SystemHandleResetHandshakeReply_UnknownRoleZeroInitializedStorage;
extern "C" void OSi_ReloadRomData(void);
extern "C" void OSi_DoBoot(void);

// Original: arm9/itcm @ 0x01FF81E4; symbol: func_01ff81e4; size: 0x34.
extern "C" void System_WaitForHardwareHalfwordAndClear(void) {
    while (SystemHandleResetHandshakeReply_UnknownRoleZeroInitializedStorage == 0) {
    }
    *(volatile unsigned short *)0x04000208 = 0;
    OSi_ReloadRomData();
    OSi_DoBoot();
}
