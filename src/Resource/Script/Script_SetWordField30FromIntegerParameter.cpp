#include <globaldefs.h>
ARM
extern "C" unsigned char* data_02108740[];extern "C" int _ZNK6Script9Parameter5ToIntEv(void*);
// Original: arm9/main @ 0x0205E05C; symbol: func_0205e05c; size: 0x20.
extern "C" bool Script_SetWordField30FromIntegerParameter(void* parameter){int value=_ZNK6Script9Parameter5ToIntEv(parameter);*(int*)(data_02108740[1]+48)=value;return true;}
