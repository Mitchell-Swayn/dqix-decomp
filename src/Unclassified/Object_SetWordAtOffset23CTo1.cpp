#include <globaldefs.h>
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
extern "C" {
// Original: arm9/main @ 0x020A27AC; symbol: func_020a27ac; size: 0xC.
ARM void Object_SetWordAtOffset23CTo1(int param_1)

{
  *(undefined4 *)(param_1 + 0x23c) = 1;
  return;
}
}
