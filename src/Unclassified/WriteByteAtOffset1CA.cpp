#include <globaldefs.h>
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
extern "C" {
// Original: arm9/main @ 0x02039880; symbol: func_02039880; size: 0x8.
ARM void WriteByteAtOffset1CA(int param_1,undefined1 param_2)

{
  *(undefined1 *)(param_1 + 0x1ca) = param_2;
  return;
}
}
