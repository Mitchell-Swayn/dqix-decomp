#include <globaldefs.h>
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
extern "C" {
// Original: arm9/main @ 0x02039DE8; symbol: func_02039de8; size: 0xC.
ARM byte ReadByteAtOffset1CEMasked10(int param_1)

{
  return *(byte *)(param_1 + 0x1ce) & 0x10;
}
}
