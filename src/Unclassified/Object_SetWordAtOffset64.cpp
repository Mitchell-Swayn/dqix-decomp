#include <globaldefs.h>
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
extern "C" {
// Original: arm9/main @ 0x0209FE10; symbol: func_0209fe10; size: 0x8.
ARM void Object_SetWordAtOffset64(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 100) = param_2;
  return;
}
}
