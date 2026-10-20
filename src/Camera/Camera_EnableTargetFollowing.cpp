#include <globaldefs.h>
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
extern "C" {
// Original: arm9/main @ 0x020A2794; symbol: func_020a2794; size: 0xC.
ARM void Camera_EnableTargetFollowing(int param_1)

{
  *(undefined4 *)(param_1 + 0x238) = 1;
  return;
}
}
