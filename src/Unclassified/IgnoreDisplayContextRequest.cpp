// Original: arm9/main @ 0x02094B30; symbol: func_02094b30; size: 0x4.
// Ignores the context and two request arguments. Callers discard the return
// register; request semantics and any original library identity are unproven.
// Proposed descriptive symbol: IgnoreDisplayContextRequest (integrator migrates ABI).
extern "C" void IgnoreDisplayContextRequest(void* context, int request, int argument)
{
}
