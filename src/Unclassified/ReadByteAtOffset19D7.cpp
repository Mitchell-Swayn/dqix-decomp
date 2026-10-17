#include <globaldefs.h>
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
extern "C" {
// Original: arm9/main @ 0x02068980; symbol: func_02068980; size: 0xC.
ARM undefined1 ReadByteAtOffset19D7(undefined4 param_1,int param_2)

{
  return *(undefined1 *)(param_2 + 0x19d7);
}
}
