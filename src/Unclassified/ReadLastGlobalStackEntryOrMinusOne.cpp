// Original ARM range reviewed. Opaque offsets document observed fields.
extern "C" volatile unsigned char data_02109da4[];extern "C" char data_02109da6[];extern "C" char data_021015a0[];extern "C" void* memset(void*,int,unsigned int);extern "C" void* memcpy(void*,const void*,unsigned int);
// Original: arm9/main @ 0x020A1FA8; symbol: func_020a1fa8; size: 0x2C.
extern "C" int ReadLastGlobalStackEntryOrMinusOne(){if((unsigned char)data_02109da4[1])return data_02109da6[(unsigned char)data_02109da4[1]-1];return -1;}
