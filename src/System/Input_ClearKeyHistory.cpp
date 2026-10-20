#include <globaldefs.h>
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
extern "C" {
// Original: arm9/main @ 0x02012518; symbol: func_02012518; size: 0x10.
ARM void Input_ClearKeyHistory(undefined2 *param_1)

{
  param_1[1] = 0;
  *param_1 = 0;
  return;
}
}
