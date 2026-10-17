// Original ARM range reviewed. Opaque offsets document observed fields.
extern "C" char data_02109da4[];extern "C" char data_02109da6[];extern "C" char data_021015a0[];extern "C" void* memset(void*,int,unsigned int);extern "C" void* memcpy(void*,const void*,unsigned int);
// Original: arm9/main @ 0x0208830C; symbol: func_0208830c; size: 0x2C.
extern "C" int TestField14Flags1And8And1000000Clear(char* p){unsigned int flags=*(unsigned int*)(p+20);if(flags&1)return 0;if(flags&8)return 0;return !(flags&0x1000000);}
