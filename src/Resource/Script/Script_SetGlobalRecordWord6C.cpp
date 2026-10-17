#include <globaldefs.h>
ARM
extern "C" unsigned char* ReadWordAtOffset0();extern "C" unsigned ReadScriptParameterAsInteger(void*);
// Original: arm9/main @ 0x0209D744; symbol: func_0209d744; size: 0x2C.
extern "C" int Script_SetGlobalRecordWord6C(void* param){unsigned char* object=ReadWordAtOffset0();if(!object)return 0;*(unsigned*)(object+0x6c)=ReadScriptParameterAsInteger(param);return 1;}
