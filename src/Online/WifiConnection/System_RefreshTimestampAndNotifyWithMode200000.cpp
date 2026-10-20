#include <globaldefs.h>
ARM
extern "C" unsigned long long _Z19GetCurrentTimestampv(void);
extern "C" void System_DispatchWithIndexedTableFlag(const void*, const void*, int, unsigned int);
// Original data: arm9/ov031 @ 0x2245fb0; symbol: data_ov031_02245fb0.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffffffffffff0000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char NetworkAdvanceBroadChannelSearch_UnknownRoleInitializedBytes;
// Original data: arm9/ov031 @ 0x2245fb8; symbol: data_ov031_02245fb8.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char NetworkAdvanceBroadChannelSearch_UnknownRoleInitializedBytes_Variant2;
// Original: arm9/ov031 @ 0x02214C44; symbol: System_RefreshTimestampAndNotifyWithMode200000; size: 0x50.
// Refreshes the 64-bit timestamp at +0xCB0, clears byte +0xD11, refreshes the timestamp again, and calls the handler with two global addresses and mode 0x200000.
extern "C" int System_RefreshTimestampAndNotifyWithMode200000(char* p) {
    *(unsigned long long*)(p + 0xcb0) = _Z19GetCurrentTimestampv();
    p[0xd11] = 0;
    *(unsigned long long*)(p + 0xcb0) = _Z19GetCurrentTimestampv();
    System_DispatchWithIndexedTableFlag(&NetworkAdvanceBroadChannelSearch_UnknownRoleInitializedBytes, &NetworkAdvanceBroadChannelSearch_UnknownRoleInitializedBytes_Variant2, *(signed char*)(p + 0xd11), 0x200000);
    return 3;
}
