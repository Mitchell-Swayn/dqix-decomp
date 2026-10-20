#include <globaldefs.h>
// Original: arm9/main @ 0x0205C508; symbol: func_0205c508; size: 0x34.
extern "C" void Selection_ComputeBoundedPageEntryRange(const int* descriptor, int* firstSize, int* totalSize)
{
    int rowSize = descriptor[2] * descriptor[3];
    *firstSize = rowSize * descriptor[5];
    *totalSize = *firstSize + rowSize;
    if (descriptor[0] < *totalSize) *totalSize = descriptor[0];
}
