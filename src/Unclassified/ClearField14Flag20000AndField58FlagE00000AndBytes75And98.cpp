// Original ARM range reviewed. Opaque offsets document observed fields.
extern "C" char data_02109da4[];extern "C" char data_02109da6[];extern "C" char data_021015a0[];extern "C" void* memset(void*,int,unsigned int);extern "C" void* memcpy(void*,const void*,unsigned int);
// Original: arm9/main @ 0x02087EFC; symbol: func_02087efc; size: 0x28.
extern "C" void ClearField14Flag20000AndField58FlagE00000AndBytes75And98(char* p){*(unsigned int*)(p+20)&=~0x20000u;*(unsigned int*)(p+0x58)&=~0xe00000u;p[0x75]=0;p[0x98]=0;}
