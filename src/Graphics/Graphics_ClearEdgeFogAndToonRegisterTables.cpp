#include <globaldefs.h>
// Original data: arm9/main @ 0x20f2270; symbol: data_020f2270.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 03000000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" int LoadToSubOAM_UnknownRoleInitializedBytes;extern "C" void MIi_CpuClear32(int,void*,unsigned);extern "C" void _Z14DMAMemsetAsyncijjjPFviEi(int,unsigned,unsigned,unsigned,void(*)(int),int);extern "C" void _Z20DMAMemsetSynchronousijjj(int,unsigned,unsigned,unsigned);
// Original: arm9/main @ 0x020C55B0; symbol: func_020c55b0; size: 0xA0.
extern "C" ARM void Graphics_ClearEdgeFogAndToonRegisterTables(){if(LoadToSubOAM_UnknownRoleInitializedBytes!=-1){_Z14DMAMemsetAsyncijjjPFviEi(LoadToSubOAM_UnknownRoleInitializedBytes,0x04000330,0,16,0,0);_Z20DMAMemsetSynchronousijjj(LoadToSubOAM_UnknownRoleInitializedBytes,0x04000360,0,96);}else{MIi_CpuClear32(0,(void*)0x04000330,16);MIi_CpuClear32(0,(void*)0x04000360,96);}int i=0;do{++i;*(volatile unsigned*)0x040004d0=0;}while(i<32);}
