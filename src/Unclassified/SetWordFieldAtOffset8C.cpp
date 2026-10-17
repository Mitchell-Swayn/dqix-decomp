#include <globaldefs.h>
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
extern "C" {
// Original: arm9/main @ 0x0209FE08; symbol: func_0209fe08; size: 0x8.
ARM void SetWordFieldAtOffset8C(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x8c) = param_2;
  return;
}
}
