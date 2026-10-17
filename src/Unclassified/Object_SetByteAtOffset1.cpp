#include <globaldefs.h>
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
extern "C" {
// Original: arm9/main @ 0x020E2D4C; symbol: func_020e2d4c; size: 0x8.
ARM void Object_SetByteAtOffset1(int param_1,undefined1 param_2)

{
  *(undefined1 *)(param_1 + 1) = param_2;
  return;
}
}
