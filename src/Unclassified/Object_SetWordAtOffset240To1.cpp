#include <globaldefs.h>
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
extern "C" {
// Original: arm9/main @ 0x020A28C4; symbol: func_020a28c4; size: 0xC.
ARM void Object_SetWordAtOffset240To1(int param_1)

{
  *(undefined4 *)(param_1 + 0x240) = 1;
  return;
}
}
