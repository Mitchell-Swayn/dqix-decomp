#include <globaldefs.h>
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
extern "C" {
// Original: arm9/main @ 0x0202B828; symbol: func_0202b828; size: 0x18.
ARM void Network_ActivateHostSession(undefined4 *param_1)

{
  param_1[0x402] = 1;
  *param_1 = 5;
  return;
}
}
