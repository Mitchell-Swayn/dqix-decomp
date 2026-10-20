#include <globaldefs.h>
ARM
// Original: arm9/ov000 @ 0x0215FF50; symbol: func_ov000_0215ff50; size: 0x30.
extern "C" void GameState_AppendIndexedEvent(unsigned char* p, unsigned short value, unsigned char flag) { if (p[0x17] < 3) { *(unsigned short*)(p + 0xe + p[0x17] * 2) = value; unsigned char* q = p + p[0x17]; q[0x14] = flag; p[0x17] = p[0x17] + 1; } }
