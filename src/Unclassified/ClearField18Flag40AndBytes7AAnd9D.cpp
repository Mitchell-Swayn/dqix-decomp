// Original instruction control flow and relocations reviewed.
extern "C" char* data_02110370[];extern "C" unsigned short data_02108d70[];extern "C" unsigned int data_0210f3c0[];struct Flag{unsigned char enabled:1;unsigned char rest:7;};
// Original: arm9/main @ 0x020890A4; symbol: func_020890a4; size: 0x1C.
extern "C" void ClearField18Flag40AndBytes7AAnd9D(char* p){*(unsigned int*)(p+24)&=~64u;p[0x7a]=0;p[0x9d]=0;}
