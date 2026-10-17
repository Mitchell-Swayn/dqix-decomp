extern "C" void ResourceManager_ExchangeGlobalValue(void*);
extern "C" int ProcessObjectAfterReadinessPredicate(void*, int, int);
extern "C" void Object_Invokewhile();
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
        result = ProcessObjectAfterReadinessPredicate((void*)record, id, options);
    } else {
        result = ProcessObjectAfterReadinessPredicate(state + 0x27, id, options);
    }
    Object_Invokewhile();
    return result;
}
