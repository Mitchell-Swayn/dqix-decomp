// Original ARM range reviewed. Opaque offsets document observed fields.
extern "C" char data_02109da4[];extern "C" char data_02109da6[];extern "C" char data_021015a0[];extern "C" void* memset(void*,int,unsigned int);extern "C" void* memcpy(void*,const void*,unsigned int);
// Original: arm9/main @ 0x0208792C; symbol: func_0208792c; size: 0x28.
extern "C" void ClearField14Flag800AndField58Flag38AndBytes6FAnd92(char* p){*(unsigned int*)(p+20)&=~0x800u;*(unsigned int*)(p+0x58)&=~0x38u;p[0x6f]=0;p[0x92]=0;}
