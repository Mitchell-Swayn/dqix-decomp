#include <globaldefs.h>
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
extern "C" {
// Original: arm9/main @ 0x02011B3C; symbol: func_02011b3c; size: 0x14.
ARM void GameState_AddTransitionRequestFlags(int param_1,byte param_2)

{
  *(byte *)(param_1 + 0x63dc) = *(byte *)(param_1 + 0x63dc) | param_2;
  return;
}
}
