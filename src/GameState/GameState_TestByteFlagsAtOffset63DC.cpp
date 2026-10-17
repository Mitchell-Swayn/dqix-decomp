#include <globaldefs.h>
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
extern "C" {
// Original: arm9/main @ 0x02011B50; symbol: func_02011b50; size: 0x18.
ARM bool GameState_TestByteFlagsAtOffset63DC(int param_1,byte param_2)

{
  return (*(byte *)(param_1 + 0x63dc) & param_2) != 0;
}
}
