#include <globaldefs.h>
ARM
extern "C" void* Pool_AppendFreeNode(unsigned int);
// Original: arm9/ov001 @ 0x0215A3D8; symbol: func_ov001_0215a3d8; size: 0x20.
extern "C" void* func_ov001_0215a3d8(unsigned int a, unsigned int b) { void* p = Pool_AppendFreeNode(a); if (p) { *(unsigned int*)p = 4; *(unsigned int*)((char*)p + 0x10) = b; } return p; }
