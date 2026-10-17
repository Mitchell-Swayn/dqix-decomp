// Original ARM range reviewed. Opaque offsets document observed fields.
extern "C" char data_02109da4[];extern "C" char data_02109da6[];extern "C" char data_021015a0[];extern "C" void* memset(void*,int,unsigned int);extern "C" void* memcpy(void*,const void*,unsigned int);
// Original: arm9/main @ 0x0206AC6C; symbol: func_0206ac6c; size: 0x28.
extern "C" int TextStream_TestFFPrefixMarker(int unused,const void* p){unsigned short v;memcpy(&v,p,2);return (v&0xff00)==0xff00;}
