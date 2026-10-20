#include <globaldefs.h>
extern "C" unsigned _Z19GetInterruptHandlerj(unsigned);
extern "C" void _Z28SetSpecificInterruptsEnabledj(unsigned);
extern "C" void _Z24EnableSpecificInterruptsj(unsigned);
extern "C" void _Z19SetInterruptHandlerjPKv(unsigned, const void*);
extern "C" void _Z29AcknowledgeSpecificInterruptsj(unsigned);
extern "C" void _Z19EnableIRQInterruptsv();
// Original data: arm9/ov031 @ 0x2290d58; symbol: data_ov031_02290d58.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char Ov031InstallVBlankInterrupt_UnknownRoleZeroInitializedStorage[];
extern "C" void WfcUtility_RunMainTasksAndSignalControl();
// Original: arm9/ov031 @ 0x0223D780; symbol: func_ov031_0223d780; size: 0x74.
extern "C" ARM void Ov031_InstallVBlankInterrupt() {
    *(unsigned int*)(Ov031InstallVBlankInterrupt_UnknownRoleZeroInitializedStorage + 4) = *(volatile unsigned int*)0x04000210;
    _Z28SetSpecificInterruptsEnabledj(0x40018);
    _Z24EnableSpecificInterruptsj(1);
    *(unsigned int*)Ov031InstallVBlankInterrupt_UnknownRoleZeroInitializedStorage = _Z19GetInterruptHandlerj(1);
    _Z19SetInterruptHandlerjPKv(1, (const void*)WfcUtility_RunMainTasksAndSignalControl);
    _Z29AcknowledgeSpecificInterruptsj(1);
    (void)*(volatile unsigned short*)0x04000208;
    *(volatile unsigned short*)0x04000208 = 1;
    _Z19EnableIRQInterruptsv();
}
