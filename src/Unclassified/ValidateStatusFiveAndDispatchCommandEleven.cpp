#include <globaldefs.h>
ARM
extern "C" int TestCurrentStatusAgainstVariadicAllowedValues(int,int);extern "C" void SetGlobalIndexedWordAtOffset18(int,void*);extern "C" int func_020d40bc(int,int);
// Original: arm9/main @ 0x020D5490; symbol: func_020d5490; size: 0x40.
extern "C" int ValidateStatusFiveAndDispatchCommandEleven(void* p){int r=TestCurrentStatusAgainstVariadicAllowedValues(1,5);if(r)return r;SetGlobalIndexedWordAtOffset18(11,p);r=func_020d40bc(11,0);if(!r)r=2;return r;}
