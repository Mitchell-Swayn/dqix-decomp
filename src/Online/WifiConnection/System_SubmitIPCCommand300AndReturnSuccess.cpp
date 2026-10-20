#include <globaldefs.h>
ARM
extern "C" int Network_SendIpcCommandAndInvalidateResponse(void *, unsigned int, unsigned int);
// Original data: arm9/ov031 @ 0x224e6a0; symbol: data_ov031_0224e6a0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern unsigned int WfcUtilityReadFourSettingsPages_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x0221ADD4; symbol: System_SubmitIPCCommand300AndReturnSuccess; size: 0x2C.
// Submits IPC command 0x300 using the shared global endpoint and input value; normalizes the result to a boolean.
extern "C" int System_SubmitIPCCommand300AndReturnSuccess(unsigned int value) {
    return Network_SendIpcCommandAndInvalidateResponse((void *)WfcUtilityReadFourSettingsPages_UnknownRoleZeroInitializedStorage[2], 0x300, value) != 0;
}
