#include <globaldefs.h>
ARM
#pragma optimize_for_size off
extern "C" int TextLookup_TestRecordOrTokenBitFlag(void*,void*,int);
// Original: arm9/main @ 0x02068CCC; symbol: func_02068ccc; size: 0x30.
extern "C" bool TextCondition_TestVocationVowelFlagClear(void* unused,char* p,int n){void** e=*(void***)(p+40);if(!e)return false;return TextLookup_TestRecordOrTokenBitFlag(e,*e,n)==0;}
