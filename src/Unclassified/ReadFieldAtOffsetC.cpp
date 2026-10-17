#include <globaldefs.h>
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
extern "C" {
// Original: arm9/main @ 0x02097240; symbol: func_02097240; size: 0x8.
ARM int ReadFieldAtOffsetC(int param_1)

{
  return (int)*(short *)(param_1 + 0xc);
}
}
