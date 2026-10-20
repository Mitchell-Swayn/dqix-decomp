#include <globaldefs.h>
// func_02039894: 0x02039894–0x020398a4, arm; 16 bytes
// Original: arm9/main @ 0x02039894; symbol: func_02039894; size: 0x10.
extern "C" void GameObject_SetUnknownPartyControlFlagAt1CEBitZero(int self) {
    *(unsigned char*)(self + 0x1ce) |= 1;
}
