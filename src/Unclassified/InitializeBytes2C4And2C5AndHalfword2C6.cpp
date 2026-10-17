// Original instruction control flow and relocations reviewed.
extern "C" char* data_02110370[];extern "C" unsigned short data_02108d70[];extern "C" unsigned int data_0210f3c0[];struct Flag{unsigned char enabled:1;unsigned char rest:7;};
// Original: arm9/main @ 0x020A2CA0; symbol: func_020a2ca0; size: 0x1C.
extern "C" void InitializeBytes2C4And2C5AndHalfword2C6(char* p){p[0x2c4]=0;*(short*)(p+0x2c6)=0;p[0x2c5]=1;}
