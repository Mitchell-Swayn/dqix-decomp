#include <globaldefs.h>
ARM
extern "C" unsigned char* ScriptQueryContext_GetActiveInstance();extern "C" unsigned Script_ReadParameterAsInteger(void*);
// Original: arm9/main @ 0x0209D744; symbol: func_0209d744; size: 0x2C.
extern "C" int Script_SetGlobalRecordWord6C(void* param){unsigned char* object=ScriptQueryContext_GetActiveInstance();if(!object)return 0;*(unsigned*)(object+0x6c)=Script_ReadParameterAsInteger(param);return 1;}
