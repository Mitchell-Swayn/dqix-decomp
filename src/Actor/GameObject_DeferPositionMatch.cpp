#include <globaldefs.h>
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
extern "C" {
// Original: arm9/main @ 0x020340B4; symbol: func_020340b4; size: 0x10.
ARM void GameObject_DeferPositionMatch(int param_1)

{
  *(byte *)(param_1 + 0xc2) = *(byte *)(param_1 + 0xc2) | 0x80;
  return;
}
}
