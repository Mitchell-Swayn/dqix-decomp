#include <globaldefs.h>
ARM
// Original: arm9/ov000 @ 0x02169B04; symbol: func_ov000_02169b04; size: 0x28.
extern "C" void* Util_FindLinkedNodeByWord(unsigned int* head, unsigned int key) { unsigned int* node = (unsigned int*)((char*)head + 8); node = (unsigned int*)node[0]; while (node) { if (node[0] == key) return node; node = (unsigned int*)node[1]; } return 0; }
