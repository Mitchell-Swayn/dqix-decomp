#include "System/RuntimeState.h"

typedef char ExitStateSizeCheck[sizeof(RuntimeExitState) == 16 ? 1 : -1];
RuntimeExitState data_020f2e60;
// The 256-byte allocation contains 64 callback slots. The exit path uses the
// separately stored count; no registration policy is inferred from its extent.
RuntimeExitHandler volatile data_020f2e70[64];
