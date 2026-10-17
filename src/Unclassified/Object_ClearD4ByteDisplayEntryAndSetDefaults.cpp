#include <globaldefs.h>
ARM
extern "C" void* memset(void*,int,unsigned int);
// Original: arm9/main @ 0x02059CC8; symbol: func_02059cc8; size: 0x34.
extern "C" void Object_ClearD4ByteDisplayEntryAndSetDefaults(unsigned char* p) { memset(p,0,0xd4);*(short*)(p+0xb2)=-1;*(short*)(p+0xb4)=-1;p[0xcc]=(p[0xcc]|4)&~8; }
