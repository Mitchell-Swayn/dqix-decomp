#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x0202A678; symbol: func_0202a678; size: 0x4C.
extern "C" void DebugMenu_AdjustNumericEntryValue(char* p,int n){*(int*)(p+64)+=n;int b,a;int hi=*(int*)(p+72),lo=*(int*)(p+68);a=lo;b=hi;if(*(unsigned short*)(p+76)&256){a=hi;b=lo;}if(*(int*)(p+64)<lo){*(int*)(p+64)=a;return;}if(hi<*(int*)(p+64))*(int*)(p+64)=b;}
