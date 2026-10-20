#include <globaldefs.h>
ARM
// Original: arm9/ov002 @ 0x0215A9B4; symbol: func_ov002_0215a9b4; size: 0x18.
extern "C" int PartyMenu_AdvanceOrderedCommandIndex(int unused, int value) {
    int result = (short)(value + 1);
    return result == 0x20 ? 0 : result;
}
