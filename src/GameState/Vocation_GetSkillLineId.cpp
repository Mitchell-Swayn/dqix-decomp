#include <globaldefs.h>
extern "C" {
// Original data: arm9/main @ 0x20ee748; symbol: data_020ee748.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00000000000102030d0f0204060d100403050d110706080e120301070e130105080d14090a010e150c01040d160a02040d17040c0b0d1808050b0d190b090c0e ...; full span in module reference.
// Observed span: 76 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned char VocationGetSkillLineId_UnknownRoleInitializedBytes[];
// Original: arm9/main @ 0x020DD11C; symbol: func_020dd11c; size: 0x38.
unsigned char Vocation_GetSkillLineId(unsigned int a,unsigned int b){if(a==0||a>=13)return 0;if(b>=5)return 0;return *(VocationGetSkillLineId_UnknownRoleInitializedBytes+a*5+b);}
}
