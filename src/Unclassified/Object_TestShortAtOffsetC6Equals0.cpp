#include <globaldefs.h>
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
extern "C" {
// Original: arm9/main @ 0x02033EC8; symbol: func_02033ec8; size: 0x14.
ARM bool Object_TestShortAtOffsetC6Equals0(int param_1)

{
  return *(short *)(param_1 + 0xc6) == 0;
}
}
