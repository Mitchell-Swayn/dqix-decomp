#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
// Original data: arm9/ov012 @ 0x218afaa; symbol: data_ov012_0218afaa.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 3601.
// Observed span: 2 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov012.md.
extern "C" short ReadModeRangeOffset_UnknownRoleInitializedBytes[];
// Original data: arm9/ov012 @ 0x218afac; symbol: data_ov012_0218afac.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0002c8002c01000064002c012d010000.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov012.md.
extern "C" short ReadModeRangeOffset_UnknownRoleInitializedBytes_Variant2[];
struct Profile {unsigned first;unsigned low:9;signed mode:10;unsigned upper:13;};
inline Profile* GetProfile() {return (Profile*)((char*)_ZN9GameState11GetInstanceEv()+0x569c);}
// Original: arm9/ov012 @ 0x0218432C; symbol: func_ov012_0218432c; size: 0x58.
// Returns signed packed-mode offset within the selected half-open table range, or zero.
extern "C" int ReadModeRangeOffset(int index) {
 int mode=GetProfile()->mode;
 int low=ReadModeRangeOffset_UnknownRoleInitializedBytes[index*2];
 if(low<=mode && mode<ReadModeRangeOffset_UnknownRoleInitializedBytes_Variant2[index*2]) return mode-low;
 return 0;
}
