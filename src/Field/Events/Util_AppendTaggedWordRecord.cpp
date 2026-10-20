#include <globaldefs.h>
ARM
// Original: arm9/ov017 @ 0x021D4AD8; symbol: func_ov017_021d4ad8; size: 0x20.
extern "C" void Util_AppendTaggedWordRecord(char* p, unsigned int value) { *(unsigned int*)(*(unsigned int**)(p + 0x14)) = 1; unsigned int* cursor = *(unsigned int**)(p + 0x14); *(unsigned int**)(p + 0x14) = cursor + 2; cursor[1] = value; }
