#include <globaldefs.h>
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
extern "C" {
// Original: arm9/main @ 0x02026420; symbol: func_02026420; size: 0x8.
ARM void SetByteFieldAtOffset765(int param_1,undefined1 param_2)

{
  *(undefined1 *)(param_1 + 0x765) = param_2;
  return;
}
}
