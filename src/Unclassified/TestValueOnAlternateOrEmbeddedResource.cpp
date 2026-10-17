#include <globaldefs.h>
extern "C" void ResourceManager_ExchangeGlobalValue(void*);extern "C" int ResourceManager_ApplyResolvedRecordParameters(void*,unsigned);
// Original: arm9/main @ 0x0203ABA8; symbol: func_0203aba8; size: 0x68.
extern "C" ARM bool TestValueOnAlternateOrEmbeddedResource(char* p,unsigned a,void* alternate){if(!*(int*)p)return false;ResourceManager_ExchangeGlobalValue(p+4);int result=1;int value;if(alternate)value=ResourceManager_ApplyResolvedRecordParameters(alternate,a);else value=ResourceManager_ApplyResolvedRecordParameters(p+0x98,a);if(!value)result=0;return result!=0;}
