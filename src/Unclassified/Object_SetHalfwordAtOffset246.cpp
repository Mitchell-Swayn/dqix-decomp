#include <globaldefs.h>
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
extern "C" {
// Original: arm9/main @ 0x020A2788; symbol: func_020a2788; size: 0xC.
ARM void Object_SetHalfwordAtOffset246(int param_1,undefined2 param_2)

{
  *(undefined2 *)(param_1 + 0x246) = param_2;
  return;
}
}
