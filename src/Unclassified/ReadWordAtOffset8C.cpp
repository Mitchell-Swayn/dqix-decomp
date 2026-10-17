#include <globaldefs.h>
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
extern "C" {
// Original: arm9/main @ 0x0203E06C; symbol: func_0203e06c; size: 0x8.
ARM undefined4 ReadWordAtOffset8C(int param_1)

{
  return *(undefined4 *)(param_1 + 0x8c);
}
}
