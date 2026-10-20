// Original: arm9/main @ 0x02094B3C; symbol: func_02094b3c; size: 0x4.
// Ignores a display-context parameter supplied before transition requests.
// ABI: callers provide context in r0 and an integer in r1; no return is used.
// Proposed name: DisplayContext_IgnoreTransitionParameter. Transition purpose
// is inferred from call order; the original option meaning remains unknown.
extern "C" void DisplayContext_IgnoreTransitionParameter(void *context, int parameter)
{
    (void)context;
    (void)parameter;
}
