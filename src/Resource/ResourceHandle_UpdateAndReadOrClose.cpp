#pragma optimize_for_size off
extern "C" void ResourceManager_ExchangeGlobalValue(void*);
extern "C" void TestResourceLoadWithAllByteFlagsAndModeOne(int, int);
extern "C" void ResourceManager_TestCommandWithModeOne(int, int, int);
extern "C" int SaveAllocatorStateOrRestoreOnFailure(int);
// Original: arm9/main @ 0x0203AAF8; symbol: func_0203aaf8; size: 0x74.
extern "C" int ResourceHandle_UpdateAndReadOrClose(int* state, int mode, int* output)
{
    if (*state == 0) {
        return 0;
    }
    ResourceManager_ExchangeGlobalValue(state + 1);
    if (output != 0) {
        ResourceManager_TestCommandWithModeOne(mode, 3, *state);
        *output = SaveAllocatorStateOrRestoreOnFailure(*state);
        ResourceManager_TestCommandWithModeOne(mode, 4, *state);
    } else {
        TestResourceLoadWithAllByteFlagsAndModeOne(mode, *state);
    }
    return 1;
}
