#include <globaldefs.h>
extern "C" {
extern unsigned int data_020fefec[];
// Original: arm9/main @ 0x0202AE30; symbol: func_0202ae30; size: 0x1C.
void SetGlobalStateTwoWhenHalfwordEqualsSixteen(unsigned short *p){if(p[2]==16)data_020fefec[2]=2;}
}
