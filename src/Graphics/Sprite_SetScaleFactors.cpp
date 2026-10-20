#include <globaldefs.h>
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
extern "C" {
// Original: arm9/main @ 0x02076988; symbol: func_02076988; size: 0xC.
ARM void Sprite_SetScaleFactors(int param_1,undefined4 param_2,undefined4 param_3)

{
  *(undefined4 *)(param_1 + 0x28) = param_2;
  *(undefined4 *)(param_1 + 0x2c) = param_3;
  return;
}
}
