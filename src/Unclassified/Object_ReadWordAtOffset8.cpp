#include <globaldefs.h>
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
extern "C" {
// Original: arm9/main @ 0x0203B508; symbol: func_0203b508; size: 0x8.
ARM undefined4 Object_ReadWordAtOffset8(int param_1)

{
  return *(undefined4 *)(param_1 + 8);
}
}
