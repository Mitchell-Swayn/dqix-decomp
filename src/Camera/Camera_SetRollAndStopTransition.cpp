#include <globaldefs.h>
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
extern "C" {
// Original: arm9/main @ 0x0202E874; symbol: func_0202e874; size: 0x18.
ARM void Camera_SetRollAndStopTransition(int param_1,undefined2 param_2)

{
  *(undefined2 *)(param_1 + 0x7c) = param_2;
  *(undefined2 *)(param_1 + 0x1ec) = 0;
  *(undefined2 *)(param_1 + 0x1ee) = 0;
  return;
}
}
