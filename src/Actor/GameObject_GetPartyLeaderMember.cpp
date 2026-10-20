#include <globaldefs.h>
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
extern "C" {
// Original: arm9/main @ 0x02039888; symbol: func_02039888; size: 0xC.
ARM int GameObject_GetPartyLeaderMember(int param_1)

{
  return (int)*(char *)(param_1 + 0x1ca);
}
}
