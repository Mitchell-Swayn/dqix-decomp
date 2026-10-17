#include <globaldefs.h>
extern "C" int data_020f2270;extern "C" void MIi_CpuClear32(int,void*,unsigned);extern "C" void _Z14DMAMemsetAsyncijjjPFviEi(int,unsigned,unsigned,unsigned,void(*)(int),int);extern "C" void _Z20DMAMemsetSynchronousijjj(int,unsigned,unsigned,unsigned);
// Original: arm9/main @ 0x020C55B0; symbol: func_020c55b0; size: 0xA0.
extern "C" ARM void Graphics_ClearEdgeFogAndToonRegisterTables(){if(data_020f2270!=-1){_Z14DMAMemsetAsyncijjjPFviEi(data_020f2270,0x04000330,0,16,0,0);_Z20DMAMemsetSynchronousijjj(data_020f2270,0x04000360,0,96);}else{MIi_CpuClear32(0,(void*)0x04000330,16);MIi_CpuClear32(0,(void*)0x04000360,96);}int i=0;do{++i;*(volatile unsigned*)0x040004d0=0;}while(i<32);}
