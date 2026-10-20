#include <globaldefs.h>
ARM
// Original: arm9/ov025 @ 0x021E24A8; symbol: func_ov025_021e24a8; size: 0x28.
extern "C" unsigned int Util_ContainsLinkedNode(void** head, void* target) { void* node = *head; while (node) { if (node == target) return 1; node = *(void**)((char*)node + 8); } return 0; }
