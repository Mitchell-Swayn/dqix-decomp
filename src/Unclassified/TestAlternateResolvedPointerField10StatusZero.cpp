#include <globaldefs.h>
ARM
#pragma optimize_for_size off
extern "C" int TextLookup_TestRecordOrTokenBitFlag(void*,void*,int);
// Original: arm9/main @ 0x02068D2C; symbol: func_02068d2c; size: 0x30.
extern "C" bool TestAlternateResolvedPointerField10StatusZero(void* unused,char* p,int n){void** e=*(void***)(p+16);if(!e)return false;return TextLookup_TestRecordOrTokenBitFlag(e,*e,n)==0;}
