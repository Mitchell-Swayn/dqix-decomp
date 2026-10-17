#include <globaldefs.h>
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
extern "C" {
// Original: arm9/main @ 0x020DF774; symbol: func_020df774; size: 0x8.
ARM int ReadFirstSignedHalfwordAsInteger(short *param_1)

{
  return (int)*param_1;
}
}
