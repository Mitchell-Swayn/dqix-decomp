#include <globaldefs.h>
ARM
#pragma optimize_for_size off
#pragma optimization_level 3
// Original: arm9/main @ 0x020BEC10; symbol: func_020bec10; size: 0x20.
extern "C" void NNS_SndArcStrmStartPrepared(char* volatile* p) { if (*p == 0) return; *(unsigned*)(*p+0x110) |= 4; }
