#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290d20; symbol: data_ov031_02290d20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned *Ov031AdvanceContextFromFive_UnknownRoleZeroInitializedStorage;
extern "C" void Multiboot_InitializeParentAndInstallEventCallback(void *, unsigned, void *);
// Original: arm9/ov031 @ 0x0223AC14; symbol: Network_ApplyHardwareConfigurationFromGlobalState; size: 0x24.
// Loads a global object hardware-configuration pointer and selector, then passes them with the object to the hardware configuration routine.
extern "C" void Network_ApplyHardwareConfigurationFromGlobalState(void) {
    char *base = (char *)Ov031AdvanceContextFromFive_UnknownRoleZeroInitializedStorage;
    Multiboot_InitializeParentAndInstallEventCallback(*(void **)(base + 0xac8), *(unsigned short *)(base + 0x648), base);
}
