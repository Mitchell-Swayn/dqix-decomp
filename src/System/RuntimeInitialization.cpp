#pragma optimize_for_size off
typedef void (*RuntimeInitializer)();
extern RuntimeInitializer gRuntimeInitializers[];
extern "C" void func_0200edc8()
{
    RuntimeInitializer* entry = gRuntimeInitializers;
    while (entry && *entry) {
        (*entry)();
        ++entry;
    }
}
