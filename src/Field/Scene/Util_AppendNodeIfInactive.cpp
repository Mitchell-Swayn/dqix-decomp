#include <globaldefs.h>
ARM
extern "C" void LinkedQueue_AppendAndMarkActive(unsigned int*, unsigned int);
// Original: arm9/ov017 @ 0x0219BC88; symbol: func_ov017_0219bc88; size: 0x24.
extern "C" void Util_AppendNodeIfInactive(char* p) { p += 0x3000; unsigned int* node = *(unsigned int**)(p + 0xbb4); if (*((unsigned char*)node + 2) == 0) LinkedQueue_AppendAndMarkActive(*(unsigned int**)(p + 0x6fc), (unsigned int)node); }
