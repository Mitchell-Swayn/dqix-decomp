#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x020DB0C4; symbol: func_020db0c4; size: 0x2C.
extern "C" void DisplayOverlay_ResetActivationState(unsigned char* p) { *(short*)(p+0x68)=-1;*(short*)(p+0x6a)=0;p[0x50]=0;p[0x52]=0;p[0x53]=1;p[0x51]=0;p[0x64]=0; }
