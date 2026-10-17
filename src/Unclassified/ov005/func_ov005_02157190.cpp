extern "C" { extern unsigned short data_02114e30[]; int Object_TestNewlySetHalfwordMask(void*,unsigned); }
// Original: arm9/ov005 @ 0x02157190; symbol: func_ov005_02157190; size: 0x40.
extern "C" int func_ov005_02157190(void* unused) { int result=0; if(!Object_TestNewlySetHalfwordMask(data_02114e30,0x30)) { if(Object_TestNewlySetHalfwordMask(data_02114e30,0x401)) result=1; } return result; }
