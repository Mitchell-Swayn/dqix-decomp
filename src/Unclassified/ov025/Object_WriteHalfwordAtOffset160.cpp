#include <globaldefs.h>

ARM
// Original: arm9/ov025 @ 0x021ED344; symbol: func_ov025_021ed344; size: 0xC.
extern "C" void Object_WriteHalfwordAtOffset160(void *self, unsigned short value) { *(unsigned short *)((unsigned char *)self+0x160)=value; }
