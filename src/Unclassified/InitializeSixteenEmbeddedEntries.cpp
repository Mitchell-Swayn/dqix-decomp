#include <globaldefs.h>
ARM
extern "C" void Object_ClearD4ByteDisplayEntryAndSetDefaults(void*);
// Original: arm9/main @ 0x02057930; symbol: func_02057930; size: 0x48.
extern "C" void InitializeSixteenEmbeddedEntries(unsigned char* p){*(int*)p=0;*(int*)(p+4)=0;*(int*)(p+0xd4c)=0;*(int*)(p+0xd50)=0;unsigned char* base=p+8;for(int i=0;i<16;++i)Object_ClearD4ByteDisplayEntryAndSetDefaults(base+i*212);*(int*)(p+0xd48)=0;}
