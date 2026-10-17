#include <globaldefs.h>
ARM
extern "C" unsigned char data_02109bf4[];
extern "C" void Object_SetUnsignedShortAtOffsetCEAndSetUnsignedCharAtOffsetC9To1(int self, unsigned short value);
// Original: arm9/ov004 @ 0x0216DFA0; symbol: func_ov004_0216dfa0; size: 0x1C.
extern "C" int GameState_SetGlobalObjectShort35AndReturnZero(void) {
    Object_SetUnsignedShortAtOffsetCEAndSetUnsignedCharAtOffsetC9To1((int)data_02109bf4, 0x35);
    return 0;
}
