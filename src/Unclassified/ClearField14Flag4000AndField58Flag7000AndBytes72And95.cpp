// Original ARM range reviewed. Opaque offsets document observed fields.
extern "C" char data_02109da4[];extern "C" char data_02109da6[];extern "C" char data_021015a0[];extern "C" void* memset(void*,int,unsigned int);extern "C" void* memcpy(void*,const void*,unsigned int);
// Original: arm9/main @ 0x02087C08; symbol: func_02087c08; size: 0x28.
extern "C" void ClearField14Flag4000AndField58Flag7000AndBytes72And95(char* p){*(unsigned int*)(p+20)&=~0x4000u;*(unsigned int*)(p+0x58)&=~0x7000u;p[0x72]=0;p[0x95]=0;}
