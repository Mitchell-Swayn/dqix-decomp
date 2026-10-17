#include <globaldefs.h>
ARM
extern "C" int ReadCachedStatusHalfwordAndClassify();extern "C" void SetGlobalIndexedWordAtOffset18(int,void*);extern "C" int func_020d40bc(int,int,...);
// Original: arm9/main @ 0x020D6A84; symbol: func_020d6a84; size: 0x50.
extern "C" int ValidateBooleanArgumentAndDispatchCommandTwentyFive(void* p,int n){int result=ReadCachedStatusHalfwordAndClassify();if(result)return result;if(n!=0&&n!=1)return 6;SetGlobalIndexedWordAtOffset18(25,p);result=func_020d40bc(25,1,n);if(!result)return 2;return result;}
