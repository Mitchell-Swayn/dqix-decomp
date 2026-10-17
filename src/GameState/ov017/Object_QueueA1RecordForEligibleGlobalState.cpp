#include <globaldefs.h>
ARM
extern "C" void* Object_GetGlobalConnectionState();
extern "C" int IsFirstWordNonzero(void*);
extern "C" bool TestActiveWordAndGlobalStateNonzero(unsigned int*);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* ReadGlobalAt02100044();
extern "C" void MoveQueuedRecordAndApplySourceValue(void*, const void*, short);
// Original: arm9/ov017 @ 0x021CFABC; symbol: func_ov017_021cfabc; size: 0x50.
extern "C" void Object_QueueA1RecordForEligibleGlobalState(void) {
    void* state = Object_GetGlobalConnectionState();
    if (IsFirstWordNonzero(state) && !TestActiveWordAndGlobalStateNonzero((unsigned int*)state)) {
        char record[0x14];
        _ZN9GameState11GetInstanceEv();
        void* object = ReadGlobalAt02100044();
        *(unsigned char*)record = 0xa1;
        MoveQueuedRecordAndApplySourceValue(object, record, 0);
    }
}
