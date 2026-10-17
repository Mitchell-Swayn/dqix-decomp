// Reviewed original ARM field widths and branch behavior. Hardware addresses are original MMIO literals.
extern "C" void func_02047230(void*);struct HalfCounter{unsigned low:16;unsigned high:16;};struct LowCounter{unsigned low:24;unsigned high:8;};
// Original: arm9/main @ 0x02070798; symbol: func_02070798; size: 0x30.
extern "C" void Graphics_WriteThreeVertexCoordinates(unsigned a,unsigned b,unsigned c){volatile unsigned* p=(volatile unsigned*)0x400048c;*p=(unsigned short)a|((unsigned short)b<<16);*p=(unsigned short)c;}
