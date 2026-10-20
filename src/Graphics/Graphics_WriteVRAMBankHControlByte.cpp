#include <globaldefs.h>
extern "C" {
// Original: arm9/main @ 0x020C9BFC; symbol: func_020c9bfc; size: 0x10.
void Graphics_WriteVRAMBankHControlByte(unsigned char v){*(volatile unsigned char *)0x04000247=v;}
}
