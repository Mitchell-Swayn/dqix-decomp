#include <globaldefs.h>
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
extern "C" {
// Original: arm9/main @ 0x020A277C; symbol: func_020a277c; size: 0xC.
ARM int ReadFieldAtOffset21C(int param_1)

{
  return (int)*(short *)(param_1 + 0x21c);
}
}
