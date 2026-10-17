#include <globaldefs.h>
extern "C" {
// Original: arm9/main @ 0x0208BE94; symbol: func_0208be94; size: 0x20.
void Object_ResetTimerAndSetFlagWhenModeNotTwo(char *p){if(*(unsigned char *)(p+0xd4)!=2){*(short *)(p+0xd0)=0;*(unsigned short *)(p+0xda)|=1;}}
}
