#include "Graphics/NSBXX/RenderCommands_Common.h"

// Command 9 caches one 4x4 and one 3x3 matrix per inverse-bind bit.
// The handler has two 32-bit validity words; 64 * 100 spans this allocation.
Struct_0210b678 data_0210b678[64];
typedef char InverseBindRecordSizeCheck[sizeof(Struct_0210b678) == 100 ? 1 : -1];
typedef char InverseBindScratchSizeCheck[sizeof(data_0210b678) == 6400 ? 1 : -1];
