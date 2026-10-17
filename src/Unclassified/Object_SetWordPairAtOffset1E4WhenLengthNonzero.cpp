#include <globaldefs.h>
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
extern "C" {
// Original: arm9/main @ 0x0202EA10; symbol: func_0202ea10; size: 0x10.
ARM void Object_SetWordPairAtOffset1E4WhenLengthNonzero(int param_1,undefined4 param_2,int param_3)

{
  if (param_3 != 0) {
    *(undefined4 *)(param_1 + 0x1e4) = param_2;
    *(int *)(param_1 + 0x1e8) = param_3;
  }
  return;
}
}
