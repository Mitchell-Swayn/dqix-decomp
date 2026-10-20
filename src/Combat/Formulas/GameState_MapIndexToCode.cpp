#include <globaldefs.h>
ARM
// Original: arm9/ov024 @ 0x021E8C48; symbol: func_ov024_021e8c48; size: 0x58.
extern "C" int GameState_MapIndexToCode(int unused, int value) {
    switch (value) {
    case -1: return 0x36;
    case 1: return 0x31;
    case 2: return 0x32;
    case 3: return 0x33;
    case 4: return 0x34;
    default: return 0x1F;
    }
}
