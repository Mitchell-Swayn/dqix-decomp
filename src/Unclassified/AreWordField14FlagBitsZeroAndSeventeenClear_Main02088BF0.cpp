#include <globaldefs.h>
extern "C" {
// Original: arm9/main @ 0x02088BF0; symbol: func_02088bf0; size: 0x20.
bool AreWordField14FlagBitsZeroAndSeventeenClear_Main02088BF0(unsigned int *p){unsigned int flags=p[5];if(flags&1)return false;return !(flags&0x20000);}
}
