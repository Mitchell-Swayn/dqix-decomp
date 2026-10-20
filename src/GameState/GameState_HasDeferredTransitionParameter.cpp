#include <globaldefs.h>
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
extern "C" {
// Original: arm9/main @ 0x02011610; symbol: func_02011610; size: 0x18.
ARM bool GameState_HasDeferredTransitionParameter(int param_1)

{
  return *(unsigned short *)(param_1 + 0x63da) != 0;
}
}
