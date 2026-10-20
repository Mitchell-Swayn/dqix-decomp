#include <globaldefs.h>
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
extern "C" {
// Original: arm9/main @ 0x0200FFD0; symbol: func_0200ffd0; size: 0x10.
ARM int GameState_GetAuxiliaryFieldObject(int param_1)

{
  int iVar1;

  iVar1 = *(int *)(param_1 + 0x330);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  return iVar1;
}
}
