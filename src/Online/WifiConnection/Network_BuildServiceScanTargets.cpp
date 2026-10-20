#include "globaldefs.h"
// Original: arm9/ov031 @ 0x02214660; symbol: AppendModeSpecificPriorityRecords.
struct Nibble{unsigned char value:4;unsigned char rest:4;};
// Original data: arm9/ov031 @ 0x2245fd8; symbol: data_ov031_02245fd8.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 576179706f727432.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char Network_BuildSavedProfileScanTargets(void*); extern "C" void MI_CpuCopy8(const void*,void*,unsigned);extern unsigned char Network_BuildServiceScanTargets_TextNWCUSBAP[],NetworkBuildServiceScanTargets_UnknownRoleInitializedBytes[],Network_BuildServiceScanTargets_TextNINTENDOWFC[];
extern "C" ARM unsigned Network_BuildServiceScanTargets(unsigned char *self){ unsigned char count; unsigned char *entry=self+0x300; count=Network_BuildSavedProfileScanTargets(self); entry+=count*36; if(((Nibble*)(self+0xd0c))->value==0||((Nibble*)(self+0xd0c))->value==4){MI_CpuCopy8(Network_BuildServiceScanTargets_TextNWCUSBAP,entry+4,8);entry[3]=8;entry[1]=6;count++;entry+=36;} if(((Nibble*)(self+0xd0c))->value==0||((Nibble*)(self+0xd0c))->value==7){MI_CpuCopy8(NetworkBuildServiceScanTargets_UnknownRoleInitializedBytes,entry+4,8);entry[3]=8;entry[1]=9;count++;entry+=36;} if(((Nibble*)(self+0xd0c))->value==0||((Nibble*)(self+0xd0c))->value==8){MI_CpuCopy8(Network_BuildServiceScanTargets_TextNINTENDOWFC,entry+4,11);entry[3]=11;entry[1]=10;count++;}return count;}