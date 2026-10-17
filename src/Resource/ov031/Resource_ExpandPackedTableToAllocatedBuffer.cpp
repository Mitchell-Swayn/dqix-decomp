#include <globaldefs.h>
ARM
extern "C" void* Ov031_ForwardGlobalIndexedWord(unsigned int table, unsigned int index);
extern "C" void ExpandPackedSixByteEntriesToEight(unsigned int table, unsigned int index, void* output);
// Original: arm9/ov031 @ 0x0223BE44; symbol: func_ov031_0223be44; size: 0x2C.
extern "C" void* Resource_ExpandPackedTableToAllocatedBuffer(unsigned int table, unsigned int index) { void* output = Ov031_ForwardGlobalIndexedWord(table, index); ExpandPackedSixByteEntriesToEight(table, index, output); return output; }
