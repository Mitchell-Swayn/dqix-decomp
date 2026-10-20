#include <globaldefs.h>
ARM

// Original: arm9/ov000 @ 0x021681F8; symbol: func_ov000_021681f8; size: 0x38.
extern "C" unsigned int MonsterFormation_GetRadiusScale(unsigned int id, int mode) {
    if (mode > 1) {
        if (id == 0xBD || id == 0xBE || id == 0xBF || id == 0x110 || id == 0x155) {
            return 0xB33;
        }
    }
    return 0x1000;
}
