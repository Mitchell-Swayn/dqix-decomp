#include <globaldefs.h>
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
extern "C" {
// Original: arm9/main @ 0x02012040; symbol: func_02012040; size: 0x10.
ARM void Object_SetByte63D5(int param_1)

{
  *(undefined1 *)(param_1 + 0x63d5) = 1;
  return;
}
}
