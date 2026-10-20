#include <globaldefs.h>
// func_02097408: 0x02097408–0x02097418, arm; 16 bytes
// Original: arm9/main @ 0x02097408; symbol: func_02097408; size: 0x10.
extern "C" unsigned int BestiaryList_ComputeEntryDataSize(const int* value) {
    return ((unsigned int)*value << 20) >> 15;
}
