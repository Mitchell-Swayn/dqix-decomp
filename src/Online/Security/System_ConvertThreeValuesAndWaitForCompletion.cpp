#include <globaldefs.h>
THUMB
extern "C" int WirelessSetup_EncodeNetworkWord(int);
extern "C" ARM int Network_ConfigureSharedWorkWithSwappedWords(void*);
extern "C" ARM void _Z19SleepCurrentContextj(unsigned);
// Original data: arm9/ov031 @ 0x224b070; symbol: data_ov031_0224b070.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffffffffffffffff.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned int AossRunSetupNegotiation_UnknownRoleInitializedBytes_Variant2[];
// Original data: arm9/ov031 @ 0x224b078; symbol: data_ov031_0224b078.
// Contains original relocated data addresses. Referenced targets and raw storage values are recorded; semantic role and record layout remain unresolved.
// Initial values: hex 0000000159e4210271e4210200000000000000000000000000000000000000000000000000100000001000000000000000000000000000000000000000000000 ...; full span in module reference.
// Observed span: 88 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned int SystemConvertThreeValuesAndWaitForCompletion_UnknownRoleDataReferences;
// Original data: arm9/ov031 @ 0x224c9d0; symbol: data_ov031_0224c9d0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned int NetworkCleanupSocketStack_UnknownRoleZeroInitializedStorage;
THUMB
// Original: arm9/ov031 @ 0x0221E480; symbol: System_ConvertThreeValuesAndWaitForCompletion; size: 0x58.
// Converts three input values into global slots, starts the operation, returns -1 on failure, and otherwise sleeps until the completion word becomes nonzero.
extern "C" int System_ConvertThreeValuesAndWaitForCompletion(int first, int second, int third) {
    AossRunSetupNegotiation_UnknownRoleInitializedBytes_Variant2[6] = WirelessSetup_EncodeNetworkWord(first);
    AossRunSetupNegotiation_UnknownRoleInitializedBytes_Variant2[7] = WirelessSetup_EncodeNetworkWord(second);
    AossRunSetupNegotiation_UnknownRoleInitializedBytes_Variant2[8] = WirelessSetup_EncodeNetworkWord(third);
    int result = Network_ConfigureSharedWorkWithSwappedWords(&SystemConvertThreeValuesAndWaitForCompletion_UnknownRoleDataReferences);
    if (result < 0) return -1;
    if (NetworkCleanupSocketStack_UnknownRoleZeroInitializedStorage == 0) {
        do {
            _Z19SleepCurrentContextj(100);
        } while (NetworkCleanupSocketStack_UnknownRoleZeroInitializedStorage == 0);
    }
    return 0;
}
