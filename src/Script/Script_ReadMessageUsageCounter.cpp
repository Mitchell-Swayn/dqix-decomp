#include <globaldefs.h>
extern "C" void ScriptFlagHistory_AppendGlobalKey(int);
// Original: arm9/main @ 0x0206EC1C; symbol: func_0206ec1c; size: 0x48.
extern "C" ARM unsigned Script_ReadMessageUsageCounter(void* ignored,int index,const unsigned char* data,unsigned length){int half=index%2;int offset=index/2;if((unsigned)offset>=length){ScriptFlagHistory_AppendGlobalKey(999);return 0;}int value=data[offset];if(half)value&=15;else value>>=4;return value;}
