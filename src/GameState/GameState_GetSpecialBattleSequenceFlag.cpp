#include <globaldefs.h>
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
extern "C" {
// Original: arm9/main @ 0x02012060; symbol: func_02012060; size: 0xC.
ARM undefined1 GameState_GetSpecialBattleSequenceFlag(int param_1)

{
  return *(undefined1 *)(param_1 + 0x63d5);
}
}
