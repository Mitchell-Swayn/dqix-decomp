#include <globaldefs.h>
// Original data: arm9/ov031 @ 0x2290d20; symbol: data_ov031_02290d20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char Ov031AdvanceContextFromFive_UnknownRoleZeroInitializedStorage[];
extern "C" void Multiboot_RequestBootForEligibleChildren();
// Original: arm9/ov031 @ 0x0223A760; symbol: func_ov031_0223a760; size: 0x34.
extern "C" ARM int Ov031_AdvanceContextFromFive() {
    unsigned char* context = *(unsigned char**)Ov031AdvanceContextFromFive_UnknownRoleZeroInitializedStorage;
    if (context[0xa90] != 5) return 0;
    context[0xa90] = 6;
    Multiboot_RequestBootForEligibleChildren();
    return 1;
}
