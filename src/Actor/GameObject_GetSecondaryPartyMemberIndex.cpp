#include <globaldefs.h>
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
extern "C" {
// Original: arm9/main @ 0x020546BC; symbol: func_020546bc; size: 0xC.
ARM int GameObject_GetSecondaryPartyMemberIndex(int param_1)

{
  return (int)*(char *)(param_1 + 0x2d1);
}
}
