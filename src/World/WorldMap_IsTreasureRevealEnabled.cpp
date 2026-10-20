#include <globaldefs.h>
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
extern "C" {
// Original: arm9/main @ 0x0202663C; symbol: func_0202663c; size: 0x8.
ARM undefined1 WorldMap_IsTreasureRevealEnabled(int param_1)

{
  return *(undefined1 *)(param_1 + 0x9ba);
}
}
