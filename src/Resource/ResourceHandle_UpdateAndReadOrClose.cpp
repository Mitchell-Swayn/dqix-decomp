#pragma optimize_for_size off
extern "C" void ResourceManager_ExchangeGlobalValue(void*);
extern "C" void NNS_SndArcLoadSeq(int, int);
extern "C" void ResourceManager_TestCommandWithModeOne(int, int, int);
extern "C" int NNS_SndHeapSaveState(int);
// Original: arm9/main @ 0x0203AAF8; symbol: func_0203aaf8; size: 0x74.
extern "C" int ResourceHandle_UpdateAndReadOrClose(int* state, int mode, int* output)
{
    if (*state == 0) {
        return 0;
    }
    ResourceManager_ExchangeGlobalValue(state + 1);
    if (output != 0) {
        ResourceManager_TestCommandWithModeOne(mode, 3, *state);
        *output = NNS_SndHeapSaveState(*state);
        ResourceManager_TestCommandWithModeOne(mode, 4, *state);
    } else {
        NNS_SndArcLoadSeq(mode, *state);
    }
    return 1;
}
