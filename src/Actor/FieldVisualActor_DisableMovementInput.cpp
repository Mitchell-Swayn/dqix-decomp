#include <globaldefs.h>
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
extern "C" {
// Original: arm9/main @ 0x020A7F40; symbol: func_020a7f40; size: 0xC.
ARM void FieldVisualActor_DisableMovementInput(int param_1)

{
  *(undefined1 *)(param_1 + 0x154) = 0;
  return;
}
}
