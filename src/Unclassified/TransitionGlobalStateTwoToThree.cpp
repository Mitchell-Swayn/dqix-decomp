// Original ARM range reviewed. Opaque offsets document observed fields.
extern "C" char data_02109da4[];extern "C" char data_02109da6[];extern "C" char data_021015a0[];extern "C" void* memset(void*,int,unsigned int);extern "C" void* memcpy(void*,const void*,unsigned int);
// Original: arm9/main @ 0x0202D0B4; symbol: func_0202d0b4; size: 0x2C.
extern "C" int TransitionGlobalStateTwoToThree(){if(*(int*)(data_021015a0+16)!=2)return 0;*(short*)(data_021015a0+4)=0;*(int*)(data_021015a0+16)=3;return 1;}
