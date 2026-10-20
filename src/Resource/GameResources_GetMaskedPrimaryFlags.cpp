#include <globaldefs.h>
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
extern "C" {
// Original: arm9/main @ 0x0203B4C4; symbol: func_0203b4c4; size: 0xC.
ARM uint GameResources_GetMaskedPrimaryFlags(uint *param_1,uint param_2)

{
  return *param_1 & param_2;
}
}
