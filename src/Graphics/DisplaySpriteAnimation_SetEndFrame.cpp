#include <globaldefs.h>
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
extern "C" {
// Original: arm9/main @ 0x020DDE98; symbol: func_020dde98; size: 0x8.
ARM void DisplaySpriteAnimation_SetEndFrame(int param_1,undefined2 param_2)

{
  *(undefined2 *)(param_1 + 2) = param_2;
  return;
}
}
