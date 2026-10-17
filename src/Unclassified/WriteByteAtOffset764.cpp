#include <globaldefs.h>
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
extern "C" {
// Original: arm9/main @ 0x02026418; symbol: func_02026418; size: 0x8.
ARM void WriteByteAtOffset764(int param_1,undefined1 param_2)

{
  *(undefined1 *)(param_1 + 0x764) = param_2;
  return;
}
}
