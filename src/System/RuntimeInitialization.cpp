#pragma optimize_for_size off
typedef void (*RuntimeInitializer)();
extern RuntimeInitializer gRuntimeInitializers[];
// Original: arm9/main @ 0x0200EDC8; symbol: func_0200edc8; size: 0x2C.
extern "C" void Runtime_RunGlobalInitializers()
{
    RuntimeInitializer* entry = gRuntimeInitializers;
    while (entry && *entry) {
        (*entry)();
        ++entry;
    }
}
