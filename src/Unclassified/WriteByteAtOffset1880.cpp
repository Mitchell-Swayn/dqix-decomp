#include <globaldefs.h>
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
extern "C" {
// Original: arm9/main @ 0x020464DC; symbol: func_020464dc; size: 0xC.
ARM void WriteByteAtOffset1880(int param_1,undefined1 param_2)

{
  *(undefined1 *)(param_1 + 0x1880) = param_2;
  return;
}
}
