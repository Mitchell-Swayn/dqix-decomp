#include <globaldefs.h>
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
extern "C" {
// Original: arm9/main @ 0x02027BAC; symbol: func_02027bac; size: 0x10.
ARM void WorldMap_SetPartyOverlaySuppressionFlags(int param_1,byte param_2)

{
  *(byte *)(param_1 + 0xa97) = *(byte *)(param_1 + 0xa97) | param_2;
  return;
}
}
