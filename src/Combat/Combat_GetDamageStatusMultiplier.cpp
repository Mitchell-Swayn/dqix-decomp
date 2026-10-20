#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x20e88c0; symbol: data_020e88c0.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0000803f0000003fcdcccc3d00000000.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" float CombatGetDamageStatusMultiplier_UnknownRoleInitializedBytes[];
// Original: arm9/main @ 0x02074938; symbol: func_02074938; size: 0x10.
extern "C" float Combat_GetDamageStatusMultiplier(unsigned int i) { return CombatGetDamageStatusMultiplier_UnknownRoleInitializedBytes[i]; }
