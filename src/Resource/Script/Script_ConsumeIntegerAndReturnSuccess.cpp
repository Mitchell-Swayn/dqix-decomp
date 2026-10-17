#include <Resource/Script.h>
// Reviewed original ARM field widths and source behavior; float initialization is a real 1.0 constant.
extern "C" {int strcmp(const char*,const char*);void* memset(void*,int,unsigned);}
// Original: arm9/main @ 0x0206ED34; symbol: func_0206ed34; size: 0x10.
extern "C" int Script_ConsumeIntegerAndReturnSuccess(void* p){((Script::Parameter*)p)->ToInt();return 1;}
