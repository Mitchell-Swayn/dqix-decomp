#include <globaldefs.h>
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
extern "C" {
// Original: arm9/main @ 0x0202EA3C; symbol: func_0202ea3c; size: 0x10.
ARM void SetWordFlagBitTwoAtOffset168(int param_1)

{
  *(uint *)(param_1 + 0x168) = *(uint *)(param_1 + 0x168) | 4;
  return;
}
}
