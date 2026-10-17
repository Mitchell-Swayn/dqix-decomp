// Original ARM range reviewed. Opaque offsets document observed fields.
extern "C" char data_02109da4[];extern "C" char data_02109da6[];extern "C" char data_021015a0[];extern "C" void* memset(void*,int,unsigned int);extern "C" void* memcpy(void*,const void*,unsigned int);
// Original: arm9/main @ 0x0206F7F4; symbol: func_0206f7f4; size: 0x28.
extern "C" int Object_ReadBoundedHalfwordArrayAtOffset8(char* p,int i){if(i<0 || *(int*)(p+4)<=i)return -1;return *(short*)(p+i*2+8);}
