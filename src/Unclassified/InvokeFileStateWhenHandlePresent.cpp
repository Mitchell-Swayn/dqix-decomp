#include <globaldefs.h>
ARM
extern "C" void ResourceManager_ExchangeGlobalValue(void*);extern "C" void ResourceManager_TestCommandWithModeOne(void*,int,void*);
// Original: arm9/main @ 0x0203AB6C; symbol: func_0203ab6c; size: 0x3C.
extern "C" int InvokeFileStateWhenHandlePresent(void** p,void* v){if(!*p)return 0;ResourceManager_ExchangeGlobalValue(p+1);ResourceManager_TestCommandWithModeOne(v,6,*p);return 1;}
