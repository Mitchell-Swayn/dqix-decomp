#include <globaldefs.h>
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
extern "C" {
// Original: arm9/main @ 0x020DB2D4; symbol: func_020db2d4; size: 0x8.
ARM undefined1 ReadByteFieldAtOffset50(int param_1)

{
  return *(undefined1 *)(param_1 + 0x50);
}
}
