#include <globaldefs.h>
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
extern "C" {
// Original: arm9/main @ 0x020A28D0; symbol: func_020a28d0; size: 0xC.
ARM void Camera_DisableRegionOrbitInput(int param_1)

{
  *(undefined4 *)(param_1 + 0x240) = 0;
  return;
}
}
