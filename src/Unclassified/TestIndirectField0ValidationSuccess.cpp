#include <globaldefs.h>
ARM
#pragma optimize_for_size off
extern "C" int TextLookup_TestRecordOrTokenBitFlag(void*,void*,int);
// Original: arm9/main @ 0x02068CFC; symbol: func_02068cfc; size: 0x30.
extern "C" bool TestIndirectField0ValidationSuccess(void* unused,char* p,int n){void** e=*(void***)(p+0);if(!e)return false;return TextLookup_TestRecordOrTokenBitFlag(e,*e,n)==0;}
