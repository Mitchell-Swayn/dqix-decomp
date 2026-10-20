#include <globaldefs.h>
extern "C" void OSi_ReferSymbol(const void*);
// Original data: arm9/ov031 @ 0x22496a4; symbol: data_ov031_022496a4.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00000000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned NetworkCleanupSocketStack_UnknownRoleInitializedBytes;
extern "C" void Network_InitializeSocketStack();
extern "C" int AllocateOverlayQueueAndInitializeContext();
// Original: arm9/ov031 @ 0x02204DBC; symbol: func_ov031_02204dbc; size: 0x3C.
extern "C" int System_RegisterPendingWorkIfIdle(unsigned value) {
    OSi_ReferSymbol((const void*)0x02000c1c);
    if (NetworkCleanupSocketStack_UnknownRoleInitializedBytes) return 0;
    NetworkCleanupSocketStack_UnknownRoleInitializedBytes = value;
    Network_InitializeSocketStack();
    return AllocateOverlayQueueAndInitializeContext();
}
