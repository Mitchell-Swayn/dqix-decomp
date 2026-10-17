#include <globaldefs.h>
ARM
#include <System/GamecardBusOwnership.h>
THUMB
extern "C" void CpuSet(const void*,void*,unsigned);
ARM
extern unsigned char data_0211214c[];extern unsigned char data_02112148[];
// Original: arm9/main @ 0x020D12E4; symbol: func_020d12e4; size: 0x38.
extern "C" void ClearGlobalWordAndGenerateLockOwnerId(){unsigned zero=0;CpuSet(&zero,data_0211214c,0x05000001);*(unsigned short*)(data_02112148+6)=GenerateLockOwnerID();}
