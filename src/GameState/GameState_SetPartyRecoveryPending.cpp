#include <globaldefs.h>
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
extern "C" {
// Original: arm9/main @ 0x0201075C; symbol: func_0201075c; size: 0xC.
ARM void GameState_SetPartyRecoveryPending(int param_1,undefined1 param_2)

{
  *(undefined1 *)(param_1 + 0x5729) = param_2;
  return;
}
}
