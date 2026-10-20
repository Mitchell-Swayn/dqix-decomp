#include <globaldefs.h>
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
extern "C" {
// Original: arm9/main @ 0x02033B58; symbol: func_02033b58; size: 0x10.
ARM void GameObject_SetMotionState(int param_1,undefined1 param_2)

{
  *(undefined1 *)(param_1 + 0xbf) = *(undefined1 *)(param_1 + 0xbe);
  *(undefined1 *)(param_1 + 0xbe) = param_2;
  return;
}
}
