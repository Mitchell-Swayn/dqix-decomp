#include <globaldefs.h>
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
extern "C" {
// Original: arm9/main @ 0x0209C3AC; symbol: func_0209c3ac; size: 0x8.
ARM undefined1 ReadByteFieldAtOffsetCD(int param_1)

{
  return *(undefined1 *)(param_1 + 0xcd);
}
}
