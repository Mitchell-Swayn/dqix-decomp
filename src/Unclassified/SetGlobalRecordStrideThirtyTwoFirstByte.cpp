#include <globaldefs.h>
extern "C" {
extern char data_020fdccc[];
// Original: arm9/main @ 0x02026F20; symbol: func_02026f20; size: 0x14.
void SetGlobalRecordStrideThirtyTwoFirstByte(int unused,int i){data_020fdccc[i*32]=1;}
}
