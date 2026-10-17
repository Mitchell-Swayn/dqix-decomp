#include <globaldefs.h>
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
extern "C" {
// Original: arm9/main @ 0x0202E7F0; symbol: func_0202e7f0; size: 0x8.
ARM undefined4 ReadWordAtOffset70(int param_1)

{
  return *(undefined4 *)(param_1 + 0x70);
}
}
