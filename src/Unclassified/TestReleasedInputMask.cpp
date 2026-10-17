// Original: arm9/main @ 0x02012468; symbol: func_02012468; size: 0x24.
extern "C" int TestReleasedInputMask(unsigned short* p,unsigned int mask){if(!(p[0]&mask)){if(p[1]&mask)return 1;}return 0;}
