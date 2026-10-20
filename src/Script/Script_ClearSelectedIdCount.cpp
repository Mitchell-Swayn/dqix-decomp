#include <globaldefs.h>
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
extern "C" {
// Original: arm9/main @ 0x0209BFFC; symbol: func_0209bffc; size: 0xC.
ARM void Script_ClearSelectedIdCount(int param_1)

{
  *(undefined2 *)(param_1 + 0x18) = 0;
  return;
}
}
