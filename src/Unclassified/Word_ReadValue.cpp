#include <globaldefs.h>
ARM
struct Word { unsigned value:8; unsigned rest:24; };
// Original: arm9/main @ 0x020797F8; symbol: func_020797f8; size: 0x10.
extern "C" unsigned Word_ReadValue(Word* p){return p->value;}
