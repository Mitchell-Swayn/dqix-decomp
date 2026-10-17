#include <globaldefs.h>
// Original: arm9/main @ 0x0203FC5C; symbol: func_0203fc5c; size: 0x28.
extern "C" ARM bool WritePositiveFloatAt40(char* object,float value){if(value<=0.0f)return false;*(float*)(object+64)=value;return true;}
