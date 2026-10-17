#include <globaldefs.h>
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
extern "C" {
// Original: arm9/main @ 0x02039874; symbol: func_02039874; size: 0xC.
ARM int Object_ReadCharAtOffset1C9(int param_1)

{
  return (int)*(char *)(param_1 + 0x1c9);
}
}
