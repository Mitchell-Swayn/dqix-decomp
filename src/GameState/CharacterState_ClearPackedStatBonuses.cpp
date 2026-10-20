#include <globaldefs.h>
#pragma optimization_level 4
extern "C" {
// Original: arm9/main @ 0x02082CDC; symbol: func_02082cdc; size: 0x5C.
ARM void CharacterState_ClearPackedStatBonuses(unsigned int *param_1) {
    param_1[0] &= 0xfffffc00;
    param_1[0] &= 0xfff003ff;
    param_1[0] &= 0xc00fffff;
    param_1[1] &= 0xfffffc00;
    param_1[1] &= 0xfff003ff;
    param_1[1] &= 0xc00fffff;
    param_1[2] &= 0xfffffc00;
    param_1[2] &= 0xfff003ff;
    param_1[2] &= 0xc00fffff;
}
}
