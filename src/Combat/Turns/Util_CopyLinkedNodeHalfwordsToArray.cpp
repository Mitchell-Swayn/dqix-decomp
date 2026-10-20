#include <globaldefs.h>
ARM
// Original: arm9/ov000 @ 0x02181C6C; symbol: func_ov000_02181c6c; size: 0x28.
extern "C" unsigned int Util_CopyLinkedNodeHalfwordsToArray(void* unused, char* head, unsigned int* out) { unsigned int index = 0; char* node = *(char**)(head + 0x10); while (node) { out[index] = *(unsigned short*)(node + 0x20); node = *(char**)(node + 0x30); index++; } return index; }
