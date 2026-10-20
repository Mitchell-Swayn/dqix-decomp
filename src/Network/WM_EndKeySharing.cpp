#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" int WM_EndDataSharing(void*);
// Original: arm9/main @ 0x020D68D0; symbol: func_020d68d0; size: 0xC.
extern "C" int WM_EndKeySharing(void* p){return WM_EndDataSharing(p);}
