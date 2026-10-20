extern "C" void ResourceManager_ExchangeGlobalValue(void*);
extern "C" int NNS_SndArcStrmStart(void*, int, int);
extern "C" void Sound_UpdatePlaybackAndFlushCommands();
// Original: arm9/main @ 0x0203AD14; symbol: func_0203ad14; size: 0x74.
extern "C" int ResourceHandle_StartIndexedRecordOperation(int* state, int id, int record, int options)
{
    if (*state == 0) {
        return 0;
    }
    ResourceManager_ExchangeGlobalValue(state + 1);
    *(short*)(state + 0x29) = (short)id;
    state[0x2a] = 0;
    int result;
    if (record != 0) {
        result = NNS_SndArcStrmStart((void*)record, id, options);
    } else {
        result = NNS_SndArcStrmStart(state + 0x27, id, options);
    }
    Sound_UpdatePlaybackAndFlushCommands();
    return result;
}
