#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x020A9EA4; symbol: func_020a9ea4; size: 0x14.
extern "C" void SaveData_ResetTransferProgress(unsigned char* p) { p[0]=0; p[1]=0; *(unsigned int*)(p+4)=0; }
