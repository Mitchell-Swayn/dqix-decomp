#pragma optimize_for_size off
#include <globaldefs.h>
extern "C" int ReadCachedStatusHalfwordAndClassify(void*);extern "C" void SetGlobalIndexedWordAtOffset18(int,void*);extern "C" int func_020d40bc(int,int,unsigned,unsigned,unsigned,unsigned);
// Original: arm9/main @ 0x020D6AD4; symbol: func_020d6ad4; size: 0x60.
extern "C" int WirelessCommand_SubmitOpcodeTwentyNineWithFourArguments(void* input,unsigned a,unsigned b,unsigned c,unsigned short d) { int result=ReadCachedStatusHalfwordAndClassify(input);if(result)return result;SetGlobalIndexedWordAtOffset18(29,input);result=func_020d40bc(29,4,a,b,c,d);if(!result)result=2;return result; }
