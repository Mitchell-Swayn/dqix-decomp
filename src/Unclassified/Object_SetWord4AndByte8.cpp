#include <globaldefs.h>
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
extern "C" {
// Original: arm9/main @ 0x0205B228; symbol: func_0205b228; size: 0xC.
ARM void Object_SetWord4AndByte8(int param_1,undefined4 param_2,undefined1 param_3)

{
  *(undefined4 *)(param_1 + 4) = param_2;
  *(undefined1 *)(param_1 + 8) = param_3;
  return;
}
}
