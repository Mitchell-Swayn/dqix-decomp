// Original: arm9/main @ 0x02094B40; symbol: func_02094b40; size: 0x4.
// Ignores the context supplied by callers; the target contains only a return.
// Proposed descriptive name: IgnoreDisplayContextHook.
// Context identity is not established beyond the shared global getter.
extern "C" void DisplayContext_IgnoreHook(void* context)
{
    (void)context;
}
