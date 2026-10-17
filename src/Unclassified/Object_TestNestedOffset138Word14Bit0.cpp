#include <globaldefs.h>
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
extern "C" {
// Original: arm9/main @ 0x02010088; symbol: func_02010088; size: 0x18.
ARM bool Object_TestNestedOffset138Word14Bit0(int param_1)

{
  return (*(uint *)(*(int *)(param_1 + 0x138) + 0x14) & 1) != 0;
}
}
