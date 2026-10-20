#include <globaldefs.h>
ARM
extern "C" void* Queue_AppendNodeFromFreeList(void*);
// Original: arm9/ov001 @ 0x0215913C; symbol: func_ov001_0215913c; size: 0x2C.
extern "C" void* System_QueueAppendFourWordRecord(void* queue, unsigned int a, unsigned int b, unsigned int c) { unsigned int* node = (unsigned int*)Queue_AppendNodeFromFreeList(queue); if (node) { node[0] = 0xd; node[1] = a; node[2] = b; node[3] = c; } return node; }
