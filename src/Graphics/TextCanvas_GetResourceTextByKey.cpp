#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void* MessageTextTable_FindTextById(void*,int);
// Original: arm9/main @ 0x02081214; symbol: func_02081214; size: 0x10.
extern "C" void* TextCanvas_GetResourceTextByKey(void** p,int key){return MessageTextTable_FindTextById(*p,key);}
