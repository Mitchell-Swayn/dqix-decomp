#include <globaldefs.h>
ARM
extern "C" void _Z28SetSpecificInterruptsEnabledj(unsigned int);
extern "C" void _Z19SetInterruptHandlerjPKv(unsigned int, const void*);
// Original data: arm9/ov031 @ 0x2290d58; symbol: data_ov031_02290d58.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned int Ov031InstallVBlankInterrupt_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x0223D7F4; symbol: func_ov031_0223d7f4; size: 0x3C.
extern "C" void System_DisableGlobalInterruptsAndInstallInterruptOneHandler(void) {
    unsigned short previous = *(volatile unsigned short*)0x04000208;
    (void)previous;
    *(volatile unsigned short*)0x04000208 = 0;
    _Z28SetSpecificInterruptsEnabledj(*(unsigned int*)((char*)&Ov031InstallVBlankInterrupt_UnknownRoleZeroInitializedStorage + 4));
    _Z19SetInterruptHandlerjPKv(1, (const void*)Ov031InstallVBlankInterrupt_UnknownRoleZeroInitializedStorage);
}
