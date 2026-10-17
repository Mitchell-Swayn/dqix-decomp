#include <globaldefs.h>
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
extern "C" {
// Original: arm9/main @ 0x02053EC8; symbol: func_02053ec8; size: 0x8.
ARM void WriteWordAtOffset158(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x158) = param_2;
  return;
}
}
