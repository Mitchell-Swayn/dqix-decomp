// Original: arm9/main @ 0x0205CB60; symbol: func_0205cb60; size: 0x4.
// Returns without accessing the embedded owner state passed in r0.
// Callers pass owner+0x3D4, owner+0x24, or owner+0x2C; no result is consumed.
// Proposed descriptive name: IgnoreEmbeddedOwnerState.
extern "C" void IgnoreEmbeddedOwnerState(void* embeddedState)
{
    (void)embeddedState;
}
