#include <globaldefs.h>
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
extern "C" {
// Original: arm9/main @ 0x02033E2C; symbol: func_02033e2c; size: 0xC.
ARM void ClearHalfwordAtOffsetC6(int param_1)

{
  *(undefined2 *)(param_1 + 0xc6) = 0;
  return;
}
}
