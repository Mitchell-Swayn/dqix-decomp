#include <globaldefs.h>
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
extern "C" {
// Original: arm9/main @ 0x02011634; symbol: func_02011634; size: 0x10.
ARM void Object_ClearHalfwordAtOffset63DA(int param_1)

{
  *(undefined2 *)(param_1 + 0x63da) = 0;
  return;
}
}
