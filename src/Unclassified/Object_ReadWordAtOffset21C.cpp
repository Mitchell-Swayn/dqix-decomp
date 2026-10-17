#include <globaldefs.h>
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
extern "C" {
// Original: arm9/main @ 0x0204A438; symbol: func_0204a438; size: 0x8.
ARM undefined4 Object_ReadWordAtOffset21C(int param_1)

{
  return *(undefined4 *)(param_1 + 0x21c);
}
}
