#include <globaldefs.h>
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
extern "C" {
// Original: arm9/main @ 0x0201250C; symbol: func_0201250c; size: 0xC.
ARM void Input_SuppressKeyRepeatUntilRelease(int param_1)

{
  *(undefined4 *)(param_1 + 0x18) = 0xffffffff;
  return;
}
}
