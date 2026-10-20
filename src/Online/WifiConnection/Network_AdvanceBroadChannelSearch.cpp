#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2245fb0; symbol: data_ov031_02245fb0.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffffffffffff0000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x2245fb8; symbol: data_ov031_02245fb8.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" {unsigned long long _Z19GetCurrentTimestampv();int Network_AdvanceAndPublishAccessPointScanPhase(void*,int);void System_DispatchWithIndexedTableFlag(void*,void*,int,unsigned);extern char NetworkAdvanceBroadChannelSearch_UnknownRoleInitializedBytes[],NetworkAdvanceBroadChannelSearch_UnknownRoleInitializedBytes_Variant2[];}
// Original: arm9/ov031 @ 0x02214C94; symbol: AdvanceTimedSequenceByTwo; size: 0xa4.
// Every300 scaled timestamp units advances sequence2, dispatches indexed flag or completes at13.
extern "C" int Network_AdvanceBroadChannelSearch(char* self){unsigned long long elapsed=_Z19GetCurrentTimestampv()-*(unsigned long long*)(self+0xcb0);if((elapsed<<6)/33514>=300){self[0xd11]+=2;if((signed char)self[0xd11]>=13)return Network_AdvanceAndPublishAccessPointScanPhase(self,3);*(unsigned long long*)(self+0xcb0)=_Z19GetCurrentTimestampv();System_DispatchWithIndexedTableFlag(NetworkAdvanceBroadChannelSearch_UnknownRoleInitializedBytes,NetworkAdvanceBroadChannelSearch_UnknownRoleInitializedBytes_Variant2,(signed char)self[0xd11],0x200000);}return 3;}
