#include <globaldefs.h>
ARM
struct Record { unsigned int padding; unsigned int value : 12; unsigned int remainder : 20; };
// Original: arm9/main @ 0x02097420; symbol: func_02097420; size: 0x10.
extern "C" unsigned int ReadWord4Low12Bits(Record* p) { return p->value; }
