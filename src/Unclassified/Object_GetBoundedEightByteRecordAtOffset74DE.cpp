#include <globaldefs.h>
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
extern "C" {
// Original: arm9/main @ 0x020120A0; symbol: func_020120a0; size: 0x18.
ARM int Object_GetBoundedEightByteRecordAtOffset74DE(int param_1,uint param_2)

{
  int iVar1;

  if (param_2 < 4) {
    iVar1 = param_1 + 0x74de + param_2 * 8;
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}
}
