#include <globaldefs.h>
ARM
extern "C" void ObjectPool_ResetDisplayEntry(void*);
// Original: arm9/main @ 0x02059CB4; symbol: func_02059cb4; size: 0x14.
extern "C" void* ObjectPool_ConstructDisplayEntry(void* p){ObjectPool_ResetDisplayEntry(p);return p;}
