#include <globaldefs.h>
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
extern "C" {
// Original: arm9/main @ 0x02033F5C; symbol: func_02033f5c; size: 0x10.
ARM uint ReadFieldE0Bit6(int param_1)

{
  return ((uint)*(byte *)(param_1 + 0xe0) << 0x19) >> 0x1f;
}
}
