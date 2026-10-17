#include <globaldefs.h>
// Follows the indexed pointer chain at offsets 0x150, 0x950 and 0x138.
// Original: arm9/ov023 @ 0x021EEA98; symbol: func_ov023_021eea98; size: 0x14.
extern "C" void* ReadIndexedField138ThroughObjectChain(void* self) {
    char* base = *(char**)((char*)self + 0x150);
    unsigned int index = *(unsigned int*)(base + 0x950);
    return *(void**)(base + index * 4 + 0x138);
}
