#include <globaldefs.h>
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
extern "C" {
// Original: arm9/main @ 0x0203B534; symbol: func_0203b534; size: 0xC.
ARM uint Object_ReadMaskedWordAtOffset8(int param_1,uint param_2)

{
  return *(uint *)(param_1 + 8) & param_2;
}
}
