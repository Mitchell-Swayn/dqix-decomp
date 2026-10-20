// ARM instruction evidence reviewed; opaque field offsets preserve observed layout.
// Original: arm9/main @ 0x020883FC; symbol: func_020883fc; size: 0x1C.
extern "C" void CombatStatus_ClearConfusion(char* p) {*(unsigned int*)(p+0x14)&=~0x20u;p[0x5e]=0;p[0x81]=0;}
