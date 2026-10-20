#include <globaldefs.h>
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
extern "C" {
// Original: arm9/main @ 0x02053EB4; symbol: func_02053eb4; size: 0xC.
ARM undefined1 GameObject_GetResolvedAttachmentBone(int param_1,int param_2)

{
  return *(undefined1 *)(param_1 + param_2 + 0x1a0);
}
}
