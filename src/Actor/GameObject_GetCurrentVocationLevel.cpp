#include <globaldefs.h>
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
extern "C" {
// Original: arm9/main @ 0x0202053C; symbol: func_0202053c; size: 0x18.
ARM undefined2 GameObject_GetCurrentVocationLevel(int param_1)

{
  return *(undefined2 *)
          (*(int *)(param_1 + 0x150) + *(int *)(*(int *)(param_1 + 0x150) + 0x950) * 2 + 0x16c);
}
}
