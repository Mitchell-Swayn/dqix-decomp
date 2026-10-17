#include <globaldefs.h>
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
extern "C" {
// Original: arm9/main @ 0x02032FD0; symbol: func_02032fd0; size: 0xC.
ARM void SetHalfwordFieldsAtOffsetsBAAndBC(int param_1,undefined2 param_2,undefined2 param_3)

{
  *(undefined2 *)(param_1 + 0xba) = param_2;
  *(undefined2 *)(param_1 + 0xbc) = param_3;
  return;
}
}
