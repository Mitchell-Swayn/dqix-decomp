#include <globaldefs.h>
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
extern "C" {
// Original: arm9/main @ 0x0202E98C; symbol: func_0202e98c; size: 0x18.
ARM void Camera_ClearYawTransition(int param_1)

{
  *(undefined2 *)(param_1 + 0x212) = 0;
  *(undefined2 *)(param_1 + 0x214) = 0;
  *(undefined2 *)(param_1 + 0x216) = 0;
  return;
}
}
