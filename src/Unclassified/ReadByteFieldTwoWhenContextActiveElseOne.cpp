#include <globaldefs.h>
ARM
extern "C" void* Object_GetGlobalConnectionState();extern "C" int IsFirstWordNonzero(void*);
// Original: arm9/main @ 0x020E37E8; symbol: func_020e37e8; size: 0x20.
extern "C" unsigned ReadByteFieldTwoWhenContextActiveElseOne(unsigned char* p){return IsFirstWordNonzero(Object_GetGlobalConnectionState())?p[2]:1;}
