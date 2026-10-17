#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x0208203C; symbol: func_0208203c; size: 0x28.
extern "C" void ResetPointedHalfwordAndSynchronizeSignedByteState(unsigned char* p) { unsigned char* q=*(unsigned char**)p; if (q) { *(short*)q=0;q[2]=0; } *(short*)(p+4)=0; *(signed char*)(p+8)=*(signed char*)(p+6); }
