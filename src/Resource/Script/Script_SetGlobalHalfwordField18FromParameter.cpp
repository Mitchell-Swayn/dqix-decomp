#include <globaldefs.h>
ARM
extern "C" unsigned char* data_02108efc;extern "C" int _ZNK6Script9Parameter5ToIntEv(void*);
// Original: arm9/main @ 0x02089AA0; symbol: func_02089aa0; size: 0x20.
extern "C" bool Script_SetGlobalHalfwordField18FromParameter(void* parameter){int value=_ZNK6Script9Parameter5ToIntEv(parameter);*(short*)(data_02108efc+24)=value;return true;}
