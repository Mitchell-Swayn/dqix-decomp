// Original ARM range reviewed. Opaque offsets document observed fields.
extern "C" char data_02109da4[];extern "C" char data_02109da6[];extern "C" char data_021015a0[];extern "C" void* memset(void*,int,unsigned int);extern "C" void* memcpy(void*,const void*,unsigned int);
// Original: arm9/main @ 0x0206E0D0; symbol: func_0206e0d0; size: 0x30.
extern "C" void Object_ClearTrailingTwelveBytesOfTwentyEightByteEntry(char* p,int i){char* q=p+i*28;memset(q+16,0,4);memset(q+20,0,8);}
