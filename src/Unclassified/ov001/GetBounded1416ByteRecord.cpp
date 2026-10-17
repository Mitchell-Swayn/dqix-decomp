#include <globaldefs.h>
ARM
extern "C" {
    extern char data_ov001_02165880[];
}
// Original: arm9/ov001 @ 0x0215AB20; symbol: func_ov001_0215ab20; size: 0x34.
// Field roles beyond the stated offset operations remain uncertain.
extern "C" char* GetBounded1416ByteRecord(int i) {
    if(i<0||i>=24)return 0;
    return *(char**)(data_ov001_02165880+28)+i*1416;
}
