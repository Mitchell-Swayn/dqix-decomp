#include <globaldefs.h>
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
extern "C" {
// Original: arm9/main @ 0x02039DCC; symbol: func_02039dcc; size: 0xC.
ARM byte ReadByte1CEBit3Mask(int param_1)

{
  return *(byte *)(param_1 + 0x1ce) & 8;
}
}
