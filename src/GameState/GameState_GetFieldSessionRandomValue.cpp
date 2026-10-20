#include <globaldefs.h>
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
extern "C" {
// Original: arm9/main @ 0x02012078; symbol: func_02012078; size: 0xC.
ARM undefined4 GameState_GetFieldSessionRandomValue(int param_1)

{
  return *(undefined4 *)(param_1 + 0x71f8);
}
}
