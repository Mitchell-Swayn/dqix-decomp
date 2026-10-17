#include <globaldefs.h>
ARM
extern "C" void InitializeObjectHandlesAndInvalidIndices(int object);
extern "C" unsigned int data_02109bf4;
// Original: arm9/ov001 @ 0x021637D4; symbol: func_ov001_021637d4; size: 0x18.
extern "C" int System_InitializeObjectHandleTable(void) { InitializeObjectHandlesAndInvalidIndices((int)&data_02109bf4); return 1; }
