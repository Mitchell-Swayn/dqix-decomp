#include <globaldefs.h>
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
extern "C" {
// Original: arm9/main @ 0x0209C0EC; symbol: func_0209c0ec; size: 0x8.
ARM undefined2 Script_GetSelectedIdCount(int param_1)

{
  return *(undefined2 *)(param_1 + 0x18);
}
}
