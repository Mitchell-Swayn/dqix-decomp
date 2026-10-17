#include <globaldefs.h>
ARM
extern "C" unsigned char* Object_GetValidSixtyByteEntry(void*,int);extern "C" int Object_FindNamedTwentyByteEntryIndex(void*,const char*);
// Original: arm9/main @ 0x0203F0FC; symbol: func_0203f0fc; size: 0x3C.
extern "C" int Object_FindNamedAnimationInSelectedEntry(unsigned char* p,const char* name){int index=*(short*)(p+40);if(index<0)return -1;unsigned char* entry=Object_GetValidSixtyByteEntry(*(void**)p,index);if(!entry)return -1;return Object_FindNamedTwentyByteEntryIndex(entry+16,name);}
