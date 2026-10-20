#include <globaldefs.h>
THUMB
struct GlobalValueSlot { unsigned int unused; unsigned int value; };
// Original data: arm9/ov031 @ 0x224b070; symbol: data_ov031_0224b070.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffffffffffffffff.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" GlobalValueSlot AossRunSetupNegotiation_UnknownRoleInitializedBytes_Variant2;
extern "C" int Network_NotifyQueueSessionObserver(unsigned int);
// Original: arm9/ov031 @ 0x0221D384; symbol: func_ov031_0221d384; size: 0x2C.
extern "C" int System_SetGlobalValueAndNotifyOnChange(unsigned int value) {
    if (value == 0xffffffffu) {
        AossRunSetupNegotiation_UnknownRoleInitializedBytes_Variant2.value = value;
        return 0;
    }
    if (AossRunSetupNegotiation_UnknownRoleInitializedBytes_Variant2.value != value) {
        AossRunSetupNegotiation_UnknownRoleInitializedBytes_Variant2.value = value;
        return Network_NotifyQueueSessionObserver(value);
    }
    return 0;
}
