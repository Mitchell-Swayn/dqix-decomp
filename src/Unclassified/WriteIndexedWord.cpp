#include <globaldefs.h>
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
extern "C" {
// Original: arm9/main @ 0x020B0334; symbol: func_020b0334; size: 0x8.
ARM void WriteIndexedWord(int param_1,int param_2,undefined4 param_3)

{
  *(undefined4 *)(param_1 + param_2 * 4) = param_3;
  return;
}
}
