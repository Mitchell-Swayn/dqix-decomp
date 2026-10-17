// Original ARM range reviewed. Opaque offsets document observed fields.
extern "C" char data_02109da4[];extern "C" char data_02109da6[];extern "C" char data_021015a0[];extern "C" void* memset(void*,int,unsigned int);extern "C" void* memcpy(void*,const void*,unsigned int);
// Original: arm9/main @ 0x02048BD0; symbol: func_02048bd0; size: 0x28.
extern "C" int TestLinkedWordFlagBitSeven(char* p){char* q=*(char**)(p+0x13c);if(!q)return 0;return (*(unsigned int*)(q+32)&128)!=0;}
