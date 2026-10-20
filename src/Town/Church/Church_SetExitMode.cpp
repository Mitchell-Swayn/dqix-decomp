#include <globaldefs.h>
ARM
// Original: arm9/ov003 @ 0x02159174; symbol: Object_WriteByteAtOffset587; size: 0x8.
// Stores the supplied byte at object offset 0x587. The field meaning is not established.
extern "C" void Church_SetExitMode(void* self, unsigned char value) { *((unsigned char*)self + 0x587) = value; }
