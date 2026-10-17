#include <globaldefs.h>
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
extern "C" {
// Original: arm9/main @ 0x020A093C; symbol: func_020a093c; size: 0xC.
ARM void Object_SetTwoWordsAndFollowingHalfword(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined2 param_4)

{
  *param_1 = param_2;
  param_1[1] = param_3;
  *(undefined2 *)(param_1 + 2) = param_4;
  return;
}
}
