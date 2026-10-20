#include <globaldefs.h>
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
extern "C" {
// Original: arm9/main @ 0x02012408; symbol: func_02012408; size: 0x14.
ARM bool Input_IsXButtonHeld(ushort *param_1)

{
  return (*param_1 & 0x400) != 0;
}
}
