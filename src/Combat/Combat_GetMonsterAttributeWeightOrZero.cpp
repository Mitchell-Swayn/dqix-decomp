#include <globaldefs.h>
extern "C" {
// Original data: arm9/main @ 0x20e88e4; symbol: data_020e88e4.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 000000000000004000008040000000410000c841.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
    extern int CombatGetMonsterAttributeWeightOrZero_UnknownRoleInitializedBytes[];
// Original: arm9/main @ 0x02074988; symbol: func_02074988; size: 0x24.
    int Combat_GetMonsterAttributeWeightOrZero(int i){
        if(i<0)return 0;
        if(i>4)return 0;
        return CombatGetMonsterAttributeWeightOrZero_UnknownRoleInitializedBytes[i];
    }
}
