#include <globaldefs.h>
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
extern "C" {
// Original: arm9/main @ 0x0202E948; symbol: func_0202e948; size: 0x14.
ARM void ClearHalfwords20EAnd210(int param_1)

{
  *(undefined2 *)(param_1 + 0x20e) = 0;
  *(undefined2 *)(param_1 + 0x210) = 0;
  return;
}
}
