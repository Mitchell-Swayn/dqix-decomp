// Original instruction control flow and relocations reviewed.
extern "C" char* data_02110370[];extern "C" unsigned short data_02108d70[];extern "C" unsigned int data_0210f3c0[];struct Flag{unsigned char enabled:1;unsigned char rest:7;};
// Original: arm9/main @ 0x020889E4; symbol: func_020889e4; size: 0x20.
extern "C" void Object_SetByte63ToFourAndFlag10000000(char* p){p[0x63]=4;p[0x86]=0;*(unsigned int*)(p+20)|=0x10000000;}
