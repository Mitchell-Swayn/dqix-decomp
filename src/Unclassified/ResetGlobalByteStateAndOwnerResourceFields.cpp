extern "C" void ClearRecordBuffersAndIndexedCategory();
extern "C" void Object_ClearOffset47CThrough498GlobalState(void*);
// Original: arm9/main @ 0x02064D1C; symbol: func_02064d1c; size: 0x1C.
extern "C" void* ResetGlobalByteStateAndOwnerResourceFields(void* object)
{
    ClearRecordBuffersAndIndexedCategory();
    Object_ClearOffset47CThrough498GlobalState(object);
    return object;
}
