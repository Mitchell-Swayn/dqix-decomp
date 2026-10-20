#include <globaldefs.h>
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
extern "C" {
// Original: arm9/main @ 0x0202E08C; symbol: func_0202e08c; size: 0x10.
ARM void Camera_SetObjectFlags(uint *param_1,uint param_2)

{
  *param_1 = *param_1 | param_2;
  return;
}
}
