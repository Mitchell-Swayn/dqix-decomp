#include <globaldefs.h>
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
extern "C" {
// Original: arm9/main @ 0x02012780; symbol: func_02012780; size: 0x18.
ARM void ClearFourByteFieldsAtOffset50(int param_1)

{
  *(undefined1 *)(param_1 + 0x52) = 0;
  *(undefined1 *)(param_1 + 0x53) = 0;
  *(undefined1 *)(param_1 + 0x51) = 0;
  *(undefined1 *)(param_1 + 0x50) = 0;
  return;
}
}
