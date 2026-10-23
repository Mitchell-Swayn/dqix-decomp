#include <globaldefs.h>
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
extern "C" {
// Original: arm9/main @ 0x020546B4; symbol: func_020546b4; size: 0x8.
extern "C" ARM void GameObject_SetSecondaryPartyMemberIndex(int param_1,int param_2)

{
  *(undefined1 *)(param_1 + 0x2d1) = param_2;
  return;
}
}
