#include <globaldefs.h>
ARM
extern "C" void* Memory_AppendFreePoolNode(unsigned int);
// Original: arm9/ov001 @ 0x0215A6DC; symbol: func_ov001_0215a6dc; size: 0x20.
extern "C" void* func_ov001_0215a6dc(unsigned int a, unsigned int b) { void* p = Memory_AppendFreePoolNode(a); if (p) { *(unsigned int*)p = 0x19; *(unsigned int*)((char*)p + 0x10) = b; } return p; }
