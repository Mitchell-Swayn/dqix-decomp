#include <globaldefs.h>
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
extern "C" {
// Original: arm9/main @ 0x0206EF40; symbol: func_0206ef40; size: 0x8.
ARM int MonsterData_GetRecordId(int param_1)

{
  return (int)*(short *)(param_1 + 8);
}
}
