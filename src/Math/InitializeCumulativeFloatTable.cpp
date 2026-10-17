#include <globaldefs.h>
extern "C" float data_020f0d1c[];
extern "C" float data_02108dc4[];
// Original: arm9/main @ 0x020E6038; symbol: __sinit_020e6038; size: 0x88.
// Constructs cumulative floating-point values from a four-element input table.
#pragma define_section init ".init" RX
extern "C" __declspec(section "init") void InitializeCumulativeFloatTable() {
 data_02108dc4[4]=((data_020f0d1c[3]+data_020f0d1c[2])+data_020f0d1c[1])+data_020f0d1c[0];
 data_02108dc4[2]=data_02108dc4[3]+data_020f0d1c[3];
 data_02108dc4[1]=data_02108dc4[2]+data_020f0d1c[2];
 data_02108dc4[0]=data_02108dc4[1]+data_020f0d1c[1];
}
