#include <globaldefs.h>
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
extern "C" {
// Original: arm9/main @ 0x020797D0; symbol: func_020797d0; size: 0xC.
ARM void Object_ClearByteAtOffset17E(int param_1)

{
  *(undefined1 *)(param_1 + 0x17e) = 0;
  return;
}
}
