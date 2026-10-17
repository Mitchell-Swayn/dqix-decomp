#include <globaldefs.h>
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
extern "C" {
// Original: arm9/main @ 0x0209CA68; symbol: func_0209ca68; size: 0x8.
ARM undefined4 Object_ReadWordAtOffsetB0(int param_1)

{
  return *(undefined4 *)(param_1 + 0xb0);
}
}
