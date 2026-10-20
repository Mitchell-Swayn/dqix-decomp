#include <globaldefs.h>
ARM
// Original data: arm9/ov027 @ 0x21e33ec; symbol: data_ov027_021e33ec.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov027.md.
extern unsigned char *MBRegisterFile_UnknownRoleZeroInitializedStorage_Variant2;
extern "C" int _Z20DisableIRQInterruptsv(void);
extern "C" int _Z20SetIRQInterruptStatei(int);
// Original: arm9/ov027 @ 0x021D8A40; symbol: func_ov027_021d8a40; size: 0x28.
extern "C" void Network_SetParentStateCallback(void *callback) {
    int irqState = _Z20DisableIRQInterruptsv();
    unsigned char *communication = MBRegisterFile_UnknownRoleZeroInitializedStorage_Variant2;
    *(void **)(communication + 0x14e4) = callback;
    _Z20SetIRQInterruptStatei(irqState);
}
