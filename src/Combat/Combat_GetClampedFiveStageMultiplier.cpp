#include <globaldefs.h>
extern "C" {
// Original data: arm9/main @ 0x20e88d0; symbol: data_020e88d0.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0000803fcdcc4c3f9a99193fcdcccc3ecdcc4c3e.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned int CombatGetClampedFiveStageMultiplier_UnknownRoleInitializedBytes[];
// Original: arm9/main @ 0x02074948; symbol: func_02074948; size: 0x20.
unsigned int Combat_GetClampedFiveStageMultiplier(int i){if(i<0)i=0;if(i>4)i=4;return CombatGetClampedFiveStageMultiplier_UnknownRoleInitializedBytes[i];}
}
