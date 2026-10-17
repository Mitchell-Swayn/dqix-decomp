#include <globaldefs.h>
ARM
extern "C" int TestCurrentStatusAgainstVariadicAllowedValues(int,int);extern "C" char* ReadGlobalOperationContextPointerAt4();extern "C" void SetGlobalIndexedWordAtOffset18(int,int);extern "C" int func_020d40bc(int,int,int);
// Original: arm9/main @ 0x020D51A8; symbol: func_020d51a8; size: 0x5C.
extern "C" int ResetSharedFieldsAndSubmitOperationEight(int a,int b){int n=TestCurrentStatusAgainstVariadicAllowedValues(1,2);if(n)return n;char* p=ReadGlobalOperationContextPointerAt4();*(unsigned short*)(p+0x150)=0;*(int*)(p+0x14c)=0;SetGlobalIndexedWordAtOffset18(8,a);n=func_020d40bc(8,1,b);if(!n)n=2;return n;}
