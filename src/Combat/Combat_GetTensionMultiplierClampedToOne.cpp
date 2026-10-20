#include <globaldefs.h>
// Original data: arm9/main @ 0x20e88f8; symbol: data_020e88f8.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0000803f0000803f0000c03f6666a63f000020400000004000008040000040400000c04000009040.
// Observed span: 40 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" float CombatGetTensionMultiplierClampedToOne_UnknownRoleInitializedBytes[][2];
// Original: arm9/main @ 0x02074738; symbol: func_02074738; size: 0x2C.
extern "C" ARM float Combat_GetTensionMultiplierClampedToOne(int a,int b){float value=CombatGetTensionMultiplierClampedToOne_UnknownRoleInitializedBytes[a][b];if(value<1.0f)value=1.0f;return value;}
