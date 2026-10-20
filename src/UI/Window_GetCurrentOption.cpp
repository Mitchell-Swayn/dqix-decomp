#include <globaldefs.h>
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
extern "C" {
// Original: arm9/main @ 0x020E2910; symbol: func_020e2910; size: 0x8.
ARM int Window_GetCurrentOption(int param_1)

{
  return (int)*(char *)(param_1 + 0x14);
}
}
