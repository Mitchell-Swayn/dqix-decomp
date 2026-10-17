#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
// Original: arm9/main @ 0x020883CC; symbol: func_020883cc; size: 0x30.
void ResetModeFieldsAndSetFlagBitFive(char *p){p[0x21]=0;*(unsigned int *)(p+0x18)&=~32;p[0x5e]=3;p[0x81]=0;*(unsigned int *)(p+0x14)|=32;}
}
