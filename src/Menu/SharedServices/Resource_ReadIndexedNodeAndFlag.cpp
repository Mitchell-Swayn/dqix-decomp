#include <globaldefs.h>
ARM
extern "C" int Resource_CombineTypeSevenFieldWithRowIndex(int);
// Original data: arm9/ov004 @ 0x217101c; symbol: data_ov004_0217101c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" unsigned int FilesystemQueuePositionRecord_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov004 @ 0x021666BC; symbol: Resource_ReadIndexedNodeAndFlag; size: 0x74.
// Follows the selected node index, outputs its halfword+2 bit 2, and returns the signed node halfword or -1.
extern "C" int Resource_ReadIndexedNodeAndFlag(int start, unsigned char* output) {
    int count = Resource_CombineTypeSevenFieldWithRowIndex(start);
    unsigned char* root = (unsigned char*)FilesystemQueuePositionRecord_UnknownRoleZeroInitializedStorage[0];
    unsigned char* node = *(unsigned char**)(root + 8);
    *output = 0;
    while (node != 0 && count != 0) {
        count = (short)(count - 1);
        node = *(unsigned char**)(node + 8);
    }
    if (node == 0) goto missing;
    unsigned bit = ((unsigned)*(unsigned short*)(node + 2) << 29) >> 31;
    if (bit != 0)
        *output = 1;
    else
        *output = 0;
    return *(short*)node;
missing:
    return -1;
}
