#include <globaldefs.h>
ARM
extern "C" void ObjectPool_ResetDisplayEntry(void*);
// Original: arm9/main @ 0x02057930; symbol: func_02057930; size: 0x48.
extern "C" void ObjectPool_ResetDisplayContainer(unsigned char* p){*(int*)p=0;*(int*)(p+4)=0;*(int*)(p+0xd4c)=0;*(int*)(p+0xd50)=0;unsigned char* base=p+8;for(int i=0;i<16;++i)ObjectPool_ResetDisplayEntry(base+i*212);*(int*)(p+0xd48)=0;}
