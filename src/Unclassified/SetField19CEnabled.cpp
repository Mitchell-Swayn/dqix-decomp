#include <globaldefs.h>
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
extern "C" {
// Original: arm9/main @ 0x020AE380; symbol: func_020ae380; size: 0xC.
ARM void SetField19CEnabled(int param_1)

{
  *(undefined1 *)(param_1 + 0x19c) = 1;
  return;
}
}
