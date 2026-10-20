#include <globaldefs.h>
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
extern "C" {
// Original: arm9/main @ 0x02033FCC; symbol: func_02033fcc; size: 0x10.
ARM void GameObject_DisableMotionUpdates(int param_1)

{
  *(byte *)(param_1 + 0xe0) = *(byte *)(param_1 + 0xe0) | 4;
  return;
}
}
