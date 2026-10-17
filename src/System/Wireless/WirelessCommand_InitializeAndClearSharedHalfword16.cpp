#include <globaldefs.h>
#pragma optimize_for_size off
extern "C" int Wireless_InitializeSharedCommandBuffers(unsigned,unsigned,unsigned);extern "C" unsigned data_021142e0[];
// Original: arm9/main @ 0x020D3DCC; symbol: func_020d3dcc; size: 0x2C.
extern "C" ARM int WirelessCommand_InitializeAndClearSharedHalfword16(unsigned a,unsigned b){int status=Wireless_InitializeSharedCommandBuffers(a,b,0xf00);if(status)return status;*(short*)(data_021142e0[1]+0x16)=0;return status;}
