#include <globaldefs.h>
THUMB
#include <std_library_functions.h>
// Original data: arm9/ov031 @ 0x224f7dc; symbol: data_ov031_0224f7dc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WirelessSetupStartConfigurationWorker_UnknownRoleZeroInitializedStorage_Variant2[];

// Original: arm9/ov031 @ 0x02222ADC; symbol: func_ov031_02222adc; size: 0x14.
extern "C" int WirelessSetup_CopyReceivedConfiguration(void *destination) {
    memcpy(destination, WirelessSetupStartConfigurationWorker_UnknownRoleZeroInitializedStorage_Variant2, 0xe8);
    return 1;
}
