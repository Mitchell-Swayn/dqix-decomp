#include "System/RuntimeUnwindTable.h"
// Keep independent endpoint declarations: the empty boundaries have the same
// existing linker symbol, but the original retains two literal-pool references.
namespace BeginBoundary { extern "C" void __sinit_020e5920(); }
namespace EndBoundary { extern "C" void __sinit_020e5920(); }
// Original: arm9/main @ 0x0200F29C; symbol: func_0200f29c; size: 0x20.
// Sets the runtime unwind range to empty. Both boundaries coincide with static-initializer code.
// Proposed descriptive name: RuntimeUnwind_InitializeEmptyRange.
extern "C" int RuntimeUnwind_InitializeEmptyRange(RuntimeUnwindTable *state, unsigned int address) {
 state->begin=(const RuntimeUnwindRange *)&BeginBoundary::__sinit_020e5920;
 state->end=(const RuntimeUnwindRange *)&EndBoundary::__sinit_020e5920;
 return 1;
}
