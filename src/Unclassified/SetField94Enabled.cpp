#include <globaldefs.h>
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
extern "C" {
// Original: arm9/main @ 0x0205CEF8; symbol: func_0205cef8; size: 0xC.
ARM void SetField94Enabled(int param_1)

{
  *(undefined1 *)(param_1 + 0x94) = 1;
  return;
}
}
