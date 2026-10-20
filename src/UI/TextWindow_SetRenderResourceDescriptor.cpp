#include <globaldefs.h>
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
extern "C" {
// Original: arm9/main @ 0x02042B30; symbol: func_02042b30; size: 0xC.
ARM void TextWindow_SetRenderResourceDescriptor(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x1e28) = param_2;
  return;
}
}
