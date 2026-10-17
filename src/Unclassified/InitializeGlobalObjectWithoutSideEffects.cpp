// Original: arm9/main @ 0x0205EC2C; symbol: func_0205ec2c; size: 0x4.
// Empty initializer for global object data_02108760; its class is unresolved.
// __sinit_020e5ee0 passes this address, then registers func_0205ec30 as destructor.
extern "C" void *InitializeGlobalObjectWithoutSideEffects(void *object)
{
    return object;
}
