#include <globaldefs.h>
ARM
extern "C" void* Object_GetGlobalConnectionState();extern "C" int IsFirstWordNonzero(void*);
// Original: arm9/main @ 0x020E3748; symbol: func_020e3748; size: 0x30.
extern "C" void ClearContextEnabledByte1Bit(unsigned char* p,int bit){if(IsFirstWordNonzero(Object_GetGlobalConnectionState()))p[1]&=~(1U<<bit);}
