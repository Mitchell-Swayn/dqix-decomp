#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x020488AC; symbol: func_020488ac; size: 0x20.
extern "C" void WriteField17FActiveAndClear180(unsigned char* p,int active) { p[0x17f]=active!=0; if (active) p[0x180]=0; }
