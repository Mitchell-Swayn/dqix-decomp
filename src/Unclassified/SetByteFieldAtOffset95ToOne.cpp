#include <globaldefs.h>
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
extern "C" {
// Original: arm9/main @ 0x0205CF04; symbol: func_0205cf04; size: 0xC.
ARM void SetByteFieldAtOffset95ToOne(int param_1)

{
  *(undefined1 *)(param_1 + 0x95) = 1;
  return;
}
}
