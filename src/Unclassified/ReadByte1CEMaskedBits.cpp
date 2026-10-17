#include <globaldefs.h>
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
extern "C" {
// Original: arm9/main @ 0x02039790; symbol: func_02039790; size: 0xC.
ARM uint ReadByte1CEMaskedBits(int param_1,uint param_2)

{
  return *(byte *)(param_1 + 0x1ce) & param_2;
}
}
