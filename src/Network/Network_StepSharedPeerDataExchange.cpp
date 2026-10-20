#include <globaldefs.h>
// Original data: arm9/main @ 0x2102be0; symbol: data_02102be0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 2080 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" int NetworkGetEnabledSharedPeerData_UnknownRoleZeroInitializedStorage_Variant2[];
// Original data: arm9/main @ 0x2101980; symbol: data_02101980.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 512 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" int NetworkGetEnabledSharedPeerData_UnknownRoleZeroInitializedStorage[];
extern "C" int Network_ExchangeQueuedWirelessPacket(int, int, int, int);
extern "C" void Network_RecordWirelessErrorUnlessTerminal(...);
// Original: arm9/main @ 0x0202DCD4; symbol: func_0202dcd4; size: 0x54.
extern "C" int Network_StepSharedPeerDataExchange(int a, int b, int c, int d) {
    int result=Network_ExchangeQueuedWirelessPacket((int)NetworkGetEnabledSharedPeerData_UnknownRoleZeroInitializedStorage_Variant2,a,(int)NetworkGetEnabledSharedPeerData_UnknownRoleZeroInitializedStorage,d);
    if (result==7) return 1;
    if (result==5) {
        Network_RecordWirelessErrorUnlessTerminal();
        return 0;
    }
    if (result==0) return 1;
    Network_RecordWirelessErrorUnlessTerminal(result);
    return 0;
}
