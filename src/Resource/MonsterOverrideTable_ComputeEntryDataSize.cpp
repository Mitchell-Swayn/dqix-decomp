#include <globaldefs.h>
// func_020a8f60: 0x020a8f60–0x020a8f70, arm; 16 bytes
// Original: arm9/main @ 0x020A8F60; symbol: func_020a8f60; size: 0x10.
extern "C" unsigned int MonsterOverrideTable_ComputeEntryDataSize(const int* value) {
    return ((unsigned int)*value << 20) >> 14;
}
