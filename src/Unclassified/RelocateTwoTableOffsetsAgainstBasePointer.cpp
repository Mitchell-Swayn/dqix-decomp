#include <globaldefs.h>
ARM
#pragma optimization_level 4
// Original: arm9/main @ 0x02042998; symbol: func_02042998; size: 0x24.
extern "C" void RelocateTwoTableOffsetsAgainstBasePointer(int *p) { if (p == 0) return; p[2] = (int)((char*)p + p[2]); p[3] = (int)((char*)p + p[3]); }
