// ARM instruction evidence reviewed; opaque field offsets preserve observed layout.
// Original: arm9/main @ 0x02049AE4; symbol: func_02049ae4; size: 0x18.
extern "C" void CombatantMotion_DisableSidestep(char* p) {char* q=*(char**)(p+0x13c); if(q) *(unsigned int*)(q+0x20)&=~4u;}
