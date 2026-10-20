#include <globaldefs.h>
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
extern "C" {
// Original: arm9/main @ 0x020546A0; symbol: func_020546a0; size: 0x8.
ARM void GameObject_SetAssociatedPartyMemberIndex(int param_1,undefined1 param_2)

{
  *(undefined1 *)(param_1 + 0x2d0) = param_2;
  return;
}
}
