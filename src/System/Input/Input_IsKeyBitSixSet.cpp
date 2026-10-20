#include <globaldefs.h>
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
extern "C" {
// Original: arm9/main @ 0x020123B8; symbol: func_020123b8; size: 0x14.
ARM bool Input_IsKeyBitSixSet(ushort *param_1)

{
  return (*param_1 & 0x40) != 0;
}
}
